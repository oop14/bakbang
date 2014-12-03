#include "virusStatus.h"

VirusStatus::VirusStatus() {};
VirusStatus::VirusStatus(double _infect[4], double _destroy[3], double _serious, double _vacMax) {
	for(int i=0; i<4; i++)
		infect[i] = _infect[i];
	for(int i=0; i<3; i++)
		destroy[i] = _destroy[i];
	serious = _serious;
	vacMax = _vacMax;
}
void VirusStatus::setInfo(double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9) {
	infect[0] = d1;
	infect[1] = d2;
	infect[2] = d3;
	infect[3] = d4;
	destroy[0] = d5;
	destroy[1] = d6;
	destroy[2] = d7;
	serious = d8;
	vacMax = d9;
}
void VirusStatus::showData(double info[3]) {
	for(int i=0; i<3; i++)
		info[i] = 0;
	for(int i=0; i<4; i++)
		info[0] += infect[i];
	for(int i=0; i<3; i++)
		info[1] += destroy[i];
	info[2] = serious;
}
