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
    BinaryTree< int, int > bt;
}

BOOST_AUTO_TEST_CASE( BinaryTreePut )
{
    BinaryTree< string, int > bt;
    bt.Put( "key1", 1 );
}\

BOOST_AUTO_TEST_CASE( BinaryTreeOperatorBracket )
{
    BinaryTree< string, int > bt;
    bt.Put( "key1", 1 );
    BOOST_CHECK( bt[ "key1" ] == 1 );
}

BOOST_AUTO_TEST_CASE( BinaryTreeKeys )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeValues )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeConstOperatorBracket )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeConstKeys )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeConstValues )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeConstCopyConstructor )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeMoveConstructor )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeConstAssignmentOperator )
{

}

BOOST_AUTO_TEST_CASE( BinaryTreeMoveAssignmentOperator )
{

}