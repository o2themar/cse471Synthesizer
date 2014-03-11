#include "StdAfx.h"
#include "NoiseGate.h"


CNoiseGate::CNoiseGate(void)
{
	m_threshold = 1;
}


CNoiseGate::~CNoiseGate(void)
{
}

void CNoiseGate::Start()
{

}

bool CNoiseGate::Generate()
{
	if(m_node == NULL)
		return false;

	m_frame[0] = m_node->Frame(0);
	m_frame[1] = m_node->Frame(1);
	
	if (m_frame[0] > m_threshold || m_frame[0] < - m_threshold)
	{
	   m_frame[0] *= 2.25;
	   if (m_frame[0] > 32768)      m_frame[0] = 32768;
	   if (m_frame[0] < -32768)   m_frame[0] = -32768;
	}

	else m_frame[0] = 0;

	if (m_frame[1] > m_threshold || m_frame[1] < - m_threshold)
	{
	   m_frame[1] *= 2.25;
	   if (m_frame[1] > 32768)      m_frame[1] = 32768;
	   if (m_frame[1] < -32768)   m_frame[1] = -32768;
	}

	else m_frame[1] = 0;

	return true;
}
