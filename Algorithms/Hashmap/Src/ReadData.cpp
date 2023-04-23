#include <string>
#include "ReadData.h"
#include "DataNode.h"

using namespace std;

ReadData::ReadData(string pathToFolder)
{
    char delim = '`';
    int genNum;
    string genName;

    int ID;
    string title;
    float rating;
    int numOfGenres;
    map<int, string> genres;
    int key;
    string value;


    for(int i = 0; i < 36; i++)
    {
        string fileName = pathToFolder + "/" + to_string(i) + ".txt";
        ifstream file(fileName);
        if(i == 15){
            cout << "reach" << endl;
        }

        if (file.is_open()) //if file exists
        {
            string line;

            //store the genre first
            getline(file, line, delim);
            genNum = stoi(line);
            getline(file, line);
            //line.substr(line.find('|') + 1); NOT NEEDED I THINK
            string genName = line;

            while (getline(file, line, delim))
            {
                //get ID
                ID = stoi(line);
                if(i == 15){cout << ID << endl;}
                //get title
                getline(file, title, delim);
                //get rating
                getline(file, line, delim);
                rating = stod(line);
                //get numOfGenres
                getline(file, line, delim);
                numOfGenres = stoi(line);
                //get genres
                for(int j = 0; j < numOfGenres; j++)
                {
                    getline(file, line, delim);
                    key = stoi(line);
                    getline(file, value, delim);
                    genres[key] = value;
                }
            }
            //cout << "File " << i << ".txt exists. Performing action A." << endl;
            file.close();
        }
        else
        {
            //cout << "File " << i << ".txt does not exist. Performing action B." << endl;
        }
    }

}