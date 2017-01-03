/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <list>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL list.
 */
template <
    typename T,
    typename Alloc = std::allocator<T>
>
class list: protected std::list<T, Alloc>
{
protected:
    typedef std::list<T, Alloc> Base;
    typedef list<T, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename V, typename A>
    friend void swap(list<V, A> &left, list<V, A> &right);

    // RELATIONAL OPERATORS
    template <typename V, typename A>
    friend bool operator==(const list<V, A> &left, const list<V, A> &right);

    template <typename V, typename A>
    friend bool operator!=(const list<V, A> &left, const list<V, A> &right);

    template <typename V, typename A>
    friend bool operator>(const list<V, A> &left, const list<V, A> &right);

    template <typename V, typename A>
    friend bool operator>=(const list<V, A> &left, const list<V, A> &right);

    template <typename V, typename A>
    friend bool operator<(const list<V, A> &left, const list<V, A> &right);

    template <typename V, typename A>
    friend bool operator<=(const list<V, A> &left, const list<V, A> &right);

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
    virtual ~list();

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
    using Base::empty;
    using Base::size;
    using Base::max_size;

    // ELEMENT ACCESS
    using Base::front;
    using Base::back;

    // MODIFIERS
    using Base::assign;
    using Base::emplace_front;
    using Base::push_front;
    using Base::pop_front;
    using Base::emplace_back;
    using Base::push_back;
    using Base::pop_back;
    using Base::emplace;
    using Base::insert;
    using Base::erase;
    using Base::resize;
    using Base::clear;
    void swap(This &other);

    // OPERATIONS
    using Base::remove;
    using Base::remove_if;
    using Base::unique;
    using Base::sort;
    using Base::reverse;
    void splice(const_iterator position, This &x);
    void splice(const_iterator position, This &&x);
    void splice(const_iterator position, This &x, const_iterator i);
    void splice(const_iterator position, This &&x, const_iterator i);
    void splice(const_iterator position, This &x, const_iterator first, const_iterator last);
    void splice(const_iterator position, This &&x, const_iterator first, const_iterator last);
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
auto list<T, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T, typename Alloc>
auto list<T, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T, typename Alloc>
auto list<T, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T, typename Alloc>
auto list<T, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T, typename Alloc>
void swap(list<T, Alloc> &left,
    list<T, Alloc> &right)
{
    left.swap(right);
}


template <typename T, typename Alloc>
bool operator==(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename T, typename Alloc>
bool operator!=(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename T, typename Alloc>
bool operator>(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename T, typename Alloc>
bool operator>=(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename T, typename Alloc>
bool operator<(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename T, typename Alloc>
bool operator<=(const list<T, Alloc> &left,
    const list<T, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename T, typename Alloc>
list<T, Alloc>::~list()
{}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &x)
{
    ref().splice(position, x.ref());
}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &&x)
{
    ref().splice(position, x.forward());
}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &x, const_iterator i)
{
    ref().splice(position, x.ref(), i);
}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &&x, const_iterator i)
{
    ref().splice(position, x.forward(), i);
}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &x, const_iterator first, const_iterator last)
{
    ref().splice(position, x.ref(), first, last);
}


template <typename T, typename Alloc>
void list<T, Alloc>::splice(const_iterator position, This &&x, const_iterator first, const_iterator last)
{
    ref().splice(position, x.forward(), first, last);
}


template <typename T, typename Alloc>
void list<T, Alloc>::merge(This &x)
{
    ref().merge(x.ref());
}

template <typename T, typename Alloc>
void list<T, Alloc>::merge(This &&x)
{
    ref().merge(x.forward());
}


template <typename T, typename Alloc>
template <typename Compare>
void list<T, Alloc>::merge(This &x, Compare comp)
{
    ref().merge(x.ref(), comp);
}

template <typename T, typename Alloc>
template <typename Compare>
void list<T, Alloc>::merge(This &&x, Compare comp)
{
    ref().merge(x.forward(), comp);
}


template <typename T, typename Alloc>
void list<T, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
