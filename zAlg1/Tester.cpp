#include "stdafx.h"

#include "Tester.h"
#include <string>
#include <iostream>

//uruchamiaj wszystkie testy po kolei
void Tester::run(){
	cout<< "Test-start" <<endl;
	test_divide();
	test_multpily();
	test_bigger();
	test_smaller();
	test_add();
	test_substract();

	cout<< "Test-koniec" <<endl;
}

//testuj dodawanie a+b
void Tester::test_add(){
	//test1
	Large test1 = Large::Set("123", base, in_base);
	Large test2 = Large::Set("123456", base, in_base);
	if ((test1+test2) != Large::Set("123579", base, in_base)){
		cout << "Test_Add1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("-1234", base, in_base);
	test2 = Large::Set("12345", base, in_base);
	if ((test1+test2) != Large::Set("11111", base, in_base)){
		cout << "Test_Add2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("-1234", base, in_base);
	test2 = Large::Set("-223", base, in_base);
	if ((test1+test2) != Large::Set("-1457", base, in_base)){
		cout << "Test_Add3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("1234", base, in_base);
	test2 = Large::Set("-2345", base, in_base);
	if ((test1+test2) != Large::Set("-1111", base, in_base)){
		cout << "Test_Add4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = Large::Set("-400", base, in_base);
	test2 = Large::Set("300", base, in_base);
	if ((test1+test2) != Large::Set("-100", base, in_base)){
		cout << "Test_Add5: " << test1.toString() << " " << test2.toString() << endl;
	}
}
	
//testuj odejmowanie a-b
void Tester::test_substract(){
	//test1
	Large test1 = Large::Set("123456", base, in_base);
	Large test2 = Large::Set("12345", base, in_base);
	if ((test1-test2) != Large::Set("111111", base, in_base)){
		cout << "Test_Sub1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("12340", base, in_base);
	test2 = Large::Set("12345", base, in_base);
	if ((test1-test2) != Large::Set("-5", base, in_base)){
		cout << "Test_Sub2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("-1204", base, in_base);
	test2 = Large::Set("401", base, in_base);
	if ((test1-test2) != Large::Set("-1605", base, in_base)){
		cout << "Test_Sub3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("2200", base, in_base);
	test2 = Large::Set("-101", base, in_base);
	if ((test1-test2) != Large::Set("2301", base, in_base)){
		cout << "Test_Sub4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = Large::Set("-100", base, in_base);
	test2 = Large::Set("-201", base, in_base);
	if ((test1-test2) != Large::Set("101", base, in_base)){
		cout << "Test_Sub5: " << test1.toString() << " " << test2.toString() << endl;
	}
}
	
//test a*b
void Tester::test_multpily(){
	//test1
	Large test1 = Large::Set("123", base, in_base);
	Large test2 = Large::Set("123456", base, in_base);
	if ((test1*test2) != Large::Set("14b17dc2", base, in_base)){
		cout << "Test_Mul1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("-123456", base, in_base);
	test2 = Large::Set("123456", base, in_base);
	if ((test1*test2) != Large::Set("-14b66cb0ce4", base, in_base)){
		cout << "Test_Mul2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("456", base, in_base);
	test2 = Large::Set("-1456", base, in_base);
	if ((test1*test2) != Large::Set("-582ce4", base, in_base)){
		cout << "Test_Mul3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("-321", base, in_base);
	test2 = Large::Set("-123", base, in_base);
	if ((test1*test2) != Large::Set("38e83", base, in_base)){
		cout << "Test_Mul4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("2222", base, in_base);
	test2 = Large::Set("555", base, in_base);
	if ((test1*test2) != Large::Set("b5ff4a", base, in_base)){
		cout << "Test_Mul4: " << test1.toString() << " " << test2.toString() << endl;
	}
}

//testujemy dzielenie a/b - wartoœæ calkowita (nie reszta)
void Tester::test_divide(){
	
	//test0
	Large test1 = Large::Set("1004", 10, in_base);
	Large test2 = Large::Set("24c", 10, in_base);
	if ((test1/test2) != Large::Set("6", 10, in_base)){
		cout << "Test_Div0: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test1
	test1 = Large::Set("123456", base, in_base);
	test2 = Large::Set("123", base, in_base);
	if ((test1/test2) != Large::Set("1003", base, in_base)){
		cout << "Test_Div1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("123", base, in_base);
	test2 = Large::Set("123", base, in_base);
	if ((test1/test2) != Large::Set("1", base, in_base)){
		cout << "Test_Div2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("-2213", base, in_base);
	test2 = Large::Set("120", base, in_base);
	Large left = test1/test2;
	Large right = Large::Set("-1e", base, in_base);
	if (left != right){
		cout << "Test_Div3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("5555", base, in_base);
	test2 = Large::Set("-321", base, in_base);
	left = test1/test2;
	right = Large::Set("-1b", base, in_base);
	if (left != right){
		cout << "Test_Div4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = Large::Set("-56789", base, in_base);
	test2 = Large::Set("-999", base, in_base);
	left = test1/test2;
	right = Large::Set("90", base, in_base);
	if (left != right){
		cout << "Test_Div5: " << test1.toString() << " " << test2.toString() << endl;
	}
}

//czy pierwszy element jest mniejszy od drugiego
void Tester::test_smaller(){
	//test1
	Large test1 = Large::Set("123", base, in_base);
	Large test2 = Large::Set("123456", base, in_base);
	if (!(test1<test2)){
		cout << "Test_Smaller1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("-123555", base, in_base);
	test2 = Large::Set("123456", base, in_base);
	if (!(test1<test2)){
		cout << "Test_Smaller2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("00000001", base, in_base);
	test2 = Large::Set("123456", base, in_base);
	if (!(test1<test2)){
		cout << "Test_Smaller3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("-123456", base, in_base);
	test2 = Large::Set("123456", base, in_base);
	if (!(test1<test2)){
		cout << "Test_Smaller4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = Large::Set("-1234", base, in_base);
	test2 = Large::Set("-1000", base, in_base);
	if (!(test1<test2)){
		cout << "Test_Smaller5: " << test1.toString() << " " << test2.toString() << endl;
	}
}

//czy pierwszy element jest wiêkszy od drugiego 
void Tester::test_bigger(){
	//test1
	Large test1 = Large::Set("123457", base, in_base);
	Large test2 = Large::Set("123456", base, in_base);
	if (!(test1>test2)){
		cout << "Test_Bigger1: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test2
	test1 = Large::Set("12", base, in_base);
	test2 = Large::Set("10", base, in_base);
	if (!(test1>test2)){
		cout << "Test_Bigger2: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test3
	test1 = Large::Set("011", base, in_base);
	test2 = Large::Set("1", base, in_base);
	if (!(test1>test2)){
		cout << "Test_Bigger3: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test4
	test1 = Large::Set("11", base, in_base);
	test2 = Large::Set("-11", base, in_base);
	if (!(test1>test2)){
		cout << "Test_Bigger4: " << test1.toString() << " " << test2.toString() << endl;
	}
	//test5
	test1 = Large::Set("11", base, in_base);
	test2 = Large::Set("-22", base, in_base);
	if (!(test1>test2)){
		cout << "Test_Bigger5: " << test1.toString() << " " << test2.toString() << endl;
	}
}