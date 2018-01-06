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
	double insert_sortTime = time_test(FUNCTIONS::INSERT, (size_t)100000);
	cout << "insert_sort 10^5 random nums spend:" << insert_sortTime << 's' << endl;
	double select_sortTime = time_test(FUNCTIONS::SELECT, (size_t)100000);
	cout << "select_sort 10^5 random nums spend:" << select_sortTime << 's'<< endl;
	system("pause");
    return 0;
}

