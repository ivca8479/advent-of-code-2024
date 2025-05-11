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

int find_count(int arr[], int num, int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            count++;
        }
    }
    return count;
}

void print_vector(const std::vector<std::vector<int>>& data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << "Row " << i << ": ";
        for (int num : data[i])
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

bool gradually_increasing(std::vector<int> row)
{
    for(int i = 1; i < row.size(); i++)
    {
      
        int diff = row[i] - row[i-1];
        if(diff <= 0)
        {
            std::cout << row[i] << " <= " << row[i-1] << " not gradually increasing" << std::endl;
            return false;
        }
        else if(diff > 3)
        {
            std::cout << "The difference between " << row[i] << " and " << row[i-1] << " is greater than 3" << " not gradually increasing" << std::endl;
            return false;
        }
    }
    return true;
}

bool gradually_decreasing(std::vector<int> row)
{
    for(int i = 1; i < row.size(); i++)
    {
        int diff = row[i] - row[i-1];
        if(diff >= 0)
        {
            std::cout << row[i] << " >= " << row[i-1] << " not gradually decrasing" << std::endl;
            return false;
        }
        else if(diff < -3)
        {
            std::cout << "The difference between " << row[i] << " and " << row[i-1] << " is greater than 3"  << " not gradually decrasing" << std::endl;
            return false;
        }
    }
    return true;
}