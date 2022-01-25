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

#ifdef _MSC_VER
#include <windows.h>
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

int main(int argc, const char** argv)
{
  using namespace boost::ut;

  bool dry_run{false};

#ifdef _MSC_VER
  auto custom_colors = colors{ .none = "", .pass = "", .fail = "" };
  auto console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  if (console_handle != INVALID_HANDLE_VALUE) {
    DWORD console_mode;
    GetConsoleMode(console_handle, &console_mode);
    console_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    auto success = SetConsoleMode(console_handle, console_mode);
    if (success != 0) {
      custom_colors.none = "\033[0m";
      custom_colors.pass = "\033[32m";
      custom_colors.fail = "\033[91m";
    }
  }
#else
  auto custom_colors = colors{};
#endif

  cfg<override> = {.filter = argc > 1 ? argv[1] : "",
                   .colors = custom_colors,
                   .dry_run = dry_run};

  return EXIT_SUCCESS;
}