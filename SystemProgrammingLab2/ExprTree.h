#pragma once
#include <iterator>
#include <string>
#include <memory>
#include "NonTerminal.h"
#include "IncorrectInputException.h"
#include "NonTermB.h"
#include "NonTermS.h"
#include "NonTermL.h"
#include "Evaluator.h"

template<typename T>
void f(T) = delete;

template<std::forward_iterator Itor>
INonTerminal::ptr<L> processPart(Itor beg, const Itor end)
{
	if(beg == end)
		throw IncorrectInputException("Pre- and post-dot number parts cannot be empty.");

	auto to_num = [](const Itor::value_type ch) { return ch - '0'; };
	auto read_b = [&to_num](const Itor::value_type ch)
	{
		auto num = to_num(ch);
		return std::make_shared<B>(static_cast<B::value_type>(num), ch);
	};

	auto fst_b = read_b(*beg++);
	auto curr_l = std::make_shared<L>(fst_b);

	for (; beg != end; ++beg)
	{
		auto nxt_b = read_b(*beg);
		curr_l = std::make_shared<L>(curr_l, nxt_b);
	}

	return curr_l;
}

template<std::forward_iterator Itor>
std::unique_ptr<INonTerminal> build_tree
(
	Itor begin,
	Itor dot_position,
	const Itor end,
	const IEvaluator& evaluator
)
{
	const std::string int_part(begin, dot_position);
	const std::string frc_part(++dot_position, end);

	auto left  = processPart(int_part.begin(), int_part.end());
	auto right = processPart(frc_part.begin(), frc_part.end());
	
	auto non_evaled = std::make_unique<S>(left, right);
	non_evaled->evaluate(evaluator);

	return non_evaled;
}

