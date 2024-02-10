#include <iostream>
#include <string>
#include <ctime>

using namespace std;
string an;

struct specifications
{
	int N;
	char vid;
};

specifications symbol;


int main() {
	srand(time(0));

	while (true)
	{		
		symbol.N = rand() % 255;

		symbol.vid = symbol.N;

		cout << "Congratulations! You got an element: " << symbol.vid << endl;

		cout << "His number: " << symbol.N << endl;

		cout << "Press 'Enter' to repeat the code execution" << endl;

		getline(cin, an);
	}

	return 0;
}
