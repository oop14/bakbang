//
// virusStatus.h
// OOP_proj
//
// Created by So 2014. 11. 17..
// Copyright (c) So. All rights reserved.
//

#ifndef _OOP_proj__VirusStatus_
#define _OOP_proj__VirusStatus_

class VirusStatus {
private:
	double infect[4];
	double destroy[3];
	double serious;
	double vacMax;
public:
	VirusStatus();
	VirusStatus(double _infect[4], double _destroy[3], double _serious, double _vacMax);
	void setInfo(double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9);
	void getInfect const(double* _infect) { _infect = infect; };
	void getDestroy const(double* _destroy) { _destroy = destroy; };
	void getSerious(double& _serious) { _serious = serious; };
	void getVacMax(double& _vacMax) { _vacMax = vacMax; };
	void showData(double info[3]);
	const VirusStatus operator+(const VirusStatus &P) {
		for(int i=0; i<4; i++)
			infect[i] += P.infect[i];
		for(int i=0; i<3; i++)
			destroy[i] += P.destroy[i];
		serious += P.serious;
		vacMax += P.vacMax;
	}
	const VirusStatus operator*(const int &X) {
		for(int i=0; i<4; i++)
			infect[i] *= X;
		for(int i=0; i<3; i++)
			destroy[i] *= X;
		serious *= X;
		vacMax *= P.vacMax;
	}
};

#endif _OOP_proj__VirusStatus_