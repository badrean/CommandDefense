#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <random>
#include <iostream>
#include <cstdarg>

int char_to_int(char* s)
{

	if (s == nullptr) return 0;

	int res = 0;
	for (unsigned i = 0; i < strlen(s); i++)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}




Sort::Sort(unsigned count, int min, int max)
{
	elements_nr = count;
	list = new int[count];
	
	srand(time(NULL));
	for (unsigned i = 0; i < elements_nr; i++)
	{
		int randomNum = rand() % (max - min + 1) + min;
		*(list + i) = randomNum;
	}
}

Sort::Sort(unsigned count, int* list)
{
	elements_nr = count;
	this->list = list;
}

Sort::Sort(unsigned count, ...)
{
	elements_nr = count;
	list = new int[count];

	va_list argum;
	va_start(argum, count);
	for (unsigned i = 0; i < elements_nr; i++)
	{
		list[i] = va_arg(argum, int);
	}
	va_end(argum);
}

Sort::Sort(const char* string)
{
	int count = 1; //dupa ultimul nr nu e virgula asa ca o punem direct
	for (unsigned i = 0; i <= strlen(string); i++)
		if (string[i] == ',') count++;
	
	elements_nr = count;
	list = new int[elements_nr];
	
	char* pointer;
	char string_cpy[500];
	strcpy(string_cpy, string);
	pointer = strtok(string_cpy, ",");
	int i = 0;
	while (pointer != NULL)
	{
		list[i] = char_to_int(pointer);
		i++;
		pointer = strtok(NULL, ",");
	}
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < elements_nr; i++)
	{
		key = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > key)
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
	this->ordered = true;
}

void Sort::QuickSort(bool ascendent)
{
	int low, high;
	low = 0;
	high = elements_nr - 1;

	int stack[100];
	int top = -1;

	stack[++top] = low;
	stack[++top] = high;

	while (top >= 0)
	{
		high = stack[top--];
		low = stack[top--];
		
		int p = partition(list, low, high);

		if (p - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = p - 1;
		}
		if (p + 1 < high)
		{
			stack[++top] = p + 1;
			stack[++top] = high;
		}
	}
	this->ordered = true;
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;

	for(i = 0; i < elements_nr - 1; i++)
		for(j = 0; j < elements_nr - i - 1; j++)
			if (list[j] > list[j + 1])
			{
				int aux = list[j];
				list[j] = list[j+1];
				list[j+1] = aux;
			}

	this->ordered = true;
}

void Sort::Print()
{
	for (unsigned i = 0; i < elements_nr; i++)
		std::cout << *(list + i) << " ";
	std::cout << std::endl;
}

int Sort::GetElementsCount()
{
	return this->elements_nr;
}

int Sort::GetElementFromIndex(int index)
{
	return list[index];
}

int Sort::partition(int* arr, int low, int high)
{
	int pivot = list[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (list[j] <= pivot)
		{
			i++;
			int aux = list[i];
			list[i] = list[j];
			list[j] = aux;
		}
	}
	int temp = list[i + 1];
	list[i + 1] = list[high];
	list[high] = temp;
	return (i + 1);
}
