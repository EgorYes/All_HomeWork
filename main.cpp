#include <iostream>
#include <string>
#include <ctime>

using namespace std;
string an;

struct specifications
{
	int N;
	char vid = N;
};

specifications symbol;


int main() {
	srand(time(0));
		
	while (true)
	{
		for (int i = 0; i < 10; i++)
		{									
			symbol.N = rand() % 255;
			
			cout << "Congratulations! You got an element: " << symbol.vid << endl;
			
			cout << "His address: " << symbol.vid << endl;

			cout << "His number: " << symbol.N << endl;					
		}
		cout << "Press 'Enter' to repeat the code execution" << endl;

		getline(cin, an);
	}

	return 0;
}
