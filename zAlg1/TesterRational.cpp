#include "stdafx.h"

#include "TesterRational.h"
#include "LargeRational.h"
#include "Large.h"

#include <string>
#include <iostream>

//uruchamiaj wszystkie testy po kolei
void TesterRational::run(){
	cout<< "Rational-start" <<endl;
	test_set();
	cout<< "Rational-koniec" <<endl;
}

void TesterRational::test_set(){
	//test1
	LargeRational test1 = LargeRational::Set("123", base, in_base);
	LargeRational test2 = LargeRational(Large::Set("123",base,in_base));
	if (!(test1 == test2)){
		cout << "Test_Set_Rational1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = LargeRational::Set("123_12", base, in_base);
	Large licznik = Large::Set("123",base,in_base); 
	Large mianownik = Large::Set("12",base,in_base); 
	test2 = LargeRational(licznik, mianownik);
	if (!(test1 == test2)){
		cout << "Test_Set_Rational2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = LargeRational::Set("00123_0012", base, in_base);
	licznik = Large::Set("00123",base,in_base); 
	mianownik = Large::Set("0012",base,in_base); 
	test2 = LargeRational(licznik, mianownik);
	if (!(test1 == test2)){
		cout << "Test_Set_Rational3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = LargeRational::Set("0012300_001200", base, in_base);
	licznik = Large::Set("0012300",base,in_base); 
	mianownik = Large::Set("001200",base,in_base); 
	test2 = LargeRational(licznik, mianownik);
	if (!(test1 == test2)){
		cout << "Test_Set_Rational3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = LargeRational::Set("_1", base, in_base);
	licznik = Large::Set("0",base,in_base); 
	mianownik = Large::Set("1",base,in_base); 
	test2 = LargeRational(licznik, mianownik);
	if (!(test1 == test2)){
		cout << "Test_Set_Rational4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = LargeRational::Set("-112345_112345", base, in_base);
	licznik = Large::Set("-112345",base,in_base); 
	mianownik = Large::Set("112345",base,in_base); 
	test2 = LargeRational(licznik, mianownik);
	if (!(test1 == test2)){
		cout << "Test_Set_Rational5: " << test1.toString() << " " << test2.toString() << endl;
	}
}