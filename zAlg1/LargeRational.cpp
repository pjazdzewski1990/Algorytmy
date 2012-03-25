#include "stdafx.h"

#include "Large.h"
#include "LargeRational.h"


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

	Large d = LargeRational::GCD(this->mianownik, second.mianownik);
	if(d == 1){
		LargeRational res = LargeRational(licznik*second.mianownik + mianownik*second.licznik, mianownik*second.mianownik);
	}else{
		Large t1 = licznik * (second.mianownik/d);
		t1 = t1 + second.licznik * (mianownik/d);
		Large t2 = mianownik * (second.mianownik/d); 

		if(t1==0){
			return LargeRational(Large::Set("0",licznik.getBase(), 10));
		}else{
			Large e = LargeRational::GCD(t1, d); 
			LargeRational res = LargeRational(t1/e, t2/e);
			return res;
		}
	}
}

/**
	Dzielenie dwóch ulamków na zasadzie mno¿enia z liczb¹ odwrotn¹ 
*/
LargeRational LargeRational::divide(LargeRational arg2){
	LargeRational lr = LargeRational(licznik*arg2.mianownik, mianownik*arg2.licznik);
	//TODO: powinno byæ jeszcze poprawione korzystaj¹c z GCD
	return lr;
}		

/*
	Typowe (szkolne) odejmowanie u³amków
	Nie interesuje nas kwestia znaku.
	Zak³adamy, ¿e liczby s¹ tej samej podstawy.
	This jest wiêksze ni¿ arg.
*/
LargeRational LargeRational::substract(LargeRational arg){
	LargeRational res = LargeRational(licznik*arg.mianownik - arg.licznik*mianownik, mianownik*arg.mianownik); 
	return res;
}