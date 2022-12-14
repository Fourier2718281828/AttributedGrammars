#ifndef _NODE_M_
#define _NODE_M_
#include "NumberAttributeSystem.h"
#include "Evaluator.h"
#include <memory>

class INonTerminal
{
public:
	using AttributeSystem = NumberAttributeSystem;
	using enum_type = AttributeSystem::ATTRIBUTES_ENUM;
	template<enum_type E>
	using _typeof = AttributeSystem::ATTRIBUTE_TYPE<E>;
	using value_type = _typeof<enum_type::VALUE>;
	using length_type = _typeof<enum_type::LENGTH>;
	template<typename T>
	using ptr = std::shared_ptr<T>;
	using child_ptr = ptr<INonTerminal>;
public:
	virtual ~INonTerminal() = default;
public:
	virtual child_ptr  left_child() = 0;
	virtual child_ptr right_child() = 0;
	virtual void evaluate(const IEvaluator&) = 0;
};

#endif // !_NODE_M_
