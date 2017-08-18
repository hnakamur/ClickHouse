#pragma once

namespace DB
{

template <typename ... Types>
struct TypeList;

template<>
struct TypeList<>
{
    static constexpr bool is_empty = true;
};

template <typename Type, typename ... Types>
struct TypeList<Type, Types ...>
{
    using Head = Type;
    using Tail = TypeList<Types ...>;

    static constexpr bool is_empty = false;
};



}
