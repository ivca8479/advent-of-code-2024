#include <iostream>
#include <string>
#include <fstream>

#pragma once
void add_to_column(std::string word, int column);
void parse_columns(std::string filename);
void get_numbers(std::string filename, int arr[]);
void read_file(std::string filename);
bool fileExist(std::string filename);
int get_file_length(std::string filename);
