Inheritance Template Library
============================

**Table of Contents**

- [Motivation](#design)
- [Design](#design)
- [Overhead](#overhead)
- [License](#license)

## Motivation

The C++ Standard Template Library forms the basis of modern C++ design, however, it features free-function design, and is not designed for inheritance. This header-only library provides minimal inheritance-safe wrappers.

## Design

1. Use protected inheritance.
2. Export all member types, variables, and functions
3. Add trivial virtual destructor.
4. Overload non-member functions in terms of the base class

```cpp
struct StdIntVector: public std::vector<int> {};
std::vector<int> *ptr = new StdIntVector;
delete ptr;                                 // undefined behavior

...

struct ItlIntVector: public itl::vector<int> {};
std::vector<int> *ptr = new ItlIntVector;   // fails to compile
itl::vector<int> *ptr = new ItlIntVector;
delete ptr;                                 // safe
```

## Overhead

Each inheritable wrapper will add a small amount of overhead (typically a pointer to a vtable, or 4-8 bytes) to the STL container, as well as incur a small runtime penalty for object destruction. However, all wrapped methods should be inlined by the compiler, making the total overhead minimal.

## License

Public Domain, see [license](LICENSE.md).
