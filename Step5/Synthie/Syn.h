#pragma once
#include "instrument.h"
#include "AddWave.h"
#include <string>

using namespace std;

class CAddSynth :
	public CInstrument
{
public:
	CAddSynth(void);
	~CAddSynth(void);

	virtual void Start();
    virtual bool Generate();

	void SetFreq(double f) {m_addwave.SetFreq(f);}
    void SetAmplitude(double a) {m_addwave.SetAmplitude(a);}
    void SetDuration(double d) {m_duration = d;}
	void SetHarmonics(wstring harmonics);

	void SetNote(CNote *note);

private:
	CAddWave m_addwave;
    double m_duration;
    double m_time;
	wstring m_type;

	double m_freq;
	double m_amp;

	double m_harmonics[definedharmonics];

	double m_attack;
	double m_decay;
	double m_sustain;
	double m_release;

	vector<double> outputQueue;
	int m_writeLoc;
};
