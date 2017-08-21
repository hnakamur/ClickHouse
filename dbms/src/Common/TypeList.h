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

/// Append Type to TypeList
/// Usage:
///     using TypeListWithType = AppendToTypeList<Type, ConcreteTypeList>::Type;
template <typename Type, typename List, typename ... Types>
struct AppendToTypeList
{
    using Type = typename AppendToTypeList<Type, typename List::Tail, typename List::Head, Types ...>;
};

template <typename Type, typename ... Types>
struct AppendToTypeList<Type, TypeList<>, Types ...>
{
    using Type = TypeList<Type, Types ...>;
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
