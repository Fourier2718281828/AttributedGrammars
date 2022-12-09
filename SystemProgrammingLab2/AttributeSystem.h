#ifndef _ATTRIBUTESYSTEM_M_
#define _ATTRIBUTESYSTEM_M_

#define ATTRIBUTES_ENUM Attributes
#define ATTRIBUTE_TYPE AttributeType
#define ATTRIBUTE_DEFAULT_TYPE DefaultType
#define ATTRIBUTE_TYPEDEF(SYST, ENUM_ATTR, TYPE)                     \
template<>                                                           \
struct SYST:: _attribute_type<SYST :: ATTRIBUTES_ENUM :: ENUM_ATTR>  \
{                                                                    \
	using Type = TYPE;                                               \
};

template<typename AttrSyst>
concept AttributeSystem =
	requires (typename AttrSyst::ATTRIBUTES_ENUM en_v)
	{
		typename AttrSyst::ATTRIBUTES_ENUM; 
		//AttrSyst::ATTRIBUTE_TYPE<en_v> ; ???????????????????
		typename AttrSyst::ATTRIBUTE_DEFAULT_TYPE;
	};

#endif