//
//  Engine.cpp
//  OOP_proj
//
//  Created by dblab on 2014. 11. 17..
//  Copyright (c) 2014�� dblab. All rights reserved.
//

#include "engine.h"

void Engine::initGame() {
	virus = new Virus;

	VirusStatus* vs;
	virus->getVirusStatus(vs);
	
	double person_activitiy[4] = {1,1,1,7};
	double person_security[3] = {1,3,6};
	double building_interact[2][B_NUMBER] = {{0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1},
											 {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1}};

	buildings.push_back(new Building("����1",0,100,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����2",1,110,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����3",2,120,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����4",3,130,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����5",4,140,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("����6",5,150,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����7",6,160,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����8",7,170,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����9",8,180,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����10",9,190,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("����11",10,210,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����12",11,220,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����13",12,230,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����14",13,240,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����15",14,250,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("����16",15,260,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����17",16,270,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����18",17,280,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����19",18,290,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("����20",19,300,person_activitiy,person_security,1,vs,building_interact));
	
	ai = new AI(/*AI�� �ϼ� �Ǹ� ���� ��*/);
}

void Engine::one_step_progress() {

    // process one step of virus propagation in a bulding.
    for(int i=0; i<B_NUMBER; i++) {
        buildings[i]->do_operation();
    }
        
    // Vanccine
    vaccine->do_operation();

	// AI
	ai->do_operation();
/*	
	// checking coin
	for(auto p : buildings) {
        p->iscoinExist(coin_flag[i++]);
    }

	// checking AI_Command
	ai->getCOMMAND();
*/
    return;
}
void Engine::plus_coin(int getCoin) {
	coin += getCoin;
}
void Engine::get_tree_levels(int index_tree, int& blockNum, int* levels) {
	
}
void Engine::click_tech(int index_tree, int index_block, char* name, char* info, double up[3]) {

}
void Engine::upgrade_available(int index_tree, int& blockNum, bool* availble) {

}