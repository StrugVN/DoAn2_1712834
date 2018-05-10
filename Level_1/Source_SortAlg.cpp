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
	gan += 2;
	while (left <= right) {
		mid = (left + right) / 2;
		gan++;
		if (x < arr[mid] && ++ss) {
			right = mid - 1;
			gan++;
		}
		else {
			left = mid + 1;
			gan++;
		}
	}
	return left;
}

void InsertionSort(int *arr, int n, int &ss, int &gan) {
	for (int i = 1; i < n; i++) {
		int x = arr[i];
		gan++;
		int pos = BinarySearch(arr, i, x,ss,gan);
		gan++;
		for (int j = i; j > pos; j--) {
			arr[j] = arr[j - 1];
			gan++;
		}

		arr[pos] = x;
		gan++;
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
void ShellSort(int *arr, int n, int &ss, int &gan) {
	for (int size = n / 2; size > 0; size /= 2) {
		for (int i = size; i < n; i++) {
			int x = arr[i];
			gan++;
			int j = i;
			while (j >= size && arr[j - size] > x && ++ss) {
				arr[j] = arr[j - size];
				gan++;
				j -= size;
			}

			arr[j] = x;
			gan++;
		}
	}
}
// ====================================================================


// ========================= Quick Sort ===============================
void QuickSort(int *arr, int l, int r, int &ss, int &gan) {
	if (l <= r)
	{
		int x = arr[(l + r) / 2];

		int i = l;
		int j = r;
		gan += 3;
		while (i <= j)
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

		if (l < j)
			QuickSort(arr, l, j, ss, gan);
		if (r > i)
			QuickSort(arr, i, r, ss, gan);
	}
}
// ====================================================================


// ======================== Merge Sort ================================
void Merge(int arr[], int l, int m, int r, int &ss, int &gan) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	gan += 2;
	int *L = (int*)malloc(sizeof(int)*n1),
		*R = (int*)malloc(sizeof(int)*n2);

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		gan++;
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		gan++;
	}

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j] & ++ss) {
			arr[k] = L[i];
			gan++;
			i++;
		}
		else {
			arr[k] = R[j];
			gan++;
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		gan++;
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		gan++;
		j++;
		k++;
	}
	free(L);
	free(R);
}

void MergeSort(int *arr, int l, int r,int &ss,int &gan) {
	if (l < r) {
		int m = l + (r - l) / 2;
		gan++;
		MergeSort(arr, l, m,ss,gan);
		MergeSort(arr, m + 1, r,ss,gan);

		Merge(arr, l, m, r,ss,gan);
	}
}
// ====================================================================


// ======================== Radix Sort ================================
int SoChuSoCaoNhatMang(int *arr, int n, int &ss, int &gan) {
	int m = (int)log10(arr[0]) + 1;
	gan++;
	for (int i = 1; i < n; i++)
		if (m < (int)(log10(arr[i]) + 1) && ++ss) {
			m = (int)log10(arr[i]) + 1;
			gan++;
		}
	return m;
}

int ChuSoThuK(int x, int k, int &ss, int &gan) {
	int kq = x / (int)pow(10, k - 1);
	int m = (int)log10(x) + 1;
	kq = kq % 10;
	gan += 3;
	return kq;
}

void RadixSort(int *arr, int n, int &ss, int &gan) {
	int m = SoChuSoCaoNhatMang(arr, n,ss,gan);
	gan++;
	for (int i = 1; i <= m; i++) {
		IntQueue lo[10];
		for (int j = 0; j < n; j++) {
			lo[ChuSoThuK(arr[j], i, ss, gan)].enQueue(arr[j]);	// Đưa các phần tử mảng vào các lô
			gan++;
		}

		int pos = 0;
		for (int l = 0; l < 10; l++)					// Nối các lô thành mảng theo đúng thứ tự
			while (!lo[l].isEmpty() && ++ss) {
				arr[pos] = lo[l].front->data;
				lo[l].deQueue();
				gan++;
				pos++;
			}
	}
}
// ====================================================================

// ======================== Heap Sort =================================
void CreateMaxHeap(int *arr, int n, int i, int &ss, int &gan) {
	int max = i;			// Ngọn
	int l = 2 * i + 1;		// Lá trái
	int r = 2 * i + 2;		// Lá phải
	gan += 3;

	if (l < n && arr[l] > arr[max] && ++ss)		// Tìm node lớn nhất trong 3
		max = l;
	if (r < n && arr[r] > arr[max] && ++ss)
		max = r;

	if (max != i) {								// Nếu node lớn nhất không là ngọn
		swap(arr[i], arr[max],gan);				// Đảo node lớn nhất và ngọn
		CreateMaxHeap(arr, n, max,ss,gan);			// Đệ quy xét tiếp ngọn cũ tại vị trí node max cũ
	}
	// Kết thúc hàm ngọn được xét sẽ được đẩy xuống đến khi giá trị lớn hơn 2 lá của nó
}

void HeapSort(int arr[], int n, int &ss, int &gan) {
	for (int i = n / 2 - 1; i >= 0; i--)	// Bắt đầu tạo max heap từ ngọn của node cuối cùng <=> n/2-1
		CreateMaxHeap(arr, n, i,ss,gan);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i],gan);			// Xóa (Đẩy về cuối mảng, n giảm 1) ngọn cao nhất (giá trị max), đưa node cuối cùng lên
		CreateMaxHeap(arr, i, 0,ss,gan);	// Tạo max heap (đưa giá trị lớn nhất còn lại của mảng lên ngọn)
	}
}
// ====================================================================