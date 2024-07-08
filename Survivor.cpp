#include "Survivor.h"

void Survivor::setSurvivor(string n, int age, char status) {
    this->setName(n);
    this->setAge(age);
    this->setStatus(status);
}

Survivor::Survivor(string n, int a, char s) {
    this->setSurvivor(n, a, s);
}
Survivor::Survivor(const Survivor& other) {
    this->setSurvivor(other.getName(), other.getAge(), other.getStatus());
}
Survivor::Survivor(bool flag) {
    if (flag)
        this->setSurvivor("Robinson_Cruso", 30, 'm');
    else
        this->setSurvivor("Tommas_Edison", 70, 's');

}
void Survivor::printSurvivor() const {
    cout<<"****************************************"<<endl;
    cout << "Survivor's name : " << this->getName() << endl;
    cout << "Survivor's age : " << this->getAge() << endl;
    if (this->getStatus() == 'r')
        cout << "Surivor stauts : in relationship" << endl;
    else if(this->getStatus()=='m')
        cout << "Surivor stauts : Marriade" << endl;
    else
        cout << "Surivor stauts : Single" << endl;
    cout<<"****************************************"<<endl;
}

