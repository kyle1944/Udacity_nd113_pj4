#include "headers/move.h"
#include "headers/zeros.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector< vector <float> > move(int dy, int dx, 
	vector < vector <float> > &beliefs) 
{
	static int height = beliefs.size();
	static int width = beliefs[0].size();

  	// OPTIMIZATION: Use improved zeros function
	static vector < vector <float> > newGrid = zeros(height, width);

// OPTIMIZATION: Eliminate any variables that aren't needed
	static int i, j;
	
  	for (i=0; i<height; i++) {
		for (j=0; j<width; j++) {
			newGrid[(i + dy + height) % height][(j + dx + width) % width] = beliefs[i][j];
		}
	}
	return newGrid;
}
