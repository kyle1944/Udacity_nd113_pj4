#include "headers/blur.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back

	static int height = grid.size();
	static int width = grid[0].size();

	static float center = 1.0 - blurring;
	static float corner = blurring / 12.0;
	static float adjacent = blurring / 6.0;

	static vector < vector <float> > window = {{corner, adjacent, corner},
                                               {adjacent, center, adjacent},
                                               {corner, adjacent, corner}};

	static vector <int> delta = {-1, 0, 1};
	//vector <int> DY = {-1, 0, 1};
	static int i, j, ii, jj;

	// OPTIMIZATION: Use your improved zeros function
	static vector < vector <float> > newGrid = zeros(height, width);

	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {
			for (ii=0; ii<3; ii++) {
				//dy = delta[ii];
				for (jj=0; jj<3; jj++) {
					//dx = delta[jj];
					newGrid[(i + delta[ii] + height) % height][(j + delta[jj] + width) % width] += grid[i][j] * window[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
