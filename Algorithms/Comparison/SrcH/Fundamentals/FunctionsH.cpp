#include <string>
#include <algorithm>
#include <chrono>
#include "FunctionsH.h"
#include "../../SrcT/FunctionsT.h"


using namespace std;

void mainC()
{
    //input - put in function
    map<int, string> inputGenMap = genrePick();

    //creates the entire data structure
    auto start = chrono::high_resolution_clock::now();
    GenreMapH* fullMap = ReadDataH("Data");
    auto stop = chrono::high_resolution_clock::now();
    auto durationH = chrono::duration_cast<chrono::microseconds>(stop - start); // Calculate the duration
    double secondsH = durationH.count() / 1000000.0;
    cout << "Build time for the HashMap: " << secondsH << " seconds";

    start = chrono::high_resolution_clock::now();
    map<int, gameTreeT*> genreMap = ReadDataT("Data");
    stop = chrono::high_resolution_clock::now();
    auto durationT = chrono::duration_cast<chrono::microseconds>(stop - start); // Calculate the duration
    double secondsT = durationT.count() / 1000000.0;
    cout << "Build Time for the B+ Tree: " << secondsT << " seconds" << endl << endl;

    //HashMap
    //---Start Chrono
    start = chrono::high_resolution_clock::now();
    //Search for top 5 games
    vector<DataNodeH> outputGamesH = findTop(inputGenMap, fullMap);
    //---End Chrono
    stop = chrono::high_resolution_clock::now();
    durationH = chrono::duration_cast<chrono::microseconds>(stop - start); // Calculate the duration
    secondsH = durationH.count() / 1000000.0;
    cout << "Search time by HashMap: " << secondsH << " seconds" << endl;

    //B+ Tree
    start = chrono::high_resolution_clock::now();
    //Search for top 5 games
    vector<DataNodeT> outputGamesT = findTopT(inputGenMap, genreMap);
    stop = chrono::high_resolution_clock::now();
    durationT = chrono::duration_cast<chrono::microseconds>(stop - start); // Calculate the duration
    secondsT = durationT.count() / 1000000.0;
    cout << "Search time by B+ Tree: " << secondsT << " seconds" << endl;

    //RESULTS
    int index = 1;
    cout << "\nTop 5 Games\n-------------" << endl;
    for (auto elem : outputGamesH) {
        cout << index++ << " " << elem.getTitle() << endl;
        //cout << elem.getTitle() << " = " << elem.getRating() << endl;
    }
}

void mainH()//Not in use for final submission
{
    //input - put in function
    map<int, string> inputGenMap = genrePick();

    //---Start Chrono
    auto start = chrono::high_resolution_clock::now();

    //creates the entire data structure
    GenreMapH* fullMap = ReadDataH("Data");

    //Search for top 5 games
    vector<DataNodeH> outputGames = findTop(inputGenMap, fullMap);

    int index = 0;
    for (auto elem : outputGames) {
        cout << index++ << " " << elem.getTitle() << endl;
        //cout << elem.getTitle() << " = " << elem.getRating() << endl;
    }

    //---End Chrono
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); // Calculate the duration
    double seconds = duration.count() / 1000000.0;
    cout << "Time taken by function: " << seconds << " seconds" << endl;
}

GenreMapH* ReadDataH(string pathToFolder)
{
    char delim = '=';
    int genNum;
    string genName;
    int numOfGenres;
    int key;
    string value;

    //game data
    int ID = 0;
    string title;
    float rating;
    map<int, string> genres;

    //Data structure
    GenreMapH* fullMap = new GenreMapH();


    for(int i = 0; i < 38; i++)
    {
        if(i > 36){
            cout << endl; //REMOVE USED FOR DEBUGGING
        }
        string fileName = pathToFolder + "/" + to_string(i) + ".txt";
        ifstream file(fileName);


        if (file.is_open()) //if file exists
        {
            string line;
            //store the genre first
            getline(file, line, delim);
            genNum = stoi(line);
            getline(file, line, delim);
            //line.substr(line.find('|') + 1); NOT NEEDED I THINK
            string genName = line;

            while (getline(file, line, delim))
            {
                if(line == "\n")
                {
                    break;
                }

                //get ID
                ID = stoi(line);
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

                //HASHMAP CUSTOM HERE

                DataNodeH* node = new DataNodeH(ID, title, rating, genres);
                fullMap->insert(node); //initialized outside main for loop

                //CUSTOM END HERE

                genres.clear();
            }
            file.close();
        }
    }
    return fullMap;
}

