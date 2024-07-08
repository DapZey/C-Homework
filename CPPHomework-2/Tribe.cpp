#include "Tribe.h"

void Tribe::sortTribe() {
    std::cout<< "sorting\n";
    std::sort(_survivorsArray,_survivorsArray + _numSurvivors, compareSurvivorNames);
    std::cout<<"sorted";
}
void Tribe::findYoungest() {
    Survivor* s = _survivorsArray[0];
    int sIndex = 1;
    if (_numSurvivors > 1){
        for (int i = 1; i < _numSurvivors; i++){
            if (_survivorsArray[i]->getAge() < s->getAge()){
                s = _survivorsArray[i];
                sIndex = i;
            }
        }
    }
        delete _survivorsArray[sIndex];
    for (int i = sIndex; i < (this->_numSurvivors - 1); i++)
        this->_survivorsArray[i] = this->_survivorsArray[i + 1];
    this->_survivorsArray[this->_numSurvivors - 1] = nullptr;
    this->_numSurvivors--;
}
Tribe::Tribe(string n, int max) {
    this->setTribe(n, max);
}
void Tribe::setTribe(string n, int max) {
    this->_tribeName = n;
    this->_maxSurvivors = max;
    this->_numSurvivors = 0;
    this->_survivorsArray = new Survivor * [max];
    for (int i = 0; i < max; i++)
        this->_survivorsArray[i] = NULL;
}
Tribe::~Tribe() {
    for (int i = 0; i < this->_numSurvivors; i++)
        delete this->_survivorsArray[i];
    delete[] this->_survivorsArray;
}
void Tribe::printTribe() const {
    cout << "Tribe details : " << endl;
    cout << "Tribe's name : " << this->_tribeName << endl;
    cout << "Tribe's capacity : " << this->_maxSurvivors << endl;
    cout << "Number of survivors : " << this->_numSurvivors << endl;
    for (int i = 0; i < this->_numSurvivors; i++) {
        cout << "Survivor number " << i << " : " << endl;
        this->_survivorsArray[i]->printSurvivor();
    }
}
void Tribe::addSurivovrToTribe() {
    string n;
    int a;
    char status;

    if (this->_maxSurvivors == this->_numSurvivors) {
        cout << "No space in the tribe for a new survivor" << endl;
        return;
    }
    cout << "Enter the new survivor's name : ";
    cin >> n;
    cout << "Enter the new survivor's age : ";
    cin >> a;
    cout << "Enter the survivor's stats (m/s/r) : ";
    cin >> status;
    Survivor* newSurv = new Survivor(n, a, status);
    this->_survivorsArray[this->_numSurvivors++] = newSurv;
    cout << "A new survivor is inserted to the tribe..." << endl;
}
void Tribe::removeSurivorFromTribe() {
    string n;
    cout << "Enter the survivor's name to remove : ";
    cin >> n;
    int index = this->findSurvivorByName(n);
    if (index == -1) {
        cout << "No survivor with this name, try again later..." << endl;
        return;
    }
    delete this->_survivorsArray[index];
    for (int i = index; i < (this->_numSurvivors - 1); i++)
        this->_survivorsArray[i] = this->_survivorsArray[i + 1];
    this->_survivorsArray[this->_numSurvivors - 1] = NULL;
    this->_numSurvivors--;
    cout << "A survivor is removed from the tribe..." << endl;
}
int Tribe::findSurvivorByName(string n) {
    for (int i = 0; i < this->_numSurvivors; i++)
        if (this->_survivorsArray[i]->getName() == n)
            return i;
    return -1;
}
void Tribe::MENU() {
    int choice;
    int index;
    string n;
    while (1) {
        cout << "MENU" << endl;
        cout << "1) Print the tribe" << endl;
        cout << "2) Insert a new survivor" << endl;
        cout << "3) Remove survivor from the tribe" << endl;
        cout << "4) Find a survivor by name" << endl;
        cout<< "5) sort survivors list\n";
        cout<<"6) remove youngest survivor\n";
        cout << "7) Exit" << endl;
        cout << "Your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                this->printTribe();
                break;
            case 2:
                this->addSurivovrToTribe();
                break;
            case 3:
                this->removeSurivorFromTribe();
                break;
            case 4:

                cout << "Enter the survivor to find : ";
                cin >> n;
                index = this->findSurvivorByName(n);
                if (index == -1) {
                    cout << "No survivor such that" << endl;
                }
                else {
                    cout << "Foud at index : " << index << endl;
                    this->_survivorsArray[index]->printSurvivor();
                }

                break;
            case 5:
                this->sortTribe();
                break;
            case 6:
                this->findYoungest();
                break;
            case 7:
                cout << "Bye bye, see you again soon..." << endl;
                return;

            default:
                cout << "Wrong choice, please try again..." << endl;
        }
    }
}
