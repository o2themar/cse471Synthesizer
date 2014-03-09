#pragma once
#include "audionode.h"
#include <string>
#include <vector>

using namespace std;

#define definedharmonics 8

class CAddWave :
	public CAudioNode
{
public:
	CAddWave(void);
	virtual ~CAddWave(void);

	virtual void Start();

	//! Start audio generation
    void Start(double harmonics[definedharmonics]);
	void GenerateTable();

    //! Generate one frame of audio
    virtual bool Generate();

    //! Set the sine wave frequency
    void SetFreq(double f) {m_freq = f;}

    //! Set the sine wave amplitude
    void SetAmplitude(double a) {m_amp = a;}

	//! Set the type of wave
	void SetHarmonics(double harmonics[definedharmonics]) { for(int i = 0; i < definedharmonics; i++) {m_harmonics[i] = harmonics[i];}}

	void SetDuration(double duration) {m_duration = duration;}

private:
    double m_freq;
    double m_amp;
    double m_phase;
	double m_harmonics[definedharmonics];
	double m_duration;

	vector<double> m_table;
	int m_cycleSize;
};

