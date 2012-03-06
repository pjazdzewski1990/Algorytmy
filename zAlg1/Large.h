#ifndef _a_h_included_
#define _a_h_included_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <deque>
#include <map>
#include <math.h>

using namespace std;

class Large
{
	private:
		//wewn�trzna podstawa systemu
		long base;

		//lista przechowuj�ca kolejne cyfry liczby 
		// zapisanej w systemie o bazie base
		// liczby "od lewej"(ma�e indeksy) maj� najwi�ksz� pot�g�
		deque<long> lista;

		static int charToLong(char c){
			return c-48;
		}

		//mapa zawieraj�ca przej�cia z litery(char) w long
		// np. '1'->1 , 'a'->10, 'Z'->co�..
		// chyba nie ma potrzeby definiowa� dalej ni� do Z
		// konieczne przy systemach o podstawach wi�kszych ni� 10
		map<char,int> dict;

		//uzupe�nij s�ownik dict warto�ciami
		void prepareDictVals(){
			int num =0;
			//0-1
			for(int i='0';i<='9';i++){
				dict[i] = num;
				num++;
			}
			//litery a-z 
			// warto�ci 10-36
			for(int i='a';i<='z'; i++){
				dict[i] = num;
				num++;
			}
			//litery a-z 
			// warto�ci 10-36
			for(int i='A';i<='Z'; i++){
				dict[i] = num;
				num++;
			}
		}

		//czy liczba jest ujemna 
		bool negative;

		deque<long> copyUpper(Large& large){
			deque<long> ret;
			
			//uzupelnij liczbe large zerami od lewej
			// a� d�ugo�� liczby b�dzie poteg� 2 
			//fillToPower(large);

			for(unsigned i=0; i<large.lista.size()/2; i++){
				ret.push_back(large.lista[i]);
			}

			return ret;
		}

		deque<long> copyLower(Large& large){
			deque<long> ret;
			
			//uzupelnij liczbe large zerami od lewej
			// a� d�ugo�� liczby b�dzie poteg� 2 
			fillToPower(large);

			for(unsigned i=large.lista.size()/2; i<large.lista.size(); i++){
				ret.push_back(large.lista[i]);
			}

			return ret;
		}

		//TODO: nei uzywana
		bool isPowerOf2(long l){
			while(true){
				if(l%2 != 0){
					if(l != 1){
						return false;
					}else{
						return true;
					}
				}else{
					l = l/2;
				}
			}
		}

		//TODO: czy da si� to zrobi� lepiej?
		//TODO: chyba ju� nie potrzebne
		void fillToPower(Large& large){
			while(!isPowerOf2(large.lista.size()) ){
				large.lista.push_front(0);
			}
		}

		void fillWithZeros(Large& l1, Large& l2){
			while(l1.lista.size() != l2.lista.size()){
				if(l1.lista.size() < l2.lista.size()){
					l1.lista.push_front(0);
				}else{
					l2.lista.push_front(0);
				}
			}

			if(l1.lista.size() % 2 == 1){
				l1.lista.push_front(0);
				l2.lista.push_front(0);
			}
			return; 
		}
	
