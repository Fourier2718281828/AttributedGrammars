#include "StandardEvaluator.h"
#include "Casting.h"
#include "NonTermB.h"
#include "NonTermL.h"
#include "NonTermS.h"
#include <cmath>

StandardEvaluator::StandardEvaluator(const INonTerminal::value_type base) :
	_base(base)
{
}

void StandardEvaluator::evaluate(L& l) const
{
	auto left_child = l.left_child();
	auto right_child = l.right_child();
	right_child->evaluate(*this);
	
	if (left_child)
	{
		left_child->evaluate(*this);
		const L& const l1 = dynamic_cast<const L&>(*left_child);
		const B& const b1 = dynamic_cast<const B&>(*right_child);

		l.value() = base() * l1.value() + b1.value();
		l.length() = l1.length() + 1;
	}
	else
	{
		const B& b = dynamic_cast<const B&>(*right_child);
		l.value() = b.value();
		l.length() = 1;
	}
}

void StandardEvaluator::evaluate(B& b) const
{
	b.value() = b.value() * base();
}

void StandardEvaluator::evaluate(S& s) const
{
	auto left_child = s.left_child();
	auto right_child = s.right_child();
	left_child->evaluate(*this);
	right_child->evaluate(*this);

	const L* const l1 = dynamic_cast<const L*>(left_child.get());
	const L* const l2 = dynamic_cast<const L*>(right_child.get());
	s.value() = l1->value() + l2->value() / base_pow(l2->length());

}


INonTerminal::value_type StandardEvaluator::base_pow(const power_type power) const
{
	return std::pow(base(), power);
}

INonTerminal::value_type StandardEvaluator::base() const
{
	return _base;
}
