//import boost.ut;
#define BOOST_UT_DISABLE_MODULE
#include <boost/ut.hpp>

int main()
{
  using namespace boost::ut;
  expect(1 == 2);
  return 0;
}