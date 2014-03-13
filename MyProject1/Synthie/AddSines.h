#pragma once
#include "audionode.h"
class CAddSines :
	public CAudioNode
{
public:
	CAddSines(void);
	~CAddSines(void);

public:
    virtual void Start();
    virtual bool Generate();

    void SetFreq(double f) {m_freq = f;}
    void SetAmplitude(int i, double a) {m_amp[i] = a;}

private:
    double m_freq;
    double m_phase;
    double m_amp[8];
};

