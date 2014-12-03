#include <iostream>
#include <string.h>
#include "virus.h"

void boolcpy(bool* dest, char* src) {
	for(int i=0; src[i]!=NULL; i++)
		dest[i] = !(src[i] == '0')
}

Virus::Virus() {
}
Virus::~Virus() {
}
void Virus::setTech(int difficulty, int cost_buf, double vac_buf, double stat_buf) {
	
	double inf[4] = {0}, des[3] = {0};
	Vstatus = new VirusStatus(inf,des,1,100+vac_buf);

	char** nameArr[3];
	char** infoArr[3];
	int* costArr[3];
	bool** indexArr[3];
	VirusStatus* statArr[3];
	int techNum[3] = {5,4,6};

	for(int i=0; i<3; i++) {
		status[i] = new TechTree(techNum[i]);
		status[i]->setMaxLevel(3);
		nameArr[i] = new char*[techNum[i]];
		infoArr[i] = new char*[techNum[i]];
		indexArr[i] = new bool*[techNum[i]];
		for(int j=0; j<techNum[i]; j++) {
			nameArr[i][j] = new char[21];
			infoArr[i][j] = new char[41];
			indexArr[i][j] = new char[techNum[i]];
		}
		costArr[i] = new int[techNum[i]];
		statArr[i] = new VirusStatus[techNum[i]];
	}

	status[0]->setName("Spread","감염 속도 높이는 기술들");
	status[1]->setName("Attack","컴퓨터 파괴 속도 높이는 기술들");
	status[2]->setName("Hiding","백신으로부터 숨는 기술들");


	boolcpy(indexArr[0][0],"00000");	strcpy(nameArr[0][0],"Internet");
	strcpy(infoArr[0][0],"Online 감염");
	cost[0][0] = 3;						statArr[0][0].setInfo(2,2,0,0,0,0,0,1,0);

	boolcpy(indexArr[0][1],"10000");	strcpy(nameArr[0][1],"P2P/웹하드");
	strcpy(infoArr[0][1],"Online 감염++");
	cost[0][1] = 7;						statArr[0][1].setInfo(7,7,0,0,0,0,0,5,0);

	boolcpy(indexArr[0][2],"00000");	strcpy(nameArr[0][2],"HDD/SSD");
	strcpy(infoArr[0][2],"Offline 감염");
	cost[0][2] = 4;						statArr[0][2].setInfo(3,0,3,0,0,0,0,1,0);

	boolcpy(indexArr[0][3],"00000");	strcpy(nameArr[0][3],"USB/SD/CD/DVD");
	strcpy(infoArr[0][3],"Offline 감염");
	cost[0][3] = 2;						statArr[0][3].setInfo(3,0,3,0,0,0,0,3,0);
	
	boolcpy(indexArr[0][4],"00110");	strcpy(nameArr[0][4],"Plug");
	strcpy(infoArr[0][4],"Offline 감염++");
	cost[0][4] = 10;					statArr[0][4].setInfo(1,1,1,1,0,0,0,0,0);



	boolcpy(indexArr[1][0],"0000");		strcpy(nameArr[1][0],"Copy");
	strcpy(infoArr[1][0],"Ctrl + C, Ctrl + V");
	cost[1][0] = 3;						statArr[1][0].setInfo(1,1,0,0,3,0,0,3,0);

	boolcpy(indexArr[1][1],"0000");		strcpy(nameArr[1][1],"Overload");
	strcpy(infoArr[1][1],"과부하");
	cost[1][1] = 5;						statArr[1][1].setInfo(0,0,0,0,3,2,0,7,0);

	boolcpy(indexArr[1][2],"0000");		strcpy(nameArr[1][2],"Modify");
	strcpy(infoArr[1][2],"변조");
	cost[1][2] = 5;						statArr[1][2].setInfo(0,0,0,0,2,0,0,0,0);

	boolcpy(indexArr[1][3],"0000");		strcpy(nameArr[1][3],"Delete");
	strcpy(infoArr[1][3],"지우기");
	cost[1][3] = 3;						statArr[1][3].setInfo(0,0,0,0,3,2,1,30,0);



	boolcpy(indexArr[2][0],"000000");	strcpy(nameArr[2][0],"Hiding");
	strcpy(infoArr[2][0],"숨기기");
	cost[2][0] = 2;						statArr[2][0].setInfo(0,0,0,0,0,0,0,0,1);

	boolcpy(indexArr[2][1],"100000");	strcpy(nameArr[2][1],"BackDoor");
	strcpy(infoArr[2][1],"마스터이?!");
	cost[2][1] = 3;						statArr[2][1].setInfo(0,0,0,0,0,0,0,0,2);

	boolcpy(indexArr[2][2],"110000");	strcpy(nameArr[2][2],"RootKit");
	strcpy(infoArr[2][2],"툴바?!");
	cost[2][2] = 5;						statArr[2][2].setInfo(0,0,0,0,0,0,0,0,3);

	boolcpy(indexArr[2][3],"100000");	strcpy(nameArr[2][3],"Worm(Dummy)");
	strcpy(infoArr[2][3],"가짜 인형 생성?!");
	cost[2][3] = 5;						statArr[2][3].setInfo(1,1,0,0,0,0,0,0,2);

	boolcpy(indexArr[2][4],"100000");	strcpy(nameArr[2][4],"Trojan horse");
	strcpy(infoArr[2][4],"아닌 듯 숨어들어갔다가 나오기");
	cost[2][4] = 4;						statArr[2][4].setInfo(1,1,0,0,0,0,0,1,2);

	boolcpy(indexArr[2][5],"110110");	strcpy(nameArr[2][5],"Vaccine Disabler");
	strcpy(infoArr[2][5],"백신 내성");
	cost[2][5] = 7;						statArr[2][5].setInfo(0,0,0,0,0,0,0,0,5);



	for(int i=0; i<3; i++) {
		for(int j=0; j<techNum; j++) {
			cost[i][j] += cost_buf;
			statArr[i][j] *= ( 1 + stat_buf );
		}
		status[i]->setStruct(nameArr[i],infoArr[i],costArr[i],indexArr[i],statArr[i]);
	}
	
	for(int i=0; i<3; i++) {
		delete[]nameArr[i];
		delete[]costArr[i];
		delete[]indexArr[i];
		delete[]statArr[i];
	}
}
void Virus::getVirusStatus(VirusStatus* _Vstatus) {
	_Vstatus = Vstatus;
}
void Virus::setDifficulty(int _difficulty, int _sinario) {
	difficulty = _difficulty;
	sinario = _sinario;

	setTech(difficulty, difficulty/2, (sinario==1)*10+difficulty, (sinario==2)*0.1);//임의 지정
}
void Virus::getTechTree(int index, TechTree* _tree) {
	_tree = NULL;
	if( index<3 && index>=0 )
		_tree = status[index];
}