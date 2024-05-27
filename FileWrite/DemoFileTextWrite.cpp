#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class City
{
	string name;
public:
	City() { name = "Cambridge";  cout << name << " is a wonderful city.\n"; } //empty constructor
	City(string input) { name = input;  cout << input << " is a city.\n"; } //constructor 
	~City() { cout << "City deleted." << endl; } //de-constructor
	string getName()
	{
		return name; //returns the string name
	}
	void setName( string newcity)
	{
		name = newcity;
	}
};

int main(void)
{
	ifstream is("testfile.txt"); 
	fstream outFile;// Define variable for data to be written and read to/from file
	outFile.open("testfile.txt", ios::out|ios::in|ios::binary);
	
	if (outFile.is_open() == false)
	{
		cout << "Error opening file\n" << endl;
	}
	else
	{
		outFile.clear(); //make sure file is clear
		City* city = new City(); //dynamic obj
		outFile.seekg(0); //put pointer at position 0
		outFile.write((char*)&city, sizeof(City)); //write city at position
		outFile.seekg(0); //put pointer to read from position 0
		if (outFile.read((char*)&city, sizeof(City))) //read city from position 
			cout << "City read successfully. - " << city->getName() << endl;
		else cout << "Error while reading." << endl;
		delete city; //destructor

		
		system("PAUSE"); //pause

		
		city = new City("London"); //dynamic obj
		outFile.seekg(50); //put pointer at position 50
		outFile.write((char*)&city,sizeof(City)); //write city at position
		outFile.seekg(50); //put pointer at position 50
		if (outFile.read((char*)&city, sizeof(City))) //read city from position 
			cout << "City read successfully. - "<< city->getName() << endl;
		else cout << "Error while reading." << endl;
		delete city;
		
	}
	
	outFile.close();
	system("pause");
	return 0;
	

}	