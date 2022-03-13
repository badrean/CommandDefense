#include <iostream>
#include <stdio.h>
#include "Canvas.h"

void main()
{
	Canvas desen(50, 30);

	unsigned int alegeDesen;

	alegeDesen = 6; // 1 pt cerc, 2 pt filledCircle, 3 pt rectangle, 4 pt filledRect, 5 pt Line, 6 pt set-Point

	switch (alegeDesen)
	{
	case 1:
		desen.DrawCircle(25, 15, 5, 43);
		break;
	case 2:
		desen.FillCircle(25, 15, 5, 43);
		break;
	case 3:
		desen.DrawRect(10, 5, 40, 10, 43);
		break;
	case 4:
		desen.FillRect(10, 5, 40, 10, 43);
		break;
	case 5:
		desen.DrawLine(12, 12, 15, 20, 43);
		break;
	case 6:
		desen.SetPoint(24, 18, 43);
		break;
	}

	desen.Print();
}