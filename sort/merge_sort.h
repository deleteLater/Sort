#pragma once
#include <iostream>

/*非原地归并排序:空间复杂度O(n)*/
template <class T>
class Merge_Sort {
public:
	Merge_Sort() {}
	void sort(T arr[], size_t nums) {
		aux = new T[nums];
		sort(arr,0,nums-1);
	}
private:
	T * aux;
	void sort(T arr[], size_t lo, size_t hi) {
		/*由上自下的递归版本
		if (hi <= lo) return;
		//if(hi-lo+1 <= 20) use insert_sort
		size_t mid = lo + (hi - lo) / 2;
		sort(arr, lo, mid);
		sort(arr, mid + 1, hi);
		merge(arr, lo, mid, hi);
		*/

		//由下自上的非递归版本
		size_t N = hi - lo + 1;
		for (size_t sz = 1; sz < N; sz *= 2) {
			size_t grouping_size = 2 * sz;
			size_t hi = 0;
			for (size_t lo = 0; lo < N - sz; lo += grouping_size) {
				hi = lo + grouping_size - 1;
				if (hi > N - 1)	hi = N - 1;
				merge(arr, lo, lo + sz - 1, hi);
			}
		}
	}
	void merge(T arr[], size_t lo, size_t mid, size_t hi) {
		//NOTICE:这里的mid应该指向前半个分组的最大值
		size_t i = lo;
		size_t j = mid + 1;
		for (size_t k = lo; k <= hi; k++)
			aux[k] = arr[k];
		for (size_t k = lo; k <= hi; k++) {
			if (i > mid)				arr[k] = aux[j++];//左半边元素用尽
			else if (j > hi)			arr[k] = aux[i++];//右半边元素用尽
			else if (aux[i] > aux[j])	arr[k] = aux[j++];//左边元素大
			else						arr[k] = aux[i++];//右边元素大
		}
	}

	/*
	原地归并排序:
		void merge(T arr[], size_t lo, size_t mi, size_t hi) {
		size_t i = lo;
		size_t j = mi + 1;
		size_t old_j{ j };
		while (i < j && j <= hi) {
			while (i < j && arr[i] <= arr[j])	i++;
			old_j = j;
			while (j <= hi && arr[j] <= arr[i])	j++;
			swap_memoryValues(&arr[i], old_j - i, j - old_j);
			i += (j - old_j);//it's IMPORTANT
		}
	}
	void reverse(T arr[], int size) {
		int left = 0;
		int right = size - 1;
		while (left < right) {
			T tmp{ arr[left] };
			arr[left++] = arr[right];
			arr[right--] = tmp;
		}
	}
	void swap_memoryValues(T arr[], size_t first_block_size, size_t second_block_size) {
		reverse(arr, first_block_size);
		reverse(arr + first_block_size, second_block_size);
		reverse(arr, first_block_size + second_block_size);
	}
	*/
};