#pragma once
/*
	�鲢����:
*/
template <class T>
class Merge_Sort {
public:
	Merge_Sort() {}
	void sort(T arr[], size_t nums) {
		aux = new T[nums];
		Merge_sort(arr,0,nums-1);
	}
	void Merge_sort(T arr[], size_t lo, size_t hi) {
		/*
		  RecursiveEdition:
		  void Merge_sort(T arr[], size_t lo, size_t hi){
		  		if (hi <= lo) return;
				//if(hi-lo+1 <= 20) use insert_sort
				size_t mid = lo + (hi - lo) / 2;
				Merge_sort(arr, lo, mid);
				Merge_sort(arr, mid + 1, hi);
				merge(arr, lo, mid, hi);
		  }
		*/
		/*���ݹ鲢�ݹ��㷨����������������������*/
		size_t N = hi - lo + 1;
		for (size_t sz = 1; sz < N; sz *= 2) {
			size_t spacing = 2*sz - 1;
			for (size_t lo = 0; lo < N - sz; lo += (spacing+1)) {
				size_t new_hi = lo + spacing;
				if (N - 1 < new_hi)
					new_hi = N - 1;
				merge(arr, lo, lo + sz - 1, new_hi);
			}

		}
	}
	void merge(T arr[], size_t lo, size_t mid, size_t hi) {
		size_t i = lo;
		size_t j = mid + 1;
		for (size_t k = lo; k <= hi; k++)
			aux[k] = arr[k];
		for (size_t k = lo; k <= hi; k++) {
			if		(i > mid)			arr[k] = aux[j++];//����Ԫ���þ�
			else if (j > hi)			arr[k] = aux[i++];//�Ұ��Ԫ���þ�
			else if (aux[i] > aux[j])	arr[k] = aux[j++];//���Ԫ�ش�
			else						arr[k] = aux[i++];//�ұ�Ԫ�ش�
		}
	}
	~Merge_Sort()
	{
		if(aux)
			delete[]aux;
	}
private:
	T* aux;
};