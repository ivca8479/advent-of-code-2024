#include "array_helpers.hpp"



int get_min(int arr[], int size)
{
    int min = INT_MAX;
    int min_index = 1;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }
    arr[min_index] = INT_MAX;
    return min;
}

void print_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}