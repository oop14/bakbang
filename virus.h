//
// virus.h
// OOP_proj
//
// Created by So 2014. 11. 17..
// Copyright (c) So. All rights reserved.
//
#include "virusStatus.h"

#ifndef _OOP_proj__virus_
#define _OOP_proj__virus_

class Virus {
private:
	int techNum[3];
	VirusStatus* Vstatus;
	TechTree* status[3];
	int difficulty;
	int sinario;
	void setTech(int difficulty, int cost_buf, double vac_buf, double stat_buf);
public:
	Virus();
	~Virus();
	void setDifficulty(int _difficulty, int _sinario);

	void getVirusStatus const(VirusStatus* _Vstatus);
	void getTechTree const(int index, TechTree* _tree);
};

#endif _OOP_proj__virus_