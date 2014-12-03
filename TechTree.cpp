#include "TechTree.h"

TechBlock::TechBlock(char* _name, char* info) {
	level = 0;
	for(int i=0;i<20; i++) {
		name[i] = _name[i];
		if( _name[i] == NULL )
			break;
	}
	name[20]=NULL;
	for(int i=0;i<40; i++) {
		info[i] = _info[i];
		if( _info[i] == NULL )
			break;
	}
	info[40]=NULL;
}
TechBlock::~TechBlock() {
	delete[]before;
}
void TechBlock::setCost(int _levelMax, int first_cost) {
	levelMax = _levelMax;
	cost = _cost;
}
void TechBlock::setPreTech(bool* _beforeIndex, TechBlock** _before, int _techNum) {
	beforeIndex = _beforeIndex;
	techNum = _techNum;
	before = new bool[techNum];
	for(int i=0; i<techNum; i++)
		before[i] = _before[i];
}
void TechBlock::setIncreaseStatus(VirusStatus _increase) {
	increase = _increase;
}
void TechBlock::getAvailable const(bool& available) {
	available = false;
	for(int i=0; i<techNum; i++) {
		if(beforeIndex[i]) {
			int lvl;
			TechBlock[i]->getLevel(lvl);
			if(!lvl)
				return;
		}
	}
	available = true;
}
void TechBlock::getCost const(int& _cost) {
	_cost = cost*(1+level);
}
void TechBlock::getLevel const(int& _level) {
	_level = level;
}
void TechBlock::getName (char* _name) {
	_name = name;
}
void TechBlock::getInfo const(char* _info, double up[3]) {
	_info = info;
	Increase.showData(up);
}
void TechBlock::upgrade(VirusStatus& Vstatus) {
	if( level < levelMax )
		Vstatus += increase*( 1 + (level++)*0.5 );
}


void TechTree::setStruct(const char** nameArr, const int* costArr, const bool** indexArr, VirusStatus* statArr) {
	for(int i=0; i<techNum; i++) {
		tree[i] = new TechBlock(nameArr[i]);
		tree[i].setCost(levelMax,cost[i]);
		tree[i].PreTech(indexArr[i],tree,techNum);
		tree[i].IncreaseStatus(statArr[i]);
	}
}
void TechTree::getCost(int index, int& cost) {
	cost = -1;
	if( index >= techNum )
		return;
	tree[index].getCost(cost);
	cost += upgradeNum;
}
void TechTree::setName(const char* _name, const char* _info) {
	for(int i=0;i<20; i++) {
		name[i] = _name[i];
		if( _name[i] == NULL )
			break;
	}
	name[20]=NULL;
	for(int i=0;i<40; i++) {
		info[i] = _info[i];
		if( _info[i] == NULL )
			break;
	}
	info[40]=NULL;
}
void TechTree::upgradeVirus(int index, VirusStatus& Vstatus) {
	if(available[i]) {
		tree[i].upgrade(Vstatus);
		upgradeNum++;
	}
}
void TechTree::showAvailabe(bool** available) {
	for(int i=0; i<techNum; i++)
		tree.getAvailable(available[i]);
}
void TechTree::showExplain(int index, char* _info, double up[3]) {
	tree.getInfo(_info,up);
}