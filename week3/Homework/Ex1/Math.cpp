#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int a, int b)
{
	return a+b;
}

int Math::Add(int a, int b, int c)
{
	return a+b+c;
}

int Math::Add(double a, double b)
{
	return a+b;
}

int Math::Add(double a, double b, double c)
{
	return a+b+c;
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a*b*c;
}

int Math::Mul(double a, double b)
{
	return a*b;
}

int Math::Mul(double a, double b, double c)
{
	return a*b*c;
}

int Math::Add(int count, ...)
{
	va_list list;
	va_start(list, count);

	int value, sum = 0;
	
	for (int i = 0; i < count; i++)
	{
		value = va_arg(list, int);
		sum += value;
	}

	va_end(list);

	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	char* joined = new char[strlen(a) + strlen(b) + 1];
	if (strlen(a) == 0 || strlen(b) == 0)
		return nullptr;
	strcpy(joined, a);
	strcat(joined, b);
	return joined;
}
