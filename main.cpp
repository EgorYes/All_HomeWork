#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

string an;
int temp;
vector<char> sim;
int temp3;

union specifications
{
	int n;
	char vid;
};

void secret(string* an, vector<char>* sim)
{
	int SIZE = an->size();
	for (int i = 0; i < SIZE; ++i)
	{
		sim->push_back((*an)[i]);
	}
}

int main() {
	srand(time(0));

	while (true)
	{
		specifications symbol = { rand() % 255 };

		cout << "Symbol:" << '\t' << "Number:" << '\t' << "From the range(-127, +127): " << endl;

		cout << symbol.vid << '\t' << symbol.n << '\t' << static_cast<int>(symbol.vid) << endl;

		while (true)
		{
			getline(cin, an);

			const char* q = an.data();

			temp = static_cast<int>(*q);

			if (temp != 0)
			{
				sim.clear();

				secret(&an, &sim);

				cout << "Symbol:" << '\t' << "Number:" << '\t' << "Number from the range(-127, +127): " << endl;

				for (int i = 0; i < sim.size(); i++)
				{
					temp = static_cast<int>(sim[i]);

					if (temp < 0)
					{
						temp = 127 + (129 + static_cast<int>(sim[i]));
					}

					cout << sim[i] << '\t' << temp << '\t' << static_cast<int>(sim[i]) << endl;
				}
				cout << "Press 'Enter' to repeat the code execution, or write any characters to find out about them:" << endl;
			}
			else
			{
				break;
			}

		}

	}

	return 0;
}
