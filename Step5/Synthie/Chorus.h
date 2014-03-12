#pragma once
#include "Instrument.h"

class CChorus:
	public CAudioNode
{
public:
	CChorus(void);
	~CChorus(void);

	virtual void Start();
	virtual bool Generate();

	void SetNode(CAudioNode* node) { m_node = node; }

	void SetThreshold(short thresh) { m_threshold = thresh; }

	void Process(double *frameIn, double *frameOut);

	void SetNote(CNote *note);

	void SetDuration(double d) {m_duration = d;}

private:
	CAudioNode* m_node;
	short m_threshold;
	double m_duration;
};

