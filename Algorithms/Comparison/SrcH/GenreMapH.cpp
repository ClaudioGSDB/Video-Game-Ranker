#include "GenreMapH.h"

using namespace std;

GenreMapH::GenreMapH()
{

}

void GenreMapH::insert(DataNodeH* node)
{
    map<int, string> genres = node->getGenres();
    for( auto gen : genres)
    {
        if (genreMap[gen.first] == nullptr)
        {
            genreMap[gen.first] = new NodeMapH();
        }
        genreMap[gen.first]->insert(*node);
        genreCode[gen.first] = gen.second;
    }
}

const vector<NodeMapH *> &GenreMapH::getGenreMap() const {
    return genreMap;
}

