#include "StdAfx.h"
#include "AR.h"


CAR::CAR(void)
{
	m_duration = .1;
}


CAR::~CAR(void)
{
}

void CAR::Start()
{
	m_attack = .05;
	m_release = .05;
	m_time = 0;
}

bool CAR::Generate()
{
	m_frame[0] = m_source->Frame(0);
	m_frame[1] = m_source->Frame(1);

	if(m_time < m_attack)
	{
		m_frame[0] *= m_time / m_attack;
		m_frame[1] *= m_time / m_attack;
	}
	else if(m_time > m_duration - m_release)
	{
		m_frame[0] *= (m_duration - m_time) / (m_duration - m_release);
		m_frame[1] *= (m_duration - m_time) / (m_duration - m_release);
	}

	m_time += GetSamplePeriod();

	return m_time >= GetBPM()  * m_duration / 120. / 60.;
}
