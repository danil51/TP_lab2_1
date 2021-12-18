#include "Note.h"

Note::Note() : secondName("�� ������"), firstName("�� ������"), phoneNumber("�� ������")
{
	birthDate[0] = 0;
	birthDate[1] = 0;
	birthDate[2] = 0;
	cout << "������ ����������� Note" << endl;
}

Note::Note(string secondName, string firstName, int birthDate[3], string phoneNumber) :
	secondName(secondName), firstName(firstName), phoneNumber(phoneNumber)
{
	setBirthDate(birthDate);
	cout << "������ ����������� Note" << endl;
}

Note::Note(const Note& note) : secondName(note.secondName), firstName(note.firstName), phoneNumber(note.phoneNumber)
{
	setBirthDate(note.birthDate);
	cout << "������ ����������� ����������� Note" << endl;
}

Note::~Note()
{
	cout << "������ ���������� Note" << endl;
}

void Note::inputFromConsole()
{
	cout << "������� �������: ";
	getline(cin, secondName);
	cout << "������� ���: ";
	getline(cin, firstName);
	cout << "������� ���� ��������: ";
	birthDate[0] = safeInput(1, 31);
	cout << "������� ����� ��������: ";
	birthDate[1] = safeInput(1, 12);
	cout << "������� ��� ��������: ";
	birthDate[2] = safeInput(1, INT32_MAX);
	phoneNumber = inputPhoneNumber();
}

void Note::printToConsole()
{
	cout << "�������: " << secondName << endl;
	cout << "���: " << firstName << endl;
	cout << "���� ��������: " << birthDate[0] << "." << birthDate[1] << "." << birthDate[2] << endl;
	cout << "����� ��������: " << phoneNumber << endl;
}

void Note::change()
{
	cout << "������� ����� �������: ";
	getline(cin, secondName);
	cout << "������� ���� ���: ";
	getline(cin, firstName);
	cout << "������� ����� ���� ��������: ";
	birthDate[0] = safeInput(1, 31);
	cout << "������� ����� ��������: ";
	birthDate[1] = safeInput(1, 12);
	cout << "������� ����� ��� ��������:\n";
	birthDate[2] = safeInput(1, INT32_MAX);
	phoneNumber = inputPhoneNumber();
}

Note& Note::operator=(const Note& note) {
	if (this == &note)
		return *this;
	secondName = note.secondName;
	firstName = note.firstName;
	phoneNumber = note.phoneNumber;
	setBirthDate(note.birthDate);
	return *this;
}

bool Note::operator>(Note& note) {
	return (secondName > note.secondName) ||
		(secondName == note.secondName && firstName > note.firstName);
}