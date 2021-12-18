#include "Note.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Note>& notes);
void changeObject(Marray<Note>& notes);
void deleteObject(Marray<Note>& notes);
void print(Marray<Note>& notes);
void searchObjects(Marray<Note>& notes);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Note> notes;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(notes);
			break;
		case 2:
			changeObject(notes);
			break;
		case 3:
			deleteObject(notes);
			break;
		case 4:
			print(notes);
			break;
		case 5:
			searchObjects(notes);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ������ �� ������ ��������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Marray<Note>& notes) {
	Note student;
	student.inputFromConsole();
	notes += student;
	notes.sort();
}

void changeObject(Marray<Note>& notes) {
	if (notes.getSize() > 0) {
		print(notes);
		cout << "������� ����� ������ ��� ���������: ";
		notes[safeInput(1, notes.getSize()) - 1].change();
	}
	else
		cout << "������ ������� ����. ������ ��������\n";
	notes.sort();
}

void deleteObject(Marray<Note>& notes) {
	if (notes.getSize() > 0) {
		print(notes);
		cout << "������� ����� ������ ��� ��������: ";
		notes -= safeInput(1, notes.getSize()) - 1;
	}
	else
		cout << "������ ������� ����. ������ �������\n";
	notes.sort();
}

void print(Marray<Note>& notes) {
	if (notes.getSize() == 0)
		cout << "������ ������� ����.\n";
	else {
		cout << "������ �������\n";
		for (int i = 0; i < notes.getSize(); i++) {
			cout << i + 1 << ". ������\n";
			notes[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Note>& notes) {
	if (notes.getSize() == 0)
		cout << "������ ������� ����\n";
	else {
		bool isPrint = false;
		cout << "������� ����� ��������: ";
		int mounht = safeInput(1, 12);
		for (int i = 0; i < notes.getSize(); i++)
				if (notes[i].getBirthDate()[1] == mounht) {
					isPrint = true;
					notes[i].printToConsole();
				}
			
		if (!isPrint)
			cout << "�����, � ����� ������� �������� ���.\n";
	}
}