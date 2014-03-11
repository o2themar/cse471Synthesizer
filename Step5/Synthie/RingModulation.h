#pragma once
#include "audionode.h"
#include "SineWave.h"

class CRingModulation :
	public CAudioNode
{
public:
	CRingModulation(void);
	~CRingModulation(void);

	virtual bool Generate();
	virtual void Start();
	void SetNode(CAudioNode *node) { m_node = node; }

private:
	CSineWave m_sine;
	CAudioNode *m_node;
};

