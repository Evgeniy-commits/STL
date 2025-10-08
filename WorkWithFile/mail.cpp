#include <iostream>
#include <Windows.h>
#include <io.h>
#include <stdio.h>
//#include <fstream>
//#include <string>
//#include <list>
//#include <map>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab			 "\t"
#define delimiter	 "\n-----------------------------------------------------\n"

void RussianMessage(char* str);

void main()
{
	setlocale(LC_ALL, "");

}

void RussianMessage(char* str)
{
	char message[100];
	CharToOem(str, message);
	cout << message;
}

bool CopyFile(char* source, char* destination)
{
	const int size = 65536;
	FILE *src, *dest;
	if (!(src = fopen(source, "rb"))) return false;

	int handle = _fileno(src);

	char* data = new char[size];
	if (!data) return false;

	if (!(dest = fopen(destination, "wb")))
	{
		delete[] data;
		return false;
	}

	int realsize;
	while (!feof(src))
	{
		realsize = fread(data, sizeof(char), size, src);
		fwrite(data, sizeof(char), realsize, dest);
	}

	fclose(src);
	fclose(dest);
	return true;
}

