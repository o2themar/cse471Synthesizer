#include "StdAfx.h"
#include "AddSinesInstrument.h"
#include "Notes.h"


CAddSinesInstrument::CAddSinesInstrument(void)
{
}


CAddSinesInstrument::~CAddSinesInstrument(void)
{
}

void CAddSinesInstrument::Start()
{
	m_start.SetSampleRate(GetSampleRate());
	m_start.Start();
	m_end.SetSampleRate(GetSampleRate());
	m_end.Start();

	m_ar.SetBPM(m_bpm);
    m_ar.SetSampleRate(GetSampleRate());
    m_ar.Start();
    m_time = 0;

	m_crossfade.SetBPM(m_bpm);
	m_crossfade.SetSampleRate(GetSampleRate());
	m_crossfade.SetStart(&m_start);
	m_crossfade.SetEnd(&m_end);
	m_crossfade.Start();

	m_ar.SetSource(&m_crossfade);
	//m_sines.SetSampleRate(GetSampleRate());
    //m_sines.Start();
    //m_ar.SetSource(&m_sines);
}


void CAddSinesInstrument::SetNote(CNote *note)
{
    // Get a list of all attribute nodes and the
    // length of that list
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Loop over the list of attributes
    for(int i=0;  i<len;  i++)
    {
        // Get attribute i
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the name of the attribute
        CComBSTR name;
        attrib->get_nodeName(&name);

        CComVariant value;
        attrib->get_nodeValue(&value);

        if(name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration(value.dblVal);
        }
        else if(name == "note")
        {
            SetFreq(NoteToFrequency(value.bstrVal));
        }
    }

}


bool CAddSinesInstrument::Generate()
{
	//m_sines.Generate();
	m_start.Generate();
	m_end.Generate();
	m_crossfade.Generate();
    bool valid = m_ar.Generate();

    m_frame[0] = m_ar.Frame(0);
    m_frame[1] = m_ar.Frame(1);

    m_time += GetSamplePeriod();
    return valid;
}