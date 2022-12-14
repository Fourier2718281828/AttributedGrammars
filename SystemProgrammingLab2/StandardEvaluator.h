#pragma once
#include "Evaluator.h"

class StandardEvaluator : public IEvaluator
{
public:
	void evaluate(L&) const override;
	void evaluate(B&) const override;
	void evaluate(S&) const override;
};

