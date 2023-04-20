#include <regex>
#include <fstream>
#include <iostream>
#include "Functions.h"

using namespace std;

regex FD = regex(" - ");

void cleanText(string inFile)
{
    size_t pos;
    string line;

    //[[:ascii:]]+ Free Download .* REGEX
    ifstream readFile(inFile);
    ofstream writeFile("data/Clean Data2.txt");

    if(readFile.is_open())
    {
        while(getline(readFile, line))
        {
            pos = line.find(" - ");
            line = line.substr(0, pos);
            writeFile << line << endl;
        }
        readFile.close();
        writeFile.close();
    }
}
