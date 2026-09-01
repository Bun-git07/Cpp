#include <iostream>
#include <chrono>
#include <array>
#include <vector>

using namespace std;
using namespace std::chrono;

// Helper function to merge two sorted subarrays: arr[left..mid] and arr[mid+1..right]
template <size_t N>
void merge(array<int, N> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary vectors to hold the split data
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements of L[]
    while (i < n1)
        arr[k++] = L[i++];

    // Copy any remaining elements of R[]
    while (j < n2)
        arr[k++] = R[j++];
}

// Recursive helper function that operates on index ranges
template <size_t N>
void mergeSortHelper(array<int, N> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Main interface matching your original signature
template <size_t N>
void mergeSort(array<int, N> &arr)
{
    if (arr.size() > 1)
    {
        mergeSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

int main()
{
    const size_t SIZE = 500;
    array<int, SIZE> arr;

    for (size_t i = 0; i < SIZE; ++i)
    {
        arr[i] = SIZE - i;
    }

    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();

    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";

    return 0;
}