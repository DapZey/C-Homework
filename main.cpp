#include "Survivor.h"
#include "Tribe.h"

int main() {
	//Survivor s1;
	//s1.printSurvivor();

	Survivor s2("Moshe", 40, 'm');
	//s2.printSurvivor();

	//Survivor s3(true);
	//s3.printSurvivor();
	//Survivor s4(false);
	//s4.printSurvivor();

	//Survivor s5(s2);
	//s5.printSurvivor();

	Survivor s6("Ronna");
	//s6.printSurvivor();

	Survivor s7("Ronen", 25);
	//s7.printSurvivor();

	//Survivor s8 = {};//default constructor
	Survivor s9 = { "Eldad",65,'r' };
	//Survivor s10 = s9;//copy constructor
	//Survivor s11 = { s9 };//copy constructor
	//s8.printSurvivor();
	//s9.printSurvivor();
	//s10.printSurvivor();
	//s11.printSurvivor();
	Tribe myTribe;
    myTribe.addSurivovrToTribe();
    myTribe.addSurivovrToTribe();
    myTribe.addSurivovrToTribe();
    myTribe.sortTribe();
    myTribe.printTribe();
}