vector<DataNodeH> findTop(map<int, string> genres, GenreMapH* fullMap)
{
    vector<DataNodeH> outputGames;

    //find the smallest nodeMap's index in between the inputted genres
    int smallNodeMapSize = INT_MAX;
    int smallNodeMapIndex;

    for(auto element : genres)
    {
        if(smallNodeMapSize > fullMap->getGenreMap()[element.first]->getNumOfElements())
        {
            smallNodeMapSize = fullMap->getGenreMap()[element.first]->getNumOfElements();
            smallNodeMapIndex = element.first;
        }
    }
    //find the elements in the smallest node with highest ratings
    for(auto key : fullMap->getGenreMap()[smallNodeMapIndex]->getNodeMap())
    {
        for(auto node : key) //check to input node
        {
            if(all_of(genres.begin(), genres.end(), [&node](const auto& genre) {
                return node.getGenres().count(genre.first) != 0;
            }))
            {
                if(outputGames.size() < 5)
                {
                    outputGames.emplace_back(node);
                }
                else if(node.getRating() > outputGames.back().getRating())
                {
                    outputGames.back() = node;
                }
                sort(outputGames.begin(), outputGames.end(), compareByRating);
            }
        }
    }
    return outputGames;
}

bool compareByRating(const DataNodeH& a, const DataNodeH& b) {
    return a.getRating() > b.getRating();
}

map<int, string> genrePick() //for inputting the genres
{
    cout << "How many genres: " << endl;
    int numOfGen;
    cin >> numOfGen;
    int genres;
    map<int, string> inputGenMap;
    cout << "Choose " << numOfGen << " Genres" << endl;
    cout << "---------------------" << endl;
    cout << "2 = Point-and-click\n"
            "4 = Fighting\n"
            "5 = Shooter\n"
            "7 = Music\n"
            "8 = Platform\n"
            "9 = Puzzle\n"
            "10 = Racing\n"
            "11 = Real Time Strategy (RTS)\n"
            "12 = Role-Playing (RPG)\n"
            "13 = Simulator\n"
            "14 = Sport\n"
            "15 = Strategy\n"
            "16 = Turn-based strategy (TBS)\n"
            "24 = Tactical\n"
            "25 = Hack and slash/Beat \\\\u0027em up\n"
            "26 = Quiz/Trivia\n"
            "30 = Pinball\n"
            "31 = Adventure\n"
            "32 = Indie\n"
            "33 = Arcade\n"
            "34 = Visual Novel\n"
            "35 = Card \\\\u0026 Board Game\n"
            "36 = MOBA" << endl;

    for(int i = 0; i < numOfGen; i++)
    {
        cin >> genres;
        switch(genres) {
            case 2:
                inputGenMap[2] = "Point-and-click";
                break;
            case 4:
                inputGenMap[4] = "Fighting";
                break;
            case 5:
                inputGenMap[5] = "Shooter";
                break;
            case 7:
                inputGenMap[7] = "Music";
                break;
            case 8:
                inputGenMap[8] = "Platform";
                break;
            case 9:
                inputGenMap[9] = "Puzzle";
                break;
            case 10:
                inputGenMap[10] = "Racing";
                break;
            case 11:
                inputGenMap[11] = "Real Time Strategy (RTS)";
                break;
            case 12:
                inputGenMap[12] = "Role-Playing (RPG)";
                break;
            case 13:
                inputGenMap[13] = "Simulator";
                break;
            case 14:
                inputGenMap[14] = "Sport";
                break;
            case 15:
                inputGenMap[15] = "Strategy";
                break;
            case 16:
                inputGenMap[16] = "Turn-based strategy (TBS)";
                break;
            case 24:
                inputGenMap[24] = "Tactical";
                break;
            case 25:
                inputGenMap[25] = "Hack and slash/Beat 'em up";
                break;
            case 26:
                inputGenMap[26] = "Quiz/Trivia";
                break;
            case 30:
                inputGenMap[30] = "Pinball";
                break;
            case 31:
                inputGenMap[31] = "Adventure";
                break;
            case 32:
                inputGenMap[32] = "Indie";
                break;
            case 33:
                inputGenMap[33] = "Arcade";
                break;
            case 34:
                inputGenMap[34] = "Visual Novel";
                break;
            case 35:
                inputGenMap[35] = "Card & Board Game";
                break;
            case 36:
                inputGenMap[36] = "MOBA";
                break;
            default:
                inputGenMap[genres] = "Unknown";
                break;
        }
    }
    return inputGenMap;
}