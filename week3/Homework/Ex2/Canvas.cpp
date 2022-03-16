#include "Canvas.h"
#include <cstdlib>
#include <iostream>

Canvas::Canvas(int width, int height)
{
	this->lines = height;
	this->columns = width;

	matrix = new char* [lines];
	
	for (int i = 0; i < this->lines; i++)
	{
		matrix[i] = new char[columns];
	}

	Clear();
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int xAux = j - x / 2;
			int yAux = y / 2 - i;

			int sumsq = xAux * xAux + yAux * yAux;
			if (((ray * ray) - 5 < sumsq) && (sumsq < (ray* ray) + 5))
				matrix[i][j] = ch;
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int xAux = i - x / 2;
			int yAux = y / 2 - j;

			int sumsq = xAux * xAux + yAux * yAux;
			if (((ray * ray) - 5 < sumsq) && (sumsq < (ray * ray) + 5))
			{
				matrix[i][j] = ch;
			}
		}
	}
	for (int i = 0; i < lines; i++)
	{
		bool foundFirst = 0;
		for (int j = 0; j < columns; j++)
		{
			if (foundFirst == 1 && matrix[i][j] == ch && matrix[i][j + 1] == ' ')
				break;
			if (matrix[i][j] == ch)
				foundFirst = 1;
			if (foundFirst == 1)
				matrix[i][j] = ch;
		}
	}

}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (abs(y2 - y1) < (x2 - x1))
	{
		if (x2 > x1)
			plotLineLow(x2, y2, x1, y1, ch);
		else
			plotLineLow(x1, y1, x2, y2, ch);
	}
	else
	{
		if (y1 > y2)
			plotLineHigh(x2, y2, x1, y1, ch);
		else
			plotLineHigh(x1, y1, x2, y2, ch);
	}
}

void Canvas::plotLineLow(int x0, int y0, int x1, int y1, char ch)
{
	int dx, dy, yi, D, x, y;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	y = y1;

	for (x = x0; x <= x1; x++)
	{
		matrix[x][y] = ch;

		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
	}
}

void Canvas::plotLineHigh(int x0, int y0, int x1, int y1, char ch)
{
	int dx, dy, xi, D, x, y;
	
	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2 * dx - dy;
	x = x0;

	for (y = y0; y <= y1; y++)
	{
		matrix[x][y] = ch;
		if (D > 0)
		{
			x = x + xi;
			D = D + 2 * (dx - dy);
		}
		else
			D = D + 2 * dx;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << matrix[i][j];
		std::cout << std::endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = ' ';
}
