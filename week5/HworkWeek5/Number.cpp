#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "Number.h"
#include <string>
#include <cstring>

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'a' + 10;
}

int to_base_ten(const char* string, int base) //numarul si baza lui
{
    int len = strlen(string);
    int power = 1;
    int num = 0;
    int i;

    for (i = len - 1; i >= 0; i--) //in baza 10
    {
        if (val(string[i]) >= base)
        {
            printf("invalid number");
            return 0;
        }

        num += val(string[i]) * power;
        power = power * base;
    }

    return num;
}

char* to_any_base(const char* string, int base, int to_base) //numarul si baza in care o sa fie
{
    int num = to_base_ten(string, base);

    std::string bases = "0123456789abcdef"; //17
    std::string result = "";

    while (num > 0)
    {
        result = bases[num % to_base] + result;
        num = num / to_base;
    }

    char* final = new char[result.size() + 1];
    strcpy(final, result.c_str());

    return final;
}

Number::Number(const char* value, int base)
{
	this->value = new char[strlen(value) + 1];
	strcpy((char*)this->value, value);
	this->base = base;
	this->digits_count = strlen(this->value);
}

Number::Number(int val)
{
    std::string temp = std::to_string(val);
    const char* convert = temp.c_str();
    
    this->value = new char[strlen(convert) + 1];
    strcpy((char*)value, convert);
    this->base = 10;
    this->digits_count = strlen(this->value);
}

Number::Number(const Number& i)
{
    this->value = i.value;
    this->base = i.base;
    this->digits_count = i.digits_count;
}

Number::Number(Number&& i)
{
    strcpy((char*)this->value,i.value);
    this->base = i.base;
    this->digits_count = i.digits_count;
    i.value = nullptr;
}

Number& Number::operator=(Number&& i)
{
    strcpy((char*)this->value, i.value);
    this->base = i.base;
    this->digits_count = i.digits_count;
    i.value = nullptr;
    return (*this);
}

Number& Number::operator=(int val)
{
    std::string temp = std::to_string(val);
    const char* convert = temp.c_str();

    int temp_base = this->base;
    
    strcpy((char*)this->value, convert);
    this->digits_count = strlen(this->value);

    if (this->base == 10)
    {
        return (*this);
    }
    
    this->base = 10;
    this->SwitchBase(temp_base);
    return (*this);
}

Number& Number::operator=(const char* value)
{
    int temp_base = this->base;

    strcpy((char*)this->value, value);
    this->digits_count = strlen(this->value);

    if (this->base = 10)
    {
        return (*this);
    }

    this->base = 10;
    this->SwitchBase(temp_base);
    return (*this);
}

char Number::operator[](int index)
{
    return value[index];
}

void Number::SwitchBase(int newbase)
{
    int len = this->GetDigitsCount();
    int power = 1; 
    int num = 0;  
    int i;

    for (i = len - 1; i >= 0; i--)
    {
        if (val(value[i]) >= base)
        {
            printf("invalid number");
            return;
        }

        num += val(value[i]) * power;
        power = power * base;
    }
    
    std::string bases = "0123456789abcdef"; //17
    std::string result = "";

    while (num > 0)
    {
        result = bases[num % newbase] + result;
        num = num / newbase;
    }
    
    const char* conversion = result.c_str();

    this->value = new char[strlen(conversion) + 1];
    strcpy((char*)value, conversion);
    this->base = newbase;
    this->digits_count = strlen(value);
}

void Number::Print() const
{
	std::cout << this->value << std::endl;
}

int Number::GetDigitsCount() const
{
	return digits_count;
}

int Number::GetBase() const
{
	return base;
}

const char* Number::GetValue() const
{
    return this->value; //error reading string ?
}

Number operator+(const Number& l, const Number& r)
{   
    //Number copy = l;
    //return Number(65); // <--------------aici e buba
    int bigger_base;
    if (l.GetBase() >= r.GetBase())
        bigger_base = l.GetBase();
    else
        bigger_base = r.GetBase();

    int left = 0;
    int right = 0;

    if (l.GetBase() != 10)
    {
        const char* test1 = l.GetValue();
        left = to_base_ten(l.GetValue(), l.GetBase());
    }
    if (r.GetBase() != 10)
    {
        const char* test = r.GetValue();
        right = to_base_ten(r.GetValue(), r.GetBase());
    }

    int sum = left + right;

    if (bigger_base == 10)
        return Number(sum);
    else
    {
        std::string suma = std::to_string(sum);
        const char* converted = suma.c_str();
        const char* final = to_any_base(converted, 10, bigger_base);
        return Number(final, bigger_base);
    }

    
}

