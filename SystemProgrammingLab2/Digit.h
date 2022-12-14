//#ifndef _DIGIT_M_
//#define _DIGIT_M_
//#include "NonTerminal.h"
//
//class Digit : public NonTerminal
//{
//public:
//	Digit(value_type, length_type) noexcept;
//	Digit(const Digit&) = default;
//	~Digit() override = default;
//public:
//	Digit& operator=(const Digit&)& = default;
//public:
//	value_type& value() override;
//	length_type& length() override;
//private:
//	value_type _value;
//	length_type _length;
//};
//
//Digit::Digit(value_type val, length_type len) noexcept :
//	_value(val),
//	_length(len)
//{
//
//}
//
//inline auto Digit::value() -> value_type&
//{
//	return _value;
//}
//
//inline auto Digit::length() -> length_type&
//{
//	return _length;
//}
//
//#endif // !_DIGIT_M_