#pragma once
#include "instrument.h"
#include "AR.h"
#include "AddSines.h"
#include "CrossFade.h"

class CAddSinesInstrument :
	public CInstrument
{
public:
	CAddSinesInstrument(void);
	virtual ~CAddSinesInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote *note);
    
    void SetDuration(double d) {m_ar.SetDuration(d); m_crossfade.SetDuration(d);}
    void SetFreq(double f) {/*m_sines.SetFreq(f);*/ m_start.SetFreq(f); m_end.SetFreq(f);}
	void SetAmplitude(int i, double s, double e) {m_start.SetAmplitude(i, s); m_end.SetAmplitude(i, e);}
	//void SetAmplitude(int i, double d) {m_sines.SetAmplitude(i, d);}

private:
    CAR         m_ar;
    double  m_time;
	//CAddSines m_sines;

	CAddSines m_start;
	CAddSines m_end;
	CCrossFade m_crossfade;
};

