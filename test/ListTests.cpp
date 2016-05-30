#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ListTests

#include <boost/test/unit_test.hpp>

#include <string>

#include "List.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( ListConstruction )
{
    List<int> l;
    BOOST_CHECK( l.Size() == static_cast<size_t> (0) );
}

BOOST_AUTO_TEST_CASE( ListPushBack )
{
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    BOOST_CHECK( l.Size() == static_cast<size_t> (3) );
}

BOOST_AUTO_TEST_CASE( ListPopBack )
{
    List<int> l;
    l.PushBack(1);
    BOOST_CHECK( l.Size() == static_cast<size_t> (1) );
    l.PopBack();
    BOOST_CHECK( l.Size() == static_cast<size_t> (0) );
}

BOOST_AUTO_TEST_CASE( ListPushFront )
{
    List<int> l;
    l.PushFront(1);
    l.PushFront(2);
    l.PushFront(3);
    BOOST_CHECK( l.Size() == static_cast<size_t> (3) );
}

BOOST_AUTO_TEST_CASE( ListPopFront )
{
    List<int> l;
    l.PushFront(1);
    BOOST_CHECK( l.Size() == static_cast<size_t> (1) );
    l.PopFront();
    BOOST_CHECK( l.Size() == static_cast<size_t> (0) );
}

BOOST_AUTO_TEST_CASE( ListFrontConst )
{
    List<int> l;
    l.PushFront(1);
    BOOST_CHECK( l.Front() == 1 );
    BOOST_CHECK( l.Back() == 1 );
}

BOOST_AUTO_TEST_CASE( ListBackConst )
{
    List<int> l;
    l.PushBack(2);
    BOOST_CHECK( l.Front() == 2 );
    BOOST_CHECK( l.Back() == 2 );
}

BOOST_AUTO_TEST_CASE( ListRandomAccessOperator )
{
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    BOOST_CHECK( l[0] == 1 );
    BOOST_CHECK( l[1] == 2 );
    BOOST_CHECK( l[2] == 3 );
}

BOOST_AUTO_TEST_CASE( ListFrontNonConst )
{
    List<string> l;
    l.PushBack("foo");
    BOOST_CHECK( l.Front() == "foo" );
    l.Front() = "bar";
    BOOST_CHECK( l.Front() == "bar" );
}

BOOST_AUTO_TEST_CASE( ListBackNonConst )
{
    List<string> l;
    l.PushBack("foo");
    BOOST_CHECK( l.Back() == "foo" );
    l.Back() = "bar";
    BOOST_CHECK( l.Back() == "bar" );
}