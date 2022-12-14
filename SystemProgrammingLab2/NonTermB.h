#ifndef _B_NONTERM_
#define _B_NONTERM_

#include "NonTerminal.h"

class B : public INonTerminal
{
public:
	B(const value_type value, const digit_type digit) noexcept :
		_value(value), _digit(digit)
	{
	}
	~B() override = default;
public:
	child_ptr  left_child() override;
	child_ptr right_child() override;
	void evaluate(const IEvaluator&) override;
	std::string view() const override;
public:
	value_type& value();
	const value_type value() const;
	const digit_type digit() const;
private:
	value_type _value;
	const digit_type _digit;
};

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

inline std::string B::view() const
{
	return std::string("B(") + std::string(1, digit()) + ')';
}

inline auto B::value() -> value_type&
{
	return _value;
}

inline auto B::value() const -> const value_type
{
	return _value;
}
inline auto B::digit() const -> const digit_type
{
	return _digit;
}
#endif // !_B_NONTERM_
