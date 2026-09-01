#include <iostream>
#include <chrono>
#include <array>
using namespace std;
using namespace std::chrono;
template <size_t N>
void insertionSort(array<int, N> &arr)
{
    int n = arr.size();
    // TODO: implement insertion sort
    // Hint: for i from 1 to n-1, save arr[i] as key, shift elements > key rightward
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    array<int, 7> arr = {5, 3, 8, 1, 2, 6, 7};
    // start timer
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    // STOP TIMER
    auto end = chrono::high_resolution_clock::now();
    // CALCULATE TIME
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Sorting time: " << duration.count() << " microseconds\n";
    return 0;
}