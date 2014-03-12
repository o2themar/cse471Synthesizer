#pragma once
#include "audionode.h"
class CFlanging:
	public CAudioNode
{
public:
	CFlanging(void);
	~CFlanging(void);

	virtual void Start();
	virtual bool Generate();

	void SetNode(CAudioNode* node) { m_node = node; }

	void SetThreshold(short thresh) { m_threshold = thresh; }

	void Process(double *frameIn, double *frameOut);

private:
	CAudioNode* m_node;
	short m_threshold;
};

