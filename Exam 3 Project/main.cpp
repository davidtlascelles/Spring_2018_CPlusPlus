/*
 Exam 3 Program
 David Lascelles
 4/2/2018
 */

#include<iostream>
#include<iomanip>
using namespace std;

class Frac {
public:
    Frac(int = 1, int = 1);
    void add(Frac, Frac);
    void sub(Frac, Frac);
    void mult(Frac, Frac);
    void div(Frac, Frac);
    void printData();
    void recip();
    int GCD(int, int);
    void reduce(int, int);
    bool checkDenominator();
    
private:
    int numerator, denominator;
};

Frac::Frac(int n, int d)
{
    numerator = n;
    denominator = d;
    reduce(n, d);
}

// Finds Greatest Common Denominator using a recursive strategy
int Frac::GCD(int num, int den){
    if (num == 0)
        return den;
    return abs(GCD(den % num, num));
}

// Checks if denominator is positive
bool Frac::checkDenominator(){
    if (denominator > 0)
        return true;
    else
        return false;
}

// Reduces fractions
void Frac::reduce(int num, int den){
    int gcd = GCD(num, den);
    numerator = num / gcd;
    denominator = den / gcd;
}

// Adds fractions together
void Frac::add(Frac a, Frac b){
    int n, d;
    n = a.numerator * b.denominator + b.numerator * a.denominator;
    d = a.denominator * b.denominator;
    
    reduce(n, d);
}

// Subtracts fraction in first argument a from fraction in second argument b
void Frac::sub(Frac a, Frac b){
    int n, d;
    n = a.numerator * b.denominator - b.numerator * a.denominator;
    d = a.denominator * b.denominator;
    
    reduce(n, d);
}

// Multiplies fractions together
void Frac::mult(Frac a, Frac b){
    int n, d;
    n = a.numerator * b.numerator;
    d = a.denominator * b.denominator;
    
    reduce(n,d);
}

// Divides fraction a by fraction b
void Frac::div(Frac a, Frac b){
    int n, d;
    n = a.numerator * b.denominator;
    d = a.denominator * b.numerator;
    
    reduce(n,d);
}

// finds the reciprocal of the fraction
void Frac::recip(){
    int temp = denominator;
    denominator = numerator;
    numerator = temp;
}

// prints fractions with formatting
void Frac::printData(){
    cout << numerator << "/" << denominator << endl;
}

int main()
{
    Frac a(3,7), b(6,12), sum, diff, prod, quo;
    
    sum.add(a,b);
    diff.sub(a,b);
    prod.mult(a,b);
    quo.div(a,b);
    if (a.checkDenominator() && b.checkDenominator())
    {
        cout << left << setw(18) <<  "Fractions are:" << setw(5) << right;
        a.printData();
        cout << setw(23) << right;
        b.printData();
        cout << endl << left << setw(18) << "Sum is:" << setw(5) << right;
        sum.printData();
        cout << left << setw(18) << "The difference is:" << setw(5) << right;
        diff.printData();
        cout << left  << setw(18) << "The product is:" << setw(5) << right;
        prod.printData();
        cout << left  << setw(18) << "The quotient is:" << setw(5) << right;
        quo.printData();
        a.recip();
        b.recip();
        cout << endl << left  << setw(18) << "Reciprocals are:" << setw(5) << right;
        a.printData();
        cout << setw(23) << right;
        b.printData();
        cout << endl;
    } else {
        cout << "Error - Denominator is 0 or negative." << endl;
    }
    return 0;
}
