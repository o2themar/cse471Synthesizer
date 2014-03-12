#include "StdAfx.h"
#include "RingModulation.h"


CRingModulation::CRingModulation(void)
{
}


CRingModulation::~CRingModulation(void)
{
}

void CRingModulation::Start()
{
	m_sine.SetSampleRate(GetSampleRate());
	m_sine.Start();
	m_sine.SetAmplitude(1);
	m_sine.SetFreq(PI / 6);
}

bool CRingModulation::Generate()
{
	if(m_node == NULL)
		return false;

	m_sine.Generate();

	m_frame[0] = m_sine.Frame(0) * m_node->Frame(0);
	m_frame[1] = m_sine.Frame(1) *  m_node->Frame(1);

	return true;
}