		/*
			W�a�ciwa procedura dodawania liczby A do liczby B
			Z tym �e A jak i B mog� by� ujemne lub dodatnie
		*/
		Large operate(Large second){
			///A jest wi�ksze-r�wne B 
			if(compareAbsolute(second) <= 0){
				//A jest ujemne
				if(this->isNegative()){
					//B jest ujemne
					if(second.isNegative()){
						///1| (-10) + (-4) = -(10+4)
						Large res = this->simpleAdd(second);
						res.setNegative(true);
						return res;
					}else{//B jest dodatnie
						///2| (-10) + 4 = -(10-4)
						Large res = this->simpleSubtract(second);
						res.setNegative(true);
						return res;
					}
				}else{//A jest dodatnie
					if(second.isNegative()){//B jest ujemne
						//3|10 + (-4) = 10 - 4
						Large res = this->simpleSubtract(second);
						res.setNegative(false);
						return res;
					}else{//B jest dodatnie
						//4| 10 + 4 
						Large res = this->simpleAdd(second);
						return res;
					}
				}
			}else{
			//A jest mniejsze od B	
				if(this->isNegative()){//A jest ujemne
					if(second.isNegative()){//B jest ujemne
						///5| (-4) + (-10) = -(4+10)
						switchSign();
						second.switchSign();
						Large res = this->simpleAdd(second);
						res.setNegative(true);
						return res;
					}else{//B jest dodatnie
						///6| (-4) + 10 = 10-4
						Large res = second.simpleSubtract(*this);
						return res;
					}
				}else{//A jest dodatnie
					if(second.isNegative()){//B jest ujemne
						//7| 4 + (-10) = -(6-4)
						Large res = second.simpleSubtract(*this);
						res.setNegative(true);
						return res;
					}else{
						//8| 4 + 10
						Large res = this->simpleAdd(second);
						return res;
					}
				}
			}
		}

	public:
		Large(long _base): base(_base) {	
			//uzupe�nij warto�� s�ownika, je�li jest on pusty
			if(dict.size() == 0){
				prepareDictVals();
			}
		}

		//TODO: drugi argument jest bez sensu
		Large(deque<long> numbers, long _base): base(_base) {	
			//uzupe�nij warto�� s�ownika, je�li jest on pusty
			if(dict.size() == 0){
				prepareDictVals();
			}

			//stw�rz liczb� na podstawie warto�ci przekazanych
			for(unsigned i=0; i<numbers.size(); i++){
				lista.push_back(numbers[i]);
			}
		}

		/*
			Metoda implementuj�ca proste odejmowanie, tj.
			zak�adamy, �e liczby maj� t� sam� baz� 
			i this jest wi�ksze ni� second
		*/
		Large simpleSubtract(Large second){
			Large res(base);
			
			long left;
			long right;
			long result;
			short borrow = 0;

			int indexA = lista.size()-1;
			int indexB = second.lista.size()-1;

			int max = indexA;
			if(max < indexB){
				max = indexB;
			}

			while(max >= 0){
				//ustaw pierwsza warto��
				if(indexA >= 0){
					left = lista[indexA];
				}else{
					right = 0;
				}
				//ustaw drug� warto��
				if(indexB >= 0){
					right = second.lista[indexB];
				}else{
					right = 0;
				}
				//je�li mamy przeniesienie to odejmij od pierwszej liczby
				if(borrow >= 1){
					left--;
					borrow=0;
				}
				//odejmij 2 liczby
				if(left < right){
					//je�li lewa jest mniejsza to r�b magi�
					borrow++;
					result = (base - right) + left;
				}else{
					result = left - right;
				}

				//dorzu� cyfr� do wyniku
				res.lista.push_front(result);
				indexA--;
				indexB--;
				max--;
			}

			res.setNegative(false);
			return res;
		}
		
		//metoda tworzy obiekt klasy string z czyteln� reprezentacj� liczby
		string toString(){
			stringstream ss;

			if(isNegative()){
				ss << '-';
			}

			for(long i=0; i < (long)lista.size(); i++){
				ss << lista[i];
				ss << ",";
			}
			ss << "(";
			ss <<  base;
			ss <<  ")";

			return ss.str();
		}

		//zamien liczb� przkazan� jako obiekt string
		// i zapisan� w systemie o podstawie in_base (domyslnie 10)
		static Large Set(string num, int base, int in_base = 10){
			//TODO: in_base moze by� wi�ksza ni� docelowa - ERROR
			Large result(base);
			bool neg = false;

			long power = 0;	//ile razy trzeba pomno�y� przez 10
			for(long i=num.length()-1; i >= 0; i--){

				//je�li ten znak to minus
				if(num[i]=='-'){
					neg = true;
					break;
				}

				int a = result.dict[num[i]];	//wsp�czynnik na pozycji "i"
												//brany ze s�ownika, bo mo�e by� liter�
				
				Large partial(base);			//cz�sciowy wynik
				partial.lista.push_back(a);		//pocz�tkowa warto��
				for(int i=0; i<power; i++){
					partial = partial * in_base;//zwi�ksz in_base-krotnie
				}

				result = result.simpleAdd(partial);		//zwi�ksz ostateczny wynik

				power++;
			}

			result.setNegative(neg);
			return result;
		}

