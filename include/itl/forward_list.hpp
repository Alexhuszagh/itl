/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <forward_list>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL forward_list.
 */
template <
    typename T,
    typename Alloc = std::allocator<T>
>
class forward_list: protected std::forward_list<T, Alloc>
{
protected:
    typedef std::forward_list<T, Alloc> Base;
    typedef forward_list<T, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename A>
    friend void swap(forward_list<V, A> &left, forward_list<V, A> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename A>
    friend bool operator==(const forward_list<V, A> &left, const forward_list<V, A> &right);

    template <typename V, typename A>
    friend bool operator!=(const forward_list<V, A> &left, const forward_list<V, A> &right);

    template <typename V, typename A>
    friend bool operator>(const forward_list<V, A> &left, const forward_list<V, A> &right);

    template <typename V, typename A>
    friend bool operator>=(const forward_list<V, A> &left, const forward_list<V, A> &right);

    template <typename V, typename A>
    friend bool operator<(const forward_list<V, A> &left, const forward_list<V, A> &right);

    template <typename V, typename A>
    friend bool operator<=(const forward_list<V, A> &left, const forward_list<V, A> &right);

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
    using typename Base::difference_type;
    using typename Base::size_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~forward_list();

    // ITERATORS
    using Base::before_begin;
    using Base::begin;
    using Base::end;
    using Base::cbefore_begin;
    using Base::cbegin;
    using Base::cend;

    // CAPACITY
    using Base::empty;
    using Base::max_size;

    // ELEMENT ACCESS
    using Base::front;

    // MODIFIERS
    using Base::assign;
    using Base::emplace_front;
    using Base::push_front;
    using Base::pop_front;
    using Base::emplace_after;
    using Base::insert_after;
    using Base::erase_after;
    using Base::resize;
    using Base::clear;
    void swap(This &other);

    // OPERATIONS
    using Base::remove;
    using Base::remove_if;
    using Base::unique;
    using Base::sort;
    using Base::reverse;
    void splice_after(const_iterator position, This &x);
    void splice_after(const_iterator position, This &&x);
    void splice_after(const_iterator position, This &x, const_iterator i);
    void splice_after(const_iterator position, This &&x, const_iterator i);
    void splice_after(const_iterator position, This &x, const_iterator first, const_iterator last);
    void splice_after(const_iterator position, This &&x, const_iterator first, const_iterator last);
    void merge(This &x);
    void merge(This &&x);

    template <typename Compare>
    void merge(This &x, Compare comp);

    template <typename Compare>
    void merge(This &&x, Compare comp);

    // OBSERVERS
    using Base::get_allocator;
};


// IMPLEMENTATION
// --------------


template <typename T, typename Alloc>
auto forward_list<T, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Alloc>
auto forward_list<T, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Alloc>
auto forward_list<T, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Alloc>
auto forward_list<T, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Alloc>
void swap(forward_list<T, Alloc> &left,
    forward_list<T, Alloc> &right)
{
    left.swap(right);
}


template <typename T, typename Alloc>
bool operator==(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Alloc>
bool operator!=(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Alloc>
bool operator>(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Alloc>
bool operator>=(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Alloc>
bool operator<(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Alloc>
bool operator<=(const forward_list<T, Alloc> &left,
    const forward_list<T, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Alloc>
forward_list<T, Alloc>::~forward_list()
{}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &x)
{
    ref().splice_after(position, x.ref());
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &&x)
{
    ref().splice_after(position, x.forward());
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &x, const_iterator i)
{
    ref().splice_after(position, x.ref(), i);
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &&x, const_iterator i)
{
    ref().splice_after(position, x.forward(), i);
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &x, const_iterator first, const_iterator last)
{
    ref().splice_after(position, x.ref(), first, last);
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::splice_after(const_iterator position, This &&x, const_iterator first, const_iterator last)
{
    ref().splice_after(position, x.forward(), first, last);
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::merge(This &x)
{
    ref().merge(x.ref());
}

template <typename T, typename Alloc>
void forward_list<T, Alloc>::merge(This &&x)
{
    ref().merge(x.forward());
}


template <typename T, typename Alloc>
template <typename Compare>
void forward_list<T, Alloc>::merge(This &x, Compare comp)
{
    ref().merge(x.ref(), comp);
}

template <typename T, typename Alloc>
template <typename Compare>
void forward_list<T, Alloc>::merge(This &&x, Compare comp)
{
    ref().merge(x.forward(), comp);
}


template <typename T, typename Alloc>
void forward_list<T, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
