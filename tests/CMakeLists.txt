
project(hello-tests)

include_directories(../src)

add_executable(hello-tests ../src/hello.hpp hello-tests-main.cpp hello-tests-ints.cpp hello-tests-strings.cpp)
