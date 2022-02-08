#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

int main()
{
	std::ifstream fin;
    int file_size = 0;

    fin.open("C:\\Users\\USER\\Desktop\\test\\lover_of_mine.txt", std::ios::binary);

    fin.seekg(0, std::ios::end);
    file_size = fin.tellg();    //get file size 
    fin.seekg(0, std::ios::beg);
	char * buffer = new char[file_size + 1];
    fin.read(buffer, file_size);
    buffer[file_size] = '\0';
    fin.close();
    
	std::ofstream fout;
	fout.open("C:\\Users\\USER\\Desktop\\test\\copy\\lover_of_mine_copy.txt", std::ios::binary);
	fout.write(buffer, file_size);
	
	return 0;

}