#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE QueueTests

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>

#include "Queue.h"

using namespace algo;
using namespace boost::unit_test;
using namespace std;

BOOST_AUTO_TEST_CASE( QueueConstructor )
{
  cout << 1 << endl;
  Queue< int > q;
  BOOST_CHECK( q.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( QueuePushBackNonConst )
{
  cout << 2 << endl;
  Queue< string > q;
  string foo{ "foo" };
  string bar{ "bar" };
  q.PushBack( foo );
  BOOST_CHECK( q.Size() == 1 );
  q.PushBack( bar );
  BOOST_CHECK( q.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueuePushBackConst )
{
  cout << 3 << endl;
  Queue< string > q;
  const string foo{ "foo" };
  const string bar{ "bar" };
  q.PushBack( foo );
  BOOST_CHECK( q.Size() == 1 );
  q.PushBack( bar );
  BOOST_CHECK( q.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueuePushFrontNonConst )
{
  cout << 4 << endl;
  Queue< string > q;
  string foo{ "foo" };
  string bar{ "bar" };
  q.PushFront( foo );
  BOOST_CHECK( q.Size() == 1 );
  q.PushFront( bar );
  BOOST_CHECK( q.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueuePushFrontConst )
{
  cout << 5 << endl;
  Queue< string > q;
  const string foo{ "foo" };
  const string bar{ "bar" };
  q.PushFront( foo );
  BOOST_CHECK( q.Size() == 1 );
  q.PushFront( bar );
  BOOST_CHECK( q.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueuePopBack )
{
  cout << 6 << endl;
  Queue< string > q;
  string foo{ "foo" };
  string bar{ "bar" };
  q.PushBack( foo );
  q.PushBack( bar );
  BOOST_CHECK( q.Size() == 2 );
  q.PopBack();
  BOOST_CHECK( q.Size() == 1 );
  q.PopBack();
  BOOST_CHECK( q.Size() == 0 );
  q.PopBack();
  BOOST_CHECK( q.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( QueuePopFront )
{
  cout << 7 << endl;
  Queue< string > q;
  string foo{ "foo" };
  string bar{ "bar" };
  q.PushFront( foo );
  q.PushFront( bar );
  BOOST_CHECK( q.Size() == 2 );
  q.PopFront();
  BOOST_CHECK( q.Size() == 1 );
  q.PopFront();
  BOOST_CHECK( q.Size() == 0 );
  q.PopFront();
  BOOST_CHECK( q.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( QueueFrontNonConst )
{
  cout << 8 << endl;
  Queue< int > q;
  q.PushFront( 1 );
  BOOST_CHECK( q.Front() == 1 );
}

BOOST_AUTO_TEST_CASE( QueueFrontConst )
{
  cout << 9 << endl;
  Queue< int > q;
  q.PushFront( 1 );
  const Queue< int >& q2 = q;
  BOOST_CHECK( q2.Front() == 1 );
}

BOOST_AUTO_TEST_CASE( QueueBackNonConst )
{
  cout << 10 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  BOOST_CHECK( q.Back() == 1 );
}

BOOST_AUTO_TEST_CASE( QueueBackConst )
{
  cout << 11 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  const Queue< int >& q2 = q;
  BOOST_CHECK( q2.Back() == 1 );
}

BOOST_AUTO_TEST_CASE( QueueClear )
{
  cout << 12 << endl;
  Queue< string > q;
  string foo{ "foo" };
  string bar{ "bar" };
  q.PushFront( foo );
  q.PushFront( bar );
  BOOST_CHECK( q.Size() == 2 );
  q.Clear();
  BOOST_CHECK( q.Size() == 0 );
}

BOOST_AUTO_TEST_CASE( QueueConstructorConstCopy )
{
  cout << 13 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  q.PushBack( 2 );
  Queue< int > q2{ q };
  BOOST_CHECK( q2.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueueConstructorMove )
{
  cout << 14 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  q.PushBack( 2 );
  Queue< int > q2{ std::move( q ) };
  BOOST_CHECK( q2.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueueAssignmentOperatorConst )
{
  cout << 15 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  q.PushBack( 2 );
  Queue< int > q2;
  q2 = q;
  BOOST_CHECK( q2.Size() == 2 );
}

BOOST_AUTO_TEST_CASE( QueueAssignmentOperatorMove )
{
  cout << 16 << endl;
  Queue< int > q;
  q.PushBack( 1 );
  q.PushBack( 2 );
  Queue< int > q2;
  q2 = std::move( q );
  BOOST_CHECK( q2.Size() == 2 );
}
