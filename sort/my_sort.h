#pragma once
#include <stdlib.h>
#include <time.h>

namespace sort {
	enum class FUNCTIONS {SELECT,INSERT,SHELL};
	template <class T>
	bool is_ascending_ordered(T arr[], size_t nums) {
		for (size_t i = 0; i < nums - 1; i++) {
			if (arr[i] > arr[i + 1])
				return false;
		}
		return true;
	}

	/*
		ѡ������:
			1.Ч�ʺ������޹�
			2.���ڹ�ģΪN�ĵ�����,����Ƚ�N(N-1)/2��,����N��
			3.���ݵ��ƶ������ٵ�,ֻ��N�ν���
	*/
	template <class T>
	void select_sort(T arr[], size_t nums) {
		for (size_t i = 0; i < nums; i++) {
			size_t min = i;
			for (size_t j = i; j < nums; j++) {
				if (arr[min] > arr[j])
					min = j;
			}
			std::swap(arr[min], arr[i]);
		}
	}

	template <class T>
	void insert_sort(T arr[], size_t nums) {
		for (size_t i = 1; i < nums; i++) {
			T insert_value = arr[i];
			size_t j = i - 1;
			for (; j >= 0 && arr[j] > insert_value; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = insert_value;
		}
	}
	
	template <class T>
	void shuffle(T arr[], size_t nums) {
		srand((unsigned)time(NULL));
		for (size_t i = 0; i < nums; i++) {
			size_t swap_pos = rand() % nums;
			std::swap(arr[i], arr[swap_pos]);
		}
	}

	double time_test(FUNCTIONS func, size_t scale) {
		srand((unsigned)time(NULL));
		int* arr = new int[scale];
		for (size_t i = 0; i < scale; i++) {
			arr[i] = (char)(rand() % 26 + 'A');
		}
		clock_t start = clock();
		switch (func)
		{
		case FUNCTIONS::INSERT:
			insert_sort(arr, scale);
			break;
		case FUNCTIONS::SELECT:
			select_sort(arr, scale);
			break;
		case FUNCTIONS::SHELL:
			break;
		}
		clock_t end = clock();
		if (is_ascending_ordered(arr, scale)) {
			return double((end - start) / CLOCKS_PER_SEC);
			delete[]arr;
		}
		return -1.0;
	}
}