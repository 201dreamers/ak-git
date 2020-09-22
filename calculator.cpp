#include "calculator.h"

//Add function
int Calculator::Add (double a, double b)
{
	return a + b + 0.5;
}

//Substitution function
int Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}

//Multiplication function
int Calculator::Mul (double a, double b)
{
    return a * b;
}

//Division function
int Calculator::Div (double a, double b)
{
    return a / b;
}
