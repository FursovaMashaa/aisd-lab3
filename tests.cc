#include "sorting.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace sorts;

TEST(Test1, quick_sort) {
	vector<int>a = { 4,6,8,13,2,1,1,5,9 };
	vector<int>b = { 1,1,2,4,5,6,8,9,13 };
	stats s;
	quick_sort(a, 0, a.size() - 1, s);
	EXPECT_EQ(a, b);
}