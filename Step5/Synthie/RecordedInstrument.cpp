#include "StdAfx.h"
#include "RecordedInstrument.h"


CRecordedInstrument::CRecordedInstrument(void)
{
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

	return TRUE;
}

void CRecordedInstrument::Start()
{
	m_wavein.Rewind();
}

bool CRecordedInstrument::Generate()
{
	short frame[2];
	ProcessReadFrame(frame);


	ProcessWriteFrame(frame);
	return m_wavein.HasAudio();
}

void CRecordedInstrument::ProcessReadFrame(short *p_frame)
{
   m_wavein.ReadFrame(p_frame);
}

void CRecordedInstrument::ProcessWriteFrame(short *p_frame)
{
	m_frame[0] = p_frame[0] / 32768.0;
	m_frame[1] = p_frame[1] / 32768.0;
}

