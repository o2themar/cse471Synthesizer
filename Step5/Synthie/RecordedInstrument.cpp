#include "StdAfx.h"
#include "RecordedInstrument.h"


CRecordedInstrument::CRecordedInstrument(void)
{
	m_currFrame = 0;
}


CRecordedInstrument::~CRecordedInstrument(void)
{
}

BOOL CRecordedInstrument::OpenDocument(LPCTSTR lpszPathName)
{
	if(!m_wavein.Open(lpszPathName))
		return FALSE;

	SetSampleRate(m_wavein.SampleRate());
	m_wavein.Rewind();

	m_noiseGate.SetNode(this);
	m_noiseGate.SetSampleRate(GetSampleRate());
	m_noiseGate.SetBPM(GetBPM());

	m_ringMod.SetNode(this);
	m_ringMod.SetSampleRate(GetSampleRate());
	m_ringMod.SetBPM(GetBPM());

	return TRUE;
}

void CRecordedInstrument::Start()
{
	m_wavein.Rewind();
	m_noiseGate.Start();
	m_ringMod.Start();
	m_currFrame = 0;
}

bool CRecordedInstrument::Generate()
{
	if( !m_wavein.HasAudio() )
		return false;

	if(++m_currFrame >= m_wavein.NumSampleFrames())
	{
		m_currFrame = 0;
		m_wavein.Rewind();
	}

	ProcessReadFrame();

	m_ringMod.Generate();
	m_frame[0] = m_ringMod.Frame(0);
	m_frame[1] = m_ringMod.Frame(1);

	m_noiseGate.Generate();
	m_frame[0] = m_noiseGate.Frame(0);
	m_frame[1] = m_noiseGate.Frame(1);

	ProcessWriteFrame();
	return true;
}

void CRecordedInstrument::ProcessReadFrame()
{
	short frame[2];
   m_wavein.ReadFrame(frame);
   m_frame[0] = frame[0];
   m_frame[1] = frame[1];

}

void CRecordedInstrument::ProcessWriteFrame()
{
	m_frame[0] /= 32768.0;
	m_frame[1] /= 32768.0;
}

