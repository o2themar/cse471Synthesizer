#pragma once
#include "AudioNode.h"
class CReverberation:
	public CAudioNode
{
public:
	CReverberation(void);
	~CReverberation(void);

	virtual void Start();
	virtual bool Generate();

	void SetNode(CAudioNode* node) { m_node = node; }

	void SetThreshold(short thresh) { m_threshold = thresh; }


	void Process(double *frameIn, double *frameOut);

private:
	CAudioNode* m_node;
	short m_threshold;

};

