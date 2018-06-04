/*
 * Set.h
 *
 *  Created on: May 1, 2018
 *      Author: abdullah
 */
#include "Block.h"
#include <vector>
#include <cmath>
using namespace std;
#ifndef SET_H_
#define SET_H_

class Set {
	string index;
	vector<Block> blocks;
	int noOfBlocks;
public:
	Set(int blocksize,int associativity,int index);
	~Set();
};

#endif /* SET_H_ */
