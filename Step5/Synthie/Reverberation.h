#pragma once
#include "AudioNode.h"
#include "Instrument.h"
#include <vector>
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

	void SetNote(CNote *note);

	void SetDuration(double d) {m_duration = d;}

private:
	CAudioNode* m_node;
	short m_threshold;

	double m_duration;

	std::vector<short> m_queue;
	int m_wrloc;
	int m_rdloc;
	double m_dry;
	double m_wet;
};

