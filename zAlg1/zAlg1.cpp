// zAlg1.cpp : Defines the entry point for the console application.
//
/*
	Program napisany pod Windowsa, by uruchomi� na sigmie prosze o wykomentowanie poni�szej linijki 
	"stdafx.h" kt�ry jest tworem wybitnie windowsowym
*/
#include "stdafx.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <deque>
#include <map>

#include "Large.h"
#include "Profiler.h"

using namespace std;

int main(int argc, char* argv[])
{
	//zak�adamy �e system docelowy jest pierwszym parametrem
	long base =  atoi(argv[1]);

	//system w kt�rym podawane b�d� liczby z wej�cia
	long in_base = 16;
	//cout << "Podaj baze systemu w ktorym b�dziesz podawa�: ";
	//cin >> in_base;

	//DEMO
	/*while(true){
		string A;
		cout << "Podaj liczb� A w systemie o podstawie "<< in_base << ":" << endl;
		cin >> A;
		Large liczbaA = Large::Set(A, base, in_base);
		cout << liczbaA.toString() << endl;
	
		string B;
		cout << "Podaj liczb� B w systemie o podstawie "<< in_base << ":" << endl;
		cin >> B;
		Large liczbaB = Large::Set(B, base, in_base);
		cout << liczbaB.toString() << endl;

		Large liczbaC = liczbaA.simpleAdd(liczbaB);
		cout << "Wynik " << liczbaC.toString() << endl;
	
		bool b = (liczbaC == liczbaB.simpleAdd(liczbaA));
		cout << b << endl;

		Large liczbaD = liczbaA.Karatsuba(liczbaB);
		cout << liczbaD.toString() << endl;

		Large conv = Large::convert(liczbaA, 16);
		cout << conv.toHex() << endl;
	}*/

	string liczba1;
	string liczba2;
	char command;

	Large l1(base);
	Large l2(base);
	Large res(base);

	while(true){
		cin>>liczba1>>command>>liczba2;
		l1 = Large::Set(liczba1, base, in_base);
		l2 = Large::Set(liczba2, base, in_base);
		switch(command){
			case '+':
				res = l1 + l2;
				//res = Large::convert(res, 16);
				cout << res.toHex() << endl;
				break;
			case '-':
				res = l1 - l2;
				//res = Large::convert(res, 16);
				cout << res.toHex() << endl;
				break;
			case '*':
				res = l1 * l2;
				//res = Large::convert(res, 16);
				cout << res.toHex() << endl;
				break;
			case '?':
				cout << Large::comparisonToChar(l1,l2) << endl;
				break;
			case 'q':	//rundka profilera
				Profiler().profile();
				break;
			default:
				cout << "Nie poprawny operator" << endl;
		}
	}

	return 0;
}

