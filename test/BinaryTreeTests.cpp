#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE BinaryTreeTests

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "BinaryTree.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( BinaryTreeConstructor )
{
    cout << 1 << endl;
    BinaryTree< int, int > bt;
}

BOOST_AUTO_TEST_CASE( BinaryTreePut )
{
    cout << 2 << endl;
    BinaryTree< string, int > bt;
    bt.Put( "key1", 1 );
}

BOOST_AUTO_TEST_CASE( BinaryTreeOperatorBracket )
{
    cout << 3 << endl;
    BinaryTree< string, int > bt;
    bt.Put( "key1", 1 );
    BOOST_CHECK( bt[ "key1" ] == 1 );
}

BOOST_AUTO_TEST_CASE( BinaryTreeKeys )
{
    cout << 4 << endl;
    BinaryTree< int, int > bt;
    bt.Put( 1, 1 );
    bt.Put( 2, 2 );
    bt.Put( 3, 3 );
    auto keys = bt.Keys();
    int i = 1;
    for ( auto itr = keys.Begin(); *(itr) != *(keys.End()); itr->Next() )
    {
        BOOST_CHECK( itr->Data() == i );
        i++;
    }
}

BOOST_AUTO_TEST_CASE( BinaryTreeValues )
{
    cout << 5 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeConstOperatorBracket )
{
    cout << 6 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeConstKeys )
{
    cout << 7 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeConstValues )
{
    cout << 8 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeConstCopyConstructor )
{
    cout << 9 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeMoveConstructor )
{
    cout << 10 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeConstAssignmentOperator )
{
    cout << 11 << endl;
}

BOOST_AUTO_TEST_CASE( BinaryTreeMoveAssignmentOperator )
{
    cout << 12 << endl;
}