		//zamie� baz� podanej liczby "l" na "new_base"
		static Large convert(Large l, long new_base){
			Large result(new_base);
			long power = 0;									//ile razy trzeba pomno�y� przez 10
			for(long i=l.lista.size()-1; i >= 0; i--){
				long a = l.lista[i];						//wsp�czynnik na pozycji "i"
				
				Large partial(new_base);					//cz�ciowy wynik
				while(a >= new_base){
					partial.lista.push_front(a%new_base);	//pocz�tkowa warto��
					a = a/new_base;
				}
				partial.lista.push_front(a);

				for(int j=0; j<power; j++){
					partial = partial * l.base;				//zwi�ksz ?-krotnie
				}

				result = result.simpleAdd(partial);			//zwi�ksz ostateczny wynik

				power++;
			}

			//TODO:obej�ciue
			long test = result.lista[0];
			if(test >= new_base){
				result.lista.push_front(test/new_base);
				result.lista[1] = test%new_base;
			}

			result.setNegative(l.isNegative());
			return result;
		}

		Large operator*(Large second){
			Large res = Karatsuba(second);
			if(isNegative() != second.isNegative()){
				res.setNegative(true);
				return res;
			}else{
				res.setNegative(false);
				return res;
			}
		}

		Large operator*(int val){
			Large res(base);

			long carry = 0;
			long sum = 0;
			for(int i = lista.size()-1; i>=0; i--){ 
				sum = lista[i]*val;
				sum += carry;
				long c = carry;	//przechowaj warto�� przeniesienia
				carry = 0;		//nalicz nowe przeniesienie

				//mie�ci si� w przedziale
				if(sum < base){
					//ustaw i-t� cyfr� na sum 
					res.lista.push_front(sum);
				}
				//jest wi�ksza ni� podstawa systemu
				if(sum>=base){
					//ustaw i-t� cyfr� na sum/base
					res.lista.push_front(sum%base);
					carry = sum/base;
				}
				//dosz�o do przepe�nienia
				if(sum < 0){
					//po kroczku do przepe�nienia
					for(int jj=0;jj<val;jj++){
						for(int kk=0; kk<lista[i]; kk++){
							//res.lista[i]++;
							//zwi�ksz o 1
							if(res.lista.size() <= (unsigned)i){
								res.lista.push_front(1);
							}else{
								res.lista[i]++;
							}
							//dosz�o do przepe�nienia
							if(res.lista[i]<0 || res.lista[i]>=base){
								carry++;
								//res.lista[i] = 0;
								//ustaw obecn� cyfr� na 0
								//TODO: czy if ma sens? zbada� czy sam push wystarczy
								if(res.lista.size() <=  (unsigned)i){
									res.lista.push_front(0);
								}else{
									res.lista[i] = 0;
								}
							}
						}
					}
				}
			}

			//je�li mamy przeniesienie to dodaj
			if(carry > 0){
				res.lista.push_front(carry);
			}

			res.setNegative(this->negative);

			return res;
		}

