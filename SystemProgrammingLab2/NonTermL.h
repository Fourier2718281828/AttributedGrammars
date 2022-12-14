#ifndef _L_NON_TERM_
#define _L_NON_TERM_

#include "NonTerminal.h"
#include "NonTermB.h"

class L : public INonTerminal
{
public:
	L(ptr<L>, ptr<B>) noexcept;
	L(ptr<B>) noexcept;
	~L() override = default;
public:
	child_ptr  left_child() override;
	child_ptr right_child() override;
	void evaluate(const IEvaluator&) override;
public:
	value_type& value();
	const value_type value() const;
	length_type& length();
	const length_type length() const;
private:
	ptr<L> _left_child;
	ptr<B> _right_child;
	value_type _value;
	length_type _length;
};

inline L::L(ptr<L> l, ptr<B> b) noexcept :
	_left_child(l),
	_right_child(b),
	_value(static_cast<value_type>(0)),
	_length(static_cast<length_type>(0))
{
}

inline L::L(ptr<B> b) noexcept :
	L(nullptr, b)
{
}

inline auto L::left_child() -> child_ptr
{
	return _left_child;
}

inline auto L::right_child() -> child_ptr
{
	return _right_child;
}

inline void L::evaluate(const IEvaluator& ev)
{
	ev.evaluate(*this);
}

inline auto L::value() -> value_type&
{
	return _value;
}

inline auto L::value() const -> const value_type
{
	return _value;
}

inline auto L::length() -> length_type&
{
	return _length;
}

inline auto L::length() const -> const length_type
{
	return _length;
}

#endif // !_L_NON_TERM_