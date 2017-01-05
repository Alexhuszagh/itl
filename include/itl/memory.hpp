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
// FORWARD
// -------

template <typename T>
class shared_ptr;

template <typename T>
class weak_ptr;

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

    template <typename U>
    friend class weak_ptr;

    template <typename U>
    friend class shared_ptr;

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
    constexpr shared_ptr() noexcept;
    constexpr shared_ptr(std::nullptr_t nullp) noexcept;
    virtual ~shared_ptr();

    shared_ptr(const Base &other);
    shared_ptr(Base &&other);
    shared_ptr(const This &other);
    shared_ptr(This &&other);

    template <typename U>
    shared_ptr(U *u);

    template <typename U, typename Deleter>
    shared_ptr(U *u, Deleter d);

    template <typename Deleter>
    shared_ptr(std::nullptr_t nullp, Deleter d);

    template <typename U, typename Deleter, typename Alloc>
    shared_ptr(U *u, Deleter d, Alloc alloc);

    template <typename Deleter, typename Alloc>
    shared_ptr(std::nullptr_t nullp, Deleter d, Alloc alloc);

    template <typename U>
    shared_ptr(const shared_ptr<U> &other, element_type *ptr);

    template <typename U>
    shared_ptr(const shared_ptr<U> &other);

    template <typename U>
    shared_ptr(shared_ptr<U> &&other);

    template <typename U>
    shared_ptr(const std::weak_ptr<U> &other);

    template <typename U>
    shared_ptr(const weak_ptr<U> &other);

    template <typename U, typename Deleter>
    shared_ptr(std::unique_ptr<U, Deleter> &&other);

    This & operator=(const Base &other);
    This & operator=(Base &&other);

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


/** \brief Inheritable weak_ptr
 */
template <typename T>
class weak_ptr: protected std::weak_ptr<T>
{
protected:
    typedef std::weak_ptr<T> Base;
    typedef weak_ptr<T> This;

    template <typename U>
    friend class weak_ptr;

    template <typename U>
    friend class shared_ptr;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename U>
    friend void swap(weak_ptr<U> &left, weak_ptr<U> &right);

public:
    constexpr weak_ptr() noexcept;
    ~weak_ptr();

    weak_ptr(const This &other);
    weak_ptr(This &&other);

    template <typename U>
    weak_ptr(const shared_ptr<U> &other) noexcept;

    template <typename U>
    weak_ptr(const weak_ptr<U> &other);

    template <typename U>
    weak_ptr(weak_ptr<U> &&other);

    This & operator=(const This &other);
    This & operator=(This &&other);

    template <typename U>
    This & operator=(const shared_ptr<U> &other) noexcept;

    template <typename U>
    This & operator=(const weak_ptr<U> &other);

    template <typename U>
    This & operator=(weak_ptr<U> &&other);

    // MODIFIERS
    using Base::reset;
    void swap(This &other);

    // OBSERVERS
    using Base::use_count;
    using Base::expired;
    using Base::lock;
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
    return shared_ptr<T>(r, p);
}


template <typename T, typename U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U> &r) noexcept
{
    if (auto p = dynamic_cast<typename shared_ptr<T>::element_type*>(r.get())) {
        return shared_ptr<T>(r, p);
    } else {
        return shared_ptr<T>();
    }
}


template <typename T, typename U>
shared_ptr<T> const_pointer_cast(const shared_ptr<U> &r) noexcept
{
    auto p = const_cast<typename shared_ptr<T>::element_type*>(r.get());
    return shared_ptr<T>(r, p);
}


template <typename T, typename U>
shared_ptr<T> reinterpret_pointer_cast(const shared_ptr<U> &r) noexcept
{
    auto p = reinterpret_cast<typename shared_ptr<T>::element_type*>(r.get());
    return shared_ptr<T>(r, p);
}


template <typename T>
constexpr shared_ptr<T>::shared_ptr() noexcept
{}

template <typename T>
constexpr shared_ptr<T>::shared_ptr(std::nullptr_t nullp) noexcept
{}


template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(U *u):
    Base(u)
{}


template <typename T>
template <typename U, typename Deleter>
shared_ptr<T>::shared_ptr(U *u,
        Deleter d):
    Base(u, d)
{}


template <typename T>
template <typename Deleter>
shared_ptr<T>::shared_ptr(std::nullptr_t nullp,
        Deleter d):
    Base(nullp, d)
{}


template <typename T>
template <typename U, typename Deleter, typename Alloc>
shared_ptr<T>::shared_ptr(U *u,
        Deleter d,
        Alloc alloc):
    Base(u, d, alloc)
{}


