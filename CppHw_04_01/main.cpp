#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	std::string cityName;
	std::string streetName;
	unsigned houseNum;
	unsigned flatNum;

public:
	Address(std::string cityName, std::string streetName, unsigned houseNum, unsigned flatNum) {

		this->cityName = cityName;
		this->streetName = streetName;
		this->houseNum = houseNum;
		this->flatNum = flatNum;
	}

	Address() {

		this->cityName = "cityName undefined";
		this->streetName = "streetName undefined";
		this->houseNum = 0;
		this->flatNum = 0;
	}

	// Methods

	std::string SaveData(Address* address, int addressCount) {
		
		std::string str;
		std::string new_str;

		for (int i = addressCount-1; i >= 0; i--) {
				str = address[i].cityName + ", " +
					address[i].streetName + ", " +
				std::to_string(address[i].houseNum) + ", " +
				std::to_string(address[i].flatNum) + "\n";
				new_str += str;
		}
			
			return new_str;
		}
};


int main() {

	setlocale(LC_ALL, "ru");

	std::ifstream fin("in.txt");
	std::string buf;
	unsigned addressCount = 0;

	fin >> buf; //read a number address from the file
	addressCount = std::stoi(buf);

	Address* address = new Address[addressCount];

	//create var for each field
	std::string cityName;
	std::string streetName;
	unsigned houseNum;
	unsigned flatNum;

	std::string new_str; //to store data from class Address
			
	if (!fin.is_open()) {
		std::cout << "Ошибка. Файл не открыт!" << std::endl;
	}
	else {
		std::cout << "Файл открыт!" << std::endl;
		for (int i = 0; i < addressCount; ++i) {
			fin >> cityName;
			fin >> streetName;
			fin >> houseNum;
			fin >> flatNum;
			address[i] = Address(cityName, streetName, houseNum, flatNum);
			new_str = address->SaveData(address, addressCount);
		}
	}
	
	fin.close();

	std::ofstream fout ("out.txt", std:: ios:: app);
	fout << buf <<'\n' << new_str << std::endl;
	
	fout.close();
	delete[] address;

	/*Вопросы:
	1. 61 стр кода:
	Непонятно, как создать динамический массив объекта класса Address без конструктора по умолчанию. 
	Компилятор не дает.

	2. 32 стр кода:
	Для обратной сортировки пришлось менять логику записи строки из полей объекта класса 
	(от последнего элемента до нуля)

	3. Откуда-то в out.txt у меня появляется пустая строка, не могу найти причину. 
	Удалила все инициализации с пустыми строками. Все равно не получается записать в выходящий файл верно

	4. Задание очень сложное, тк никаких подводящих данных или информации, как работать с массивами объектов классов
	нам не давали
	*/
	
	
}