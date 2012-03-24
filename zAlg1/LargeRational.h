#ifndef _LARGERATIONAL_h_included_
#define _LARGERATIONAL_h_included_

#include "Large.h"

/*
	Klasa do obs�ugi du�ych liczb wymiernych
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

			return ss.str();
		}
		string toHex();

		//metody fabrykuj�ce
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
		static LargeRational GCD(LargeRational first, LargeRational second){
			Large s = Large::Set("1", first.licznik.getBase(), 10); 
			Large t = Large::Set("0", first.licznik.getBase(), 10); 
			LargeRational d = LargeRational(first);

			Large v1 = Large::Set("0", first.licznik.getBase(), 10); 
			Large v2 = Large::Set("1", first.licznik.getBase(), 10); 
			LargeRational v3 = LargeRational(second);

			while(!(v3==Large::Set("0", first.licznik.getBase(), 10))){
				//zmienna pomocnicza
				LargeRational temp = d.divide(v3);
				Large helper = temp.licznik/temp.mianownik;

				//krok 1
				Large t1 = s - (helper * v1);
				Large t2 = t - (helper * v2);
				LargeRational t3 = d.substract(v3 * helper);

				//krok2
				s = v1;
				t = v2;
				d = v3;

				//krok3
				v1 = t1;
				v2 = t2;
				v3 = t3;
			}
			return d;
		}

		/**
			Dzielenie dw�ch ulamk�w na zasadzie mno�enia z liczb� odwrotn� 
		*/
		LargeRational divide(LargeRational arg2);

		/*
			Typowe (szkolne) odejmowanie u�amk�w
		*/
		LargeRational substract(LargeRational arg);

		//OPERATORY
		bool operator==(long val){
			//obie liczby musz� by� znormalizowane
			return (licznik/mianownik)==val;
		}
		bool operator==(LargeRational second){
			//obie liczby musz� by� znormalizowane
			return (licznik==second.licznik) && (mianownik==second.mianownik);
		}
		LargeRational operator*(Large l){
			LargeRational lr(*this);
			lr.licznik = lr.licznik * l;
			return lr;
		}

};

#endif