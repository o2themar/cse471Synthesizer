#pragma once
#include "AddSinesInstrument.h"
#include "Note.h"

class CAddSinesFactory
{
public:
	CAddSinesFactory(void);
	virtual ~CAddSinesFactory(void);

	CAddSinesInstrument* CreateInstrument();
	void SetNote(CNote *note);

private:
	double m_ampsStart[8];
	double m_ampsEnd[8];
};

