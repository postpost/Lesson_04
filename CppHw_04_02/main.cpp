#include "main.h"
#include <iostream>
#include <string>
#include <fstream>

class Address {
private:
	std::string cityName;
	std::string streetName;
	unsigned houseNum;
	unsigned flatNum;

public:

	Address() {
		this->cityName = "undefined";
		this->streetName = "undefined";
		this->houseNum = 0;
		this->flatNum = 0;
	}

	Address(std::string cityName, std::string streetName, unsigned houseNum, unsigned flatNum) {
		this->cityName = cityName;
		this->streetName = streetName;
		this->houseNum = houseNum;
		this->flatNum = flatNum;
	}

	std::string SaveTostring(Address* address, int addressCount) {
		std::string str;
		std::string new_str;

		for (int i = 0; i < addressCount; i++) {
			str = address[i].cityName + ", "
				+ address[i].streetName + ", "
				+ std::to_string(address[i].houseNum) + ", "
				+ std::to_string(address[i].flatNum) + '\n';
			new_str += str;
		}
		return new_str;
	}

	void Sort(Address* address, int addressCount) {

		std::string new_str;
		std::string sorted_str;

		// array to collect first letters of the cities
		char* letter = new char [addressCount];
			for (int i = 0; i < addressCount; i++) {
				new_str = address[i].cityName;
				letter[i] = new_str[0];
			}
		
		// bubble sort
		for (int i = 0; i < addressCount; ++i) {
			for (int j = 0; j < addressCount - 1; ++j) {
					if (letter[j] > letter[j + 1]) {
					std::swap(letter[j], letter[j + 1]);
					std::swap(address[j], address[j + 1]);
					}
			}
		}
		// return sorted array:  
		/*for (int i = 0; i < addressCount; i++) {
			std::cout << '\n' << letter[i] << "-";
		}

		for (int i = 0; i < addressCount; i++) {
			std::cout << '\n' << address[i].cityName << "-";
		}*/
		delete[] letter;
	}
	
};

int main() {

	setlocale(LC_ALL, "ru");

	std::ifstream fin("in.txt");
	std::string buf;
	int addressCount = 0;
	fin >> buf; //read first string from the file

	addressCount = std::stoi(buf);

	Address* address = new Address [addressCount]; //array for class Address

	std::string cityName;
	std::string streetName;
	unsigned houseNum;
	unsigned flatNum;

	std::string str;

	if (!fin.is_open()) {

		std::cout << "Error. File is not open!";
	}
	else {

		std::cout << "File is open!" << std::endl;;
		for (int i = 0; i < addressCount; i++) {
			fin >> cityName;
			fin >> streetName;
			fin >> houseNum;
			fin >> flatNum;

			address[i] = Address(cityName, streetName, houseNum, flatNum);
			str = address[i].SaveTostring(address, addressCount);
		}
	}
	fin.close();
	
	//Sort and write to the file

	std::string new_str;

	address->Sort(address, addressCount);
	new_str = address->SaveTostring(address, addressCount);

	std::ofstream fout("out.txt", std::ios::app);
	fout << buf << '\n' << new_str;
	fout.close();
	
	delete[] address;
}


