#include "stdafx.h"

#include "Large.h"
#include "LargeRational.h"

/*string LargeRational::toString(){
	stringstream ss;

	if(licznik.isNegative()){
		ss << '-';
	}

	ss << licznik.toString();
	ss << "-";
	ss << mianownik.toString();

	ss << "(";
	ss <<  licznik.getBase();
	ss <<  ")";

	return ss.str();
}*/

string LargeRational::toHex(){
	stringstream ss;

	if(licznik.isNegative()){
		ss << '-';
	}

	ss << licznik.toHex();
	ss << "-";
	ss << mianownik.toHex();

	ss << "(";
	ss <<  licznik.getBase();
	ss <<  ")";

	return ss.str();
}

/*
	Metoda dodaje 2 liczby wymierne, 
	 ignorujemy kwestie znaku, zak³adamy ¿e argumenty dodawania maj¹ tak¹ sam¹ podstawê
*/
LargeRational LargeRational::add(LargeRational second){
	if(*this == 0){
		return LargeRational(second);
	}
	if(second == 0){
		return LargeRational(*this);
	}
	long d = GCD(*this, second);
	if(d == 1){
		LargeRational res = LargeRational(licznik*second.mianownik + mianownik*second.licznik, mianownik*second.mianownik);
	}else{
		Large t1 = licznik * (second.mianownik/d);
		t1 = t1 + second.licznik * (mianownik/d);
		Large t2 = mianownik * (second.mianownik/d); 

		if(t1==0){
			return LargeRational(Large::Set("0",licznik.getBase(), 10));
		}else{
			long e = GCD(t1, t1); //powinno byæ d
			LargeRational res = LargeRational(t1/e, t2/e);
			return res;
		}
	}
}
