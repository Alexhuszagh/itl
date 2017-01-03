/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <memory>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable shared_ptr.
 */
template <typename T>
class shared_ptr: protected std::shared_ptr<T>
{
protected:
    typedef std::shared_ptr<T> Base;
    typedef shared_ptr<T> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename U>
    friend void swap(shared_ptr<U> &left, shared_ptr<U> &right);

    template <typename Deleter, typename U>
    friend Deleter * get_deleter(const shared_ptr<U> &p);

    template <typename U, typename V, typename W>
    friend std::basic_ostream<V, W> & operator<<(std::basic_ostream<V, W> &stream, const shared_ptr<U> &ptr);

    // RELATIONAL OPERATORS
    template <typename U, typename V>
    friend bool operator==(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U, typename V>
    friend bool operator!=(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U, typename V>
    friend bool operator<(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U, typename V>
    friend bool operator>(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U, typename V>
    friend bool operator<=(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U, typename V>
    friend bool operator>=(const shared_ptr<U> &left, const shared_ptr<V> &right);

    template <typename U>
    friend bool operator==(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator==(std::nullptr_t left, const shared_ptr<U> &right);

    template <typename U>
    friend bool operator!=(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator!=(std::nullptr_t left, const shared_ptr<U> &right);

    template <typename U>
    friend bool operator<(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator<(std::nullptr_t left, const shared_ptr<U> &right);

    template <typename U>
    friend bool operator>(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator>(std::nullptr_t left, const shared_ptr<U> &right);

    template <typename U>
    friend bool operator<=(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator<=(std::nullptr_t left, const shared_ptr<U> &right);

    template <typename U>
    friend bool operator>=(const shared_ptr<U> &left, std::nullptr_t right);

    template <typename U>
    friend bool operator>=(std::nullptr_t left, const shared_ptr<U> &right);

    // ATOMIC OPERATIONS
    template <typename U>
    friend bool atomic_is_lock_free(const shared_ptr<U> *p);

    template <typename U>
    friend void atomic_store(shared_ptr<U> *p, shared_ptr<U> r);

    template <typename U>
    friend void atomic_store_explicit(shared_ptr<U> *p, shared_ptr<U> r, std::memory_order mo);

    template <typename U>
    friend bool atomic_compare_exchange_weak(shared_ptr<U> *p, shared_ptr<U> *expected, shared_ptr<U> desired);

    template <typename U>
    friend bool atomic_compare_exchange_strong(shared_ptr<U> *p, shared_ptr<U> *expected, shared_ptr<U> desired);

    template <typename U>
    friend bool atomic_compare_exchange_strong_explicit(shared_ptr<U> *p, shared_ptr<U> *expected, shared_ptr<U> desired, std::memory_order success, std::memory_order failure);

    template <typename U>
    friend bool atomic_compare_exchange_weak_explicit(shared_ptr<U> *p, shared_ptr<U> *expected, shared_ptr<U> desired, std::memory_order success, std::memory_order failure);

    // CASTS
    template <typename U, typename V>
    friend shared_ptr<U> static_pointer_cast(const shared_ptr<V> &r) noexcept;

    template <typename U, typename V>
    friend shared_ptr<U> dynamic_pointer_cast(const shared_ptr<V> &r) noexcept;

    template <typename U, typename V>
    friend shared_ptr<U> const_pointer_cast(const shared_ptr<V> &r) noexcept;

    template <typename U, typename V>
    friend shared_ptr<U> reinterpret_pointer_cast(const shared_ptr<V> &r) noexcept;

public:
    // MEMBER TYPES
    // ------------
    using typename Base::element_type;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~shared_ptr();

    // MODIFIERS
    using Base::reset;
    void swap(This &other);

    // OBSERVERS
    using Base::get;
    using Base::operator*;
    using Base::operator->;
    using Base::use_count;
    using Base::unique;
    using Base::operator bool;
    using Base::owner_before;
};


// IMPLEMENTATION
// --------------


template <typename T>
auto shared_ptr<T>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T>
auto shared_ptr<T>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T>
auto shared_ptr<T>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T>
auto shared_ptr<T>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T>
void swap(shared_ptr<T> &left, shared_ptr<T> &right)
{
    left.swap(right);
}


template <typename Deleter, typename T>
Deleter * get_deleter(const shared_ptr<T> &p)
{
    return get_deleter<Deleter, T>(p.ref());
}


template <typename U, typename V, typename W>
std::basic_ostream<V, W> & operator<<(std::basic_ostream<V, W> &stream,
    const shared_ptr<U> &ptr)
{
    return operator<<(stream, ptr.ref());
}


template <typename T, typename U>
bool operator==(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator==(left.ref(), right.ref());
}


template <typename T, typename U>
bool operator!=(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator!=(left.ref(), right.ref());
}


template <typename T, typename U>
bool operator<(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator<(left.ref(), right.ref());
}


template <typename T, typename U>
bool operator>(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator>(left.ref(), right.ref());
}


template <typename T, typename U>
bool operator<=(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator<=(left.ref(), right.ref());
}


template <typename T, typename U>
bool operator>=(const shared_ptr<T> &left, const shared_ptr<U> &right)
{
    return operator>=(left.ref(), right.ref());
}


template <typename T>
bool operator==(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator==(left.ref(), right);
}


template <typename T>
bool operator==(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator==(left, right.ref());
}


template <typename T>
bool operator!=(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator!=(left.ref(), right);
}


template <typename T>
bool operator!=(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator!=(left, right.ref());
}


template <typename T>
bool operator<(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator<(left.ref(), right);
}


template <typename T>
bool operator<(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator<(left, right.ref());
}


template <typename T>
bool operator>(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator>(left.ref(), right);
}


template <typename T>
bool operator>(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator>(left, right.ref());
}


template <typename T>
bool operator<=(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator<=(left.ref(), right);
}


template <typename T>
bool operator<=(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator<=(left, right.ref());
}


template <typename T>
bool operator>=(const shared_ptr<T> &left, std::nullptr_t right)
{
    return operator>=(left.ref(), right);
}


template <typename T>
bool operator>=(std::nullptr_t left, const shared_ptr<T> &right)
{
    return operator>=(left, right.ref());
}


template <typename T>
bool atomic_is_lock_free(const shared_ptr<T> *p)
{
    return std::atomic_is_lock_free(&p->ref());
}


template <typename T>
void atomic_store(shared_ptr<T> *p, shared_ptr<T> r)
{
    std::atomic_store(&p->ref(), r.ref());
}


template <typename T>
void atomic_store_explicit(shared_ptr<T> *p,
    shared_ptr<T> r,
    std::memory_order mo)
{
    std::atomic_store_explicit(&p->ref(), r.ref(), mo);
}


template <typename T>
bool atomic_compare_exchange_weak(shared_ptr<T> *p,
    shared_ptr<T> *expected,
    shared_ptr<T> desired)
{
    return std::atomic_compare_exchange_weak(&p->ref(), &expected->ref(), desired.ref());
}


template <typename T>
bool atomic_compare_exchange_strong(shared_ptr<T> *p,
    shared_ptr<T> *expected,
    shared_ptr<T> desired)
{
    return std::atomic_compare_exchange_strong(&p->ref(), &expected->ref(), desired.ref());
}


template <typename T>
bool atomic_compare_exchange_strong_explicit(shared_ptr<T> *p,
    shared_ptr<T> *expected,
    shared_ptr<T> desired,
    std::memory_order success,
    std::memory_order failure)
{
    return std::atomic_compare_exchange_strong_explicit(&p->ref(), &expected->ref(), desired.ref(), success, failure);
}


template <typename T>
bool atomic_compare_exchange_weak_explicit(shared_ptr<T> *p,
    shared_ptr<T> *expected,
    shared_ptr<T> desired,
    std::memory_order success,
    std::memory_order failure)
{
    return std::atomic_compare_exchange_weak_explicit(&p->ref(), &expected->ref(), desired.ref(), success, failure);
}


template <typename T, typename U>
shared_ptr<T> static_pointer_cast(const shared_ptr<U> &r) noexcept
{
    auto p = static_cast<typename shared_ptr<T>::element_type*>(r.get());
    return shared_ptr<T>(r.ref(), p);
}


template <typename T, typename U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U> &r) noexcept
{
    if (auto p = dynamic_cast<typename shared_ptr<T>::element_type*>(r.get())) {
        return shared_ptr<T>(r.ref(), p);
    } else {
        return shared_ptr<T>();
    }
}


template <typename T, typename U>
shared_ptr<T> const_pointer_cast(const shared_ptr<U> &r) noexcept
{
    auto p = const_cast<typename shared_ptr<T>::element_type*>(r.get());
    return shared_ptr<T>(r.ref(), p);
}


template <typename T, typename U>
shared_ptr<T> reinterpret_pointer_cast(const shared_ptr<U> &r) noexcept
{
    auto p = reinterpret_cast<typename shared_ptr<T>::element_type*>(r.get());
    return shared_ptr<T>(r.ref(), p);
}


template <typename T>
shared_ptr<T>::~shared_ptr()
{}


template <typename T>
void shared_ptr<T>::swap(This &other)
{
    ref().swap(other.ref());
}

}   /* itl */


namespace std
{
// SPECIALIZATION
// --------------


template <typename T>
struct hash<itl::shared_ptr<T>>
{
    size_t operator()(const itl::shared_ptr<T> &x) const
    {
        return hash<std::shared_ptr<T>>(x.ref());
    }
};

}   /* std */