		//na razie zak�adamy, �e maj� tak� sam� podstaw�
		//ignorujemy te� kwestie znaku
		Large simpleAdd(Large val){
			Large res(base);

			long carry = 0;
			long sum = 0;
			long size = lista.size();
			if(val.lista.size() >  (unsigned)size){
				size = val.lista.size();
			}

			for(long i = 0; i<size; i++){ 
				//pobierz warto�� i-ta od prawej z liczby this
				long left;
				long index = lista.size();
				index--;
				index = index - i;
				if(index >= 0){
					left = lista[index];
				}else{
					left = 0;
				}
				
				//pobierz warto�� i-t� od prawej z liczby val
				long right;
				index = val.lista.size();
				index--;
				index = index - i;
				if(index >= 0){
					right = val.lista[index];
				}else{
					right = 0;
				}

				sum = left + right;	//dodaj warto�ci cz�stkowe
				sum += carry;
				long c = carry;		//przechowaj warto�� przeniesienia
				carry = 0;			//nalicz nowe przeniesienie

				//mie�ci si� w przedziale
				if(sum < base){
					//w razie potrzeby rozszerz tablic�
					//ustaw i-t� cyfr� na sum
					res.lista.push_front(sum);
				}
				//jest wi�ksza ni� podstawa systemu
				if(sum>=base){
					//ustaw i-t� cyfr� na sum/base
					res.lista.push_front(sum%base);
					carry = sum/base;
				}

				//TODO: inny spos�b na wykrycie przepe�nienia
				//dosz�o do przepe�nienia
				if(sum < 0){
					//po kroczku do przepe�nienia
					for(int jj=0;jj<right;jj++){
						res.lista[i]++;
						//dosz�o do przepe�nienia
						if(res.lista[i]<0 || res.lista[i]>=base){
							carry++;
							res.lista[i] = 0;
						}
					}
				}
			}

			//je�li mamy przeniesienie to dodaj
			if(carry > 0){
				res.lista.push_front(carry);
			}

			res.setNegative(false);
			return res;
		}

		/*
			Metoda por�wnuj�ca dwie liczby typu Large
			Metoda zwraca:
			-1	je�li liczba na kt�rej rzecz jest wykonywane compare jest wi�ksza
			0	gdy liczby s� r�wne
			1	gdy liczba second jest wi�ksza
		*/
		int compare(Large second){
			//obie liczby s� r�nego znaku
			if(isNegative() != second.isNegative()){
				if(isNegative()){
					return -1;
				}else{
					return 1;
				}
			}else{
				return compareAbsolute(second);
			}
		}

		/*
			Metoda por�wnuj�ca warto�� bezwgl�dn� dw�ch liczb typu Large
			Metoda zwraca:
			-1	je�li liczba na kt�rej rzecz jest wykonywane compare jest wi�ksza
			0	gdy liczby s� r�wne
			1	gdy liczba second jest wi�ksza
		*/
		int compareAbsolute(Large second){
			//zacznij od por�wnania d�ugo�ci
			if(lista.size() != second.lista.size()){
				if(lista.size() > second.lista.size()){
					return -1;
				}else{
					return 1;
				}
			}else{
				//przechodzimy po kolei i por�wnujemy elementy
				int i = 0;
				int size = lista.size();
				//dop�ki mamy jeszcze nie sprawdzone pozycje
				while(i < size){
					//ten obiekt jest wi�kszy na pozycji i
					if(lista[i] > second.lista[i]){
						return -1;
					} 
					//obiekt second jest wi�kszy na pozycji i
					if(lista[i] < second.lista[i]){
						return 1;
					} 

					//je�li dotarli�my tutaj to znaczy �e na pozycjach <i obiekty s� identyczne
					i++;
				}

				//je�li por�wnywanie kolejnych cyfr nie przynios�o skutku to obiekty s� r�wne
				return 0;
			}
		}

