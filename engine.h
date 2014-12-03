//
//  engine.h
//  OOP_proj
//
//  Created by dblab on 2014. 11. 17..
//  Copyright (c) 2014³â dblab. All rights reserved.
//

#ifndef __OOP_proj__engine__
#define __OOP_proj__engine__

#include <iostream>
#include <vector>

#include "virus.h"
#include "virusStatus.h"
#include "vaccine.h"
#include "building.h"
#include "AI.h"

class Engine {
private:
    Virus*                  virus;
    std::vector<Building*>  buildings;
    Vaccine*                vaccine;
    AI*						ai;
    double	speed_of_game;
	int coin;
public:
    
	Engine() { coin=0;};
    ~Engine();
    
	void initGame();
    void one_step_progress();

	void plus_coin(int getCoin);

	void get_tree_levels(int index_tree, int& blockNum, int* levels);
	void click_tech(int index_tree, int index_block, char* name, char* info, double up[3]);

	void upgrade_available(int index_tree, int& blockNum, bool* availble);
};

#endif /* defined(__OOP_proj__engine__) */
