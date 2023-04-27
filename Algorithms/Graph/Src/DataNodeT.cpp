#include "DataNodeT.h"

DataNodeT::DataNodeT()
{
	ID = 0;
	title = "";
	rating = 0.0;
	genres.emplace(make_pair(0, ""));
}

DataNodeT::DataNodeT(int ID, string title, double rating, map<int, string> genres)
{
    this->ID = ID;
    this->title = title;
    this->rating = rating;
    this->genres = genres;
}

int DataNodeT::getId() const
{
    return ID;
}

const string &DataNodeT::getTitle() const
{
    return title;
}

float DataNodeT::getRating() const
{
    return rating;
}

const map<int, string> &DataNodeT::getGenres() const
{
    return genres;
}
bool DataNodeT::operator==(const DataNodeT &other) const {
	if(this->ID == other.ID){
		return true;
	}
	return false;
}

