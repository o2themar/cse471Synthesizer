#pragma once
#include "audionode.h"
class CCrossFade :
	public CAudioNode
{
public:
	CCrossFade(void);
	virtual ~CCrossFade(void);

	virtual void Start();
    virtual bool Generate();
	void SetDuration(double value) { m_duration = value; }
	void SetBPM(double value) {m_bpm = value;}
	void SetStart(CAudioNode *start) { m_start = start;}
	void SetEnd(CAudioNode *end) {m_end = end;}

private:
	CAudioNode *m_start;
	CAudioNode *m_end;

	double m_bpm;
	double m_duration;
	double m_time;
};

