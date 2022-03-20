// TemaLab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sort.h"

int main()
{
	Sort test1(10, -10, 10);
	Sort test2;
	int* lista = new int[9]{ 3,2,15,4,20,11,-3,-1,6 };
	Sort test3(9, lista);
	Sort test4 = { 8, 12, 2, 3 ,4 ,10, 1, 9, 5 };
	const char* sir = "2,3,1,12,6,5,8,10,11,9,3,19,12,26";
	Sort test5(sir);

	std::cout << "Listele nesortate: " << std::endl << std::endl;

	std::cout << "Lista 1: " << std::endl;
	test1.Print();

	std::cout << "Lista 2: " << std::endl;
	test2.Print();

	std::cout << "Lista 3: " << std::endl;
	test3.Print();

	std::cout << "Lista 4: " << std::endl;
	test4.Print();

	std::cout << "Lista 5: " << std::endl;
	test5.Print();
	std::cout << std::endl;

	std::cout << "Numarul de elemente din lista 5: " << std::endl;
	std::cout << test5.GetElementsCount() << std::endl;
	
	std::cout << "Elementul 3 din lista 5: " << std::endl;
	std::cout << test5.GetElementFromIndex(3) << std::endl;

	//-----------------------------------------------------------------
	std::cout << "Listele sortate: " << std::endl << std::endl;
	
	std::cout << "Lista 1: " << std::endl;
	test1.QuickSort();
	test1.Print();

	std::cout << "Lista 2: " << std::endl;
	test2.InsertSort();
	test2.Print();

	std::cout << "Lista 3: " << std::endl;
	test3.BubbleSort();
	test3.Print();

	std::cout << "Lista 4: " << std::endl;
	test4.InsertSort();
	test4.Print();

	std::cout << "Lista 5: " << std::endl;
	test5.QuickSort();
	test5.Print();
	std::cout << std::endl;

	std::cout << "Numarul de elemente din lista 5: " << std::endl;
	std::cout << test5.GetElementsCount() << std::endl;

	std::cout << "Elementul 3 din lista 5: " << std::endl;
	std::cout << test5.GetElementFromIndex(3) << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
