/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <queue>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL queue.
 */
template <
    typename T,
    typename Container = std::deque<T>
>
class queue: protected std::queue<T, Container>
{
protected:
    typedef std::queue<T, Container> Base;
    typedef queue<T, Container> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename C>
    friend void swap(queue<V, C> &left, queue<V, C> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename C>
    friend bool operator==(const queue<V, C> &left, const queue<V, C> &right);

    template <typename V, typename C>
    friend bool operator!=(const queue<V, C> &left, const queue<V, C> &right);

    template <typename V, typename C>
    friend bool operator>(const queue<V, C> &left, const queue<V, C> &right);

    template <typename V, typename C>
    friend bool operator>=(const queue<V, C> &left, const queue<V, C> &right);

    template <typename V, typename C>
    friend bool operator<(const queue<V, C> &left, const queue<V, C> &right);

    template <typename V, typename C>
    friend bool operator<=(const queue<V, C> &left, const queue<V, C> &right);

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
    virtual ~queue();

    using Base::empty;
    using Base::size;
    using Base::front;
    using Base::back;
    using Base::push;
    using Base::emplace;
    using Base::pop;
    void swap(This &other);
};


// IMPLEMENTATION
// --------------


template <typename T, typename Container>
auto queue<T, Container>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Container>
auto queue<T, Container>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Container>
auto queue<T, Container>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Container>
auto queue<T, Container>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Container>
void swap(queue<T, Container> &left,
    queue<T, Container> &right)
{
    left.swap(right);
}


template <typename T, typename Container>
bool operator==(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Container>
bool operator!=(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Container>
bool operator>(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Container>
bool operator>=(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Container>
bool operator<(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Container>
bool operator<=(const queue<T, Container> &left,
    const queue<T, Container> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Container>
queue<T, Container>::~queue()
{}


template <typename T, typename Container>
void queue<T, Container>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
