#include "StdAfx.h"
#include "AR.h"


CAR::CAR(void)
{
	m_duration = .1;
	m_attack = .05;
	m_release =.05;
	m_decay = .05;
	m_level = .5;
	m_time = 0;
}


CAR::~CAR(void)
{
}

void CAR::Start()
{
	
}

bool CAR::Generate()
{
	m_frame[0] = m_source->Frame(0);
	m_frame[1] = m_source->Frame(1);

	// attack
	if(m_time < m_attack)
	{
		m_frame[0] = m_frame[0] * (m_time / m_attack);
		m_frame[1] = m_frame[1] * (m_time / m_attack);
	}
	// decay
	else if (m_time < m_attack + m_decay)
	{
		m_frame[0] = (m_frame[0] - (m_frame[0] * m_level)) + m_frame[0] * (m_attack + m_decay - m_time)/m_decay;
		m_frame[1] = (m_frame[1] - (m_frame[1] * m_level)) + m_frame[1] * (m_attack + m_decay - m_time)/m_decay;
	}
	//sustain
	else if (m_time < (m_duration - m_release))
	{
		m_frame[0] = m_frame[0] * m_level;
		m_frame[1] = m_frame[1] * m_level;
	}
	// release
	else
	{
		m_frame[0] = (m_frame[0] * m_level) * (m_duration - m_time) / m_release;
		m_frame[1] = (m_frame[1] * m_level) * (m_duration - m_time) / m_release;
	}

	m_time += GetSamplePeriod();

	return m_time < m_duration/(m_bpm/60.0);
}
