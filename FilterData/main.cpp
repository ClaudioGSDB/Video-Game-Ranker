#include <iostream>
#include "dataSort.h"

int main() {
	dataSort cat("data/input/Data.txt", "../../Algorithms/Graph/cmake-build-debug/data/");

	cout << cat.gamesVisited.size() << endl;

	return 0;
}
