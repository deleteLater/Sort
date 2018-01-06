#pragma once
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"

namespace sort {
	enum class FUNCTIONS {SELECT,INSERT,SHELL,MERGE};

	/*
		ѡ������:
			1.Ч�ʺ������޹�
			2.���ڹ�ģΪN�ĵ�����,����Ƚ�N(N-1)/2��,����N��
			3.���ݵ��ƶ������ٵ�,ֻ��N�ν���
			4.��ֱ��
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
		��������:
			1.Ч�ʺ��������
			2.���ڹ�ģΪN������(�޴����ظ������),��������Ƚ�N(N-1)/2��,����N(N-1)/2��,ƽ�������ÿ��Ԫ�ض���������ƶ��������ĳ���,��������һ��
			4.���ڽӽ�����(������������)��������˵,����ʱ����ܽӽ����Լ���
			5.��ֱ��
	*/

	template <class T>
	void insert_sort(T arr[], size_t nums) {
		/*
			����һ�ְ汾:
			//Ԫ�ؽ����������������еĵ�����,�Ƚϴ������ڵ��ڵ�����,С�ڵ��ڵ�����+���鳤��-1
				for(size_t i = 1; i < N; i++){
					for(size_t j = i; j > 0 && arr[j] < arr[j-1]; j--)
						std::swap(arr[j],arr[j-1]);
				}
		*/
		for (size_t i = 1; i < nums; i++) {
			//Ԫ���ƶ���������ÿ�鵹�õļ���ĺ�
			T insert_value = arr[i];
			size_t j = i - 1;
			for (; j >= 0 && arr[j] > insert_value; j--)
				arr[j+1] = arr[j];
			arr[j + 1] = insert_value;
		}
	}
	
	/*
		ϣ������:
			1.���ڲ�������,�Բ��������һ���Ľ��汾
			2."����Ψһ�޷�׼ȷ������������������������������򷽷�" --- �㷨���İ�P163
			3.��������Ľ�����˼��:���ڲ��������������˵,��������Ч�ʷǳ��ɹ�,������ֱ������֮ǰ,���������һЩ����ʹ�䲿������
			4.ϣ������˼��:ʹ������������Ϊh(h��һ����������)������
			5.ϣ������:��4����,h������ɵ����оͽ�ϣ������
			6.�ֽ�(1/6/2018)��δ�ҳ�һ��"��õ�"��ϣ������
			7.������õ�ϣ�������������㷨���İ�:1/2*(3^k-1),��N/3�ݼ���һ
	*/

	template <class T>
	void shell_sort(T arr[],size_t nums) {
		size_t h = 1;
		while (h < nums / 3) h = 3 * h + 1;//����������ֵ(��һ�η����ĵ�һ�����һ��Ԫ������λ��)
		while (h >= 1) {
			//insert_sort
			for (size_t i = h; i < nums; i++) {
				for (size_t j = i; j >= h && arr[j] < arr[j - h]; j -= h)
					std::swap(arr[j],arr[j-h]);
			}
			h = h / 3;
		}
	}

	template <class T>
	void merge_sort(T arr[], size_t nums) {
		Merge_Sort<T> ms;
		ms.sort(arr, nums);
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
			arr[i] = rand();
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
			shell_sort(arr, scale);
			break;
		case FUNCTIONS::MERGE:
			merge_sort(arr, scale);
			break;
		}
		clock_t end = clock();
		//check if sort successfully
		if (is_ascending_ordered(arr, scale)) {
			return double((end - start));
			delete[]arr;
		}
		return -1.0;
	}
	
}