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
	cout << "对10^6个随机数采用希尔排序耗时:" << shell_sortTime << "ms" << endl;
	double insert_sortTime = time_test(FUNCTIONS::INSERT, (size_t)100000);
	cout << "对10^5个随机数采用插入排序耗时:" << insert_sortTime << "ms" << endl;
	double select_sortTime = time_test(FUNCTIONS::SELECT, (size_t)100000);
	cout << "对10^5个随机数采用选择排序耗时:" << select_sortTime << "ms"<< endl;
	double merge_sortTime = time_test(FUNCTIONS::MERGE, 10000000);
	cout << "对10^7个随机数采用原地归并排序耗时:" << merge_sortTime << "ms" << endl;*/
	cout << "success:" << time_test(FUNCTIONS::MERGE, 2560) << endl;
	system("pause");
    return 0;
}

