// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "my_sort.h"
#include <iostream>


using std::cout;
using std::endl;
using namespace sort;

int main()
{
	/*
	TEST:
	double insert_sortTime = time_test(FUNCTIONS::INSERT, (size_t)100000);
	cout << "insert_sort 10^5 random nums spend:" << insert_sortTime << 's' << endl;
	double select_sortTime = time_test(FUNCTIONS::SELECT, (size_t)100000);
	cout << "select_sort 10^5 random nums spend:" << select_sortTime << 's'<< endl;
	*/
	srand((unsigned)time(NULL));
	int* arr = new int[1000];
	for (int i = 0; i < 1000; i++) {
		arr[i] = (char)(rand() % 26 + 'A');
	}
	select_sort(arr,1000);
	cout << "选择排序测试:";
	cout << is_ascending_ordered(arr, 1000) << endl;
	shuffle(arr, 1000);
	insert_sort(arr, 1000);
	cout << "插入排序测试:" <<is_ascending_ordered(arr, 1000) << endl;
	//delete []arr;
	system("pause");
    return 0;
}

