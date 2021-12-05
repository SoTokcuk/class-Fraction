#include <iostream>
#include <stdio.h>
#include <exception>
using namespace std;
class Fraction
{
private:
    long n_numerator;
    long n_denominator;
public:
    Fraction(long numerator, long denominator);
    void set_numerator(long numerator);
    void set_denominator(long denominator);
    long get_denominator() const;
    long get_numerator() const;
    void print() const;
    double get_double() const;
    Fraction operator * (const Fraction& frac);
    Fraction operator + (const Fraction& frac);
    Fraction operator - (const Fraction& frac);
    Fraction operator / (const Fraction& frac);
    Fraction operator - ();
    friend std::ostream& operator<< (ostream& out, const Fraction& fraction);
    bool operator > (const Fraction& frac);
    bool operator < (const Fraction& frac);
    bool operator >= (const Fraction& frac);
    bool operator <= (const Fraction& frac);
    bool operator == (const Fraction& frac);
    bool operator != (const Fraction& frac);
};
