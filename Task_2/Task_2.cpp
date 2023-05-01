// Task 2. Write a function that takes two pointers to arrays of integers and their sizes,
// and returns a pointer to a new array that contains only those elements that are in both arrays
//

#include <iostream>
using namespace std;

void GenerateArray(int* arr, int* size);//Generate function
void PrintArray(int* arr, int* size);//Print function
int* Identicator(int* arr_1, int* size_1, int* arr_2, int* size_2, int* size);//Gets two arrays and returns a pointer by one with elements that are repeated in both

int main()
{
	srand(time(NULL));

	int arr_1[15];
	int size_1 = sizeof(arr_1) / sizeof(int);
	GenerateArray(arr_1, &size_1);//Generate first array

	cout << "\n\n\tArray 1: ";
	PrintArray(arr_1, &size_1);//Print first array

	int arr_2[10];
	int size_2 = sizeof(arr_2) / sizeof(int);
	GenerateArray(arr_2, &size_2);//Generate second array

	cout << "\n\n\tArray 2: ";
	PrintArray(arr_2, &size_2);//Print second array

	int size = size_1 + size_2;
	int* arr_new = Identicator(arr_1, &size_1, arr_2, &size_2, &size);

	cout << "\n\n\tArray 3: ";
	PrintArray(arr_new, &size);//Print new array
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

int* Identicator(int* arr_1, int* size_1, int* arr_2, int* size_2, int* size)//Gets two arrays and returns a pointer by one with elements that are repeated in both
{
	int* arr_new = new int[*size];
	*size = 0;

	for (int i = 0; i < *size_1; i++)
	{
		for (int j = 0; j < *size_2; j++)
		{
			if (*(arr_1 + i) == *(arr_2 + j))//Finds matches and puts into a new array
			{
				*(arr_new + *size) = *(arr_1 + i);
				*size = *size + 1;
				for (int k = 0; k < *size; k++)
				{
					if (*(arr_new + k) == *(arr_new + k - 1))//Validates a new array and does not allow repetitions
					{
						*size = *size - 1;
						break;
					}
				}
			}
		}
	}
	return arr_new;
}