#include "StdAfx.h"
#include "AddSynth.h"
#include "Notes.h"
#include <string>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

double const M_PI = 3.14159265;

CAddSynth::CAddSynth(void)
{
	m_duration = 0.1;
	m_attack = 0.1;
	m_decay = 0.5;
	m_sustain = 0.9;
	m_release = 1.0;
	m_writeLoc = 0;
}


CAddSynth::~CAddSynth(void)
{
}

void CAddSynth::SetHarmonics(wstring harmonics)
{
	for(int i = 0; i < definedharmonics; i++)
	{
		harmonics[i] = 10^(3*(definedharmonics-i)/20);
	}
}

void CAddSynth::Start()
{
    m_addwave.SetSampleRate(GetSampleRate());
    m_addwave.Start(m_harmonics);
    m_time = 0;
	outputQueue.resize(9);
}


bool CAddSynth::Generate()
{
    // Tell the component to generate an audio sample
    m_addwave.Generate();

	double sustainValue = .5;

	double rawDuration = (m_duration/ (double)(m_bpm / 60.0));

	double ramp;
	if (m_time <= (m_attack * rawDuration))
	{
		ramp = m_time / (m_attack  * rawDuration);
	}
	else if(m_time > (rawDuration * m_attack) && m_time <= (m_decay * rawDuration))
	{
		ramp = 1 + (1-sustainValue)/(m_decay - m_attack) * m_decay * rawDuration - (((1-sustainValue)/(m_decay - m_attack) * m_decay * rawDuration) * (m_time/rawDuration - m_attack));
	}
	else if (m_time <= (m_sustain * rawDuration) && m_time > (m_decay * rawDuration))
	{
		ramp = sustainValue; //(rawDuration - m_time) / m_release;
	}
	else if (m_time > m_sustain * rawDuration && m_time <= rawDuration)
	{
		ramp = sustainValue - sustainValue * (m_time - m_release * rawDuration)/((1 - m_release * rawDuration));
	}
	else
	{
		ramp = 0;
	}

    // Read the component's sample and make it our resulting frame.
    m_frame[0] = m_addwave.Frame(0) *ramp;
    m_frame[1] = m_addwave.Frame(1) *ramp;

    // Update time
    m_time += GetSamplePeriod();

    // We return true until the time reaches the duration.
    return m_time < m_duration * 60 / m_bpm;
}

void CAddSynth::SetNote(CNote *note)
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
            SetFreq(NoteToFrequency(value.bstrVal));
			m_freq = NoteToFrequency(value.bstrVal);
        }
		else if(name == "harmonics")
		{
			SetHarmonics(value.bstrVal);
		}
    }

}


