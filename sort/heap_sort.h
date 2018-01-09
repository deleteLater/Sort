#pragma once
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

class Heap_sort {
public:
	Heap_sort(int arr[], size_t nums) {
		datas = new int[nums + 1];
		this->size = 0;
		for (size_t i = 0; i < nums; i++) {
			insert(arr[i]);
		}
	}
	void insert(int& value) {
		datas[++size] = value;
		swim(size);
	}
	int deleteMin() {
		std::swap(datas[1], datas[size--]);
		sink(1);
		return datas[size + 1];
	}
private:
	void sink(size_t pos) {
		while (2 * pos <= size) {
			size_t ptr = 2 * pos;
			if (ptr < size && datas[ptr] > datas[ptr + 1])	ptr++;//judge ptr < size to avoid oversteping
			if (datas[pos] < datas[ptr])	break;
			std::swap(datas[pos], datas[ptr]);
			pos = ptr;
		}
	}
	void swim(size_t pos) {
		while (pos > 1 && datas[pos] < datas[pos/2]) {
			std::swap(datas[pos], datas[pos / 2]);
			pos /= 2;
		}
	}
	int* datas;
	size_t size;
};