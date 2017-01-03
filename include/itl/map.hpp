/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <map>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL map.
 */
template <
    typename Key,
    typename Value,
    typename Compare = std::less<Key>,
    typename Alloc = std::allocator<std::pair<const Key,Value>>
>
class map: protected std::map<Key, Value, Compare, Alloc>
{
protected:
    typedef std::map<Key, Value, Compare, Alloc> Base;
    typedef map<Key, Value, Compare, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename V, typename C, typename A>
    friend void swap(map<K, V, C, A> &left, map<K, V, C, A> &right);

    // RELATIONAL OPERATORS
    template <typename K, typename V, typename C, typename A>
    friend bool operator==(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator!=(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator>(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator>=(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator<(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator<=(const map<K, V, C, A> &left, const map<K, V, C, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::mapped_type;
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
    virtual ~map();

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
    using Base::operator[];
    using Base::at;

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


/** \brief Inheritable STL multimap.
 */
template <
    typename Key,
    typename Value,
    typename Compare = std::less<Key>,
    typename Alloc = std::allocator<std::pair<const Key, Value>>
>
class multimap: protected std::multimap<Key, Value, Compare, Alloc>
{
protected:
    typedef std::multimap<Key, Value, Compare, Alloc> Base;
    typedef multimap<Key, Value, Compare, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename V, typename C, typename A>
    friend void swap(multimap<K, V, C, A> &left, multimap<K, V, C, A> &right);

    // RELATIONAL OPERATORS
    template <typename K, typename V, typename C, typename A>
    friend bool operator==(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator!=(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator>(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator>=(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator<(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

    template <typename K, typename V, typename C, typename A>
    friend bool operator<=(const multimap<K, V, C, A> &left, const multimap<K, V, C, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::mapped_type;
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
    virtual ~multimap();

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


template <typename Key, typename Value, typename Compare, typename Alloc>
auto map<Key, Value, Compare, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto map<Key, Value, Compare, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto map<Key, Value, Compare, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto map<Key, Value, Compare, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
void swap(map<Key, Value, Compare, Alloc> &left,
    map<Key, Value, Compare, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator==(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator!=(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator>(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator>=(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator<(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator<=(const map<Key, Value, Compare, Alloc> &left,
    const map<Key, Value, Compare, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
map<Key, Value, Compare, Alloc>::~map()
{}


template <typename Key, typename Value, typename Compare, typename Alloc>
void map<Key, Value, Compare, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto multimap<Key, Value, Compare, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto multimap<Key, Value, Compare, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto multimap<Key, Value, Compare, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
auto multimap<Key, Value, Compare, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
void swap(multimap<Key, Value, Compare, Alloc> &left,
    multimap<Key, Value, Compare, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator==(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() == right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator!=(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() != right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator>(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() > right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator>=(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() >= right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator<(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() < right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
bool operator<=(const multimap<Key, Value, Compare, Alloc> &left,
    const multimap<Key, Value, Compare, Alloc> &right)
{
    return left.ref() <= right.ref();
}


template <typename Key, typename Value, typename Compare, typename Alloc>
multimap<Key, Value, Compare, Alloc>::~multimap()
{}


template <typename Key, typename Value, typename Compare, typename Alloc>
void multimap<Key, Value, Compare, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
