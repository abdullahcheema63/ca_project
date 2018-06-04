/*
 * Block.h
 *
 *  Created on: May 1, 2018
 *      Author: abdullah
 */
#include <string>
#include <vector>
using namespace std;


#ifndef BLOCK_H_
#define BLOCK_H_

class Block {
	vector<string> bytes;
	int size;
	string tag;
	bool validityBit;
	bool dirtyBit;
public:
	Block(int size,string tag);
	Block(int size,string tag,vector<string> b);
	bool isValid();
	void setValid();
	void setInvalid();
	int getBlockSize();
	string getTag();

	string getData(int offset);
	bool saveData(int offset,string data);

	vector<string> getBlockData();
	void loadBlock(vector<string> b);

	~Block();
};

#endif /* BLOCK_H_ */
