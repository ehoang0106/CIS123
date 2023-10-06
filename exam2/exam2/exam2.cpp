#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


void loadData(vector<string>& plate);
bool validPlate(string plate);
bool findPlate(vector<string> plates, string plate);
bool hasTicket(vector<string> plates, string plate);
void addPlate(vector<string>& plates);


int main()
{
	vector<string> plates;


	loadData(plates);
	
	string licensePlate;
	bool quit = false;
	while (!quit)
	{
		////debug print out license plates

		//for (int i = 0; i < plates.size(); i++)
		//{
		//	cout << plates[i] << endl;
		//}

		////
		char option;
		cout << "Enter (f) to find a plate" << endl;
		cout << "Enter (a) to add a plate" << endl;
		cout << "Enter (q) to quit" << endl;
		cout << "Choose: ";
		cin >> option;
		cin.ignore();

		if (option == 'f')
		{
			cout << "Enter a license plate: ";
			cin >> licensePlate;
			cin.ignore();

			if (licensePlate == "q")
			{
				quit = true;
				break;
			}

			if (validPlate(licensePlate))
			{
				if (findPlate(plates, licensePlate))
				{
					cout << "License plate " << licensePlate << " found!" << endl;
				}
				else
				{
					cout << "License plate " << licensePlate << " not found!" << endl;
				}

				if (hasTicket(plates, licensePlate))
				{
					cout << "You car has received a ticket in the past month!" << endl;
				}
				else
				{
					cout << "You are a good driver. You've not received any ticket!" << endl;
				}
			}
			else
			{
				cout << "Invalid license plate format. Try again!" << endl;
			}

			
		}
		else if(option == 'a')
		{
			addPlate(plates);
		}
		else if (option == 'q')
		{
			
			quit = true;
		}
		else
		{
			cout << "Invalid option! Try again." << endl;
		}
	}
	

	//write file
	ofstream outputFile("plates.txt");

	if (outputFile.is_open())
	{
		for (int i = 0; i < plates.size(); i++)
		{

			outputFile << plates[i];
			//to avoid blank line after the laste element in vector plates
			if (i < plates.size() - 1)
			{
				outputFile << "\n";
			}
		}

		outputFile.close();
	}
	else
	{
		cout << "Error! Unable to write to file" << endl;
	}



	return 0;
}

void loadData(vector<string>& plates) 
{
	string plate;
	ifstream inputFile;
	inputFile.open("plates.txt");

	while (!inputFile.eof())
	{
		getline(inputFile, plate);
		plates.push_back(plate);
	}
	inputFile.close();
}


bool validPlate(string plate)
{
	if (plate.length() != 7)
	{
		return false;
	}

	if (!isalpha(plate[0]))
	{
		return false;
	}

	for (int i = 1; i < 7; i++)
	{
		if (!isdigit(plate[i]))
		{
			return false;
		}
	}

	return true;
}

bool findPlate(vector<string> plates, string plate)
{
	for (int i = 0; i < plates.size(); i++)
	{
		if (plates[i] == plate)
		{
			return true;
		}
	}
	return false;
}

bool hasTicket(vector<string> plates, string plate)
{
	for (int i = 0; i < plates.size(); i++)
	{
		if (plates[i] == plate)
		{
			return true;
		}
		
	}
	return false;
}


void addPlate(vector<string>& plates)
{
	string licensePlate;

	cout << "Enter license plate: ";
	getline(cin, licensePlate);


	if (findPlate(plates, licensePlate))
	{
		cout << "License plate already exists" << endl;
		return;
	}

	if (!validPlate(licensePlate))
	{
		cout << "Invalid license plate format!" << endl;
		return;
	}

	plates.push_back(licensePlate);
	cout << "Successfully added license plate!" << endl;

}
