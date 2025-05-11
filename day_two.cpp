#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio>


#include "libraries/string_helpers.hpp"
#include "libraries/array_helpers.hpp"
#include <cmath>

#define MAX_LINES   (2000)
#define MAX_PRODUCED_FILES (1000)


int main()
{
    std::string filename = "text_files/day_two_numbers.txt";
    std::cout << "File name: " << filename << std::endl;
    delete_files("row", MAX_PRODUCED_FILES);  
    int rows = parse_rows(filename);

    std::vector<std::vector<int>> row_data;
    for(int i = 0; i < rows; i++)
    {
        std::string row_num = std::to_string(i);
        std::string file = "text_files/row" + row_num + ".txt";
        row_data.push_back(get_numbers(file));
    }
    std::cout << rows << std::endl;

    int safe_rows = 0;
    for(int i = 0; i < row_data.size(); i++)
    {
        if(gradually_decreasing(row_data[i]) || gradually_increasing(row_data[i]))
        {
            std::cout << "Row " << i << " is safe" << std::endl;
            safe_rows++;
        }
        std::cout << std::endl;
    }
    std::cout << "Found a total of " << safe_rows  << " safe rows" << std::endl;
}