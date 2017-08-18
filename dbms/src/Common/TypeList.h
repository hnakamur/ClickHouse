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

template <template <typename ...> typename Class, template <typename ...> typename List, typename ... Types>
struct ApplyTypeListForClass;

template <template <typename ...> typename Class, template <typename Type, typename ...> typename List, typename ... Types>
struct ApplyTypeListForClass<Class, List, Types ...>
{
    using Type = typename ApplyTypeListForClass<Class, typename List::Tail, Type, Types ...>::Type;
};

template <template <typename ...> typename Class, template <> typename List, typename ... Types>
struct ApplyTypeListForClass<Class, List, Types ...>
{
    using Type = typename Class<Types ...>;
};

}
