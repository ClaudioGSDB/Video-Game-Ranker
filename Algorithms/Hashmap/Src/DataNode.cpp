#include "DataNode.h"
#include "ReadData.h"

DataNode::DataNode(int ID, string title, float rating, map<int, string> genres)
{
    this->ID = ID;
    this->title = title;
    this->rating = rating;
    this->genres = genres;
}

int DataNode::getId() const
{
    return ID;
}

const string &DataNode::getTitle() const
{
    return title;
}

float DataNode::getRating() const
{
    return rating;
}

const map<int, string> &DataNode::getGenres() const
{
    return genres;
}
