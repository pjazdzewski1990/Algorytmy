
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
			LargeRational(_licznik, Large::Set("1",_licznik.getBase(),10));
		}
		LargeRational(Large _licznik, Large _mianownik){
			licznik = _licznik;
			mianownik = _mianownik;
		}
		LargeRational(LargeRational& wzor){
			licznik = wzor.licznik;
			licznik = wzor.mianownik;
		}
		//metoda fabrykuj¹ca
		static LargeRational Set(long base, Large licznik, Large mianownik);

		LargeRational add(LargeRational second);
		LargeRational mul(LargeRational second);
		static long GCD(LargeRational first, LargeRational second);
};