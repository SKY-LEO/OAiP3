#include <math.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#define PI 3.14159265359
#define E 2.71828182846
using namespace std;

int main()
{
	double a, b, h, x, n, r, resultY, resultZ, resultS;
	int k;
	cout << "Please, write a = ";
	cin >> a;
	cout << "Please, write b = ";
	cin >> b;
	cout << "Please, write h = ";
	cin >> h;
	cout << "Please, write n = ";
	cin >> n;
	if (cin.get() != '\n') {
		cout << "\nError, please write numbers!";
		return 0;
	}
	for (x = a; x <= b; x += h) {
		resultS = 0;
		r = x;
		for (k = 1; k <= n; k++) {
			r *= x;
			resultS += r * cos(k * PI / 3.) / (k * x);
		}
		resultY = -1. / 2. * log(1. - 2. * x * cos(PI / 3.) + x * x) / log(E);
		resultZ = fabs(resultY - resultS);
		cout << "x = " << x << setw(15) << "Y(x) = " << resultY << setw(15) << "S(x) = " << resultS << setw(30) << "|Y(x) - S(x)| = " << resultZ << endl;
	}
	_getch();
}