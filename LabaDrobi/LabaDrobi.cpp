#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
    long numerator1, denominator1, numerator2, denominator2;
    cout << "Enter the numerator and denominator of fraction: \n";
    cin >> numerator1;
    cin >> denominator1;
    Fraction frac1(numerator1, denominator1);
    frac1.set_numerator(numerator1);
    frac1.set_denominator(denominator1);
    cout << "Entered fraction: " << frac1 << "\n";
    cout << "Value in double: " << frac1.get_double() << "\n";
    cout << "Enter the numerator and denominator of the second fraction: \n";
    cin >> numerator2;
    cin >> denominator2;
    Fraction frac2(numerator2, denominator2);
    cout << "Entered fraction: " << frac2 << "\n";
    cout << "Value in double: " << frac2.get_double() << "\n";
    cout << "Sum of fractions: " << frac1 + frac2 << "\n";
    cout << "Difference in fractions: " << frac1 - frac2 << "\n";
    cout << "Product of fractions: " << frac1 * frac2 << "\n";
    cout << "Partial fractions: " << frac1 / frac2 << "\n";
    if (frac1 == frac2)
    {
        cout << "The first fraction is equal to the second\n";
    }
    if (frac1 != frac2)
    {
        cout << "The first fraction is not equal to the second\n";
    }
    if (frac1 > frac2)
    {
        cout << "The first fraction is larger than the second\n";
    }
    if (frac1 < frac2)
    {
        cout << "The first fraction is smaller than the second\n";
    }
    if (frac1 >= frac2)
    {
        cout << "The first fraction is greater than or equal to the second\n";
    }
    if (frac1 <= frac2)
    {
        cout << "The first fraction is less than or equal to the second\n";
    }
    cout << "Unary minus of the first fraction: " << -frac1 << "\n";
    try
    {
        frac1.set_denominator(denominator1);
        frac2.set_denominator(denominator2);
    }
    catch (const exception& ex)
    {
        cout << "Wrong value:" << ex.what() << "\n";
    }
    return 0;
}
