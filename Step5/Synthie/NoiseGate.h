#pragma once
#include "audionode.h"
class CNoiseGate :
	public CAudioNode
{
public:
	CNoiseGate(void);
	~CNoiseGate(void);

	virtual void Start();
	virtual bool Generate();

	void SetNode(CAudioNode* node) { m_node = node; }

	void SetThreshold(short thresh) { m_threshold = thresh; }

private:
	CAudioNode* m_node;
	short m_threshold;
};

