// Task 3. Write a function that receives a pointer to an array and its size, 
// and returns the number of negative, positive, and zero elements of the array.
//

#include <iostream>
using namespace std;

void GenerateArray(int* arr, int* size);//Generate function
void PrintArray(int* arr, int* size);//Print function
void Determinator(int* arr, int* size, int* pp, int* pz, int* pn);//Determinate Positive, Negative and Zero elements

int main()
{
	srand(time(NULL));

	int arr[15];
	int size = sizeof(arr) / sizeof(int);
	GenerateArray(arr, &size);//Generate function

	cout << "\n\n\tArray 1: ";
	PrintArray(arr, &size);//Print function

	int positive = 0;
	int negative = 0;
	int zero = 0;

	Determinator(arr, &size, &positive, &zero, &negative);//Determinate Positive, Negative and Zero elements

	cout << "\n\n\tPositive elements:\t" << positive;
	cout << "\n\tNegative elements:\t" << negative;
	cout << "\n\tZero elements:\t\t" << zero;
	cout << "\n\n\n";
}

void GenerateArray(int* arr, int* size)//Generate function
{
	for (int i = 0; i < *size; i++)
	{
		int ran = rand() % 2 + 0;
		if (ran != 0)
		{
			ran = rand() % 10 + 0;
			ran = -ran;
			*(arr + i) = ran;
		}
		else
		{
			*(arr + i) = rand() % 10 + 0;
		}
	}
}

void PrintArray(int* arr, int* size)//Print function
{
	for (int i = 0; i < *size; i++)
	{
		cout << *(arr + i) << " ";
	}
}

void Determinator(int* arr, int* size, int* pp, int* pz, int* pn)//Determinate Positive, Negative and Zero elements
{
	for (int i = 0; i < *size; i++)
	{
		if (*(arr + i) > 0)//Positive elements
		{
			*pp = *pp + 1;
		}
		else if (*(arr + i) == 0)//Zero elements
		{
			*pz = *pz + 1;
		}
		else if (*(arr + i) < 0)//Negative elements
		{
			*pn = *pn + 1;
		}
	}
}