//Number operator+(const Number& l, int r)
//{
//    int bigger_base;
//    if (l.base >= 10)
//        bigger_base = l.base;
//    else
//        bigger_base = 10;
//    
//    Number l_copy = l;
//    if (l.base != 10)
//        l_copy.SwitchBase(10);
//
//    int len, num, power;
//    len = strlen(l_copy.value);
//    num = 0;
//    power = 1;
//
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (val(l_copy.value[i]) >= l_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num += val(l_copy.value[i]) * power;
//        power = power * l_copy.base;
//    }
//
//    int sum = num + r;
//
//    Number final(sum);
//    final.SwitchBase(bigger_base);
//
//    return Number(final.value, final.base);
//}
//
//Number operator+(int l, const Number& r)
//{
//    int bigger_base;
//    if (r.base >= 10)
//        bigger_base = r.base;
//    else
//        bigger_base = 10;
//
//    Number r_copy = r;
//    if (r.base != 10)
//        r_copy.SwitchBase(10);
//
//    int len, num, power;
//    len = strlen(r_copy.value);
//    num = 0;
//    power = 1;
//
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (val(r_copy.value[i]) >= r_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num += val(r_copy.value[i]) * power;
//        power = power * r_copy.base;
//    }
//
//    int sum = l + num;
//
//    Number final(sum);
//    final.SwitchBase(bigger_base);
//
//    return final;
//}
//
//Number operator-(const Number& l, const Number& r)
//{
//    int bigger_base;
//    if (l.base >= r.base)
//        bigger_base = l.base;
//    else
//        bigger_base = r.base;
//
//    Number l_copy = l;
//    Number r_copy = r;
//
//    if (l.base != 10)
//    {
//        l_copy.SwitchBase(10);
//    }
//    if (r.base != 10)
//    {
//        r_copy.SwitchBase(10);
//    }
//
//    int len_l, len_r, num_l, num_r, power;
//    len_l = strlen(l_copy.value);
//    len_r = strlen(r_copy.value);
//    num_l = 0; num_r = 0;
//    power = 1;
//
//    for (int i = len_l - 1; i >= 0; i--)
//    {
//        if (val(l_copy.value[i]) >= l_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num_l += val(l_copy.value[i]) * power;
//        power = power * l_copy.base;
//    }
//
//    power = 1;
//
//    for (int i = len_r - 1; i >= 0; i--)
//    {
//        if (val(r_copy.value[i]) >= r_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num_r += val(r_copy.value[i]) * power;
//        power = power * r_copy.base;
//    }
//
//    int dif = num_l - num_r;
//
//    Number final(dif); //va fi in baza 10;
//    final.SwitchBase(bigger_base);
//
//    return final;
//}
//
//Number operator-(const Number& l, int r)
//{
//    int bigger_base;
//    if (l.base >= 10)
//        bigger_base = l.base;
//    else
//        bigger_base = 10;
//
//    Number l_copy = l;
//    if (l.base != 10)
//        l_copy.SwitchBase(10);
//
//    int len, num, power;
//    len = strlen(l_copy.value);
//    num = 0;
//    power = 1;
//
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (val(l_copy.value[i]) >= l_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num += val(l_copy.value[i]) * power;
//        power = power * l_copy.base;
//    }
//
//    int dif = num - r;
//
//    Number final(dif);
//    final.SwitchBase(bigger_base);
//
//    return final;
//}
//
//Number operator-(int l, const Number& r)
//{
//    int bigger_base;
//    if (r.base >= 10)
//        bigger_base = r.base;
//    else
//        bigger_base = 10;
//
//
//    Number r_copy = r;
//    if (r.base != 10)
//        r_copy.SwitchBase(10);
//
//    int len, num, power;
//    len = strlen(r_copy.value);
//    num = 0;
//    power = 1;
//
//    for (int i = len - 1; i >= 0; i--)
//    {
//        if (val(r_copy.value[i]) >= r_copy.base)
//        {
//            printf("invalid number");
//            return 0;
//        }
//
//        num += val(r_copy.value[i]) * power;
//        power = power * r_copy.base;
//    }
//
//    int dif = l + num;
//
//    Number final(dif);
//    final.SwitchBase(bigger_base);
//
//    return final;
//}

bool Number::operator>(const Number& i)
{
    return false;
}
