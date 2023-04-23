#include <iostream>
#include "dataSort.h"

int main() {
	dataSort cat("data/input/Data.txt", "data/output/");

	cout << cat.gamesVisited.size() << endl;

	return 0;
}
