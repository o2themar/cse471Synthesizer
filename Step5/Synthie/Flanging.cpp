#include "StdAfx.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Flanging.h"
#include <vector>

CFlanging::CFlanging(void)
{
}


CFlanging::~CFlanging(void)
{
}

void CFlanging::Start()
{

}

bool CFlanging::Generate()
{
	return false;
}

void CFlanging::Process(double *frameIn, double *frameOut)
{
	const int QUEUESIZE = 200000;
	double delay = 1.0;

	std::vector<short> queue;
	queue.resize(QUEUESIZE);

	int wrloc = 0;

	double time = 0;

	delay = 0.006 + sin(0.25 * 2 * PI * time) * 0.004;

	wrloc = (wrloc + 2) % QUEUESIZE;
	queue[wrloc] = frameIn[0];
	queue[wrloc + 1] = frameIn[1];

	int delaylength = int( (delay * GetSampleRate() + 0.5)) * 2;
	int rdloc = (wrloc + QUEUESIZE - delaylength) % QUEUESIZE;

	frameOut[0] = frameIn[0]/2 + queue[rdloc++]/2;
	frameOut[1] = frameIn[1]/2 + queue[rdloc]/2;
}

void CFlanging::SetNote(CNote *note)
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
