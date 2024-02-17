#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

string input;
int temp;
vector<char> Vect;

union specifications //union позволяет нам заполнить все показатели одни и тем же числом
{
	short n;
	char vid;
};

void secret(string* input, vector<char>* Vect) // Заполняем вектор тем, что ввёл пользователь
{
	int SIZE = input->size();
	for (int i = 0; i < SIZE; ++i)
	{
		Vect->push_back((*input)[i]);
	}
}

int main() {
	srand(time(0));

	while (true)
	{
		cout << "Press 'Enter' to repeat the code execution or write any characters to find out about them:" << endl; /*Просим пользователя нажать Enter, чтобы программа сама написала свойства рандомного символо,
													                      или пользователь может сам написать символы и уже их программа расшифрует */
		getline(cin, input); //Полуечаем ответ от пользователя

		if (input.size() == 0)
		{
			specifications s = { rand() % 255 };

			cout << "Symbol:" << '\t' << "Number:" << '\t' << "Number from the range(-127, +127): " << endl;

			cout << s.vid << '\t' << s.n << '\t' << static_cast<int>(s.vid) << endl;
		}
		else
		{
			Vect.clear();

			secret(&input, &Vect);

			cout << "Symbol:" << '\t' << "Number:" << '\t' << "Number from the range(-127, +127): " << endl;

			for (int i = 0; i < Vect.size(); i++) // выводим всё, что нашли
			{
				temp = static_cast<int>(Vect[i]);

				if (static_cast<int>(Vect[i]) < 0)
				{
					temp = 127 + (129 + static_cast<int>(Vect[i]));
				}

				cout << Vect[i] << '\t' << temp << '\t' << static_cast<int>(Vect[i]) << endl;
			}
		}
	}

	return 0;
}
