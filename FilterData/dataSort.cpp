//
// Created by torre on 4/23/2023.
//

#include "dataSort.h"

void dataSort::commaRemove(string &line) {
	if(regex_match(line, regexCase[","])){
		line = regex_replace(line, regexCase["h,"], "");
	}
}

dataSort::dataSort(string inputFile, string ouputPath) {
	regexCase["\""] = R"(")";
	regexCase[","] = R"([^,.]*,)";
	regexCase["["] = R"(\s*\[)";
	regexCase["]"] = R"(\s*\])";
	regexCase["]["] = R"(\s*\]\[)";
	regexCase["{"] = R"(\s*\{)";
	regexCase["}"] = R"(\s*\})";
	regexCase["id"] = R"(\s*"id": *[0-9]+)";
	regexCase["genre"] = R"(\s*"genres": \[)";
	regexCase["name"] = R"(\s*"name": ".+,?)";
	regexCase["rating"] = R"(\s*"rating": [0-9.]+)";
	regexCase["h,"] = R"(,)";
	regexCase["hid"] = R"(\s*"id": )";
	regexCase["hname"] = R"(\s*"name": )";
	regexCase["hrating"] = R"(\s*"rating": )";

	int id = 0;
	map<int, string> gameGenres;
	string name;
	double rating = 0;

	ifstream dataFile;
	dataFile.open(inputFile);
	string line;
	string push;

	if(dataFile.is_open()){
		while(getline(dataFile, line)){
			// if name field
			if(regex_match(line,regexCase["name"])){
				// clean the formatting
				line = regex_replace(line, regexCase["hname"], "");
				line = regex_replace(line, regexCase["\""], "");

				if(line[line.size() - 1] == ','){
					line.pop_back();
				}

				// store in node variable
				name = line;
			}
			// else remove commas
			else{
				commaRemove(line);
			}

			// if division between pulls
			if(regex_match(line, regexCase["["]) or regex_match(line, regexCase["]"]) or
				regex_match(line, regexCase["]["])){
				// ignore
				continue;
			}

			// if start of a node
			if(regex_match(line, regexCase["{"])){
				// restart node variables
				id = 0;
				gameGenres.clear();
				name = "";
				rating = 0;
				push = "";
				continue;
			}

			// if id field
			else if(regex_match(line, regexCase["id"])){
				// clean the formatting
				line = regex_replace(line, regexCase["hid"], "");
				// store in node variable
				id = stoi(line);
			}

			// if genre section of node
			else if(regex_match(line, regexCase["genre"])){
				bool gotId = false;
				bool gotName = false;
				string gName;
				int gId;

				// while not the end of the section
				while(!regex_match(line, regexCase["]"])){
					getline(dataFile, line);

					// if name field
					if(regex_match(line,regexCase["name"])){
						// clean the formatting
						line = regex_replace(line, regexCase["hname"], "");
						line = regex_replace(line, regexCase["\""], "");

						if(line[line.size() - 1] == ','){
							line.pop_back();
						}

						// store in node variable
						gName = line;
						gotName = true;
					}
						// else remove commas
					else{
						commaRemove(line);
					}

					// if end of section
					if(regex_match(line, regexCase["]"])){
						continue;
					}

					// if id field
					if(regex_match(line, regexCase["id"])){
						// clean the formatting
						line = regex_replace(line, regexCase["hid"], "");
						// store in node variable
						gId = stoi(line);
						gotId = true;
					}

					// if enough information to store
					if(gotId and gotName){
						gotId = false;
						gotName = false;

						gameGenres[gId] = gName;

					}

				}
				/*for(auto &i : gameGenres){
					cout << to_string(i.first) + ", " + i.second << endl;
				}*/
				continue;
			}

			// if Rating field
			else if(regex_match(line, regexCase["rating"])){
				// clean the formating
				line = regex_replace(line, regexCase["hrating"], "");
				// store in node variable
				rating = stod(line);
			}

			// if end of node
			else if(regex_match(line, regexCase["}"])){
				// if the game has been seen before
				if(gamesVisited.count(id) > 0){
					continue;
				}
				for(auto &genre : gameGenres){
					push = "";
					// if the genre file has not been created
					if(genreFiles.end() == find_if(genreFiles.begin(), genreFiles.end(),
												   [=](auto &thing)
												   {return genre.first == thing.first;}))
					{
						// create the file
						genreFiles[genre.first].open(ouputPath + to_string(genre.first));
						// store id and name of category in file.
						genreFiles[genre.first] << to_string(genre.first) + "|" + genre.second << endl;
					}

					push += to_string(id) + "|" + name + "|" + to_string(rating) + "|" +
						to_string(gameGenres.size()) + "|";

					for(auto &g : gameGenres){
						push += to_string(g.first) + "|" + g.second + "|";
					}
					push.pop_back();

						genreFiles[genre.first] << push << endl;
						gamesVisited.emplace(id);
				}
				continue;
			}

			//cout << line << endl;
		}
	}


}

