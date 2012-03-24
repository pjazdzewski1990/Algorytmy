#ifndef _LARGERATIONAL_h_included_
#define _LARGERATIONAL_h_included_

#include "Large.h"

/*
	Klasa do obs³ugi du¿ych liczb wymiernych
*/
class LargeRational {
	private:
		Large licznik;
		Large mianownik;

	public:
		//KONSTRUKTORY
		LargeRational(Large _licznik){
			licznik = _licznik;
			mianownik = Large::Set("1",_licznik.getBase(),10);
		}
		LargeRational(Large _licznik, Large _mianownik){
			licznik = _licznik;
			mianownik = _mianownik;
		}
		LargeRational(LargeRational& wzor){
			licznik = wzor.licznik;
			mianownik = wzor.mianownik;
		}

		string toString(){
			stringstream ss;

			if(licznik.isNegative()){
				ss << '-';
			}

			ss << licznik.toString();
			ss << "_";
			ss << mianownik.toString();

			ss << "(";
			ss <<  licznik.getBase();
			ss <<  ")";
			//TODO
			string test = ss.str();
			return ss.str();
		}
		string toHex();

		//metody fabrykuj¹ce
		static LargeRational Set(long base, Large licznik, Large mianownik){
			Large _licznik = Large::convert(licznik, base);
			Large _mianownik = Large::convert(mianownik, base);
			return LargeRational(_licznik, _mianownik);
		}
		static LargeRational Set(string num, int base, int in_base=10){
			int pos = num.find("_");
			string licznik = "0";
			if(pos != 0){
				licznik = num.substr(0, pos);
			}
			string mianownik = "1";
			if(pos != -1){
				mianownik = num.substr(pos+1);
			}
			LargeRational res(Large::Set(licznik, base, in_base), Large::Set(mianownik, base, in_base));
			return res;
		}

		LargeRational add(LargeRational second);
		LargeRational mul(LargeRational second);
		static long GCD(LargeRational first, LargeRational second);

		//OPERATORY
		bool operator==(long val){
			//obie liczby musz¹ byæ znormalizowane
			return (licznik/mianownik)==val;
		}
		bool operator==(LargeRational second){
			//obie liczby musz¹ byæ znormalizowane
			return (licznik==second.licznik) && (mianownik==second.mianownik);
		}
};

#endif