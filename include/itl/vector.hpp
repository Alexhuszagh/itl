/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <vector>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL vector.
 */
template <
    typename T,
    typename Alloc = std::allocator<T>
>
class vector: protected std::vector<T, Alloc>
{
protected:
    typedef std::vector<T, Alloc> Base;
    typedef vector<T, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename A>
    friend void swap(vector<V, A> &left, vector<V, A> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename A>
    friend bool operator==(const vector<V, A> &left, const vector<V, A> &right);

    template <typename V, typename A>
    friend bool operator!=(const vector<V, A> &left, const vector<V, A> &right);

    template <typename V, typename A>
    friend bool operator>(const vector<V, A> &left, const vector<V, A> &right);

    template <typename V, typename A>
    friend bool operator>=(const vector<V, A> &left, const vector<V, A> &right);

    template <typename V, typename A>
    friend bool operator<(const vector<V, A> &left, const vector<V, A> &right);

    template <typename V, typename A>
    friend bool operator<=(const vector<V, A> &left, const vector<V, A> &right);

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
    virtual ~vector();

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
    using Base::reserve;
    using Base::shrink_to_fit;

    // ELEMENT ACCESS
    using Base::operator[];
    using Base::at;
    using Base::front;
    using Base::back;
    using Base::data;

    // MODIFIERS
    using Base::assign;
    using Base::push_back;
    using Base::pop_back;
    using Base::insert;
    using Base::erase;
    using Base::clear;
    using Base::emplace;
    using Base::emplace_back;
    void swap(This &other);

    // ALLOCATORS
    using Base::get_allocator;
};


// IMPLEMENTATION
// --------------


template <typename T, typename Alloc>
auto vector<T, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Alloc>
auto vector<T, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Alloc>
auto vector<T, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Alloc>
auto vector<T, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Alloc>
void swap(vector<T, Alloc> &left,
    vector<T, Alloc> &right)
{
    left.swap(right);
}


template <typename T, typename Alloc>
bool operator==(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Alloc>
bool operator!=(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Alloc>
bool operator>(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Alloc>
bool operator>=(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Alloc>
bool operator<(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Alloc>
bool operator<=(const vector<T, Alloc> &left,
    const vector<T, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Alloc>
vector<T, Alloc>::~vector()
{}


template <typename T, typename Alloc>
void vector<T, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
