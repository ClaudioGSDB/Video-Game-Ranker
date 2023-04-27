#include <string>
#include <algorithm>
#include <chrono>
#include "FunctionsT.h"


using namespace std;

void mainT()
{
    //input - put in function
    map<int, string> inputGenMap = genrePick();

    //---Start Chrono
    auto start = chrono::high_resolution_clock::now();

    //creates the entire data structure
	map<int, gameTreeT*> genreMap = ReadData("Data");

    //Search for top 5 games
    vector<DataNodeT> outputGames = findTop(inputGenMap, genreMap);

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

map<int, gameTreeT*> ReadData(string pathToFolder)
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
    map<int, gameTreeT*> genreMap;


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

			genreMap[genNum] = new gameTreeT();


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

                // CUSTOM HERE

                DataNodeT* node = new DataNodeT(ID, title, rating, genres);


				genreMap[genNum]->insert(*node); // initialized outside main for loop

                // CUSTOM END HERE

                genres.clear();
            }
            file.close();
        }
    }
    return genreMap;
}

vector<DataNodeT> findTop(map<int, string> genres, map<int, gameTreeT*> &genreMap)
{
    vector<DataNodeT> outputGames;
	int smallId = 0;
	int small = INT_MAX;

	// for every genre we're looking for, find the one with the smallest id
    for(auto element : genres){
        if(genreMap[element.first]->leafAmount() < small){
			small = genreMap[element.first]->leafAmount();
			smallId = element.first;
		}
    }
	genreMap[smallId]->findMatch(genres, outputGames);

    return outputGames;
}

bool compareByRating(const DataNodeT& a, const DataNodeT& b) {
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