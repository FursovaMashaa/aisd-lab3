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

/*TEST(Tests5, insertionSort_1) {
	setlocale(LC_ALL, "Rus");
	cycle_rand_insertion();
	cycle_ord_insertion();
	cycle_revers_insertion();
	EXPECT_EQ(1, 1);
}*/

TEST(Tests6, quickSort_1) {
	setlocale(LC_ALL, "Rus");
	cycle_rand_quick();
	cycle_ord_quick();
	cycle_revers_quick();
	EXPECT_EQ(1, 1);
}

TEST(Tests6, mergeSort_1) {
	setlocale(LC_ALL, "Rus");
	cycle_rand_merge();
	cycle_ord_merge();
	cycle_revers_merge();
	EXPECT_EQ(1, 1);
}