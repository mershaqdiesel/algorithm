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

BOOST_AUTO_TEST_CASE( ArrayPushBack )
{
    cout << 2 << endl;
    Array<int> a;
    int i = 1;
    a.PushBack(i);
    a.PushBack(i);
    a.PushBack(i);
    BOOST_CHECK( a.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( ArrayPopBack )
{
    cout << 3 << endl;
    Array<int> a;
    int i = 1;
    a.PushBack(i);
    BOOST_CHECK( a.Size() == 1 );
    a.PopBack();
    BOOST_CHECK( a.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( ArrayPushFront )
{
    cout << 4 << endl;
    Array<int> a;
    int i = 1;
    a.PushFront(i);
    a.PushFront(i);
    a.PushFront(i);
    BOOST_CHECK( a.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( ArrayPopFront )
{
    cout << 5 << endl;
    Array<int> a;
    int i = 1;
    a.PushFront(i);
    BOOST_CHECK( a.Size() == 1 );
    a.PopFront();
    BOOST_CHECK( a.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( ArrayFrontNonConst )
{
    cout << 6 << endl;
    Array<string> a;
    string foo{"foo"};
    a.PushFront(foo);
    BOOST_CHECK( a.Front() == "foo" );
    a.Front() = "bar";
    BOOST_CHECK( a.Front() == "bar" );
}

BOOST_AUTO_TEST_CASE( ArrayBackNonConst )
{
    cout << 7 << endl;
    Array<string> a;
    string foo{"foo"};
    a.PushBack(foo);
    BOOST_CHECK( a.Back() == "foo" );
    a.Back() = "bar";
    BOOST_CHECK( a.Back() == "bar" );
}

BOOST_AUTO_TEST_CASE( ArrayFrontConst )
{
    cout << 8 << endl;
    Array<int> a;
    a.PushFront(1);
    const Array<int> &m = a;
    BOOST_CHECK( m.Front() == 1 );
}

BOOST_AUTO_TEST_CASE( ArrayBackConst )
{
    cout << 9 << endl;
    Array<int> a;
    a.PushBack(1);
    const Array<int> &m = a;
    BOOST_CHECK( m.Back() == 1 );
}

BOOST_AUTO_TEST_CASE( ArrayRandomAccessOperator )
{
    cout << 10 << endl;
    Array<int> a;
    a.PushBack(1);
    a.PushBack(2);
    a.PushBack(3);
    BOOST_CHECK( a[0] == 1 );
    BOOST_CHECK( a[1] == 2 );
    BOOST_CHECK( a[2] == 3 );
}

BOOST_AUTO_TEST_CASE( ArrayPushFrontMove )
{
    cout << 11 << endl;
    Array<string> a;
    a.PushFront("foo");
    BOOST_CHECK( a.Front() == "foo" );
}

BOOST_AUTO_TEST_CASE( ArrayPushBackMove )
{
    cout << 12 << endl;
    Array<string> a;
    a.PushBack("foo");
    BOOST_CHECK( a.Back() == "foo" );
}

BOOST_AUTO_TEST_CASE( ArrayConstCopyConstructor )
{
    cout << 13 << endl;
    Array<int> a = {1};
    Array<int> m{a};
    m.PushBack(2);
    BOOST_CHECK( a.Size() == 1 );
    BOOST_CHECK( m.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( ArrayMoveCopyConstructor )
{
    cout << 14 << endl;
    Array<int> a{1,2,3,4};
    Array<int> m{std::move(a)};
}

BOOST_AUTO_TEST_CASE( ArrayInitializerArrayConstructor )
{
    cout << 15 << endl;
    Array<int> a{1,2,3,4};
    BOOST_CHECK( a.Size() == 4 );
}

BOOST_AUTO_TEST_CASE( ArrayConstAssignmentOperator )
{
    cout << 16 << endl;
    Array<int> a{1,2,3,4};
    Array<int> m;
    m = a;
    BOOST_CHECK( a.Size() == m.Size() );
}

BOOST_AUTO_TEST_CASE( ArrayMoveAssignmentOperator )
{
    cout << 17 << endl;
    Array<int> a{1,2,3,4};
    Array<int> m;
    m = std::move(a);
    BOOST_CHECK( m.Size() == 4 );
}

BOOST_AUTO_TEST_CASE( ArrayIterableNonConst )
{
    cout << 18 << endl;
    Array<int> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i = 1;
    for ( auto itr = a.Begin(); *(itr) != *(a.End()); itr->Next())
    {
        BOOST_CHECK( itr->Data() == i );
        i++;
    }
}