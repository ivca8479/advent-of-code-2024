#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#pragma once
void add_to_column(std::string word, int column);
int parse_columns(std::string filename);
std::vector<int> get_numbers(const std::string& filename);
void read_file(std::string filename);
bool fileExist(std::string filename);
int get_file_length(std::string filename);
int parse_rows(std::string filename);
void add_to_row(std::string word, int row);
void delete_files(std::string filetype, int num_files);