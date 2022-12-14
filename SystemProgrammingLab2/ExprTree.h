#pragma once
#include <iterator>
#include <string>
#include <memory>
#include "Evaluator.h"
#include "NonTerminal.h"

template<std::forward_iterator Itor>
std::unique_ptr<INonTerminal> build_tree
(
	Itor begin,
	Itor dot_position,
	const Itor end,
	const IEvaluator& evaluator
)
{
	const std::string _int_part(begin, dot_position);
	const std::string _frc_part(++dot_position, end);



	return { nullptr };
}
