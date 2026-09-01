#include <iostream>
#include <chrono>
#include <array>
using namespace std;
using namespace std::chrono;
template <size_t N>
void selectionSort(array<int, N> &arr)
{
    int n = arr.size();
    // TODO: implement selection sort
    // Hint: for each i, track minIndex, then swap arr[i] and arr[minIndex]
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
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
    selectionSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();
    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";

    return 0;
}