#ifndef SENSE_H
#define SENSE_H

#include <vector>
#include <iostream>

std::vector< std::vector <float> > sense(char color, vector< vector <char> > &grid, int height, int width, std::vector< std::vector <float> > &beliefs,  float p_hit, float p_miss);

#endif /* SENSE.H */