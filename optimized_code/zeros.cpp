#include "headers/zeros.h"

using namespace std;

vector < vector <float> > zeros(int height, int width) {

	int i;
	vector < vector <float> > newGrid;
	newGrid.reserve(height);

	vector <float> newRow;
	newRow.assign(width, 0);

	for (i=0; i<height; i++) {
		newGrid.push_back(newRow);
	}

	return newGrid;
  /*
	// OPTIMIZATION: Reserve space in memory for vectors
	static vector < vector <float> > newGrid (height, vector <float> (width, 0));

  	// OPTIMIZATION: nested for loop not needed
    // because every row in the matrix is exactly the same

	return newGrid;
    */
}