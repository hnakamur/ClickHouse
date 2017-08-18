#pragma once

namespace DB
{

template <typename ... Types>
struct TypeList;

template<>
struct TypeList<>
{
};

template <template <typename ...> typename Class, template <typename ... Types> typename List>
struct ApplyTypeListForClass
{
    using Type = typename Class<Types ...>;
};

}
