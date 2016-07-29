#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE StackTests

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "Stack.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( StackDefaultConstructor )
{
    cout << 1 << endl;
    Stack<int> s;
    BOOST_CHECK( s.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( StackNonConstPush )
{
    cout << 2 << endl;
    Stack< string > s;
    string foo{ "foo" };
    string bar{ "bar" };
    string baz{ "baz" };
    s.Push( foo );
    s.Push( bar );
    s.Push( baz );
    BOOST_CHECK( s.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( StackConstPush )
{
    cout << 3 << endl;
    Stack< string > s;
    const string foo{ "const foo" };
    const string bar{ "const bar" };
    const string baz{ "const baz" };
    s.Push( foo );
    s.Push( bar );
    s.Push( baz );
    BOOST_CHECK( s.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( StackPop )
{
    cout << 4 << endl;
    Stack< int > s;
    s.Push( 1 );
    s.Push( 2 );
    s.Push( 3 );
    BOOST_CHECK( s.Size() == 3 );

    s.Pop();
    BOOST_CHECK( s.Size() == 2 );
    s.Pop();
    BOOST_CHECK( s.Size() == 1 );
    s.Pop();
    BOOST_CHECK( s.Size() == 0 );
    s.Pop();        // one extra pop empty stack checking
    BOOST_CHECK( s.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( StackConstTop )
{
    cout << 5 << endl;
    Stack< string > s;
    s.Push( "foo" );
    const Stack< string >& s2 = s;
    BOOST_CHECK( s2.Top() == "foo" );
}

BOOST_AUTO_TEST_CASE( StackTop )
{
    cout << 6 << endl;
    Stack< int > s;
    s.Push( 1 );
    BOOST_CHECK( s.Top() == 1 );
}

BOOST_AUTO_TEST_CASE( StackClear )
{
    cout << 7 << endl;
    Stack< int > s;
    s.Push( 1 );
    s.Push( 2 );
    s.Push( 3 );
    BOOST_CHECK( s.Size() == 3 );
    s.Clear();
    BOOST_CHECK( s.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( StackConstCopyConstructor )
{
    cout << 8 << endl;
    Stack< int > s1;
    s1.Push( 1 );
    Stack< int > s2{ s1 };
    BOOST_CHECK( s1.Top() == s2.Top() );
    s2.Push( 2 );
    BOOST_CHECK( s1.Top() == 1 );
    BOOST_CHECK( s1.Size() == 1 );
    BOOST_CHECK( s2.Top() == 2 );
    BOOST_CHECK( s2.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( StackMoveConstructor )
{
    cout << 9 << endl;
    Stack< int > s;
    s.Push( 1 );
    s.Push( 2 );
    s.Push( 3 );
    Stack< int > s2( std::move( s ) );
    BOOST_CHECK( s2.Top() == 3 );
    BOOST_CHECK( s2.Size() == 3 );
}

BOOST_AUTO_TEST_CASE( StackConstAssignmentOperator )
{
    cout << 10 << endl;
    Stack< int > s;
    s.Push( 1 );
    s.Push( 2 );
    Stack< int > sprime;
    sprime = s;
    BOOST_CHECK( sprime.Top() == 2 );
    BOOST_CHECK( sprime.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( StackMoveAssignmentOperator )
{
    cout << 11 << endl;
    Stack< int > s;
    s.Push( 1 );
    s.Push( 2 );
    Stack< int > sprime;
    sprime = std::move( s );
    BOOST_CHECK( sprime.Top() == 2 );
    BOOST_CHECK( sprime.Size() == 2 );
}