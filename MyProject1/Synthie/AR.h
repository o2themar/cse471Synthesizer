#pragma once
#include "AudioNode.h"

class CAR : public CAudioNode
{
public:
	CAR(void);
	~CAR(void);

	void SetSource(CAudioNode *source) { m_source = source; }
	virtual void Start();
	virtual bool Generate();
	void SetDuration(double value) { m_duration = value; }
	void SetBPM(double value) {m_bpm = value;}

private:
	double m_attack;
	double m_release;
	double m_decay;
	double m_level;

	double m_duration;
	double m_time;
	double m_bpm;

	CAudioNode *m_source;
};
