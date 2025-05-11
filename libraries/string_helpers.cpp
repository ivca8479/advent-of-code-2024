#include "string_helpers.hpp"
#define MAX (9999999)
#define ERROR (-1)

std::vector<int> get_numbers(const std::string& filename)
{
    std::vector<int> result;
    std::ifstream inFile(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return result;
    }

    std::string word;
    while (getline(inFile, word))
    {
        result.push_back(std::stoi(word));
    }

    inFile.close();
    return result;
}



void add_to_column(std::string word, int column)
{
    std::string col = std::to_string(column);
    std::string filename = "text_files/row" + col + ".txt";
    // Open File pertaining to the column
    std::ofstream file(filename, std::ios::app);
    // Add word to the column
    file << word << '\n';
    file.close();
}



void add_to_row(std::string word, int row)
{
    std::string row_num = std::to_string(row);
    // Open File pertaining to the column
    std::string filename = "text_files/row" + row_num + ".txt";
    std::ofstream file(filename, std::ios::app);
        // Add word to the column
    file << word << '\n';
    file.close();
}


int parse_columns(std::string filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return ERROR;
    }
    std::string word;
    char c;
    int column = 0;
    int num_columns = 0;
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
                num_columns++;
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
    return num_columns;
}


int parse_rows(std::string filename)
{
    std::ifstream inFile;
    inFile.open(filename);
    if (inFile.fail())
    {
        std::cout << "Error opening file" << std::endl;
        return ERROR;
    }
    std::string word;
    char c;
    int row = 0;
    while(inFile.get(c))
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(!word.empty())
            {
                add_to_row(word, row);
                word.clear();
            }
            if(c == '\n')
            {
                row++;
            }
        }
        else
        {
            word += c;
        }
    }
    if(!word.empty())
    {
        add_to_row(word, row);
        word.clear();
        row++;
    }
    inFile.close();
    return row;
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


void delete_files(std::string filetype, int num_files)
{
    for(int i = 0; i <= num_files; i++)
    {
        std::string num = std::to_string(i);
        std::string file = "text_files/" + filetype  + num + ".txt";
        if(std::remove(file.c_str()) == 0)
        {
            std::cout << "Removed the file " << file << std::endl;
        }
    }
}

void create_files(std::string filetype, int num_file)
{

}