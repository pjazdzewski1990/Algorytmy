#ifndef _LARGERATIONAL_h_included_
#define _LARGERATIONAL_h_included_

#include "Large.h"
#include <stdio.h>
#include <stdlib.h>

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
			if(pos != -1 && pos != num.length()-1){
				mianownik = num.substr(pos+1);
			}
			LargeRational res(Large::Set(licznik, base, in_base), Large::Set(mianownik, base, in_base));
			return res;
		}

		LargeRational add(LargeRational second);
		LargeRational mul(LargeRational second);

		/**
			Metoda zwraca najwi�kszy wsp�lny dzielnik dwoch du�ych liczb
			Wynik GCD jest zawsze dodatni
		*/
		static Large GCD(Large first, Large second){
			Large s = Large::Set("1", first.getBase(), 10); 
			Large t = Large::Set("0", first.getBase(), 10); 
			Large d = Large(first);

			Large v1 = Large::Set("0", first.getBase(), 10); 
			Large v2 = Large::Set("1", first.getBase(), 10); 
			Large v3 = Large(second);

			Large zero = Large::Set("0", first.getBase(), 10);
			while(!(v3.compare(zero)==0)){
				//zmienna pomocnicza
				d.fix();
				v3.fix();
				Large helper = d/v3;

				//krok 1
				Large test = (helper * v1);
				test.fix();
				Large t1 = s - test;
				Large t2 = t - (helper * v2);
				test = (v3 * helper);
				Large t3 = d - test;

				//krok2
				s = v1;
				t = v2;
				d = v3;

				//krok3
				v1 = t1;
				v2 = t2;
				v3 = t3;
			}
			d.setNegative(false);
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
			//pami�tamy, �e nie mo�na por�wnywa� Large i long
			char buffer [sizeof(long)*8+1];
			_ltoa_s (val,buffer,10);
			string str = string(buffer);
			Large l = Large::Set(str, licznik.getBase(), 10); 
			
			Large zero = Large::Set("0", licznik.getBase(), 16);
			Large rest = Large(licznik.getBase());

			Large wynik = licznik.divide(mianownik, rest);

			return (licznik/mianownik)==l && rest==zero;
		}
		
		bool operator==(LargeRational second){
			//obie liczby musz� by� znormalizowane
			return ( (licznik==second.licznik) && (mianownik==second.mianownik) ) || 
				( (licznik==second.licznik) && (licznik==Large::Set("0", licznik.getBase(), 10)) );
		}

		LargeRational operator*(Large l){
			LargeRational lr(*this);
			lr.licznik = lr.licznik * l;
			return lr;
		}
		LargeRational operator*(LargeRational l){
			LargeRational lr = mul(l);
			if(licznik.isNegative() != l.licznik.isNegative()){
				lr.licznik.setNegative(true);
				lr.mianownik.setNegative(false);
			}else{
				lr.licznik.setNegative(false);
				lr.mianownik.setNegative(false);
			}
			return lr;
		}
		LargeRational operator+(LargeRational second){
			LargeRational lr = this->add(second);

			//algorytm podany na zajeciach nie zawsze zwraca poprawna warto��
			// patrz test numer 5
			// potrzebna jest jeszcze r�czna korekta
			Large gcd = LargeRational::GCD(lr.licznik, lr.mianownik);			
			Large zero = Large::Set("0", lr.licznik.getBase()); 
			if(!(gcd == zero)){
				lr.licznik = lr.licznik/gcd;
				lr.mianownik = lr.mianownik/gcd;
			}
			
			return lr;
		}
};

#endif