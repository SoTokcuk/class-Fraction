#include "Header.h"
#include <math.h>
#include <ostream>
using namespace std;
long reduction(long numerator, long denominator)
{
    long gcd = abs(denominator);
    if (numerator < 0)
    {
        numerator *= -1;
    }
    if (numerator > denominator)
    {
        while ((numerator % gcd != 0) || (denominator % gcd != 0))
        {
            gcd--;
        }
    }
    else
    {
        gcd = 1;
    }
    return gcd;
}
ostream& operator<< (ostream& out, const Fraction& fraction)
{
    out << fraction.get_numerator() << "/" << fraction.get_denominator() << "\n";
    return out;
}
Fraction Fraction::operator - () //Унарный минус
{
    return Fraction(-n_numerator, n_denominator);
}
Fraction::Fraction(long numerator, long denominator)
{
    long gcd = reduction(numerator, denominator);
    n_numerator = numerator / gcd;
    n_denominator = denominator / gcd;
}
void Fraction::set_numerator(long numerator) //Сеттер числителя
{
    if (numerator < 0)
    {
        n_numerator = abs(numerator);
    }
    else
    {
        n_numerator = numerator;
    }
}

long Fraction::get_numerator() const // Геттер числителя
{
    return n_numerator;
}

void Fraction::set_denominator(long denominator)//Сеттер знаменателя
{
    if (n_denominator == 0)
    {
        throw ("Dividing by 0\n");
    }
    if (n_numerator == 0)
    {
        n_denominator = 1;
    }
    else
    {
        n_denominator = denominator;
    }
}

long Fraction::get_denominator() const //Геттер знаменателя
{
    return n_denominator;
}

void Fraction::print() const //Метод print
{
    if (n_denominator == 1)
    {
        cout << get_numerator() << "\n";
    }
    else
    {
        cout << get_numerator() << "/" << get_denominator() << "\n";
    }
}
double Fraction::get_double() const //Перевод в double
{
    return (double)n_numerator / (double)n_denominator;
}

Fraction Fraction::operator * (const Fraction& fraction2) //Перегрузка умножения дробей
{
    long gcd = reduction(n_numerator * fraction2.get_numerator(), n_denominator * fraction2.get_denominator());
    return Fraction(n_numerator * fraction2.get_numerator() / gcd, n_denominator * fraction2.get_denominator() / gcd);
}
Fraction Fraction::operator + (const Fraction& fraction2) //Перегрузка сложения дробей
{
    long long a = n_numerator * fraction2.get_denominator() + fraction2.get_numerator() * n_denominator;
    long long b = n_denominator * fraction2.get_denominator();
    long gcd = reduction(a, b);
    return Fraction(a / gcd, b / gcd);
}
Fraction Fraction::operator - (const Fraction& fraction2) //Перегрузка разности дробей
{
    long long a = n_numerator * fraction2.get_denominator() - fraction2.get_numerator() * n_denominator;
    long long b = n_denominator * fraction2.get_denominator();
    long gcd = reduction(a, b);
    return Fraction(a / gcd, b / gcd);
}
Fraction Fraction::operator / (const Fraction& fraction2) //Перегрузка деления дробей
{
    long gcd = reduction(n_numerator * fraction2.get_denominator(), n_denominator * fraction2.get_numerator());
    return Fraction(n_numerator * fraction2.get_denominator() / gcd, n_denominator * fraction2.get_numerator() / gcd);
}
bool Fraction::operator > (const Fraction& fraction2) //Перегрузка оператора >
{
    if ((double)n_numerator / (double)n_denominator > fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator < (const Fraction& fraction2) //Перегрузка оператора <
{
    if ((double)n_numerator / (double)n_denominator < fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator >= (const Fraction& fraction2) //Перегрузка оператора >=
{
    if ((double)n_numerator / (double)n_denominator >= fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator <= (const Fraction& fraction2) //Перегрузка оператора <=
{
    if ((double)n_numerator / (double)n_denominator <= fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator == (const Fraction& fraction2) //Перегрузка оператора ==
{
    if ((double)n_numerator / (double)n_denominator == fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator != (const Fraction& fraction2) //Перегрузка оператора !=
{
    if ((double)n_numerator / (double)n_denominator != fraction2.get_double())
    {
        return true;
    }
    else
    {
        return false;
    }
}
