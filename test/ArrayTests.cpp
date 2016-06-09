#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ArrayTests

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "Array.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( ArrayConstruction )
{
    cout << 1 << endl;
    Array<int> a;
    BOOST_CHECK( a.Size() == 0 );
}