#include "SortAlg.h"

void swap(int &a, int &b,int &gan) {
	int temp = a;
	a = b;
	b = temp;
	gan += 3;
}

/*
void swap(int &a, int &b) {
a = a + b;
b = a - b;
a = a - b;
}
*/

// ========================= Selection Sort ==============================
int* getMin(int *arr, int n, int &ss, int &gan) {
	int *temp = arr;
	gan++;
	for (int i = 1; i < n; i++)
		if (*temp > arr[i] && ++ss) {
			temp = arr + i;
			gan++;
		}
	return temp;
}

void SelectionSort(int *arr, int n, int &ss, int &gan) {
	for (int i = 0; i < n - 1; i++) {
		int *t = getMin(arr + i, n - i,ss,gan);
		if (t != arr + i && ++ss)
			swap(arr[i], *t, gan);
	}
}
// ===================================================================


// ========================= Insertion Sort ==============================
int BinarySearch(int *arr, int n, int x, int &ss, int &gan) {
	int left, right, mid;
	left = 0;
	right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (x < arr[mid] && ++ss)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return left;
}

void InsertionSort(int *arr, int n, int &ss, int &gan) {
	for (int i = 1; i < n; i++) {
		int x = arr[i];
		int pos = BinarySearch(arr, i, x,ss,gan);

		for (int j = i; j > pos; j--)
			arr[j] = arr[j - 1];

		arr[pos] = x;
	}
}
// ===================================================================


// ========================= Interchange Sort ==========================
void InterchangeSort(int *arr, int n, int &ss, int &gan) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j] && ++ss)
				swap(arr[i], arr[j],gan);
}
// =====================================================================


// ========================= Bubble Sort ==========================
void BubbleSort(int *arr, int n, int &ss, int &gan) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1] && ++ss)
				swap(arr[j], arr[j - 1],gan);
}
// =====================================================================


// ========================= Shell Sort ===============================
void ShellSort(int *arr, int n) {
	for (int size = n / 2; size > 0; size /= 2) {
		for (int i = size; i < n; i++) {
			int x = arr[i];

			int j = i;
			while (j >= size && arr[j - size] > x) {
				arr[j] = arr[j - size];
				j -= size;
			}

			arr[j] = x;
		}
	}
}
// ====================================================================


// ========================= Quick Sort ===============================
void QuickSort(int *arr, int l, int r, int &ss, int &gan) {
	if (l <= r && ++ss)
	{
		int x = arr[(l + r) / 2];

		int i = l;
		int j = r;
		gan += 3;
		while (i <= j && ++ss)
		{
			while (arr[i] < x && ++ss)
				i++;
			while (arr[j] > x && ++ss)
				j--;

			if (i <= j && ++ss)
			{
				swap(arr[i], arr[j], gan);
				i++;
				j--;
			}
		}

		if (l < j && ++ss)
			QuickSort(arr, l, j, ss, gan);
		if (r > i && ++ss)
			QuickSort(arr, i, r, ss, gan);
	}
}
// ====================================================================


// ======================== Merge Sort ================================
void Merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = (int*)malloc(sizeof(int)*n1),
		*R = (int*)malloc(sizeof(int)*n2);

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void MergeSort(int *arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}
// ====================================================================


// ======================== Radix Sort ================================
int SoChuSoCaoNhatMang(int *arr, int n) {
	int m = (int)log10(arr[0]) + 1;
	for (int i = 1; i < n; i++)
		if (m < (int)(log10(arr[i]) + 1))
			m = (int)log10(arr[i]) + 1;
	return m;
}

int ChuSoThuK(int x, int k) {
	int kq = x / (int)pow(10, k - 1);
	int m = (int)log10(x) + 1;
	kq = kq % 10;
	return kq;
}

void RadixSort(int *arr, int n) {
	int m = SoChuSoCaoNhatMang(arr, n);

	for (int i = 1; i <= m; i++) {
		IntQueue lo[10];
		for (int j = 0; j < n; j++)
			lo[ChuSoThuK(arr[j], i)].enQueue(arr[j]);	// Đưa các phần tử mảng vào các lô

		int pos = 0;
		for (int l = 0; l < 10; l++)					// Nối các lô thành mảng theo đúng thứ tự
			while (!lo[l].isEmpty()) {
				arr[pos] = lo[l].front->data;
				lo[l].deQueue();
				pos++;
			}
	}
}
// ====================================================================