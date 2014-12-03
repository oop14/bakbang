//
// vaccine.h
// OOP_proj
//
// Created by So 2014. 11. 24..
// Copyright (c) So. All rights reserved.
//

#ifndef _OOP_proj__vaccine_
#define _OOP_proj__vaccine_

class Virus;

class Vaccine {
private:
	Building** pBuilding;
	double current_developed_point;
	double developing_speed;
public:
	Vaccine(Virus* _virus, Building** _pBuilding) {
		_virus->getVirusStatus(Vstatus);
		pBuilding = _pBuilding;
		vaccine_point = 0;	
	};
	~Vaccine();
	void do_operation();
	void getVaccine const(double& current_point, double& speed);
};

#endif _OOP_proj__vaccine_