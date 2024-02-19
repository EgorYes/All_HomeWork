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
	int min = Arra[0], max = Arra[0];
	cout << "From less to more: " << endl;

	int Temp[SIZE];

	for (int q = 0; q < SIZE; q++)
	{
		Temp[q] = Arra[q];//собираем новый массив на основе старого

		if (max < Temp[q])
			max = Temp[q] + 1;//находим макисмальное число и прибавояем к нему 1, чтобы оно не мегало

		if (min > Temp[q])
			min = Temp[q];// находим минимум новой матрицы
	}

	for (int i = 0; i < SIZE; i++)
	{
		int q = 0;

		Arra[i] = min;

		while (q < SIZE)
		{
			if (Temp[q] == min)
			{
				Temp[q] = max;//убираем один из минимальных, который мы занесли в основную матрицу

				break;
			}
			++q;
		}
		min = max;

		for (int q = 0; q < SIZE; q++)
		{
			if (min > Temp[q])//начинаем снова искать минимальные элементы
				min = Temp[q];
		}
	}
	Print(Arra);
}


int main()
{
	srand(time(0));

	int Arra[SIZE]; //Создаём массив

	for (int i = 0; i < SIZE; i++) //Заполняем его
		Arra[i] = (rand() % 20) + 1;


	int* p_Arra = Arra; //Создаём указатель на массив

	cout << "We display one of the array elements on the screen using a pointer: " << '\n' << p_Arra[0] << endl;

	cout << "We display the entire array on the screen :" << endl;

	Print(Arra);//Расписываем элементы массив

	Print2(Arra);//Расписываем чётные элементы массив

	max(Arra);// сортируем массив от большего к меньшему

	min(Arra);// сортируем массив от меньшего к большему другим способом

	return 0;
}
