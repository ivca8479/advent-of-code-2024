#include "string_helpers.hpp"
#define MAX (9999999)


void get_numbers(std::string filename, int arr[])
{
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string word;
    int count = 0;
    while(getline(inFile, word))
    {
        arr[count] = stoi(word);
        count++; 
    }
    inFile.close();
}



void add_to_column(std::string word, int column)
{
    std::string col = std::to_string(column);
    // Open File pertaining to the column
    std::ofstream file("text_files/column" + col + ".txt", std::ios::app);
    // Add word to the column
    file << word << '\n';
    file.close();
}


void parse_columns(std::string filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    std::string word;
    char c;
    int column = 0;
    while(inFile.get(c))
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(!word.empty())
            {
                add_to_column(word, column);
                column++;
                word.clear();
            }
            if(c == '\n')
            {
                column = 0;
            }
        }
        else
        {
            word += c;
        }
    }
    if(!word.empty())
    {
        add_to_column(word, column);
        word.clear();
    }
    inFile.close();
    return;
}

int get_file_length(std::string filename)
{
    int length = 0;
    std::ifstream inFile;
    inFile.open(filename);
    std::string line;
    while(getline(inFile, line))
    {
        length++;
    }
    inFile.close();
    return length;
}


void read_file(std::string filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return;
    }
    char c;
    while(inFile.get(c))
    {
        std::cout << c;
    }
    inFile.close();
}

bool fileExist(std::string filename)
{
    std::ifstream inFile(filename);
    if(!(inFile.is_open()))
    {
        return true;
    }
    return false;
}