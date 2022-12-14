#pragma once
#include "Evaluator.h"

class StandardEvaluator : public IEvaluator
{
private:
	using power_type = size_t;
public:
	StandardEvaluator(const INonTerminal::value_type base);
	~StandardEvaluator() override = default;
public:
	void evaluate(L&) const override;
	void evaluate(B&) const override;
	void evaluate(S&) const override;
private:
	INonTerminal::value_type base_pow(const power_type) const;
	INonTerminal::value_type base() const;
private:
	const INonTerminal::value_type _base;
};

