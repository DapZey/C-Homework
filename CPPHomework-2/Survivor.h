#pragma once
#include<iostream>
#include<string>

#define NAME_LEN 20
using namespace std;
class Survivor
{
private:
    string _survivorName;
    //char _survivorName[NAME_LEN+1];
    int _survivorAge;
    char _survivorStatus;//'m' = marriage , 's' = single , 'r' = in relationship
public:
    //getters:
    string getName() const { return this->_survivorName; }
    int getAge() const { return this->_survivorAge; }
    char getStatus() const { return this->_survivorStatus; }
    //setters:
    void setName(string n="Robinson") { this->_survivorName = n; }
    void setAge(int a=20) { this->_survivorAge = a; }
    void setStatus(char s='s') { this->_survivorStatus = s; }
    void setSurvivor(string n = "Robinson", int age = 20, char status = 's');

    //Constructors:
    //Survivor();
    Survivor(string n = "Robinson", int age = 20, char status = 's');
    Survivor(const Survivor& other);
    Survivor(bool flag);
    //Detructor:
    ~Survivor() {
        cout << "A survivor is destroyed from address : " << this << endl;
        cout << "The name of the destroyed survivor is : " << this->getName() << endl;
    }

    void printSurvivor() const;
};

