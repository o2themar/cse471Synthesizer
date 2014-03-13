#include "StdAfx.h"
#include "CrossFade.h"


CCrossFade::CCrossFade(void)
{
	m_time = 0;
}


CCrossFade::~CCrossFade(void)
{
}

void CCrossFade::Start()
{
	m_time = 0;
}

bool CCrossFade::Generate()
{
	m_frame[0] = ((m_duration - m_time/m_duration) * m_start->Frame(0)) + ((m_time/m_duration) * m_end->Frame(0));
	m_frame[1] = ((m_duration - m_time/m_duration) * m_start->Frame(1)) + ((m_time/m_duration) * m_end->Frame(1));

	m_time += GetSamplePeriod();

	return m_time < m_duration/(m_bpm/60.0);
}