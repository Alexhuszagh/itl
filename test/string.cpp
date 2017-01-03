/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/string.hpp>

#include <sstream>


TEST(basic_string, MemberFunctions)
{
    itl::string string = {'A', 'S', 'C', 'I', 'I'};
    itl::string other;
    string.swap(other);

    EXPECT_EQ(string.size(), 0);
    EXPECT_EQ(other.size(), 5);
}



TEST(basic_string, MemberVariables)
{
    EXPECT_EQ(itl::string::npos, size_t(-1));
}


TEST(basic_string, NonMemberFunctions)
{
    itl::string line, copy, empty;
    std::istringstream is(std::string({'A', 'S', '\n', 'I', 'I'}));
    itl::getline(is, line, '\n');

    EXPECT_EQ(line, "AS");

    std::stringstream stream;
    stream << line;
    stream >> copy;
    EXPECT_EQ(line, copy);

    EXPECT_TRUE(line == copy);
    EXPECT_TRUE(line != empty);
    EXPECT_TRUE(empty < line);
    EXPECT_TRUE(empty <= line);
    EXPECT_TRUE(line > empty);
    EXPECT_TRUE(line >= empty);
}
