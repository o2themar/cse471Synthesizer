#pragma once
#include "instrument.h"
#include "audio/Wave.h"
#include "audio/DirSoundStream.h"
#include "audio/DirSoundSource.h"
#include "audio/WaveformBuffer.h"

class CRecordedInstrument :
	public CAudioNode
{
public:
	CRecordedInstrument(void);
	virtual ~CRecordedInstrument(void);

	virtual void Start();

	virtual bool Generate();

	BOOL OpenDocument(LPCTSTR lpszPathName);

private:
	void ProcessReadFrame(short *p_frame);
	void ProcessWriteFrame(short *p_frame);

	CDirSoundSource   m_wavein;
};

