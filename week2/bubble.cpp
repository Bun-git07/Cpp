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
    // TODO: implement bubble sort
    // Hint: nested loop, swap arr[j] and arr[j+1] if arr[j] > arr[j+1]
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    // Specify the size parameter for std::array
    array<int, 7> arr = {5, 3, 8, 1, 2,6,7};

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();
    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";
    return 0;
}