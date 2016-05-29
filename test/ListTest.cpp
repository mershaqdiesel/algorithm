#define BOOST_TEST_MODULE ListTest

#include <boost/test/included/unit_test.hpp>

#include "List.h"

using namespace algo;
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE( ListConstruction )
{
    List<int> l;
    BOOST_TEST( l.Size() == static_cast<size_t> (0) );
}

BOOST_AUTO_TEST_CASE( ListPushBack )
{
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    BOOST_TEST( l.Size() == static_cast<size_t> (3) );
}