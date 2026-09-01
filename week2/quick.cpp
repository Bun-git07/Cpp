#include <iostream>
#include <chrono>
#include <array>
#include <utility> // for std::swap

using namespace std;
using namespace std::chrono;

template <size_t N >
int partition(array<int, N> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <size_t N>
void quickSortHelper(array<int, N> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

template <size_t N>
void quickSort(array<int, N> &arr)
{
    if (arr.size() > 1)
    {
        quickSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
    }
}

int main()
{
    const size_t SIZE = 500;
    array<int, SIZE> arr;

    // 1. Fill the array BEFORE starting the clock
    for (size_t i = 0; i < SIZE; ++i)
    {
        arr[i] = SIZE - i;
    }

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();
    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";

    return 0;
}