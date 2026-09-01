#include <iostream>
#include <chrono>
#include <array>
#include <utility> // for std::swap

using namespace std;
using namespace std::chrono;

template <size_t N>
void bubbleSort(array<int, N> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements correctly
                std::swap(arr[j], arr[j + 1]);
            }
        }
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
    bubbleSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();
    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";

    return 0;
}