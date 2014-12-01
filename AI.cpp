#include "AI.h"
												//get들
void AI::getSum_total_pc(double& pc){
	pc = sum_total_pc;
}

void AI::getSum_infected_pc(double& pc){
	pc = sum_infected_pc;
}

void AI::getSum_uninfected_pc(double& pc){
	pc = sum_uninfected_pc;
}

void AI::getSum_dead_pc(double& pc){
	pc = sum_dead_pc;
}

void AI::getSum_live_pc(double& pc){
	pc = sum_live_pc;
}

												//get들 끝
void AI::intialize_pc(){
	sum_total_pc = 0;
	sum_infected_pc = 0;
	sum_uninfected_pc = 0;
	sum_dead_pc = 0;
	sum_live_pc = 0;
}

void AI::gather_info(){
	Building_Information temp_info;
	intialize_pc();
	for(int i=0; i<B_NUMBER; i++){
		building_list[i]->getInformation(&temp_info);
		sum_total_pc += temp_info.total_pc;	
		sum_infected_pc += temp_info.infected_pc;
		sum_uninfected_pc += temp_info.uninfected_pc;
		sum_dead_pc += temp_info.dead_pc;
		sum_live_pc += temp_info.live_pc;
	}
	getVM_from_VirusStatus();
	getVP_from_Vaccine();
}

void AI::setEach_Building_Information(){
	Building_Information temp_info;	
	
	for(int i=0; i<B_NUMBER; i++){
		building_list[i]->getInformation(&temp_info);
		if(temp_info.infected_pc == 0) {uninfected_building[i] = true; infected_building[i] = false;}
		else if(temp_info.infected_pc > 0) {infected_building[i] = true; uninfected_building[i] = false;}
		if(temp_info.dead_pc == 0) dead_building[i] = false;
		else if(temp_info.dead_pc > 0) dead_building[i] = true;
												//감염안된 building들과 감염된 building들과 죽은 building들 처리완료
		block_checking(building_list[i]);		
												//빌딩의 감염 및 죽음 정도와 바이러스의 심각성에 따라 백신 개발시작 여부도 판단하며 
												//그 빌딩에 대한 교류도 줄이거나 한다.
	}
}

void AI::block_checking(Building* b){
	double building_serious = 0;				//빌딩의 감염 및 죽음 정도를 보고, 그 빌딩과 다른 빌딩과의 상호작용을 control해준다.
												//만약 일정수준 이상으로 심각해지면, 그 빌딩에 대한 교류는 모두 끊어서 그 빌딩은 내부에서만 감염 및 죽음이 퍼지게 한다.
	double building_infected_percent = 0;		//빌딩의 감염률
	double building_death_percent = 0;			//빌딩의 죽음률
	double virus_serious = 0;					//바이러스 심각성
	double* temp_interact[2];					//각 빌딩들의 서로 상호작용성
	b->getInfectPercent(building_infected_percent);
	b->getDeathPercent(building_death_percent);
	b->getInteract(temp_interact);
	vs->getSerious(virus_serious);
	building_serious = building_infected_percent + (building_death_percent + virus_serious)*5;
	if(building_serious > 150)/*심각정도*/{
		for(int j=0; j<B_NUMBER; j++){
			
		}
	}
}

void AI::building_called(int index, char* _name, double& _uninfected, double& _infected, double& _dead, bool& on_block, bool& off_block){
	Building_Information temp_info;
	building_list[index]->getInformation(&temp_info);
	building_list[index]->getName(_name);		//이름 전달	
	_uninfected = temp_info.uninfected_pc;		//감염되지 않은 pc전달
	_infected = temp_info.infected_pc;			//감염된 pc전달
	_dead = temp_info.dead_pc;					//죽은 pc전달
	on_block = blocked_building[0][index];		//online의 block여부 전달
	off_block = blocked_building[1][index];		//offline의 block여부 전달
}