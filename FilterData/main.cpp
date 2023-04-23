#include <iostream>
#include "dataSort.h"

int main() {
	dataSort cat("data/input/Data.txt", "../../Algorithms/Hashmap/cmake-build-debug/data/");

	cout << cat.gamesVisited.size() << endl;

	return 0;
}
