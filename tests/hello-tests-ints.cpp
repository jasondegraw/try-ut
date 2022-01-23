//
// Copyright (c) 2022 Jason W. DeGraw
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//
#ifdef __cpp_modules
#ifdef _MSC_VER
#define BOOST_UT_DISABLE_MODULE
#include <boost/ut.hpp>
#else
import boost.ut; // Doesn't appear to work yet with MSVC/CMake
#endif
#else
#include <boost/ut.hpp>
#endif

#include "hello.hpp"
#include <sstream>

boost::ut::suite ints = [] {
  using namespace boost::ut;

  "answer"_test = [] {
    std::stringstream strstream;
    Hello hello(strstream);
    expect(42_i == hello.the_answer()) << "the universe and all that";
  };

  "nothing"_test = [] {
    expect(1_i == 1) << "probably should never fail";
  };
};
