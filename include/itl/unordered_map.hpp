/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <unordered_map>


namespace itl
{
// DECLARATION
// -----------


template <
    typename Key,
    typename Value,
    typename Hash = std::hash<Key>,
    typename Pred = std::equal_to<Key>,
    typename Alloc = std::allocator<std::pair<const Key, Value>>
>
/** \brief Inheritable STL unordered_map.
 */
class unordered_map: protected std::unordered_map<Key, Value, Hash, Pred, Alloc>
{
protected:
    typedef std::unordered_map<Key, Value, Hash, Pred, Alloc> Base;
    typedef unordered_map<Key, Value, Hash, Pred, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename V, typename H, typename P, typename A>
    friend void swap(unordered_map<K, V, H, P, A> &left, unordered_map<K, V, H, P, A> &right);

    // RELATIONAL OPERATORS
    // --------------------
    template <typename K, typename V, typename H, typename P, typename A>
    friend bool operator==(const unordered_map<K, V, H, P, A> &left, const unordered_map<K, V, H, P, A> &right);

    template <typename K, typename V, typename H, typename P, typename A>
    friend bool operator!=(const unordered_map<K, V, H, P, A> &left, const unordered_map<K, V, H, P, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::mapped_type;
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
    virtual ~unordered_map();

    // CAPACITY
    using Base::empty;
    using Base::size;
    using Base::max_size;

    // ITERATORS
    using Base::begin;
    using Base::end;
    using Base::cbegin;
    using Base::cend;

    // ELEMENT ACCESS
    using Base::operator[];
    using Base::at;

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


template <
    typename Key,
    typename Value,
    typename Hash = std::hash<Key>,
    typename Pred = std::equal_to<Key>,
    typename Alloc = std::allocator<std::pair<const Key, Value>>
>
/** \brief Inheritable STL unordered_multimap.
 */
class unordered_multimap: protected std::unordered_multimap<Key, Value, Hash, Pred, Alloc>
{
protected:
    typedef std::unordered_multimap<Key, Value, Hash, Pred, Alloc> Base;
    typedef unordered_multimap<Key, Value, Hash, Pred, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename K, typename V, typename H, typename P, typename A>
    friend void swap(unordered_multimap<K, V, H, P, A> &left, unordered_multimap<K, V, H, P, A> &right);

    // RELATIONAL OPERATORS
    // --------------------
    template <typename K, typename V, typename H, typename P, typename A>
    friend bool operator==(const unordered_multimap<K, V, H, P, A> &left, const unordered_multimap<K, V, H, P, A> &right);

    template <typename K, typename V, typename H, typename P, typename A>
    friend bool operator!=(const unordered_multimap<K, V, H, P, A> &left, const unordered_multimap<K, V, H, P, A> &right);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::key_type;
    using typename Base::value_type;
    using typename Base::mapped_type;
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
    virtual ~unordered_multimap();

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


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_map<Key, Value, Hash, Pred, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_map<Key, Value, Hash, Pred, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_map<Key, Value, Hash, Pred, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_map<Key, Value, Hash, Pred, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
void swap(unordered_map<Key, Value, Hash, Pred, Alloc> &left,
    unordered_map<Key, Value, Hash, Pred, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_map<Key, Value, Hash, Pred, Alloc> &left,
    const unordered_map<Key, Value, Hash, Pred, Alloc> &right)
{
    return operator==(left.ref(), right.ref());
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
bool operator!=(const unordered_map<Key, Value, Hash, Pred, Alloc> &left,
    const unordered_map<Key, Value, Hash, Pred, Alloc> &right)
{
    return operator!=(left.ref(), right.ref());
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
unordered_map<Key, Value, Hash, Pred, Alloc>::~unordered_map()
{}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
void unordered_map<Key, Value, Hash, Pred, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_multimap<Key, Value, Hash, Pred, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_multimap<Key, Value, Hash, Pred, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_multimap<Key, Value, Hash, Pred, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
auto unordered_multimap<Key, Value, Hash, Pred, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
void swap(unordered_multimap<Key, Value, Hash, Pred, Alloc> &left,
    unordered_multimap<Key, Value, Hash, Pred, Alloc> &right)
{
    left.swap(right);
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
bool operator==(const unordered_multimap<Key, Value, Hash, Pred, Alloc> &left,
    const unordered_multimap<Key, Value, Hash, Pred, Alloc> &right)
{
    return operator==(left.ref(), right.ref());
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
bool operator!=(const unordered_multimap<Key, Value, Hash, Pred, Alloc> &left,
    const unordered_multimap<Key, Value, Hash, Pred, Alloc> &right)
{
    return operator!=(left.ref(), right.ref());
}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
unordered_multimap<Key, Value, Hash, Pred, Alloc>::~unordered_multimap()
{}


template <typename Key, typename Value, typename Hash, typename Pred, typename Alloc>
void unordered_multimap<Key, Value, Hash, Pred, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */
