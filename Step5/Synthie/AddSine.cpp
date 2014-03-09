#include "StdAfx.h"
#include <math.h>
#include "AddWave.h"

using namespace std;

double const M_PI = 3.14159265;

CAddWave::CAddWave(void)
{
	m_phase = 0;
	m_amp = 0.2;
	
	for(int i = 0; i < definedharmonics; i++)
	{
		m_harmonics[i] = 0;
	}
}


CAddWave::~CAddWave(void)
{
}

void CAddWave::Start()
{
	m_phase = 0;

	bool someAmp = false;

	for(int i = 0; i < definedharmonics; i++)
	{
		if(m_harmonics[i] != 0)
		{
			someAmp = true;
			break;
		}
	}

	if(!someAmp)
	{
		m_harmonics[0] = 1.;
	}
	GenerateTable();
}

void CAddWave::Start(double harmonics[definedharmonics])
{
	for(int i = 0; i < definedharmonics; i++)
	{
		m_harmonics[i] = harmonics[i];
	}

    m_phase = 0;
	GenerateTable();
}

void CAddWave::GenerateTable()
{
	double timeVal = 0;
	m_cycleSize = int(double(m_sampleRate / m_freq) + 0.5);
	m_table.resize(m_cycleSize);

	//Generate Table
	for(int i = 0; i < m_cycleSize; i++)
	{
		double time = i / m_sampleRate;
		double curVal = 0;
		for(int j = 1; m_freq * double(j) < m_sampleRate/2; j++)
		{
			double sinVal = sin(time * 2 * M_PI * m_freq * j);
			double interm = m_harmonics[j-1] * sinVal;
			curVal += interm;
		}
		m_table[i] = curVal;
	}

}

bool CAddWave::Generate()
{
	m_frame[0] = m_frame[1] = m_table[int(m_phase) % m_cycleSize];

    m_phase += 1;

    return true;
}
