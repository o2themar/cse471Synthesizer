#include "StdAfx.h"
#include "AddSines.h"
#include <cmath>


CAddSines::CAddSines(void)
{
    for(int i=0; i<8;  i++)
        m_amp[i] = 1;
}

CAddSines::~CAddSines(void)
{
}


void CAddSines::Start()
{
    m_phase = 0;
}

bool CAddSines::Generate()
{
    double sample = 0;
    for(int i=0;  i<8;  i++)
    {
        sample += m_amp[i] * sin(m_phase * (i * 2 + 1));
    }

    m_frame[1] = m_frame[0] = sample;
    m_phase += 2 * PI * m_freq * GetSamplePeriod();

    return true;
}
