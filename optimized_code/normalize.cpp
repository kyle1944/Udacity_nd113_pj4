#include "headers/normalize.h"
using namespace std;

// OPTIMIZATION: Pass variable by reference
vector< vector<float> > normalize(vector< vector <float> > &grid) {

  	// OPTIMIZATION: Avoid declaring and defining 				// intermediate variables that are not needed.
	static float total = 0.0;
	static int i, j;
	
	static int height = grid.size();
	static int width = grid[0].size();

	for (i=0; i < height; i++){
		for (j=0; j< width; j++){
			total += grid[i][j];
		}
	}

	for (i=0; i < height; i++){
		for (j=0; j< width; j++){
			grid[i][j] /= total;
		}
	}

	return grid;
}
