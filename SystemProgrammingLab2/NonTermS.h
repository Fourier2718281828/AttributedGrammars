#ifndef _S_NON_TERM
#define _S_NON_TERM

#include "NonTerminal.h"
#include "NonTermL.h"

class S : public INonTerminal
{
public:
	S(ptr<L> l, ptr<L> r) noexcept :
		_left_child(l), _right_child(r), _value(static_cast<value_type>(0))
	{
	}
	~S() override = default;
public:
	child_ptr  left_child() override;
	child_ptr right_child() override;
	void evaluate(const IEvaluator&) override;
public:
	value_type& value() noexcept;
	const value_type& value() const noexcept;
private:
	ptr<L> _left_child;
	ptr<L> _right_child;
	value_type _value;
};

//S::S(ptr<L> l, ptr<L> r) noexcept :
//	_left_child(l), _right_child(r), _value(static_cast<value_type>(0))
//{
//}

inline auto S::left_child() -> child_ptr
{
	return _left_child;
}

inline auto S::right_child() -> child_ptr
{
	return _right_child;
}

inline void S::evaluate(const IEvaluator& ev)
{
	ev.evaluate(*this);
}

inline auto S::value() noexcept -> value_type&
{
	return _value;
}

inline auto S::value() const noexcept -> const value_type&
{
	return _value;
}

#endif // !_S_NON_TERM