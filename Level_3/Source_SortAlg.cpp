#include "SortAlg.h"

void swap(LargeInt &a, LargeInt &b, LargeInt& gan) {
	LargeInt temp = a;
	a = b;
	b = temp;
	gan++;
}

// ========================= Selection Sort ==============================
LargeInt getMin(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt temp = arr[0];
	gan++;
	for (int i = 1; i < n; i++)
		if (temp > arr[i] && ss++) {
			temp = arr[i];
			gan++;
		}
	return temp;
}

void SelectionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = 0; i < n - 1; i++) {
		LargeInt t = getMin(arr + i, n - i, ss, gan);
		if (t != arr[i] && ss++)
			swap(arr[i], t, gan);
	}
}
// ===================================================================


// ========================= Insertion Sort ==============================
LargeInt BinarySearch(LargeInt *arr, int n, LargeInt x, LargeInt &ss, LargeInt &gan) {
	int left, right, mid;
	left = 0;
	right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (x < arr[mid] && ss++) {
			right = mid - 1;
		}
		else {
			left = mid + 1;

		}
	}
	return arr[left];
}

void InsertionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = 1; i < n; i++) {
		LargeInt x = arr[i];
		gan++;
		LargeInt pos = BinarySearch(arr, i, x, ss, gan);

		for (int j = i; arr[j] != pos; j--) {
			arr[j] = arr[j - 1];
			gan++;
		}

		pos = x;
		gan++;
	}
}
// ===================================================================


// ========================= Interchange Sort ==========================
void InterchangeSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {	// Đã chạy
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j] && ss++)
				swap(arr[i], arr[j], gan);
}
// =====================================================================


// ========================= Bubble Sort ==========================
void BubbleSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {		// Đã chạy
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1] && ss++)
				swap(arr[j], arr[j - 1], gan);
}
// =====================================================================


// ========================= Shell Sort ===============================
void ShellSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {		// Đã chạy ?
	for (int size = n / 2; size > 0; size /= 2) {
		for (int i = size; i < n; i++) {
			LargeInt x = arr[i];
			gan++;
			int j = i;
			while (j >= size && arr[j - size] > x && ss++) {
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
void QuickSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan) {
	if (l <= r)
	{
		LargeInt x = arr[(l + r) / 2];

		int i = l;
		int j = r;

		while (i <= j)
		{
			while (arr[i] < x && ss++)
				i++;
			while (arr[j] > x && ss++)
				j--;

			if (i <= j)
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
void Merge(LargeInt *arr, int l, int m, int r, LargeInt &ss, LargeInt &gan) {	// Đã chạy
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	LargeInt *L = (LargeInt*)malloc(sizeof(LargeInt)*n1),
			*R = (LargeInt*)malloc(sizeof(LargeInt)*n2);

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
		if (L[i] <= R[j] && ss++) {
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

void MergeSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan) {
	if (l < r) {
		int m = l + (r - l) / 2;
		gan++;
		MergeSort(arr, l, m, ss, gan);
		MergeSort(arr, m + 1, r, ss, gan);

		Merge(arr, l, m, r, ss, gan);
	}
}
// ====================================================================


// ======================== Radix Sort ================================
LargeInt getMax(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt temp = arr[0];
	gan++;
	for (int i = 1; i < n; i++)
		if (temp < arr[i] && ss++) {
			temp = arr[i];
			gan++;
		}
	return temp;
}

int getLastDigit(LargeInt a) {
	return a.list.head->data % 10;
}

void CountSort(LargeInt *arr, int n, LargeInt exp, LargeInt &ss, LargeInt &gan) {
	LargeInt *output = (LargeInt*)malloc(sizeof*output *n);
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++) {
		count[getLastDigit(arr[i] / exp)]++;
		gan++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
		gan++;
	}
	for (i = n - 1; i >= 0; i--) {
		output[count[getLastDigit(arr[i] / exp)] - 1] = arr[i];
		count[getLastDigit(arr[i] / exp)]--;
		gan += 2;
	}

	for (int i = 0; i < n; i++)
		arr[i].eraseData();

	for (i = 0; i < n; i++) {
		arr[i] = output[i];
		gan++;
	}
}

void RadixSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt m = getMax(arr, n, ss, gan);

	LargeInt exp;
	exp.getFromStr("1");
	for (; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp, ss, gan);
}
// ====================================================================

// ======================== Heap Sort =================================
void CreateMaxHeap(LargeInt *arr, int n, int i, LargeInt &ss, LargeInt &gan) {
	int max = i;			// Ngọn
	int l = 2 * i + 1;		// Lá trái
	int r = 2 * i + 2;		// Lá phải
	gan += 3;

	if (l < n && arr[l] > arr[max] && ss++)		// Tìm node lớn nhất trong 3
		max = l;
	if (r < n && arr[r] > arr[max] && ss++)
		max = r;

	if (max != i) {								// Nếu node lớn nhất không là ngọn
		swap(arr[i], arr[max], gan);				// Đảo node lớn nhất và ngọn
		CreateMaxHeap(arr, n, max, ss, gan);			// Đệ quy xét tiếp ngọn cũ tại vị trí node max cũ
	}
	// Kết thúc hàm ngọn được xét sẽ được đẩy xuống đến khi giá trị lớn hơn 2 lá của nó
}

void HeapSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = n / 2 - 1; i >= 0; i--)	// Bắt đầu tạo max heap từ ngọn của node cuối cùng <=> n/2-1
		CreateMaxHeap(arr, n, i, ss, gan);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i], gan);			// Xóa (Đẩy về cuối mảng, n giảm 1) ngọn cao nhất (giá trị max), đưa node cuối cùng lên
		CreateMaxHeap(arr, i, 0, ss, gan);	// Tạo max heap (đưa giá trị lớn nhất còn lại của mảng lên ngọn)
	}
}
// ====================================================================

// ============================ Shaker sort ===========================
void ShakerSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1] && ss++) {
				swap(arr[i], arr[i + 1], gan);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1] && ss++) {
				swap(arr[i], arr[i + 1], gan);
				swapped = true;
			}
		}

		++start;
	}
}
//=================================================