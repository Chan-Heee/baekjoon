#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double a, b;
    double result;

    cin >> a >> b;
    result = a / b;
    cout << fixed;
    cout.precision(10);
    cout << result;
}