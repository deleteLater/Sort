#pragma once
#include <stdlib.h>
#include <time.h>

namespace sort {
	enum class FUNCTIONS {SELECT,INSERT,SHELL};

	/*
		选择排序:
			1.效率和输入无关
			2.对于规模为N的的输入,共需比较N(N-1)/2次,交换N次
			3.数据的移动是最少的,只需N次交换
			4.简单直观
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
	/*
		插入排序:
			1.效率和输入相关
			2.对于规模为N的输入(无大量重复情况下),最坏情况下需比较N(N-1)/2次,交换N(N-1)/2次,平均情况下每个元素都可能向后移动半个数组的长度,即最坏情况的一半
			3.对于接近有序的数组来说,排序时间可能接近线性级别
			4.简单直观
	*/
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
	
	/*
		希尔排序:
			1.基于插入排序,对插入排序的一个改进版本
			2."我们唯一无法准确描述其对乱序的数组的性能特征的排序方法" --- 算法第四版P163
			3.插入排序改进核心思想:对于部分有序的数组来说,插入排序效率非常可观,所以在直接排序之前,对数组进行一些处理使其部分有序
			4.希尔排序思想:使数组中任意间隔为h(h是一个有序数组)的有序化
			5.希尔序列:据4所述,h数组组成的序列就叫希尔序列
			6.现今还未找出一个"最好的"的希尔序列
	*/
	template <class T>
	void shell_sort(T arr[],size_t nums) {

	}

	/*O(N)*/
	template <class T>
	void shuffle(T arr[], size_t nums) {
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