// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::mp
{

template<class T, class U, template<class...> class V>
struct is_same_template : std::false_type
{ static constexpr bool value = false; };

template<template<class...> class T, template<class...> class U, class... Ts>
struct is_same_template<T<Ts...>, U<Ts...>, U>
{
    using type = std::true_type;
    static constexpr bool value = std::is_same_v<T<Ts...>,U<Ts...>>;
};

template<class T, template<class...> class U>
using is_same_template_t = typename is_same_template<T,T,U>::type;

/**
 * @brief Is class T a realization of template U?
 *
 * @tparam T the class to test
 * @tparam U the template to compare
 */
template<class T, template<class...> class U>
static constexpr bool is_same_template_v = is_same_template<T,T,U>::value;

}; // mp
