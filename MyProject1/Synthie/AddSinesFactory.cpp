#include "StdAfx.h"
#include "AddSinesFactory.h"

CAddSinesFactory::CAddSinesFactory(void)
{
	for(int i=0;  i<8;  i++)
	{
        m_ampsStart[i] = 0;
		m_ampsEnd[i] = 0;
	}
}


CAddSinesFactory::~CAddSinesFactory(void)
{
}

CAddSinesInstrument *CAddSinesFactory::CreateInstrument()
{
    CAddSinesInstrument *instrument = new CAddSinesInstrument();

	for(int i=0;  i<8;  i++)
    {
        instrument->SetAmplitude(i, m_ampsStart[i], m_ampsEnd[i]);
    }

    return instrument;
}


void CAddSinesFactory::SetNote(CNote *note)
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

		if(name == "a1")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[0] = value.dblVal;
        }
        else if(name == "a2")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[1] = value.dblVal;
        }
        else if(name == "a3")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[2] = value.dblVal;
        }
        else if(name == "a4")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[3] = value.dblVal;
        }
		 else if(name == "a5")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[4] = value.dblVal;
        }
        else if(name == "a6")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[5] = value.dblVal;
        }
        else if(name == "a7")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[6] = value.dblVal;
        }
		else if(name == "a8")
        {
            value.ChangeType(VT_R8);
            m_ampsStart[7] = value.dblVal;
        }
		// second sound b
		else if(name == "b1")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[0] = value.dblVal;
        }
        else if(name == "b2")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[1] = value.dblVal;
        }
        else if(name == "b3")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[2] = value.dblVal;
        }
        else if(name == "b4")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[3] = value.dblVal;
        }
		 else if(name == "b5")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[4] = value.dblVal;
        }
        else if(name == "b6")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[5] = value.dblVal;
        }
        else if(name == "b7")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[6] = value.dblVal;
        }
		else if(name == "b8")
        {
            value.ChangeType(VT_R8);
            m_ampsEnd[7] = value.dblVal;
        }
    }

}
