/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#pragma once

#include <string>


namespace itl
{
// DECLARATION
// -----------


/** \brief Inheritable STL string.
 */
template <
    typename Char,
    typename Traits = std::char_traits<Char>,
    typename Alloc = std::allocator<Char>
>
class basic_string: protected std::basic_string<Char, Traits, Alloc>
{
protected:
    typedef std::basic_string<Char, Traits, Alloc> Base;
    typedef basic_string<Char, Traits, Alloc> This;

    const Base & ref() const;
    Base & ref();
    const Base && forward() const;
    Base && forward();

    // NON-MEMBER FUNCTIONS
    // --------------------
    template <typename C, typename T, typename A>
    friend void swap(basic_string<C, T, A> &left, basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend std::basic_istream<C, T> & operator>>(std::basic_istream<C, T> &stream,
        basic_string<C, T, A> &str);

    template <typename C, typename T, typename A>
    friend std::basic_ostream<C, T> & operator<<(std::basic_ostream<C, T> &stream,
        basic_string<C, T, A> &str);

    // OPERATOR+
    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const basic_string<C, T, A> &left, const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(basic_string<C, T, A> &&left,
        basic_string<C, T, A> &&right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(basic_string<C, T, A> &&left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const basic_string<C, T, A> &left,
        basic_string<C, T, A> &&right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(basic_string<C, T, A> &&left,
        const C *right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const C *left,
        basic_string<C, T, A> &&right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(const basic_string<C, T, A> &left,
        C right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(basic_string<C, T, A> &&left,
        C right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(C left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend basic_string<C, T, A> operator+(C left,
        basic_string<C, T, A> &&right);

    // RELATIONAL OPERATORS
    template <typename C, typename T, typename A>
    friend bool operator==(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator==(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator==(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend bool operator!=(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator!=(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator!=(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend bool operator<(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator<(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator<(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend bool operator<=(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator<=(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator<=(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend bool operator>(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator>(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator>(const basic_string<C, T, A> &left,
        const C *right);

    template <typename C, typename T, typename A>
    friend bool operator>=(const basic_string<C, T, A> &left,
        const basic_string<C, T, A> &right) noexcept;

    template <typename C, typename T, typename A>
    friend bool operator>=(const C *left,
        const basic_string<C, T, A> &right);

    template <typename C, typename T, typename A>
    friend bool operator>=(const basic_string<C, T, A> &left,
        const C *right);

    // GETLINE
    template <typename C, typename T, typename A>
    friend std::basic_istream<C, T> & getline(std::basic_istream<C, T> &stream,
        basic_string<C, T, A> &str,
        C delim);

    template <typename C, typename T, typename A>
    friend std::basic_istream<C, T> & getline(std::basic_istream<C, T> &&stream,
        basic_string<C, T, A> &str,
        C delim);

    template <typename C, typename T, typename A>
    friend std::basic_istream<C, T> & getline(std::basic_istream<C, T> &stream,
        basic_string<C, T, A> &str);

    template <typename C, typename T, typename A>
    friend std::basic_istream<C, T> & getline(std::basic_istream<C, T> &&stream,
        basic_string<C, T, A> &str);

public:
    // MEMBER TYPES
    // ------------
    using typename Base::traits_type;
    using typename Base::allocator_type;
    using typename Base::value_type;
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

    // MEMBER VARIABLES
    // ----------------
    static const size_type npos = Base::npos;

    // MEMBER FUNCTIONS
    // ----------------
    using Base::Base;
    virtual ~basic_string();

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
    using Base::length;
    using Base::max_size;
    using Base::resize;
    using Base::capacity;
    using Base::reserve;
    using Base::clear;
    using Base::empty;
    using Base::shrink_to_fit;

    // ELEMENT ACCESS
    using Base::operator[];
    using Base::at;
    using Base::front;
    using Base::back;

    // MODIFIERS
    using Base::operator+=;
    using Base::append;
    using Base::push_back;
    using Base::assign;
    using Base::insert;
    using Base::erase;
    using Base::replace;
    using Base::pop_back;
    void swap(This &other);

    // STRING OPERATIONS
    using Base::c_str;
    using Base::data;
    using Base::get_allocator;
    using Base::copy;
    using Base::find;
    using Base::rfind;
    using Base::find_first_of;
    using Base::find_last_of;
    using Base::find_first_not_of;
    using Base::find_last_not_of;
    using Base::substr;
    using Base::compare;
};


// IMPLEMENTATION
// --------------


template <typename Char, typename Traits, typename Alloc>
auto basic_string<Char, Traits, Alloc>::ref() const
    -> const Base &
{
    return static_cast<const Base&>(*this);
}


template <typename Char, typename Traits, typename Alloc>
auto basic_string<Char, Traits, Alloc>::ref()
    -> Base &
{
    return static_cast<Base&>(*this);
}


template <typename Char, typename Traits, typename Alloc>
auto basic_string<Char, Traits, Alloc>::forward() const
    -> const Base &&
{
    return static_cast<const Base&&>(*this);
}


template <typename Char, typename Traits, typename Alloc>
auto basic_string<Char, Traits, Alloc>::forward()
    -> Base &&
{
    return static_cast<Base&&>(*this);
}


template <typename Char, typename Traits, typename Alloc>
void swap(basic_string<Char, Traits, Alloc> &left,
    basic_string<Char, Traits, Alloc> &right)
{
    left.swap(right);
}


template <typename Char, typename Traits, typename Alloc>
std::basic_istream<Char, Traits> & operator>>(std::basic_istream<Char, Traits> &stream,
    basic_string<Char, Traits, Alloc> &str)
{
    return operator>>(stream, str.ref());
}

template <typename Char, typename Traits, typename Alloc>
std::basic_ostream<Char, Traits> & operator<<(std::basic_ostream<Char, Traits> &stream,
    basic_string<Char, Traits, Alloc> &str)
{
    return operator<<(stream, str.ref());
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const basic_string<Char, Traits, Alloc> &left,
        const basic_string<Char, Traits, Alloc> &right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.ref() + right.ref();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(basic_string<Char, Traits, Alloc> &&left,
        basic_string<Char, Traits, Alloc> &&right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.forward() + right.forward();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(basic_string<Char, Traits, Alloc> &&left,
        const basic_string<Char, Traits, Alloc> &right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.forward() + right.ref();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const basic_string<Char, Traits, Alloc> &left,
        basic_string<Char, Traits, Alloc> &&right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.ref() + right.forward();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const basic_string<Char, Traits, Alloc> &left,
        const Char *right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.ref() + right;
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(basic_string<Char, Traits, Alloc> &&left,
        const Char *right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.forward() + right;
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const Char *left,
        const basic_string<Char, Traits, Alloc> &right)
    -> basic_string<Char, Traits, Alloc>
{
    return left + right.ref();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const Char *left,
        basic_string<Char, Traits, Alloc> &&right)
    -> basic_string<Char, Traits, Alloc>
{
    return left + right.forward();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(const basic_string<Char, Traits, Alloc> &left,
        Char right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.ref() + right;
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(basic_string<Char, Traits, Alloc> &&left,
        Char right)
    -> basic_string<Char, Traits, Alloc>
{
    return left.forward() + right;
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(Char left,
        const basic_string<Char, Traits, Alloc> &right)
    -> basic_string<Char, Traits, Alloc>
{
    return left + right.ref();
}


template <typename Char, typename Traits, typename Alloc>
auto operator+(Char left,
        basic_string<Char, Traits, Alloc> &&right)
    -> basic_string<Char, Traits, Alloc>
{
    return left + right.forward();
}


template <typename Char, typename Traits, typename Alloc>
bool operator==(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator==(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator==(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator==(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator==(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator==(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
bool operator!=(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator!=(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator!=(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator!=(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator!=(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator!=(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
bool operator<(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator<(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator<(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator<(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator<(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator<(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
bool operator<=(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator<=(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator<=(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator<=(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator<=(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator<=(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
bool operator>(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator>(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator>(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator>(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator>(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator>(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
bool operator>=(const basic_string<Char, Traits, Alloc> &left,
    const basic_string<Char, Traits, Alloc> &right) noexcept
{
    return operator>=(left.ref(), right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator>=(const Char *left,
    const basic_string<Char, Traits, Alloc> &right)
{
    return operator>=(left, right.ref());
}


template <typename Char, typename Traits, typename Alloc>
bool operator>=(const basic_string<Char, Traits, Alloc> &left,
    const Char *right)
{
    return operator>=(left.ref(), right);
}


template <typename Char, typename Traits, typename Alloc>
std::basic_istream<Char, Traits> & getline(std::basic_istream<Char, Traits> &stream,
    basic_string<Char, Traits, Alloc> &str,
    Char delim)
{
    return getline(stream, str.ref(), delim);
}


template <typename Char, typename Traits, typename Alloc>
std::basic_istream<Char, Traits> & getline(std::basic_istream<Char, Traits> &&stream,
    basic_string<Char, Traits, Alloc> &str,
    Char delim)
{
    return getline(std::forward(stream), str.ref(), delim);
}


template <typename Char, typename Traits, typename Alloc>
std::basic_istream<Char, Traits> & getline(std::basic_istream<Char, Traits> &stream,
    basic_string<Char, Traits, Alloc> &str)
{
    return getline(stream, str.ref());
}


template <typename Char, typename Traits, typename Alloc>
std::basic_istream<Char, Traits> & getline(std::basic_istream<Char, Traits> &&stream,
    basic_string<Char, Traits, Alloc> &str)
{
    return getline(std::forward(stream), str.ref());
}


template <typename Char, typename Traits, typename Alloc>
const typename basic_string<Char, Traits, Alloc>::size_type basic_string<Char, Traits, Alloc>::npos;


template <typename Char, typename Traits, typename Alloc>
basic_string<Char, Traits, Alloc>::~basic_string()
{}


template <typename Char, typename Traits, typename Alloc>
void basic_string<Char, Traits, Alloc>::swap(This &other)
{
    ref().swap(other.ref());
}


// TYPES
// -----

typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
typedef basic_string<char16_t> u16string;
typedef basic_string<char32_t> u32string;

}   /* itl */
