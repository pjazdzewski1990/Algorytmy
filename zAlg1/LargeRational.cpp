#include "stdafx.h"

#include "Large.h"
#include "LargeRational.h"

//metoda fabrykuj�ca
static LargeRational Set(long base, Large licznik, Large mianownik){
	Large _licznik = Large::convert(licznik, base);
	Large _mianownik = Large::convert(mianownik, base);
	return LargeRational(_licznik, _mianownik);
}

/*
	Metoda dodaje 2 liczby wymierne, 
	 ignorujemy kwestie znaku, zak�adamy �e argumenty dodawania maj� tak� sam� podstaw�
*/
LargeRational LargeRational::add(LargeRational second){


}