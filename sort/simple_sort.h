#pragma once
#include <utility>
//TODO:improvement

/*
	选择排序:
		1.效率和输入无关
		2.对于规模为N的的输入,共需比较N(N-1)/2次,交换N次
		3.数据的移动是最少的,只需N次交换
		4.简单直观
*/

void select_sort(int arr[], size_t lo,size_t hi) {
	for (size_t i = lo; i <= hi; i++) {
		size_t min = i;
		for (size_t j = i; j <= hi; j++) {
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
		3.对于接近有序(倒置数量很少)的数组来说,排序时间可能接近线性级别
		4.简单直观
*/

void insert_sort(int arr[], size_t lo,size_t hi) {
	/*
	另外一种版本:
	//元素交换次数等于数组中的倒置数,比较次数大于等于倒置数,小于等于倒置数+数组长度-1
	for(size_t i = 1; i < N; i++){
		for(size_t j = i; j > 0 && arr[j] < arr[j-1]; j--)
			std::swap(arr[j],arr[j-1]);
	}
	*/
	for (size_t i = lo + 1; i <= hi; i++) {
		//元素移动次数等于每组倒置的间隔的和
		int insert_value = arr[i];
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
		6.现今(1/6/2018)还未找出一个任意情况下"最好的"的希尔序列
		7.这里采用的希尔序列来自于算法第四版:1/2*(3^k-1),从N/3递减至一
*/

void shell_sort(int arr[], size_t lo,size_t hi) {
	size_t h = 1;
	while (h < (hi - lo + 1) / 3) h = 3 * h + 1;//获得最大增量值(第一次分组后的第一组最后一个元素所在位置)
	while (h >= 1) {
		//insert_sort
		for (size_t i = h; i <= hi; i++) {
			//插入arr[i]
			for (size_t j = i; j >= h && arr[j] < arr[j - h]; j -= h)
				std::swap(arr[j], arr[j - h]);
		}
		h = h / 3;
	}
}