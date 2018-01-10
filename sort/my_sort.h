#pragma once
#include <stdlib.h>
#include <time.h>
#include "simple_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
//TODO:improvement

namespace sort {
	enum class FUNCTIONS {SELECT,INSERT,SHELL,MERGE,QUICK,HEAP};

	/*O(N)*/
	void shuffle(int arr[], size_t nums) {
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < nums; i++) {
			size_t swap_pos = rand() % nums;
			std::swap(arr[i], arr[swap_pos]);
		}
	}

	/*O(N)*/
	template <class T>
	bool is_ascending_ordered(T arr[], size_t nums) {
		for (size_t i = 0; i < nums - 1; i++) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	double time_test(FUNCTIONS func, size_t scale) {
		srand((unsigned)time(NULL));
		int* arr = new int[scale];
		for (size_t i = 0; i < scale; i++) {
			arr[i] = rand();
		}
		clock_t start = clock();
		switch (func)
		{
		case FUNCTIONS::INSERT:
			insert_sort(arr, 0, scale - 1);
			break;
		case FUNCTIONS::SELECT:
			select_sort(arr, 0, scale - 1);
			break;
		case FUNCTIONS::SHELL:
			shell_sort(arr, 0, scale - 1);
			break;
		case FUNCTIONS::MERGE:
			Merge_Sort().sort(arr, 0, scale - 1);
			break;
		case FUNCTIONS::QUICK:
			_qsort(arr, 0, scale - 1);
			break;
		case FUNCTIONS::HEAP:
			Heap_sort hs(arr, scale);
			for (size_t i = 0; i < scale; i++) {
				arr[i] = hs.deleteMin();
			}
			break;
		}
		clock_t end = clock();
		//check if sort successfully
		if (is_ascending_ordered(arr, scale)) {
			delete[]arr;
			return double((end - start));
		}
		return -1.0;
	}
}