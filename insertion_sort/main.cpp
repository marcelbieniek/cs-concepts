#include <iostream>
#include <array>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    std::cout << "[ ";
    for (const auto &el : arr)
    {
        std::cout << el << ", ";
    }
    std::cout << "]";
}

template <typename T, std::size_t N>
void insertionSort(std::array<T, N>& arr)
{
    const std::size_t n = arr.size();
    for (std::size_t i = 1; i < n; ++i)
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    std::array inputArray{5, 3, 23, 8, 65, 1};

    std::cout << "initial array: ";
    printArray(inputArray);
    std::cout << std::endl;

    insertionSort(inputArray);

    std::cout << "sorted array: ";
    printArray(inputArray);
    std::cout << std::endl;

    return 0;
}