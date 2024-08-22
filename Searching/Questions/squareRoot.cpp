#include <iostream>
using namespace std;

int findSqrt(int n) {
    int start = 0;
    int end = n;
    int ans = -1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid > n) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    
    return ans;
}

double findPreciseSqrt(int n, int precision, int integerPart) {
    double factor = 1;
    double result = integerPart;

    for (int i = 0; i < precision; i++) {
        factor /= 10; // Decrease the factor for precision

        for (double j = result; j * j <= n; j += factor) {
            result = j;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter a number to find its square root: ";
    cin >> n;

    int integerPart = findSqrt(n);
    cout << "Integer part of the square root is: " << integerPart << endl;

    int precision;
    cout << "Enter the number of decimal places for precision: ";
    cin >> precision;

    double preciseSqrt = findPreciseSqrt(n, precision, integerPart);
    cout.precision(precision + 1);
    cout << "The square root with precision is: " << preciseSqrt << endl;

    return 0;
}
