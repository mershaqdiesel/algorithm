#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE ListTests

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "List.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( ListConstruction )
{
    cout << 1 << endl;
    List<int> l;
    BOOST_CHECK( l.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( ListPushBack )
{
    cout << 2 << endl;
    List<int> l;
    int i = 1;
    l.PushBack(i);
    l.PushBack(i);
    l.PushBack(i);
    BOOST_CHECK( l.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( ListPopBack )
{
    cout << 3 << endl;
    List<int> l;
    int i = 1;
    l.PushBack(i);
    BOOST_CHECK( l.Size() == 1 );
    l.PopBack();
    BOOST_CHECK( l.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( ListPushFront )
{
    cout << 4 << endl;
    List<int> l;
    int i = 1;
    l.PushFront(i);
    l.PushFront(i);
    l.PushFront(i);
    BOOST_CHECK( l.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( ListPopFront )
{
    cout << 5 << endl;
    List<int> l;
    int i = 1;
    l.PushFront(i);
    BOOST_CHECK( l.Size() == 1 );
    l.PopFront();
    BOOST_CHECK( l.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( ListFrontNonConst )
{
    cout << 6 << endl;
    List<string> l;
    string foo{"foo"};
    l.PushFront(foo);
    BOOST_CHECK( l.Front() == "foo" );
    l.Front() = "bar";
    BOOST_CHECK( l.Front() == "bar" );
}

BOOST_AUTO_TEST_CASE( ListBackNonConst )
{
    cout << 7 << endl;
    List<string> l;
    string foo{"foo"};
    l.PushBack(foo);
    BOOST_CHECK( l.Back() == "foo" );
    l.Back() = "bar";
    BOOST_CHECK( l.Back() == "bar" );
}

BOOST_AUTO_TEST_CASE( ListFrontConst )
{
    cout << 8 << endl;
    List<int> l;
    l.PushFront(1);
    const List<int> &m = l;
    BOOST_CHECK( m.Front() == 1 );
}

BOOST_AUTO_TEST_CASE( ListBackConst )
{
    cout << 9 << endl;
    List<int> l;
    l.PushBack(1);
    const List<int> &m = l;
    BOOST_CHECK( m.Back() == 1 );
}

BOOST_AUTO_TEST_CASE( ListRandomAccessOperator )
{
    cout << 10 << endl;
    List<int> l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    BOOST_CHECK( l[0] == 1 );
    BOOST_CHECK( l[1] == 2 );
    BOOST_CHECK( l[2] == 3 );
}

BOOST_AUTO_TEST_CASE( ListPushFrontMove )
{
    cout << 11 << endl;
    List<string> l;
    l.PushFront("foo");
    BOOST_CHECK( l.Front() == "foo" );
}

BOOST_AUTO_TEST_CASE( ListPushBackMove )
{
    cout << 12 << endl;
    List<string> l;
    l.PushBack("foo");
    BOOST_CHECK( l.Back() == "foo" );
}

BOOST_AUTO_TEST_CASE( ListConstCopyConstructor )
{
    cout << 13 << endl;
    List<int> l = {1};
    List<int> m{l};
    m.PushBack(2);
    BOOST_CHECK( l.Size() == 1 );
    BOOST_CHECK( m.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( ListMoveCopyConstructor )
{
    cout << 14 << endl;
    List<int> l{1,2,3,4};
    List<int> m{std::move(l)};
}

BOOST_AUTO_TEST_CASE( ListInitializerListConstructor )
{
    cout << 15 << endl;
    List<int> l{1,2,3,4};
    BOOST_CHECK( l.Size() == 4 );
}

BOOST_AUTO_TEST_CASE( ListConstAssignmentOperator )
{
    cout << 16 << endl;
    List<int> l{1,2,3,4};
    List<int> m;
    m = l;
    BOOST_CHECK( l.Size() == m.Size() );
}

BOOST_AUTO_TEST_CASE( ListMoveAssignmentOperator )
{
    cout << 17 << endl;
    List<int> l{1,2,3,4};
    List<int> m;
    m = std::move(l);
    BOOST_CHECK( m.Size() == 4 );
}

BOOST_AUTO_TEST_CASE( ListIterableNonConst )
{
    cout << 18 << endl;
    List<int> l{1,2,3,4,5,6,7,8,9,10};
    int i = 1;
    for ( auto itr = l.Begin(); *(itr) != *(l.End()); itr->Next())
    {
        BOOST_CHECK( itr->Data() == i );
        i++;
    }
}