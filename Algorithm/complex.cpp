#include "complex.h"
using namespace std;
int main()
{
	Complex<int> com1(1,2);
	Complex<int> com2(2,1);
	cout << com1 << endl << com2 << endl;
	cout << com1 + com2 << endl;
	cout << com1 - com2 << endl;
	cout << com1 * com2 << endl;
	cout << (com1 == com2) << endl << (com1 < com2) << endl << (com1 > com2) << endl;
	com1.setValue(com2);
	cout << com1 << endl;
	Complex<int> com3(com2);
	Complex<int> com4 = com3;
	cout << com3 << endl << com4;
	return 1;
}
