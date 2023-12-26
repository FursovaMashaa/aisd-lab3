#include "sorting.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace sorts;


TEST(Test1, insertionSort) {
	vector<int>a = { 4,6,8,13,2,1,1,5,9 };
	vector<int>b = { 1,1,2,4,5,6,8,9,13 };
	stats s;
	insertionSort(a, s);
	EXPECT_EQ(a, b);
}

TEST(Test2, quickSort) {
	vector<int>a = { 4,6,8,13,2,1,1,5,9 };
	vector<int>b = { 1,1,2,4,5,6,8,9,13 };
	stats s;
	quickSort(a, 0, a.size() - 1, s);
	EXPECT_EQ(a, b);
};

TEST(Test3, merge_sort) {
	vector<int>a = { 4,6,8,13,2,1,1,5,9 };
	vector<int>b = { 1,1,2,4,5,6,8,9,13 };
	stats s;
	merge_sort(a,s);
	EXPECT_EQ(a, b);
};

TEST(Test4, merge_sort2) {
	vector<int>a = { 4,6,8,13,2,1,1,5,9,34,0,24,11,66,45 };
	vector<int>b = { 0,1,1,2,4,5,6,8,9,11,13,24,34,45,66 };
	stats s;
	merge_sort(a, s);
	EXPECT_EQ(a, b);
};
