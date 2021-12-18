#include "helper.h"

bool checkStringToPhoneNumber(std::string s) {
	if (s.size() != 11)
		return false;
	for (char ch : s)
		if (!isdigit(ch))
			return false;
	return true;
}

std::string inputPhoneNumber() {
	std::cout << "Введите номер телефона(11 цифр): ";
	std::string phone;
	while (true) {
		std::cin >> phone;
		if (!checkStringToPhoneNumber(phone))
			std::cout << "Неверный ввод.\nПовторите снова: " << std::endl;
		else
			return phone;
	}
}