#pragma once
#include <iostream>
#include <climits>
#include <vector>

void print_vector(const std::vector<std::vector<int>>& data);
int get_min(int arr[], int size);
int find_count(int arr[], int num, int size);
void print_array(int arr[], int size);

bool gradually_increasing(std::vector<int> row);
bool gradually_decreasing(std::vector<int> row);