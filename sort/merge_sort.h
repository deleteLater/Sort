#pragma once
#include <iostream>

/*ԭ�ع鲢����:�ռ临�Ӷ�O(N)*/
template <class T>
class Merge_Sort {
public:
	Merge_Sort() {}
	void sort(T arr[], size_t nums) {
		Merge_sort(arr,0,nums-1);
	}
	void Merge_sort(T arr[], size_t lo, size_t hi) {
		/*
		  �������µݹ�汾:
		  void Merge_sort(T arr[], size_t lo, size_t hi){
		  		if (hi <= lo) return;
				//if(hi-lo+1 <= 20) use insert_sort
				size_t mid = lo + (hi - lo) / 2;
				Merge_sort(arr, lo, mid);
				Merge_sort(arr, mid + 1, hi);
				merge(arr, lo, mid, hi);
		  }
		*/

		/*��������*/
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

	/*
	//��ԭ�صݹ�����merge����
	void merge(T arr[], size_t lo, size_t mid, size_t hi) {
		//NOTICE:�����midӦ��ָ��ǰ�����������ֵ
		size_t i = lo;
		size_t j = mid + 1;
		for (size_t k = lo; k <= hi; k++)
			aux[k] = arr[k];
		for (size_t k = lo; k <= hi; k++) {
			if (i > mid)				arr[k] = aux[j++];//����Ԫ���þ�
			else if (j > hi)			arr[k] = aux[i++];//�Ұ��Ԫ���þ�
			else if (aux[i] > aux[j])	arr[k] = aux[j++];//���Ԫ�ش�
			else						arr[k] = aux[i++];//�ұ�Ԫ�ش�
		}
	}
	*/

private:
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
};