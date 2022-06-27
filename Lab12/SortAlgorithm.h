#ifndef SORTALGORITHM
#define SORTALGORITHM
#include <iostream>
#include <string>
using namespace std;

// task 1

template <class T>
class Sort {

	protected:

		int size;

		void swap(T*, T*);
		void merge(T arr[], T, T, T);
		void countSort(T arr[], T);
		void heapify(T arr[], T, T);
		int patrition(T arr[], int, int);
		int getMax(T arr[]);

	public:

		// constructor
		Sort(int);
		Sort();

		// prototype functions/members' functions
		void bubbleSort(T arr[]);
		void insertionSort(T arr[]);
		void mergeSort(T arr[], T, T);
		void quickSort(T arr[], int, int);
		void countingSort(T arr[]);
		void radixSort(T arr[]);
		void heapSort(T arr[]);
		void printArray(T arr[]);
};

// constructor
template <class T>
Sort<T>::Sort(int s) {

	this->size = s;
}

template <class T>
Sort<T>::Sort() {

	this->size = 50;
}

// swap function for the bubble sort
template <class T>
void Sort<T>::swap(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}

//bubble sort algorithm
template <class T>
void Sort<T>::bubbleSort(T arr[]) {

	bool swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			// compare and swap
			if (arr[j] >= arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
	}
}

//insertion algorithm
template <class T>
void Sort<T>::insertionSort(T arr[]) {

	for (int i = 0; i < size; i++) {
		T key = arr[i];
		int j = i - 1;
		/*
		* move the number to position greater than key
		* which is one ahead of their current position
		*/
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		// return the item at the correct index
		arr[j + 1] = key;
	}
}

/*
* This function takes last element as pivot, places the pivot
* element at its correct position in sorted array, and paces all
* smaller to left of pivot and all greater elements to right to pivot
*/
template <class T>
int Sort<T>::patrition(T arr[], int low, int high) {

	T pivot = arr[high]; // pivot
	int i = (low - 1); // index of smaller element and indicates the right

	for (int j = low; j <= high - 1; j++) {
		// if current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
* The main function that implements quicksort
* arr[] --> array to be sorted
*/
template <class T>
void Sort<T>::quickSort(T arr[], int start, int end) {

	if (start < end) {
		// finding the patrition
		int p = patrition(arr, start, end);

		// separately sort elements before patrition and after it
		quickSort(arr, start, p - 1);
		quickSort(arr, p + 1, end);
	}
}

// a get max function for the counting sort
// to get a max number for generating the max range
template <class T>
int Sort<T>::getMax(T arr[]) {

	int max = -9999;
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

// counting sort
template <class T>
void Sort<T>::countingSort(T arr[]) {

	T* result = new T[size + 1];
	int max = getMax(arr);
	T* count = new T[max + 1]; // creat count array with size[max + 1]

	for (int i = 0; i <= max; ++i) {
		count[i] = 0; // fill count array with 0
	}

	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1]; // find cumulative frequency
	}

	// find the index of each element of original array in count, place them in result
	for (int i = size - 1; i >= 0; i--) {
		result[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--; // decrease count for the same numbers
	}

	for (int i = 0; i < size; i++) {
		arr[i] = result[i]; // store the sorted elements into main array
	}
}

// merge two subarrays L and M into arr
template <class T>
void Sort<T>::merge(T arr[], T p, T q, T r) {

	// create L <- A[p..q] and M <- A[q+1..r]
	T n1 = q - p + 1;
	T n2 = r - q;

	T* L = new T[n1];
	T* M = new T[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (int j = 0; j < n2; j++) {
		M[j] = arr[q + 1 + j];
	}

	// maintain current index of sub-arrays and main array
	int i = 0;
	int j = 0;
	int k = p;

	// until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// when we run out of elements in either L or M
	// pick up the remaining elements and put in A[p..r]
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

// divide the array into two subarrays, sort them and merge them
template <class T>
void Sort<T>::mergeSort(T arr[], T l, T r) {

	if (l < r) {
		// m is the point where array is divided into two subarrays
		T m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// merge the sorted subarrays
		merge(arr, l, m, r);
	}
}

// a function to do counting sort of arr[] according to
// the digit represented by exp
template <class T>
void Sort<T>::countSort(T arr[], T exp) {

	T* output = new T[size];
	int max = getMax(arr);
	T* count = new T[max];
	for (int i = 0; i <= max; ++i) {
		count[i] = 0; // fill count with 0
	}

	// store count of occurences in count[]
	for (int i = 0; i < size; i++) {
		count[(arr[i] / exp) % 10]++;
	}

	// change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	// build the output array
	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

// radix sort
template <class T>
void Sort<T>::radixSort(T arr[]) {
	
	// find the maximum number to know number of digits
	int m = getMax(arr);

	// do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, exp);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
template <class T>
void Sort<T>::heapify(T arr[], T n, T root) {

	T largest = root; // initialize largest as root
	T left = 2 * root + 1;
	T right = 2 * root + 2;

	// if left child is larger than root
	if (left < n && arr[left] > arr[largest]) largest = left;

	// if right child is larger than largest so far
	if (right < n && arr[right] > arr[largest]) largest = right;

	// if largest is not root
	if (largest != root) {
		swap(&arr[root], &arr[largest]);

		heapify(arr, n, largest);
	}
}

// heap sort
template <class T>
void Sort<T>::heapSort(T arr[]) {

	// build heap (rearrange array)
	for (int i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);

	// one by one extract an element from heap
	for (int i = size - 1; i >= 0; i--) {
		// move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// print out the array
template <class T>
void Sort<T>::printArray(T arr[]) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

#endif