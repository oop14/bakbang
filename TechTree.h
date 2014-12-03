//
// TechTree.h
// OOP_proj
//
// Created by So 2014. 11. 22..
// Copyright (c) So. All rights reserved.
//

#include <string.h>
#include "virus.h"

#ifndef _OOP_proj__TechTree_
#define _OOP_proj__TechTree_


class TechBlock {
private:
	char name[21];
	char info[41];
	VirusStatus increase;
	int levelMax;
	int level;
	int cost;
	TechBlock** before;
	int techNum;
	bool* beforeIndex;
public:
	TechBlock(char* _name, char* _info);
	~TechBlock();
	void setCost(int _levelMax, int first_cost);
	void setPreTech(bool* _beforeIndex, TechBlock** _before, int _techNum);
	void setIncreaseStatus(VirusStatus _increase);
	void getAvailable const(bool& available);
	void getCost const(int& _cost);
	void getLevel const(int& _level);
	void getName const(char** _name);
	void getInfo const(char* info, double up[3]);
	void upgrade(VirusStatus& Vstatus);
};

class TechTree {
private:
	const int techNum;
	char name[21];
	char info[41];
	int levelMax;
	TechBlock** tree;
	static int upgradeNum;
public:
	TechTree(const int _techNum):techNum(_techNum) {
		tree = new TechBlock*[techNum];
		upgradeNum = 0;
	}
	~TechTree() {
		delete[]tree;
	}
	void setName(const char* _name, const char* _info);
	void setMaxLevel(int& _levelMax) { levelMax = _levelMax; };
	void setStruct(const char** nameArr, const char** infoArr,
				const int* costArr,	const bool** indexArr, const VirusStatus* statArr);
	void getCost(int index, int& cost);	//index´Â 0~(techNUm-1)±îÁö
	void upgradeVirus(int index, VirusStatus& Vstatus);
	void showAvailabe(bool** available);
	void showExplain(int index, char* info, double up[3]);
};

#endif _OOP_proj__TechTree_