#pragma once
#include "audionode.h"
class CRingModulation :
	public CAudioNode
{
public:
	CRingModulation(void);
	~CRingModulation(void);

	virtual bool Generate();
	virtual void Start();
};

