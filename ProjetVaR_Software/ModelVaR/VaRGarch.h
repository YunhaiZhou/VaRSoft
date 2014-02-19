#ifndef H_VARGARCH
#define H_VARGARCH

#include "VaRAlgorithm.h"
#include "GarchModel.h"

class VaRGarch: public VaRAlgorithm {
private:
	const GarchModel& garchModel;

public:
	VaRGarch(const Portfolio& portfolio, double risk, const GarchModel& garchModel);
    virtual double execute(QDateTime timeHorizon) const;
};

#endif