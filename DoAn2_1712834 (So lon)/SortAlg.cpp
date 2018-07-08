#include "SortAlg.h"

void swap(LargeInt &a, LargeInt &b, LargeInt& gan) {	// Vì nội dung của a b là các con trỏ, hàm này <=> đổi địa chỉ trỏ của 2 con trỏ và ko gây rò rỉ
	LargeInt temp = a;
	a = b;
	b = temp;
	gan++;
}

// ========================= Selection Sort ==============================
// Check:	Địa chỉ của các con trỏ bị thay đổi, không tạo thêm bất kì LargeInt nào => Ko rò rỉ
LargeInt* getMin(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt* temp = arr;
	gan++;
	for (int i = 1; i < n; i++)
		if (*temp > arr[i] && ss++) {
			temp = arr + i;
			gan++;
		}
	return temp;
}

void SelectionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = 0; i < n - 1; i++) {
		LargeInt *t = getMin(arr + i, n - i, ss, gan);
		gan++;
		if (*t != arr[i] && ss++)
			swap(arr[i], *t, gan);
	}
}
// ===================================================================


// ========================= Insertion Sort ==============================
// Check:	x mới được tạo sẽ bị xóa ở j = i, arr[j-1] mới sẽ bị xóa ở vòng lặp tiếp theo hoặc tại pos => Ko rò rỉ
int BinarySearch(LargeInt *arr, int n, LargeInt x, LargeInt &ss, LargeInt &gan) {
	int left, right, mid;
	left = 0;
	right = n - 1;
	gan += 2;
	while (left <= right) {
		mid = (left + right) / 2;

		if (x < arr[mid] && ss++) {
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

void InsertionSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = 1; i < n; i++) {
		LargeInt x = arr[i].Duplicate();
		gan++;

		int pos = BinarySearch(arr, i, x, ss, gan);
		gan++;

		for (int j = i; j != pos; j--) {
			arr[j].eraseData();
			arr[j] = arr[j - 1].Duplicate();
			gan++;
		}
		arr[pos].eraseData();
		arr[pos] = x;
		gan++;
	}
}
// ===================================================================


// ========================= Bubble Sort ==========================
// Check:	Không tạo thêm LargeInt => Không rò rỉ
void BubbleSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[j - 1] && ss++)
				swap(arr[j], arr[j - 1], gan);
}
// =====================================================================


// ========================= Shell Sort ===============================
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi giữa các địa chỉ => Không rò rỉ
void ShellSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	for (int size = n / 2; size > 0; size /= 2) {
		for (int i = size; i < n; i++) {
			LargeInt x = arr[i];
			gan++;
			int j = i;
			gan++;
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
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi giữa các địa chỉ => Không rò rỉ
void QuickSort(LargeInt *arr, int l, int r, LargeInt &ss, LargeInt &gan) {
	if (l <= r) {
		LargeInt x = arr[r];
		int i = l - 1;
		gan += 2;

		for (int j = l; j < r; j++) {
			if (arr[j] <= x && ss++) {
				i++;
				swap(arr[i], arr[j], gan);
			}
		}
		swap(arr[i + 1], arr[r], gan);

		int p = i + 1;
		gan++;
		QuickSort(arr, l, p - 1, ss, gan);
		QuickSort(arr, p + 1, r, ss, gan);
	}
}
// ====================================================================


// ======================== Merge Sort ================================
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi và copy giữa các địa chỉ => Không rò rỉ
void Merge(LargeInt *arr, int l, int m, int r, LargeInt &ss, LargeInt &gan) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	gan += 2;
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
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi và copy giữa các địa chỉ => Không rò rỉ
LargeInt *getMax(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt *temp = arr;
	gan++;
	for (int i = 1; i < n; i++)
		if (*temp < arr[i] && ss++) {
			temp = arr + i;
			gan++;
		}
	return temp;
}

int getMaxDigit(LargeInt a, LargeInt &ss, LargeInt &gan) {
	int kq = 0;
	LargeInt temp = a.Duplicate();

	LongLongNode *p = temp.list.head;
	gan += 2;
	while (p->next) {
		kq += 9;
		p = p->next;
		gan += 2;
	}
	while (p->data != 0) {
		p->data /= 10;
		kq++;
		gan++;
	}

	temp.eraseData();

	return kq;
}

int getDitgitAtIndex(LargeInt a, int index, LargeInt &ss, LargeInt &gan) {
	LongLongNode *p = a.list.head;

	while (index > 9) {
		p = p->next;
		gan++;
		if (p == NULL)
			return 0;
		index -= 9;
	}

	return (p->data / (int)pow(10,index-1)) % 10;
}

void CountSort(LargeInt *arr, int n, int index, LargeInt &ss, LargeInt &gan) {
	LargeInt *output = (LargeInt*)malloc(sizeof*output *n);
	int i, count[10] = { 0 };
	int *IndexDigitOfArr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		IndexDigitOfArr[i] = getDitgitAtIndex(arr[i], index, ss, gan);
		gan++;
	}

	for (i = 0; i < n; i++) {
		count[IndexDigitOfArr[i]]++;
		gan++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
		gan++;
	}
	for (i = n - 1; i >= 0; i--) {
		output[count[IndexDigitOfArr[i]] - 1] = arr[i];
		count[IndexDigitOfArr[i]]--;
		gan += 2;
	}

	for (i = 0; i < n; i++) {
		arr[i] = output[i];
		gan++;
	}

	free(output);
	free(IndexDigitOfArr);
}

void RadixSort(LargeInt *arr, int n, LargeInt &ss, LargeInt &gan) {
	LargeInt *m = getMax(arr, n, ss, gan);

	int max = getMaxDigit(*m,ss,gan);
	gan++;

	for (int i = 1; i <= max; i++)
		CountSort(arr, n, i, ss, gan);
}
// ====================================================================

// ======================== Heap Sort =================================
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi giữa các địa chỉ => Không rò rỉ
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
// Check:	Không tạo thêm LargeInt, chỉ chuyển đổi giữa các địa chỉ = > Không rò rỉ
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