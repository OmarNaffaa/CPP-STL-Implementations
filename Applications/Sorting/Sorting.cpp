// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;

// cout use int mArray[] or int* mArray
void SelectionSort(int mArray[], int SIZE);
void BubbleSort(int mArray[], int SIZE);
void InsertionSort(int mArray[], int SIZE);
void BucketSort(int mArray[], int SIZE);
void QuickSort(int mArray[], int left, int right);
void MergeSort(int* a, int* b, int aSize, int bSize);

// supplemental functions
int AssignPivot(int a[], int left, int right);
int GetMax(int arr[], int n);
int CountSort(int arr[], int n, int exp, int cnt);
void Swap(int& a, int& b);
void Display(int mArray[]);
void AssignValues(int mArray[], int SIZE);


int main()
{
	int* selectionSort = new int[SIZE];
	int* bubbleSort = new int[SIZE];
	int* insertionSort = new int[SIZE];
	int* bucketSort = new int[SIZE];
	int* quickSort = new int[SIZE];
	int* mergeSort1 = new int[SIZE];
	int* mergeSort2 = new int[SIZE];

	// fill the arrays with random values
	AssignValues(selectionSort, SIZE);
	AssignValues(bubbleSort, SIZE);
	AssignValues(insertionSort, SIZE);
	AssignValues(bucketSort, SIZE);
	AssignValues(quickSort, SIZE);
	AssignValues(mergeSort1, SIZE);
	AssignValues(mergeSort2, SIZE);

	// Selection Sort
	cout << "Array before selection sort:" << endl;
	Display(selectionSort);
	cout << "\nArray after selection sort: ";
	SelectionSort(selectionSort, SIZE);
	Display(selectionSort);

	// Bubble Sort
	cout << "\nArray before bubble sort:" << endl;
	Display(bubbleSort);
	cout << "\nArray after bubble sort: ";
	BubbleSort(bubbleSort, SIZE);
	Display(bubbleSort);

	// Insertion Sort
	cout << "\nArray before insertion sort:" << endl;
	Display(insertionSort);
	cout << "\nArray after insertion sort: ";
	InsertionSort(insertionSort, SIZE);
	Display(insertionSort);

	// Bucket Sort
	cout << "\nArray before bucket sort:" << endl;
	Display(bucketSort);
	cout << "\nArray after bucket sort: ";
	BucketSort(bucketSort, SIZE);
	Display(bucketSort);

	// Quick Sort
	cout << "\nArray before quick sort:" << endl;
	Display(quickSort);
	cout << "\nArray after quick sort: " << endl;
	QuickSort(quickSort, 0, SIZE-1);
	Display(quickSort);

	// Heap Sort
	cout << "\nArrays before merge sort:" << endl;
	Display(mergeSort1);
	cout << endl;
	Display(mergeSort2);
	cout << "\nArray after merge sort: " << endl;
	MergeSort(mergeSort1, mergeSort2, SIZE, SIZE);
}

void SelectionSort(int mArray[], int SIZE)
{
	int count = 0; // keep track of how many iterations are needed

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (mArray[j] < mArray[i])
				Swap(mArray[i], mArray[j]);
			count++;
		}
	}

	cout << "Count: " << count << endl;
}

void BubbleSort(int mArray[], int SIZE)
{
	int count = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++)
		{
			if (mArray[j] > mArray[j + 1])
				Swap(mArray[j], mArray[j + 1]);
			count++;
		}
	}

	cout << "Count: " << count << endl;
}

void InsertionSort(int mArray[], int SIZE)
{
	int i = 1, count = 0;

	while (i < SIZE)
	{
		int j = i;

		while ((j > 0) && (mArray[j-1] > mArray[j]))
		{
			Swap(mArray[j], mArray[j-1]);
			j -= 1;
			count++;
		}

		i += 1;
	}

	cout << "Count: " << count << endl;
}

void BucketSort(int mArray[], int SIZE)
{
	int count = SIZE; // set to size to account for getmax function

	// get the maximum number to find max amount of digits
	int max = GetMax(mArray, SIZE);

	// use CountSort function on each bucket
	// (passing the place (ones, tens, etc) to search that digit
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		count += CountSort(mArray, SIZE, exp, count);
		count++;
	}

	cout << "Count: " << count << endl;
}

void QuickSort(int mArray[], int left, int right)
{
	if (left < right)
	{
		// assign the pivot value in the array
		int pivot = AssignPivot(mArray, left, right);

		QuickSort(mArray, left, pivot - 1);
		QuickSort(mArray, pivot + 1, right);
	}
}

void MergeSort(int a[], int b[], int aSize, int bSize)
{
	int xPos = 0, yPos = 0;

	// sort the arrays
	SelectionSort(a, aSize);
	SelectionSort(b, bSize);

	// create an array that can hold all elements
	int* mergedArray = new int[aSize + bSize];

	int i = 0;
	while (i < aSize && i < bSize)
	{
		int x = a[xPos];
		int y = b[yPos];

		if (x < y)
		{
			mergedArray[i] = a[xPos];
			xPos++;
		}
		else
		{
			mergedArray[i] = b[yPos];
			yPos++;
		}

		i++;
	}

	// display the merged array
	for (int i = 0; i < aSize+bSize; i++)
	{
		cout << "  " << mergedArray[i];
	}

	cout << endl;
}

// supplemental functions
int AssignPivot(int a[], int left, int right)
{
	// pivot (Element to be placed at right position)
	int pivot = a[right];

	int i = (left - 1);  // Index of smaller element

	for (int j = left; j <= right - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (a[j] <= pivot)
		{
			i++;    // increment index of smaller element
			Swap(a[i], a[j]);
		}
	}

	Swap(a[i + 1], a[right]);

	return (i + 1);
}

int GetMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

int CountSort(int arr[], int n, int exp, int cnt)
{
	int* output = new int[n]; // output array 
	int i, count[10] = { 0 };

	// see how many digits need to go into each bucket
	// (arr[i] / exp) % 10 determines index each number would go into
	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
		cnt++;
	}

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
		cnt++;
	}

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		cnt++;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
		cnt++;
	}

	return cnt;
}

void Swap(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void Display(int mArray[])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "  " << mArray[i];
	}

	cout << endl;
}

void AssignValues(int mArray[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		*(mArray + i) = rand() % 50;

	// OR use: mArray[i] = rand();
}