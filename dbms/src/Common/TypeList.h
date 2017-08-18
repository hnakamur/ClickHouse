#pragma once

namespace DB
{

template <typename ... Types>
struct TypeList;

template<>
struct TypeList<> {};

template <typename Type, typename ... Types>
struct TypeList<Type, Types ...>
{
    using Head = Type;
    using Tail = TypeList<Types ...>;
};



}