template <typename T>
template <typename Deleter, typename Alloc>
shared_ptr<T>::shared_ptr(std::nullptr_t nullp,
        Deleter d,
        Alloc alloc):
    Base(nullp, d, alloc)
{}


template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(const shared_ptr<U> &other,
        element_type *ptr):
    Base(other.ref(), ptr)
{}

template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(const shared_ptr<U> &other):
    Base(other.ref())
{}

template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(shared_ptr<U> &&other):
    Base(other.forward())
{}


template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(const std::weak_ptr<U> &other):
    Base(other)
{}

template <typename T>
template <typename U>
shared_ptr<T>::shared_ptr(const weak_ptr<U> &other):
    Base(other.ref())
{}

template <typename T>
template <typename U, typename Deleter>
shared_ptr<T>::shared_ptr(std::unique_ptr<U, Deleter> &&other):
    Base(std::move(other))
{}


template <typename T>
shared_ptr<T>::shared_ptr(const Base &other):
    Base(other)
{}


template <typename T>
shared_ptr<T>::shared_ptr(const This &other):
    Base(other.ref())
{}


template <typename T>
shared_ptr<T>::shared_ptr(Base &&other):
    Base(std::move(other))
{}


template <typename T>
shared_ptr<T>::shared_ptr(This &&other):
    Base(other.forward())
{}


template <typename T>
auto shared_ptr<T>::operator=(const Base &other)
    -> This &
{
    Base::operator=(other);
    return *this;
}


template <typename T>
auto shared_ptr<T>::operator=(Base &&other)
    -> This &
{
    Base::operator=(std::move(other));
    return *this;
}


template <typename T>
shared_ptr<T>::~shared_ptr()
{}


template <typename T>
void shared_ptr<T>::swap(This &other)
{
    ref().swap(other.ref());
}


template <typename T>
auto weak_ptr<T>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename T>
auto weak_ptr<T>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename T>
auto weak_ptr<T>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename T>
auto weak_ptr<T>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename T>
void swap(weak_ptr<T> &left, weak_ptr<T> &right)
{
    left.swap(right);
}


template <typename T>
constexpr weak_ptr<T>::weak_ptr() noexcept
{}


template <typename T>
weak_ptr<T>::~weak_ptr()
{}


template <typename T>
weak_ptr<T>::weak_ptr(const This &other):
    Base(other.ref())
{}


template <typename T>
template <typename U>
weak_ptr<T>::weak_ptr(const shared_ptr<U> &other) noexcept :
    Base(other.ref())
{}


template <typename T>
weak_ptr<T>::weak_ptr(This &&other):
    Base(other.forward())
{}


template <typename T>
template <typename U>
weak_ptr<T>::weak_ptr(const weak_ptr<U> &other):
    Base(other.ref())
{}


template <typename T>
template <typename U>
weak_ptr<T>::weak_ptr(weak_ptr<U> &&other):
    Base(other.forward())
{}


template <typename T>
auto weak_ptr<T>::operator=(const This &other)
    -> This &
{
    Base::operator=(other.ref());
    return *this;
}


template <typename T>
auto weak_ptr<T>::operator=(This &&other)
    -> This &
{
    Base::operator=(other.forward());
    return *this;
}


template <typename T>
template <typename U>
auto weak_ptr<T>::operator=(const shared_ptr<U> &other) noexcept
    -> This &
{
    Base::operator=(other.ref());
    return *this;
}


template <typename T>
template <typename U>
auto weak_ptr<T>::operator=(const weak_ptr<U> &other)
    -> This &
{
    Base::operator=(other.ref());
    return *this;
}


template <typename T>
template <typename U>
auto weak_ptr<T>::operator=(weak_ptr<U> &&other)
    -> This &
{
    Base::operator=(other.forward());
    return *this;
}


template <typename T>
void weak_ptr<T>::swap(This &other)
{
    Base::swap(other.ref());
}


// FUNCTIONS
// ---------


template <typename T, typename... Ts>
shared_ptr<T> make_shared(Ts&&... ts)
{
    return shared_ptr<T>(std::make_shared<T>(std::forward<Ts>(ts)...));
}


template <typename T, typename Alloc, typename... Ts>
shared_ptr<T> allocate_shared(const Alloc& alloc,
    Ts&&... ts)
{
    return shared_ptr<T>(std::allocate_shared<T, Alloc>(alloc, std::forward<Ts>(ts)...));
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
