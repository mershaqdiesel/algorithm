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
    s.Pop();
    s.Push( 2 );
    BOOST_CHECK( s.Top() == 2 );
    s.Pop();
    s.Push( 3 );
    BOOST_CHECK( s.Top() == 3 );
    s.Pop();
}

BOOST_AUTO_TEST_CASE( StackConstCopyConstructor )
{

}