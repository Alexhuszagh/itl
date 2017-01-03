/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <set>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL set.
 */
template <
    typename T,
    typename Compare = std::less<T>,
    typename Alloc = std::allocator<T>
>
class set: protected std::set<T, Compare, Alloc>
{
protected:
    typedef std::set<T, Compare, Alloc> Base;
    typedef set<T, Compare, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename C, typename A>
    friend void swap(set<K, C, A> &left, set<K, C, A> &right);

    // RELATIONAL OPERATORS
    template <typename K, typename C, typename A>
    friend bool operator==(const set<K, C, A> &left, const set<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator!=(const set<K, C, A> &left, const set<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator>(const set<K, C, A> &left, const set<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator>=(const set<K, C, A> &left, const set<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator<(const set<K, C, A> &left, const set<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator<=(const set<K, C, A> &left, const set<K, C, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::key_compare;
    using typename Base::value_compare;
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
    virtual ~set();

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

    // MODIFIERS
    using Base::insert;
    using Base::erase;
    using Base::clear;
    using Base::emplace;
    using Base::emplace_hint;
    void swap(This &other);

    // OBSERVERS
    using Base::key_comp;
    using Base::value_comp;

    // OPERATIONS
    using Base::find;
    using Base::count;
    using Base::lower_bound;
    using Base::upper_bound;
    using Base::equal_range;

    // ALLOCATOR
    using Base::get_allocator;
};


/** \brief Inheritable STL multiset.
 */
template <
    typename T,
    typename Compare = std::less<T>,
    typename Alloc = std::allocator<T>
>
class multiset: protected std::multiset<T, Compare, Alloc>
{
protected:
    typedef std::multiset<T, Compare, Alloc> Base;
    typedef multiset<T, Compare, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename C, typename A>
    friend void swap(multiset<K, C, A> &left, multiset<K, C, A> &right);

    // RELATIONAL OPERATORS
    template <typename K, typename C, typename A>
    friend bool operator==(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator!=(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator>(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator>=(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator<(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

    template <typename K, typename C, typename A>
    friend bool operator<=(const multiset<K, C, A> &left, const multiset<K, C, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::key_compare;
    using typename Base::value_compare;
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
    virtual ~multiset();

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

    // MODIFIERS
    using Base::insert;
    using Base::erase;
    using Base::clear;
    using Base::emplace;
    using Base::emplace_hint;
    void swap(This &other);

    // OBSERVERS
    using Base::key_comp;
    using Base::value_comp;

    // OPERATIONS
    using Base::find;
    using Base::count;
    using Base::lower_bound;
    using Base::upper_bound;
    using Base::equal_range;

    // ALLOCATOR
    using Base::get_allocator;
};


// IMPLEMENTATION
// --------------


template <typename Key, typename Compare, typename Alloc>
auto set<Key, Compare, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto set<Key, Compare, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto set<Key, Compare, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto set<Key, Compare, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
void swap(set<Key, Compare, Alloc> &left,
    set<Key, Compare, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Compare, typename Alloc>
bool operator==(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator!=(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator>(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator>=(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator<(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator<=(const set<Key, Compare, Alloc> &left,
    const set<Key, Compare, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename Key, typename Compare, typename Alloc>
set<Key, Compare, Alloc>::~set()
{}


template <typename Key, typename Compare, typename Alloc>
void set<Key, Compare, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}


template <typename Key, typename Compare, typename Alloc>
auto multiset<Key, Compare, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto multiset<Key, Compare, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto multiset<Key, Compare, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
auto multiset<Key, Compare, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Compare, typename Alloc>
void swap(multiset<Key, Compare, Alloc> &left,
    multiset<Key, Compare, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Compare, typename Alloc>
bool operator==(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator!=(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator>(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator>=(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator<(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename Key, typename Compare, typename Alloc>
bool operator<=(const multiset<Key, Compare, Alloc> &left,
    const multiset<Key, Compare, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename Key, typename Compare, typename Alloc>
multiset<Key, Compare, Alloc>::~multiset()
{}


template <typename Key, typename Compare, typename Alloc>
void multiset<Key, Compare, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
