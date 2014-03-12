#pragma once
#include "OddSinesInstrument.h"
#include "Note.h"

class COddSinesFactory
{
public:
	COddSinesFactory(void);
	virtual ~COddSinesFactory(void);

	COddSinesInstrument* CreateInstrument();
	void SetNote(CNote *note);

private:
	double m_amps[4];
};

