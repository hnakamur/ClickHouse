#pragma once

namespace DB
{

template <typename ... Types>
struct TypeList;

template <typename Type, typename ... Types>
struct TypeList<Type, Types...>
{
    using Head = Type;
    using Tail = TypeList<Types ...>;
};

template<>
struct TypeList<>
{
};

/// Apply TypeList as variadic template argument of Class.
/// Usage:
///     using ClassWithAppliedTypeList = ApplyTypeListForClass<Class, ConcreteTypeList>::Type;
template <template <typename ...> typename Class, typename List, typename ... Types>
struct ApplyTypeListForClass
{
    using Type = typename ApplyTypeListForClass<Class, typename List::Tail, typename List::Head, Types ...>::Type;
};

template <template <typename ...> typename Class, typename ... Types>
struct ApplyTypeListForClass<Class, TypeList<>, Types ...>
{
    using Type = Class<Types ...>;
};

}
