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
	/*double shell_sortTime = time_test(FUNCTIONS::SHELL, (size_t)1000000);
	cout << "shell_sort 10^6 random nums spend:" << shell_sortTime << "ms" << endl;
	double insert_sortTime = time_test(FUNCTIONS::INSERT, (size_t)100000);
	cout << "insert_sort 10^5 random nums spend:" << insert_sortTime << "ms" << endl;
	double select_sortTime = time_test(FUNCTIONS::SELECT, (size_t)100000);
	cout << "select_sort 10^5 random nums spend:" << select_sortTime << "ms"<< endl;*/
	double merge_sortTime = time_test(FUNCTIONS::MERGE, 10000000);
	cout << "merge_sort 10^7 random nums spend:" << merge_sortTime << "ms" << endl;
	system("pause");
    return 0;
}

