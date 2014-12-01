#include "AI.h"
												//get��
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

												//get�� ��
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
												//�����ȵ� building��� ������ building��� ���� building�� ó���Ϸ�
		block_checking(building_list[i]);		
												//������ ���� �� ���� ������ ���̷����� �ɰ����� ���� ��� ���߽��� ���ε� �Ǵ��ϸ� 
												//�� ������ ���� ������ ���̰ų� �Ѵ�.
	}
}

void AI::block_checking(Building* b){
	double building_serious = 0;				//������ ���� �� ���� ������ ����, �� ������ �ٸ� �������� ��ȣ�ۿ��� control���ش�.
												//���� �������� �̻����� �ɰ�������, �� ������ ���� ������ ��� ��� �� ������ ���ο����� ���� �� ������ ������ �Ѵ�.
	double building_infected_percent = 0;		//������ ������
	double building_death_percent = 0;			//������ ������
	double virus_serious = 0;					//���̷��� �ɰ���
	double* temp_interact[2];					//�� �������� ���� ��ȣ�ۿ뼺
	b->getInfectPercent(building_infected_percent);
	b->getDeathPercent(building_death_percent);
	b->getInteract(temp_interact);
	vs->getSerious(virus_serious);
	building_serious = building_infected_percent + (building_death_percent + virus_serious)*5;
	if(building_serious > 150)/*�ɰ�����*/{
		for(int j=0; j<B_NUMBER; j++){
			
		}
	}
}

void AI::building_called(int index, char* _name, double& _uninfected, double& _infected, double& _dead, bool& on_block, bool& off_block){
	Building_Information temp_info;
	building_list[index]->getInformation(&temp_info);
	building_list[index]->getName(_name);		//�̸� ����	
	_uninfected = temp_info.uninfected_pc;		//�������� ���� pc����
	_infected = temp_info.infected_pc;			//������ pc����
	_dead = temp_info.dead_pc;					//���� pc����
	on_block = blocked_building[0][index];		//online�� block���� ����
	off_block = blocked_building[1][index];		//offline�� block���� ����
}