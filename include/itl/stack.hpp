/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <stack>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL stack.
 */
template <
    typename T,
    typename Container = std::deque<T>
>
class stack: protected std::stack<T, Container>
{
protected:
    typedef std::stack<T, Container> Base;
    typedef stack<T, Container> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename C>
    friend void swap(stack<V, C> &left, stack<V, C> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename C>
    friend bool operator==(const stack<V, C> &left, const stack<V, C> &right);

    template <typename V, typename C>
    friend bool operator!=(const stack<V, C> &left, const stack<V, C> &right);

    template <typename V, typename C>
    friend bool operator>(const stack<V, C> &left, const stack<V, C> &right);

    template <typename V, typename C>
    friend bool operator>=(const stack<V, C> &left, const stack<V, C> &right);

    template <typename V, typename C>
    friend bool operator<(const stack<V, C> &left, const stack<V, C> &right);

    template <typename V, typename C>
    friend bool operator<=(const stack<V, C> &left, const stack<V, C> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::value_type;
    using typename Base::container_type;
    using typename Base::reference;
    using typename Base::const_reference;
    using typename Base::size_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~stack();

    using Base::empty;
    using Base::size;
    using Base::top;
    using Base::push;
    using Base::emplace;
    using Base::pop;
    void swap(This &other);
};


// IMPLEMENTATION
// --------------


template <typename T, typename Container>
auto stack<T, Container>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Container>
auto stack<T, Container>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Container>
auto stack<T, Container>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Container>
auto stack<T, Container>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Container>
void swap(stack<T, Container> &left,
    stack<T, Container> &right)
{
    left.swap(right);
}


template <typename T, typename Container>
bool operator==(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Container>
bool operator!=(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Container>
bool operator>(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Container>
bool operator>=(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Container>
bool operator<(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Container>
bool operator<=(const stack<T, Container> &left,
    const stack<T, Container> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Container>
stack<T, Container>::~stack()
{}


template <typename T, typename Container>
void stack<T, Container>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
