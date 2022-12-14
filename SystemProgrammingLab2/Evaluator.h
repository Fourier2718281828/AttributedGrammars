#pragma once
#include "NonTerminal.h"

class L;
class B;
class S;

class IEvaluator
{
public:
	virtual ~IEvaluator() = default;
public:
	virtual void evaluate(L&) const = 0;
	virtual void evaluate(B&) const = 0;
	virtual void evaluate(S&) const = 0;
};

