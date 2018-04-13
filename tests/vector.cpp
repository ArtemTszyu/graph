#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("creating queue")
{
	queue_t queue;
	REQUIRE( queue.head() == 0 );
	REQUIRE( queue.tail() == 0 );
}

TEST_CASE("copying queue")
{
	queue_t<int> list;
	list.push(1);
	list.push(2);
	queue_t<int> list2(list);
	int sum = list2.pop();
	sum = sum + list2.pop();
	REQUIRE( sum == 3 );
	
}

TEST_CASE("pushing elements")
{
	queue_t queue;

	queue.push(1);
	REQUIRE( queue.head() == 1 );
	REQUIRE( queue.tail() == 1 );

	queue.push(2);
	REQUIRE( queue.head() == 1 );
	REQUIRE( queue.tail() == 2 );

	queue.push(3);
	REQUIRE( queue.head() == 1 );
	REQUIRE( queue.tail() == 3 );
}

TEST_CASE("poping elements")
{
	queue_t queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);

	queue.pop();
	REQUIRE( queue.head() == 2 );
	REQUIRE( queue.tail() == 4 );

	queue.pop();
	REQUIRE( queue.head() == 3 );
	REQUIRE( queue.tail() == 4 );

	queue.pop();
	REQUIRE( queue.head() == 4 );
	REQUIRE( queue.tail() == 4 );
}
