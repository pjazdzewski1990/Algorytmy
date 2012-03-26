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
	test_add();
	test_GDC();
	test_substract();
	test_divide();
	test_set();
	cout<< "Rational-koniec" <<endl;
}

void TesterRational::test_add(){
	//test1
	LargeRational test1 = LargeRational::Set("123_1", base, in_base);
	LargeRational test2 = LargeRational::Set("123_1",base,in_base);
	LargeRational result = LargeRational::Set("246_1",base,in_base);
	/*if (!(test1.add(test2) == result)){
		cout << "Test_Add_Rational1: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test2
	test1 = LargeRational::Set("1_321", base, in_base);
	test2 = LargeRational::Set("1_321",base,in_base);
	result = LargeRational::Set("2_321",base,in_base);
	if (!(test1.add(test2) == result)){
		cout << "Test_Add_Rational2: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test3
	test1 = LargeRational::Set("7_42", base, in_base);
	test2 = LargeRational::Set("11_c",base,in_base);
	result = LargeRational::Set("43_2c",base,in_base);
	if (!(test1.add(test2) == result)){
		cout << "Test_Add_Rational3: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test4
	test1 = LargeRational::Set("123_1", base, in_base);
	test2 = LargeRational::Set("1_123",base,in_base);
	result = LargeRational::Set("14aca_123",base,in_base);
	if (!(test1.add(test2) == result)){
		cout << "Test_Add_Rational4: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test5
	test1 = LargeRational::Set("23_521", base, in_base);
	test2 = LargeRational::Set("401_500",base,in_base);
	result = LargeRational::Set("43e6d_52100",base,in_base);
	if (!(test1+test2 == result)){
		cout << "Test_Add_Rational5: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test6
	test1 = LargeRational::Set("0_100", base, in_base);
	test2 = LargeRational::Set("52_456",base,in_base);
	result = LargeRational::Set("29_22b",base,in_base);
	if (!(test1+test2 == result)){
		cout << "Test_Add_Rational6: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test7
	test1 = LargeRational::Set("4d2_1964", base, in_base);
	test2 = LargeRational::Set("3fb_26aa",base,in_base);
	result = LargeRational::Set("23ee10_7ab68d",base,in_base);
	if (!(test1+test2 == result)){
		cout << "Test_Add_Rational7: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}*/
	//test8
	test1 = LargeRational::Set("3e9_1068", base, in_base);
	test2 = LargeRational::Set("1151_457",base,in_base);
	result = LargeRational::Set("3e8f3_ecb8",base,in_base);
	if (!(test1+test2 == result)){
		cout << "Test_Add_Rational8: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
}

void TesterRational::test_GDC(){
	//test1
	Large test1 = Large::Set("123", base, in_base);
	Large test2 = Large::Set("123",base,in_base);
	Large result =Large::Set("123",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational1: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test2
	test1 = Large::Set("80", base, in_base);
	test2 = Large::Set("40",base,in_base);
	result =Large::Set("40",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational2: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test3
	test1 = Large::Set("1000", base, in_base);
	test2 = Large::Set("125",base,in_base);
	result =Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational3: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test4
	test1 = Large::Set("4321", base, in_base);
	test2 = Large::Set("1234",base,in_base);
	result = Large::Set("5",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational4: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test5
	test1 = Large::Set("123321", base, in_base);
	test2 = Large::Set("0a0",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational5: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test6
	test1 = Large::Set("123321", base, in_base);
	test2 = Large::Set("0a0",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational6: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test7
	test1 = Large::Set("10", base, in_base);
	test2 = Large::Set("ffbbaa",base,in_base);
	result = Large::Set("2",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational7: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test8
	test1 = Large::Set("1", base, in_base);
	test2 = Large::Set("ffad213",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational8: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test9
	test1 = Large::Set("1123521", base, in_base);
	test2 = Large::Set("1",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational9: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test10
	test1 = Large::Set("11", base, in_base);
	test2 = Large::Set("1121",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational10: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test11
	test1 = Large::Set("a234", base, in_base);
	test2 = Large::Set("234b",base,in_base);
	result = Large::Set("1",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational11: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
	//test12
	test1 = Large::Set("a234", base, in_base);
	test2 = Large::Set("b88cd404",base,in_base);
	result = Large::Set("a234",base,in_base);
	if (!(LargeRational::GCD(test1, test2) == result)){
		cout << "Test_GDC_Rational12: " << test1.toString() << " " << test2.toString() << " " << result.toString() << endl;
	}
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