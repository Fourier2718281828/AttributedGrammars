#ifndef _NODE_M_
#define _NODE_M_
#include "NumberAttributeSystem.h"
#include <type_traits>

class Digit
{
public:
	using AttributeSystem = NumberAttributeSystem;
private:
	using AS = AttributeSystem;
	using Enum = AS::ATTRIBUTES_ENUM;
	template<Enum E>
	using TypeOf = AS::ATTRIBUTE_TYPE<E>;
public:
	using value_type = TypeOf<Enum::VALUE>;
	using length_type = TypeOf<Enum::LENGTH>;
	template<Enum E>
	using get_return_type = std::conditional_t
		<
		std::is_arithmetic_v<TypeOf<E>>,
		TypeOf<E>, 
		const TypeOf<E>&
		>;
public:
	Digit(value_type, length_type) noexcept;
	Digit(const Digit&) = default;
	~Digit() = default;
public:
	Digit& operator=(const Digit&)& = default;
public:
	template<Enum _Attr>
	get_return_type<_Attr> get_attribute() const noexcept;
private:
	value_type _value;
	length_type _length;
};

Digit::Digit(value_type val, length_type len) noexcept :
	_value(val),
	_length(len)
{

}

template<Digit::Enum _Attr>
inline auto Digit::get_attribute() const noexcept -> get_return_type<_Attr>
{
	if constexpr (_Attr == Enum::VALUE)
		return _value;
	else
		return _length;
}

#endif // !_NODE_M_
