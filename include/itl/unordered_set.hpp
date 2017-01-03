/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <unordered_set>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL unordered_set.
 */
template <
    typename Key,
    typename Hash = std::hash<Key>,
    typename Pred = std::equal_to<Key>,
    typename Alloc = std::allocator<Key>
>
class unordered_set: protected std::unordered_set<Key, Hash, Pred, Alloc>
{
protected:
    typedef std::unordered_set<Key, Hash, Pred, Alloc> Base;
    typedef unordered_set<Key, Hash, Pred, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename H, typename P, typename A>
    friend void swap(unordered_set<K, H, P, A> &left, unordered_set<K, H, P, A> &right);

    // RELATIONAL OPERATORS
    // --------------------
    template <typename K, typename H, typename P, typename A>
    friend bool operator==(const unordered_set<K, H, P, A> &left, const unordered_set<K, H, P, A> &right);

    template <typename K, typename H, typename P, typename A>
    friend bool operator!=(const unordered_set<K, H, P, A> &left, const unordered_set<K, H, P, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::hasher;
    using typename Base::key_equal;
    using typename Base::allocator_type;
    using typename Base::reference;
    using typename Base::const_reference;
    using typename Base::pointer;
    using typename Base::const_pointer;
    using typename Base::iterator;
    using typename Base::const_iterator;
    using typename Base::local_iterator;
    using typename Base::const_local_iterator;
    using typename Base::size_type;
    using typename Base::difference_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~unordered_set();

    // CAPACITY
    using Base::empty;
    using Base::size;
    using Base::max_size;

    // ITERATORS
    using Base::begin;
    using Base::end;
    using Base::cbegin;
    using Base::cend;

    // LOOKUP
    using Base::find;
    using Base::count;
    using Base::equal_range;

    // MODIFIERS
    using Base::emplace;
    using Base::emplace_hint;
    using Base::insert;
    using Base::erase;
    using Base::clear;
    void swap(This &other);

    // BUCKETS
    using Base::bucket_count;
    using Base::max_bucket_count;
    using Base::bucket_size;
    using Base::bucket;

    // HASH POLICY
    using Base::load_factor;
    using Base::max_load_factor;
    using Base::rehash;
    using Base::reserve;

    // OBSERVERS
    using Base::hash_function;
    using Base::key_eq;
    using Base::get_allocator;
};


/** \brief Inheritable STL unordered_multiset.
 */
template <
    typename Key,
    typename Hash = std::hash<Key>,
    typename Pred = std::equal_to<Key>,
    typename Alloc = std::allocator<Key>
>
class unordered_multiset: protected std::unordered_multiset<Key, Hash, Pred, Alloc>
{
protected:
    typedef std::unordered_multiset<Key, Hash, Pred, Alloc> Base;
    typedef unordered_multiset<Key, Hash, Pred, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename H, typename P, typename A>
    friend void swap(unordered_multiset<K, H, P, A> &left, unordered_multiset<K, H, P, A> &right);

    // RELATIONAL OPERATORS
    // --------------------
    template <typename K, typename H, typename P, typename A>
    friend bool operator==(const unordered_multiset<K, H, P, A> &left, const unordered_multiset<K, H, P, A> &right);

    template <typename K, typename H, typename P, typename A>
    friend bool operator!=(const unordered_multiset<K, H, P, A> &left, const unordered_multiset<K, H, P, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::hasher;
    using typename Base::key_equal;
    using typename Base::allocator_type;
    using typename Base::reference;
    using typename Base::const_reference;
    using typename Base::pointer;
    using typename Base::const_pointer;
    using typename Base::iterator;
    using typename Base::const_iterator;
    using typename Base::local_iterator;
    using typename Base::const_local_iterator;
    using typename Base::size_type;
    using typename Base::difference_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~unordered_multiset();

    // CAPACITY
    using Base::empty;
    using Base::size;
    using Base::max_size;

    // ITERATORS
    using Base::begin;
    using Base::end;
    using Base::cbegin;
    using Base::cend;

    // LOOKUP
    using Base::find;
    using Base::count;
    using Base::equal_range;

    // MODIFIERS
    using Base::emplace;
    using Base::emplace_hint;
    using Base::insert;
    using Base::erase;
    using Base::clear;
    void swap(This &other);

    // BUCKETS
    using Base::bucket_count;
    using Base::max_bucket_count;
    using Base::bucket_size;
    using Base::bucket;

    // HASH POLICY
    using Base::load_factor;
    using Base::max_load_factor;
    using Base::rehash;
    using Base::reserve;

    // OBSERVERS
    using Base::hash_function;
    using Base::key_eq;
    using Base::get_allocator;
};


// IMPLEMENTATION
// --------------


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_set<Key, Hash, Pred, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_set<Key, Hash, Pred, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_set<Key, Hash, Pred, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_set<Key, Hash, Pred, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
void swap(unordered_set<Key, Hash, Pred, Alloc> &left,
    unordered_set<Key, Hash, Pred, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_set<Key, Hash, Pred, Alloc> &left,
    const unordered_set<Key, Hash, Pred, Alloc> &right)
{
    return operator==(left.ref(), right.ref());
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
bool operator!=(const unordered_set<Key, Hash, Pred, Alloc> &left,
    const unordered_set<Key, Hash, Pred, Alloc> &right)
{
    return operator!=(left.ref(), right.ref());
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
unordered_set<Key, Hash, Pred, Alloc>::~unordered_set()
{}


template <typename Key, typename Hash, typename Pred, typename Alloc>
void unordered_set<Key, Hash, Pred, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_multiset<Key, Hash, Pred, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_multiset<Key, Hash, Pred, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_multiset<Key, Hash, Pred, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
auto unordered_multiset<Key, Hash, Pred, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
void swap(unordered_multiset<Key, Hash, Pred, Alloc> &left,
    unordered_multiset<Key, Hash, Pred, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_multiset<Key, Hash, Pred, Alloc> &left,
    const unordered_multiset<Key, Hash, Pred, Alloc> &right)
{
    return operator==(left.ref(), right.ref());
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
bool operator!=(const unordered_multiset<Key, Hash, Pred, Alloc> &left,
    const unordered_multiset<Key, Hash, Pred, Alloc> &right)
{
    return operator!=(left.ref(), right.ref());
}


template <typename Key, typename Hash, typename Pred, typename Alloc>
unordered_multiset<Key, Hash, Pred, Alloc>::~unordered_multiset()
{}


template <typename Key, typename Hash, typename Pred, typename Alloc>
void unordered_multiset<Key, Hash, Pred, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
