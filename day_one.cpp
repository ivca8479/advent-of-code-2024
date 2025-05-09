#include <iostream>
#include <fstream>
#include <string>

#include "libraries/string_helpers.hpp"
#include "libraries/array_helpers.hpp"
#include <cmath>

#define MAX_LINES   (2000)

int main()
{
    std::string filename = "text_files/day_one_numbers.txt";
    int length = get_file_length(filename);
    std::cout << "File name: " << filename << std::endl;
    if(!fileExist("column0.txt"))
    {
        parse_columns(filename);
    }
    int col_one[MAX_LINES];
    int col_two[MAX_LINES];
    get_numbers("text_files/column0.txt", col_one);
    get_numbers("text_files/column1.txt", col_two);
    int sum = 0;
    int i = 0;
    //print_array(col_one, length);
    //print_array(col_two, length);
    for(int i = 0; i < length; i++)
    {
        int a = get_min(col_one, length);
        std::cout << "a = " << a << std::endl;
        int b = get_min(col_two, length);
        std::cout << "b = " << b << std::endl;
        int diff = a - b;
        diff = std::abs(diff);
        sum += diff;
    }
    std::cout << "The total difference = " << sum << std::endl;
    return 0;
}
