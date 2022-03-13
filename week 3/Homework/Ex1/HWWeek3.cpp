// HWWeek3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Math.h"

int main()  
{
    Math m;
    int a, b, c, d, e, f, g, h, i;
    char* j;

    a = m.Add(15, 30);
    b = m.Add(15, 20, 12);
    c = m.Add(1.2, 30.6);
    d = m.Add(1.5, 2.5, 1.0);
    e = m.Mul(15, 10);
    f = m.Mul(15, 20, 1);
    g = m.Mul(1.5, 2.0);
    h = m.Mul(1.5, 3.0, 0.0);
    i = m.Add(8, 1, 2, 3, 4, 5, 6, 7, 8);
    j = m.Add("Trecem ", "la POO!");

    printf("a: %d\nb: %d\nc: %d\nd: %d\ne: %d\nf: %d\ng: %d\nh: %d\ni: %d\nj: %s\n", a, b, c, d, e, f, g, h, i, j);

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
