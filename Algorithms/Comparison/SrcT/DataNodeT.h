#include <iostream>
#include <map>

using namespace std;

class DataNodeT{
private:

private:
    int ID;
    string title;
    double rating;
    map<int, string> genres;
public:
	DataNodeT();

    DataNodeT(int ID, string title, double rating, map<int, string> genres);

    int getId() const;
    const string &getTitle() const;
    float getRating() const;
    const map<int, string> &getGenres() const;
	bool operator==(const DataNodeT& other) const;

};