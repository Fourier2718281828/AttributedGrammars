#pragma once
#include "NonTerminal.h"

class B : public INonTerminal 
{
public:
	explicit B(const value_type& value) noexcept;
	~B() override = default;
public:
	child_ptr  left_child() override;
	child_ptr right_child() override;
	void evaluate(const IEvaluator&) override;
public:
	const value_type& value() const;
private:
	value_type _value;
};

B::B(const value_type& value) noexcept :
	_value(value)
{
}

inline auto B::left_child() -> child_ptr
{
	return nullptr;
}

inline auto B::right_child() -> child_ptr
{
	return nullptr;
}

inline void B::evaluate(const IEvaluator& ev)
{
	ev.evaluate(*this);
}

inline auto B::value() const -> const value_type&
{
	return _value;
}