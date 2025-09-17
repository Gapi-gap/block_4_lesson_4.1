#include<iostream>
#include<fstream>
#include<string>

class Adress
{
public:
	
	Adress() = default;

	bool Initalizator(std::string adress, std::string street, std::string number_house, std::string number_apartment)
	{
		if (adress == " " || street == " " || number_house == " " || number_apartment == " ")
		{
			this->adress = "Не корректные данные в файле чтения.";
			return false;
		}
		this->adress = adress;
		this->street = street;
		this->number_house = number_house;
		this->number_apartment = number_apartment;
		return true;
	}

	std::string OutPutStr()
	{
		if (adress == "Не корректные данные в файле чтения.")
			return adress;
		return adress + ", " + street + ", " + number_house + ", " + number_apartment + ".";
	}

private:
	std::string adress;
	std::string street;
	std::string number_house;
	std::string number_apartment;
};

int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream InFile("in.txt");
	if (!InFile.is_open())
	{
		return 0;
	}
	std::string str_size_struct;
	getline(InFile, str_size_struct);
	size_t size_struct = std::stoi(str_size_struct);

	Adress* ptr_adress = new Adress[size_struct];
	
	for (int i = 0; i < size_struct; ++i)
	{
		std::string adress;
		std::string street;
		std::string str_number_house;
		std::string str_number_apartment;

		getline(InFile, adress);
		getline(InFile, street);
		getline(InFile, str_number_house);
		getline(InFile, str_number_apartment);


		ptr_adress[i].Initalizator(adress, street, str_number_house, str_number_apartment);

	}
	InFile.close();

	std::ofstream OutFile("out.txt");
	OutFile << str_size_struct<<std::endl;
	for (int i = size_struct - 1; i >= 0; --i)
	{
		OutFile << ptr_adress[i].OutPutStr() << std::endl;
	}
	OutFile.close();
	delete[] ptr_adress;
}