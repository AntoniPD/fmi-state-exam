//
// Created by Antoni Dobrenov on 1.07.23.
//

#include "iostream"

bool find(int value, int* arr, size_t size)
{
    if (size == 0)
        return false;

    size_t mid = size / 2;
    if (value == arr[mid])
        return true;
    if (value < arr[mid])
        return find(value, arr, mid);
    else
        return find(value, arr + mid + 1, size - mid + 1);
}

void insertionSort(int arr[], int size) {
    int j, key;
    for (int i = 0; i < size; i ++) {
        key = arr[i];
        j = i - 1;
        while( j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil)
{
    ReturnType result = nil;
    for (size_t i = 0; i < size; ++i)
        result = op(result, arr[i]);
    return result;
}

int op(char Digit, int Result)
{
    return (Result * 10) + (Digit - '0');
}

int str_to_int(const char* str)
{
    return (str == nullptr) ? 0 : fold_left(str, strlen(str), op, 0);
}

int main() {
    int arr[10] = {5,4,10,2,3,22,9,11,7, 6};
    insertionSort(arr, 10);
    for (int i = 0; i < 10; i ++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << find(333, arr, 10); // 0
    std::cout << find(3, arr, 10) << std::endl; // 0

    std::cout << str_to_int("12345");

    return 0;
}