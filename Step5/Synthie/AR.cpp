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
	m_attack = m_duration/4;
	m_release = m_duration/4;
	m_decay = m_duration/4;
	m_level = .5;
	m_time = 0;
}

bool CAR::Generate()
{
	m_frame[0] = m_source->Frame(0);
	m_frame[1] = m_source->Frame(1);

	if(m_time < m_attack)
	{
		m_frame[0] = m_frame[0] * (m_time / m_attack);
		m_frame[1] = m_frame[1] * (m_time / m_attack);
	}
	else if (m_time > m_attack && m_time < m_attack + m_decay)
	{
		m_frame[0] = (m_frame[0] * m_level) + m_frame[0] * (m_attack + m_decay - m_time)/m_decay;
		m_frame[1] = (m_frame[1] * m_level) + m_frame[1] * (m_attack + m_decay - m_time)/m_decay;
	}
	else if (m_time > (m_attack + m_decay) && m_time < (m_duration - m_release))
	{
		m_frame[0] = m_frame[0] * m_level;
		m_frame[1] = m_frame[1] * m_level;
	}
	else if(m_time > m_duration - m_release)
	{
		m_frame[0] = (m_frame[0] * m_level) * (m_duration - m_time) / m_release;
		m_frame[1] = (m_frame[1] * m_level) * (m_duration - m_time) / m_release;
	}

	m_time += GetSamplePeriod();

	return m_time < m_duration/(m_bpm/60.0);
}
