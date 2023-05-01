// Task 1. Write a function that receives a pointer to an array and its size. 
// The function should remove all negative numbers from the array and return a pointer to the new array
//

#include <iostream>
using namespace std;

void GenerateArray(int* arr, int* size);//Generate function
void PrintArray(int* arr, int* size);//Print function
int* Pozitivator(int* arr, int* size);//Create new array only with pozitive numbers

int main()
{

	int arr[10];
	int size = sizeof(arr) / sizeof(int);

	GenerateArray(arr, &size);//Generate function

	cout << "\n\n\tArray: ";
	PrintArray(arr, &size);//Print function

	int* arr_new = Pozitivator(arr, &size);//Create new array only with pozitive numbers

	cout << "\n\n\tNew Array: ";
	PrintArray(arr_new, &size);//Print function
}

void GenerateArray(int* arr, int* size)//Generate function
{
	srand(time(NULL));

	for (int i = 0; i < *size; i++)
	{
		int ran = rand() % 2 + 0;
		if (ran != 0)
		{
			ran = rand() % 5 + 0;
			ran = -ran;
			*(arr + i) = ran;
		}
		else
		{
			*(arr + i) = rand() % 5 + 0;
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

int* Pozitivator(int* arr, int* size)//Create new array only with pozitive numbers
{
	int* arr_new = new int[*size];
	int j = -1;

	for (int i = 0; i < *size; i++)
	{
		if (*(arr + i) >= 0)
		{
			j++;
			*(arr_new + j) = *(arr + i);
		}
	}

	*size = j + 1;
	return arr_new;
}