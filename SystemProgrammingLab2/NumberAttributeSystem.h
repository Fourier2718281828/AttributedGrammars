#ifndef _ATTRIBUTE_SYSTEM_M_
#define _ATTRIBUTE_SYSTEM_M_
#include "AttributeSystem.h"
#include <concepts>

struct NumberAttributeSystem
{
public:
	enum class ATTRIBUTES_ENUM
	{
		VALUE,
		LENGTH,
	};
private:
	template<ATTRIBUTES_ENUM _Attr>
	struct _attribute_type;
public:
	template<ATTRIBUTES_ENUM _Attr>
	using ATTRIBUTE_TYPE = _attribute_type<_Attr>;
	using ATTRIBUTE_DEFAULT_TYPE = std::nullptr_t;
};

template<NumberAttributeSystem::ATTRIBUTES_ENUM _Attr>
struct NumberAttributeSystem::_attribute_type
{
	using Type = NumberAttributeSystem::UndefinedType;
};

ATTRIBUTE_TYPEDEF(NumberAttributeSystem, VALUE, float)
ATTRIBUTE_TYPEDEF(NumberAttributeSystem, LENGTH, int)

#endif // !_ATTRIBUTE_SYSTEM_M_