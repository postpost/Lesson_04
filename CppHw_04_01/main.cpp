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
		std::cout << "������. ���� �� ������!" << std::endl;
	}
	else {
		std::cout << "���� ������!" << std::endl;
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

	/*�������:
	1. 61 ��� ����:
	���������, ��� ������� ������������ ������ ������� ������ Address ��� ������������ �� ���������. 
	���������� �� ����.

	2. 32 ��� ����:
	��� �������� ���������� �������� ������ ������ ������ ������ �� ����� ������� ������ 
	(�� ���������� �������� �� ����)

	3. ������-�� � out.txt � ���� ���������� ������ ������, �� ���� ����� �������. 
	������� ��� ������������� � ������� ��������. ��� ����� �� ���������� �������� � ��������� ���� �����

	4. ������� ����� �������, �� ������� ���������� ������ ��� ����������, ��� �������� � ��������� �������� �������
	��� �� ������
	*/
	
	
}