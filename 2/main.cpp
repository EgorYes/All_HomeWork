#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 20;
int m;

void Print(int* Arra)
{
	for (int i = 0; i < SIZE; i++)
		cout << Arra[i] << " ";

	cout << '\n';
}

void Print2(int* Arra)
{
	cout << "We output only even elements: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (Arra[i] % 2 == 0)
			cout << Arra[i] << " ";
	}
	cout << '\n';
}

void max(int* Arra)
{
	cout << "From more to less: " << endl;

	for (int i = 1; i < SIZE; i++)
	{
		if (Arra[i] > Arra[i - 1])
		{
			m = Arra[i];

			Arra[i] = Arra[i - 1];

			Arra[i - 1] = m;

			i = 0;
		}
	}

	Print(Arra);
}

void min(int* Arra)
{
	cout << "From less to more: " << endl;

	for (int i = 1; i < SIZE; i++)
	{
		if (Arra[i] < Arra[i - 1])
		{
			m = Arra[i];

			Arra[i] = Arra[i - 1];

			Arra[i - 1] = m;

			i = 0;
		}
	}

	Print(Arra);
}


int main()
{
	srand(time(0));

	int Arra[SIZE]; //Создаём массив

	for (int i = 0; i < SIZE; i++) //Заполняем его
		Arra[i] = (rand() % 10) + 1;


	int* p_Arra = Arra; //Создаём указатель на массив

	cout << "We display one of the array elements on the screen using a pointer: " << '\n' << p_Arra[6] << endl;

	cout << "We display the entire array on the screen :" << endl;

	Print(Arra);//Расписываем элементы массив

	Print2(Arra);//Расписываем чётные элементы массив

	max(Arra);// сортируем массив от большего к меньшему

	min(Arra);// сортируем массив от меньшего к большему

	return 0;
}
