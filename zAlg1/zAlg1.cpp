// zAlg1.cpp : Defines the entry point for the console application.
//
/*
	Program napisany pod Windowsa, by uruchomiæ na sigmie prosze o wykomentowanie poni¿szej linijki 
	"stdafx.h" który jest tworem wybitnie windowsowym
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
#include "LargeRational.h"

#include "Profiler.h"
#include "Tester.h"
#include "TesterRational.h"

using namespace std;

int main(int argc, char* argv[])
{
	//zak³adamy ¿e system docelowy jest pierwszym parametrem
	long base =  atoi(argv[1]);

	//system w którym podawane bêd¹ liczby z wejœcia
	long in_base = 16;
	//cout << "Podaj baze systemu w ktorym bêdziesz podawa³: ";
	//cin >> in_base;

	string liczba1;
	string liczba2;
	char command;

	Large l1(base);
	Large l2(base);
	Large res(base);

	/*while(true){
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
			case '/':
				res = l1 / l2;
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
	//}*/

		//test 16
	Large test1 = Large::Set("221", base, in_base);
	Large test2 = Large::Set("5", base, in_base);
	if ((test1/test2) != Large::Set("6d", base, in_base)){
		cout << "saddsa: " << test1.toString() << " " << test2.toString() << endl;
	}

	TesterRational tt = TesterRational();
	tt.run();
	Tester t = Tester();
	t.run();

	cin >>command;
	return 0;
}

