#include "StdAfx.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Reverberation.h"
#include "Notes.h"

const float DECAY = 0.5;

CReverberation::CReverberation(void)
{
	m_wrloc = 0;
	m_rdloc = 0;
	m_dry = 1.0;
	m_wet = 0.0;
}


CReverberation::~CReverberation(void)
{
}

void CReverberation::Start()
{

}

bool CReverberation::Generate()
{
	return false;
}

void CReverberation::Process(double *frameIn, double *frameOut)
{
	const int QUEUESIZE = 200000;
	m_queue.resize(QUEUESIZE);

	for(int c = 0; c < 2; c++)
	{
		m_queue[m_wrloc + c] = frameIn[c] * DECAY;

		// Add output of the queue to the current input
		frameOut[c] = m_dry * frameIn[c] + m_wet * m_queue[m_rdloc + c];
	}

	m_wrloc = (m_wrloc + 2) % QUEUESIZE;
	m_rdloc = (m_rdloc + 2) % QUEUESIZE;
}

void CReverberation::SetNote(CNote *note)
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

        // Get the value of the attribute.  A CComVariant is a variable
        // that can have any type. It loads the attribute value as a
        // string (UNICODE), but we can then change it to an integer 
        // (VT_I4) or double (VT_R8) using the ChangeType function 
        // and then read its integer or double value from a member variable.
        CComVariant value;
        attrib->get_nodeValue(&value);

        if(name == "duration")
        {
            value.ChangeType(VT_R8);
            SetDuration(value.dblVal);
        }
		else if(name == "note")
        {
            
        }
		else if(name == "beat")
        {
			SetBPM(value.intVal);
        }
    }
}
