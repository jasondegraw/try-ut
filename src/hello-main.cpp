//
// Copyright (c) 2022 Jason W. DeGraw
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//
#include "hello.hpp"
#include <iostream>

int main()
{
  Hello hello(std::cout);
  hello.greetings();
  std::cout << std::endl;
  return EXIT_SUCCESS;
}