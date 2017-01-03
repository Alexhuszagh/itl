/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <deque>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL deque.
 */
template <
    typename T,
    typename Alloc = std::allocator<T>
>
class deque: protected std::deque<T, Alloc>
{
protected:
    typedef std::deque<T, Alloc> Base;
    typedef deque<T, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename A>
    friend void swap(deque<V, A> &left, deque<V, A> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename A>
    friend bool operator==(const deque<V, A> &left, const deque<V, A> &right);

    template <typename V, typename A>
    friend bool operator!=(const deque<V, A> &left, const deque<V, A> &right);

    template <typename V, typename A>
    friend bool operator>(const deque<V, A> &left, const deque<V, A> &right);

    template <typename V, typename A>
    friend bool operator>=(const deque<V, A> &left, const deque<V, A> &right);

    template <typename V, typename A>
    friend bool operator<(const deque<V, A> &left, const deque<V, A> &right);

    template <typename V, typename A>
    friend bool operator<=(const deque<V, A> &left, const deque<V, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::value_type;
    using typename Base::allocator_type;
    using typename Base::reference;
    using typename Base::const_reference;
    using typename Base::pointer;
    using typename Base::const_pointer;
    using typename Base::iterator;
    using typename Base::const_iterator;
    using typename Base::reverse_iterator;
    using typename Base::const_reverse_iterator;
    using typename Base::difference_type;
    using typename Base::size_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~deque();

    // ITERATORS
    using Base::begin;
    using Base::end;
    using Base::rbegin;
    using Base::rend;
    using Base::cbegin;
    using Base::cend;
    using Base::crbegin;
    using Base::crend;

    // CAPACITY
    using Base::size;
    using Base::max_size;
    using Base::resize;
    using Base::empty;
    using Base::shrink_to_fit;

    // ELEMENT ACCESS
    using Base::operator[];
    using Base::at;
    using Base::front;
    using Base::back;

    // MODIFIERS
    using Base::assign;
    using Base::push_back;
    using Base::push_front;
    using Base::pop_back;
    using Base::pop_front;
    using Base::insert;
    using Base::erase;
    using Base::clear;
    using Base::emplace;
    using Base::emplace_front;
    using Base::emplace_back;
    void swap(This &other);

    // ALLOCATORS
    using Base::get_allocator;
};


// IMPLEMENTATION
// --------------


template <typename T, typename Alloc>
auto deque<T, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Alloc>
auto deque<T, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Alloc>
auto deque<T, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Alloc>
auto deque<T, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Alloc>
void swap(deque<T, Alloc> &left,
    deque<T, Alloc> &right)
{
    left.swap(right);
}


template <typename T, typename Alloc>
bool operator==(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Alloc>
bool operator!=(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Alloc>
bool operator>(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Alloc>
bool operator>=(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Alloc>
bool operator<(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Alloc>
bool operator<=(const deque<T, Alloc> &left,
    const deque<T, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Alloc>
deque<T, Alloc>::~deque()
{}


template <typename T, typename Alloc>
void deque<T, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
