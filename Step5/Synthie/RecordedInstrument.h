#pragma once
#include "instrument.h"
#include "audio/Wave.h"
#include "audio/DirSoundStream.h"
#include "audio/DirSoundSource.h"
#include "audio/WaveformBuffer.h"
#include "NoiseGate.h"
#include "RingModulation.h"

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
	void ProcessReadFrame();
	void ProcessWriteFrame();

	CDirSoundSource   m_wavein;

	CNoiseGate m_noiseGate;
	CRingModulation m_ringMod;
};

