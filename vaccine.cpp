#include "vaccine.h"
#include "virus.h"

void Vaccine::do_operation() {
	developing_speed = 0.0001;

	for(int i=0; i<B_NUMBER; i++)
		pBuilding[i]->getC2V(developing_speed);

	current_developed_point += developing_speed;
}
void Vaccine::getVaccine(double& current_point, double& speed) {
	current_point = current_developed_point;
	speed = developing_speed;
}