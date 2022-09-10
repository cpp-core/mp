// Copyright (C) 2021, 2022 by Mark Melton
//

#pragma once
#include <type_traits>

namespace core::mp
{

template<class L>
struct foreach_iterator;

template<template<class...> class W, class... Ts>
struct foreach_iterator<W<Ts...>> {
    template<class F, class... Args>
    void operator()(F&& f, Args&&... args) {
	(f.template operator()<Ts>(std::forward<Args>(args)...), ...);
    }

    template<class F, class... Args>
    void apply(F&& f, Args&&... args) {
	(f.template operator()<Ts>(std::forward<Args>(args)...), ...);
    }
    
    template<class F, class... Args>
    bool fold_or(F&& f, Args&&... args) {
	return (f.template operator()<Ts>(std::forward<Args>(args)...) || ...);
    }
    
    template<class F, class... Args>
    bool fold_and(F&& f, Args&&... args) {
	return (f.template operator()<Ts>(std::forward<Args>(args)...) && ...);
    }
};

template<class L, class... Args>
void foreach(Args&&... args) {
    foreach_iterator<L> impl;
    impl(std::forward<Args>(args)...);
}

template<class L, class... Args>
bool foreach_fold_or(Args&&... args) {
    foreach_iterator<L> impl;
    return impl.fold_or(std::forward<Args>(args)...);
}

template<class L, class... Args>
bool foreach_fold_and(Args&&... args) {
    foreach_iterator<L> impl;
    return impl.fold_and(std::forward<Args>(args)...);
}

}; // mp