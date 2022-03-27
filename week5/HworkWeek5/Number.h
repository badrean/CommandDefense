#pragma once
class Number

{
private:
	const char* value;
	int base;
	int digits_count;
public:

	Number(const char* value, int base); // where base is between 2 and 16

	Number() : value("0"), base(10), digits_count(1) {}

	~Number() { delete[] value; } //destr

	Number(int val); //constr

	Number(const Number& i); //copy

	Number(Number&& i); //move

	// add operators and copy/move constructor > , < , >= , <=, ==, +=, ++x, x++, --x, x++
	/*add the following operators : addition, subtraction, index operator, relation operators(> , < , >= , <= , == , !=)

	add copy& move constructors and move assignment operator

	when performing operations with two Number object that have a different  base, the result(except for the relationand index operators) will have the biggest base of the two Number instances.

	for additionand subtraction use friend functions

	implement the-- operator with the following syntax : if used in a prefix form it will remove the first(most significant digit)
	from the number; if used in a post - fix form it will remove the last(least significant) digit from the number;*/

	Number& operator = (Number&& i);
	Number& operator = (int val); //nr isi pastreaza baza pe care a avut-o initial
	Number& operator = (const char* value); //nr isi pastreaza baza pe care a avut-o initial

	friend Number operator+(const Number& l, const Number& r);
	friend Number operator+(const Number& l, int r);
	friend Number operator+(int l, const Number& r);

	friend Number operator-(const Number& l, const Number& r);
	friend Number operator-(const Number& l, int r);
	friend Number operator-(int l, const Number& r);

	bool operator > (const Number& i);
	bool operator < (const Number& i);
	bool operator >= (const Number& i);
	bool operator <= (const Number& i);
	bool operator == (const Number& i);
	bool operator != (const Number& i);

	Number& operator += (const Number& i);

	Number& operator --();
	Number& operator --(int);

	char operator[](int index);

	void SwitchBase(int newBase);

	void Print() const;

	int  GetDigitsCount() const; // returns the number of digits for the current number

	int  GetBase() const; // returns the current base

	const char* GetValue() const;
};


