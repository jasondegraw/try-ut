//
// Copyright (c) 2022 Jason W. DeGraw
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//
#ifndef HELLO_HPP
#define HELLO_HPP
template <typename T> class Hello
{
public:
  Hello(T& c) : c(c) {}
  int the_answer() const
  {
    return 42;
  }
  void greetings() const
  {
    c << "Hello, World!";
  }
private:
  T& c;
};
#endif