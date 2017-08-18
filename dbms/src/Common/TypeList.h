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

template <template <typename ...> typename Class, typename List, typename ... Types>
struct ApplyTypeListForClass;

template <template <typename ...> typename Class, typename List, typename ... Types>
struct ApplyTypeListForClass<Class, List, Types ...>
{
    using Type = typename ApplyTypeListForClass<Class, typename List::Tail, typename List::Head, Types ...>::Type;
};

template <template <typename ...> typename Class, typename ... Types>
struct ApplyTypeListForClass<Class, TypeList<>, Types ...>
{
    using Type = typename Class<Types ...>;
};

}
