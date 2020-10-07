// Chattendance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const string Present[55] = { "Hamerty Abebe",
"Robin Alston",
"Alexandria Baker",
"Kendrick Bell",
"Russell Bishop",
"Amanuel Borga",
"Summer Boyd",
"Krishawn Brown",
"Carl Burch",
"Wayan Caldwell",
"Mercy Chebet",
"Mark Cole",
"Korderrick Davis",
"Subash Dhungana",
"Corey Dixon",
"Kobe Dixon",
"David Foster",
"Samuel Foster",
"Ryan Garry",
"Dorian Gray",
"James Harris",
"Stanley Harris",
"Vermont Haymon",
"Lorraine Hicks",
"Gregory Hobson",
"Nia Hodges",
"Cameron Jackson",
"Jarmira Jackson",
"Johnathan Johnson",
"SHAHASH KANDEL",
"Jorian Lenard",
"Clairice Magee",
"Darrell McClendon",
"DeMarco McDonald",
"Ariel McGee",
"Hakeem Menefee",
"Brittany Morgan",
"Hanif Muhammad",
"Martin Palomino",
"Janaurius Porter",
"Vincent Price",
"Godfrey Robinson",
"Tabitha Rosier",
"Carolyne Rutto",
"Eliza Samuels",
"Toy Slaughter",
"Shomari Smith",
"William Smith",
"Zachary Tate",
"Hervey Tchounwou",
"Caleb Wade",
"Austin Westmoreland",
"Simon Williams",
"Branden Willis",
"Kirubel Zebene" };

	bool here[55];

	char Comp[30];
	string Hold;

	fstream file;
	file.open("chat.txt");

	while (file.is_open()) {
		getline(file, Hold,']');
		for (int a = 0; a < 55; a++) {
			if (Hold.find(Present[a]) == 1 && here[a]!=true) {
				here[a] = true;
			}
		}
		if (file.eof()) {
			file.close();
		}
	} 

	for (int a = 0; a < 55; a++) {
		if (here[a] == true) {
			cout << Present[a] << endl;
		}
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
