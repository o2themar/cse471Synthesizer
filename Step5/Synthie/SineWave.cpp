#include "StdAfx.h"
#include "SineWave.h"
#include <cmath>

CSineWave::CSineWave()
{

}

void CSineWave::Start()
{
    m_phase = 0;
}


CSineWave::~CSineWave(void)
{
}

bool CSineWave::Generate()
{
    m_frame[0] = m_amp * sin(m_phase * 2 * PI);
    m_frame[1] = m_frame[0];

    m_phase += m_freq * GetSamplePeriod();

    return true;
}
