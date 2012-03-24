#include "stdafx.h"

#include "TesterRational.h"
#include "LargeRational.h"
#include "LargeRational.cpp"
#include "Large.h"

#include <string>
#include <iostream>

//uruchamiaj wszystkie testy po kolei
void TesterRational::run(){
	cout<< "Rational-start" <<endl;
	test_substract();
	test_divide();
	test_set();
	cout<< "Rational-koniec" <<endl;
}

void TesterRational::test_substract(){
	//test1
	LargeRational test1 = LargeRational::Set("123_123", base, in_base);
	LargeRational test2 = LargeRational::Set("23_123",base,in_base);
	LargeRational result = LargeRational(Large::Set("12300",base,in_base), Large::Set("14ac9",base,in_base));
	if (!(test1.substract(test2) == result)){
		cout << "Test_Substract_Rational1: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test2
	test1 = LargeRational::Set("2000_5000", base, in_base);
	test2 = LargeRational::Set("5_10",base,in_base);
	result = LargeRational(Large::Set("7000",base,in_base), Large::Set("50000",base,in_base));
	if (!(test1.substract(test2) == result)){
		cout << "Test_Substract_Rational2: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test3
	test1 = LargeRational::Set("1_10", base, in_base);
	test2 = LargeRational::Set("1_100",base,in_base);
	result = LargeRational(Large::Set("f0",base,in_base), Large::Set("1000",base,in_base));
	if (!(test1.substract(test2) == result)){
		cout << "Test_Substract_Rational3: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test4
	test1 = LargeRational::Set("100_100", base, in_base);
	test2 = LargeRational::Set("50_100",base,in_base);
	result = LargeRational(Large::Set("b000",base,in_base), Large::Set("10000",base,in_base));
	if (!(test1.substract(test2) == result)){
		cout << "Test_Substract_Rational4: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test5
	test1 = LargeRational::Set("10_10", base, in_base);
	test2 = LargeRational::Set("10_10",base,in_base);
	result = LargeRational(Large::Set("0",base,in_base), Large::Set("100",base,in_base));
	if (!(test1.substract(test2) == result)){
		cout << "Test_Substract_Rational5: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
}

void TesterRational::test_divide(){
	//test1
	LargeRational test1 = LargeRational::Set("123_123", base, in_base);
	LargeRational test2 = LargeRational(Large::Set("123",base,in_base), Large::Set("123",base,in_base));
	LargeRational result = LargeRational(Large::Set("14ac9",base,in_base), Large::Set("14ac9",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational1: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test2
	test1 = LargeRational::Set("12_34", base, in_base);
	test2 = LargeRational(Large::Set("56",base,in_base),Large::Set("78",base,in_base));
	result = LargeRational(Large::Set("870",base,in_base), Large::Set("1178",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational2: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test3
	test1 = LargeRational::Set("_34", base, in_base);
	test2 = LargeRational(Large::Set("12",base,in_base), Large::Set("12_34",base,in_base));
	result = LargeRational(Large::Set("0",base,in_base), Large::Set("3a8",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational3: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test4
	test1 = LargeRational::Set("12_", base, in_base);
	test2 = LargeRational::Set("22_33",base,in_base);
	result = LargeRational(Large::Set("396",base,in_base), Large::Set("22",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational4: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test5
	test1 = LargeRational::Set("123456_123", base, in_base);
	test2 = LargeRational::Set("321_654321",base,in_base);
	result = LargeRational(Large::Set("7336bf94116",base,in_base), Large::Set("38e83",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational5: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test6
	test1 = LargeRational::Set("1357_12", base, in_base);
	test2 = LargeRational::Set("321321_654",base,in_base);
	result = LargeRational(Large::Set("7a628c",base,in_base), Large::Set("3855852",base,in_base));
	if (!(test1.divide(test2) == result)){
		cout << "Test_Divide_Rational6: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
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