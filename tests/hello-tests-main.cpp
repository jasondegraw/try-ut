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

boost::ut::suite errors = [] {
  using namespace boost::ut;

  "exception"_test = [] {
    expect(throws([] { throw 0; })) << "throws any exception";
  };

  "equals"_test = [] {
    expect(1_i == 2) << "guaranteed to fail";
  };
};

int main()
{
  return EXIT_SUCCESS;
}