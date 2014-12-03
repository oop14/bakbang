//
//  engine.cpp
//  OOP_proj
//
//  Created by dblab on 2014. 11. 17..
//  Copyright (c) 2014喇 dblab. All rights reserved.
//

#include "engine.h"

void engine::initGame() {
	virus = new Virus;

	VirusStatus* vs;
	virus->getVirusStatus(vs);
	
	double person_activitiy[4] = {1,1,1,7};
	double person_security[3] = {1,3,6};
	double building_interact[2][B_NUMBER] = {{0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1},
											 {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1}};

	buildings.push_back(new Building("網註1",0,100,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註2",1,110,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註3",2,120,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註4",3,130,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註5",4,140,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("網註6",5,150,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註7",6,160,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註8",7,170,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註9",8,180,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註10",9,190,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("網註11",10,210,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註12",11,220,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註13",12,230,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註14",13,240,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註15",14,250,person_activitiy,person_security,1,vs,building_interact));

	buildings.push_back(new Building("網註16",15,260,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註17",16,270,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註18",17,280,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註19",18,290,person_activitiy,person_security,1,vs,building_interact));
	buildings.push_back(new Building("網註20",19,300,person_activitiy,person_security,1,vs,building_interact));
	
	ai = new AI(/*AI陛 諫撩 腎賊 嫡擊 匙*/);
}

void engine::one_step_progress() {

    // process one step of virus propagation in a bulding.
    for(auto p : buildings) {
        p->do_operation();
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
    // wait for the next step. (depending on 'speed_of_game')
    wait_for_next_step();

    return;
}
void engine::plus_coin(int getCoin) {
	coin += getCoin;
}
void engine::get_tree_levels(int index_tree, int& blockNum, int* levels) {
	virus->
}
void engine::click_tech(int index_tree, int index_block, char* name, char* info, double up[3]) {

}
void engine::upgrade_available(int index_tree, int& blockNum, bool* availble) {

}