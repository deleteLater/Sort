#pragma once
#include <utility>
#include "simple_sort.h"
#define SMALL_ARRAY_SIZE 15

size_t partition(int arr[], size_t lo, size_t hi) {
	size_t i = lo, j = hi + 1;
	int key = arr[lo];	//默认把切分区间的第一个元素作为key值
	/*
	Other Edition for partition:
	size_t i = lo,j = hi;
	key = arr[lo + (hi-lo)/2];
	while (i <= j) {
		while (arr[i] < key)	i++;
		while (arr[j] > key)	j--;
		if (i <= j) {
			std::swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	*/
	while (true) {
		while (arr[++i] < key) { if (i == hi) break; }
		while (arr[--j] > key) { if (j == lo) break; }
		if (i >= j)	break;
		std::swap(arr[i], arr[j]);
	}
	std::swap(arr[lo], arr[j]);
	return j;
}

/*快速排序*/
void _qsort(int arr[], size_t lo, size_t hi) {
	/*  arr[] --> Array to be sorted,
		lo  --> Starting index,
		hi  --> Ending index
	*/
	if ((hi - lo + 1) <= SMALL_ARRAY_SIZE) { insert_sort(arr, lo, hi); return;}
	size_t pivot = partition(arr, lo, hi);
	_qsort(arr, lo, pivot - 1);
	_qsort(arr, pivot + 1, hi);

	/*
	Non-Recursive Edition : Very slow on my computer...
	// Create an auxiliary stack
	stack<size_t> s;
	// push initial values of l and h to stack
	s.push(lo);
	s.push(hi);

	// Keep popping from stack while is not empty
	while (!s.empty())
	{
		// Pop hi and lo
		hi = s.top(); s.pop();
		lo = s.top(); s.pop();

		// Set pivot element at its correct position in sorted array
		size_t pivot = partition(arr, lo, hi);

		// If there are elements on left side of pivot, then push left side to stack
		if (pivot > lo + 1)
		{
			s.push(lo);
			s.push(pivot - 1);
		}

		// If there are elements on right side of pivot, then push right side to stack
		if (pivot < hi - 1)
		{
			s.push(pivot + 1);
			s.push(hi);
		}
	}
	*/
}