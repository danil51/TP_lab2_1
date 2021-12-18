#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class Note
{
private:
	string secondName, firstName;
	int birthDate[3];
	string phoneNumber;
public:
	Note();
	Note(string secondName, string firstName, int birthDate[3], string phoneNumber);
	Note(const Note& note);
	~Note();

	void inputFromConsole();
	void printToConsole();
	void change();

	string getSecondName() { return secondName; }
	void setSecondName(string secondName) { this->secondName = secondName; }

	string getFirstName() { return firstName; }
	void setFirstName(string firstName) { this->firstName = firstName; }

	int* getBirthDate() { return birthDate; }
	void setBirthDate(const int birthDate[3]) { this->birthDate[0] = birthDate[0]; this->birthDate[1] = birthDate[1]; this->birthDate[2] = birthDate[2]; }

	string getPhoneNumber() { return phoneNumber; }
	void setPhoneNumber(string phoneNumber) { this->phoneNumber = phoneNumber; }

	Note& operator=(const Note& note);
	bool operator>(Note& note);
};