		/*
		Algorytm mno�enia Karatsuby
		zak�adamy, �e liczby s� tej samej bazy
		*/
		Large Karatsuba(Large second){

			if(lista.size()!=second.lista.size() && lista.size()!=1 && second.lista.size()!=1){
				//uzupelnij liczbe large zerami od lewej
				// a� d�ugo�� liczby b�dzie poteg� 2 
				fillWithZeros(*this, second);
			}

			//przypadek bazowy d�ugo�� liczby = 1
			if(lista.size()<=1 || second.lista.size()<=1){
				//po prostu mno�ymy 2 liczby
				Large product = Large(base);
				long val = 0;
				if(lista.size() <= 1){
					if(lista.size()==0){
						return second;
					}else{
						product = second * lista[0];
						return product;
					}
				}
				
				if(second.lista.size() <= 1){
					if(second.lista.size() == 0){
						return *this;
					}else{
						product = *this * second.lista[0]; 
						return product;
					}
				}
				return product;
			}else{
				//przechowa tymczasowe warto�ci
				Large temp(base);
				
				//oblicz X
				//stw�rz obiekt large na podstawie danych z listy(deque)
				Large X(copyUpper(*this), base);
				//do temp przypisz cz�� drugiej liczby
				temp = Large(copyUpper(second), base);
				//mn� (rekursywnie)
				X = X.Karatsuba(temp);

				//oblicz Y
				Large Y = Large(copyLower(*this), base);
				temp = Large(copyLower(second), base);
				Y = Y.Karatsuba(temp);
			
				//oblicz A
				Large A = Large(copyUpper(*this), base).simpleAdd( Large(copyLower(*this), base) );

				//oblicz B
				Large B = Large(copyUpper(second), base).simpleAdd( Large(copyLower(second), base) );

				//oblicz Z
				Large Z = A.Karatsuba(B);
				Z = Z.simpleSubtract(X);
				Z = Z.simpleSubtract(Y);

				//wynik = X*10^2n + Z*10^n + Y
				int m;
				if(lista.size()%2==1){
					m = (lista.size()+1)/2;
				}else{
					m = lista.size()/2;
				}
				Large wynik = X << (2*m);
				wynik = wynik.simpleAdd(Z << m);
				wynik = wynik.simpleAdd(Y);

				wynik.setNegative(false);
				return wynik;
			}
		}

		string toHex(){
			stringstream ss;
			//TODO: powinien automatycznie konwertowa� na hexy
			
			if(isNegative()){
				ss << '-';
			}

			if(base != 16){
				return "ERROR";
			}else{
				for(unsigned i=0; i<lista.size(); i++){
					switch(lista[i]){
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9: 
						ss << lista[i];
						break;
					case 10:
						ss << 'a';
						break;
					case 11:
						ss << 'b';
						break;
					case 12:
						ss << 'c';
						break;
					case 13:
						ss << 'd';
						break;
					case 14:
						ss << 'e';
						break;
					case 15:
						ss << 'f';
						break;

					}
				}
			}
			return ss.str();
		}

		static char comparisonToChar(Large arg0, Large arg1){
			if(arg0 < arg1){
				return '<';
			}
			if(arg0 > arg1){
				return '>';
			}
			return '=';
		}

		inline bool operator<(Large l) {
			return (compare(l) == 1);
		}

		inline bool operator<=(Large l) {
			return compare(l) >= 0;
		}

		inline bool operator>(Large l) {
			return (compare(l) == -1);
		}

		inline bool operator>=(Large l) {
			return compare(l) <= 0;
		}

		inline bool operator==(Large l) {
			return compare(l) == 0;
		}

		inline Large operator<<(long l){
			Large res = Large(this->lista, base);
			for(int i=0; i<l; i++){
				res.lista.push_back(0);
			}
			return res;
		}

		inline bool isNegative(){
			return negative;
		}

		inline void setNegative(bool val){
			negative = val;
		} 

		inline bool switchSign(){
			negative = !negative;
			return negative;
		}

		//upro�� by mi�dzy this a second by� tylko jeden operator: +
		// (tj. druga liczba ma by� dowolna, byle by realizowa� operacj� dodawania)
		// i potem przekazuj dalej
		inline Large operator-(Large second){
			//1| this - (-second)  = this + second
			//2| this - second  = this + (-second)
			second.switchSign();
			//przeka� do w�a�ciwej procedury licz�cej
			return this->operate(second);
		}

		inline Large operator+(Large second){
			return this->operate(second); 
		}
};
#endif