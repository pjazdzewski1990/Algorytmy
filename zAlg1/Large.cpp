#include "stdafx.h"

#include "Large.h"
#include <vector>

using namespace std;

//TODO: to powinno by� statyczne, ale no c�: C++
//na potrzeby profilowania
long multiplication_count;
long addition_count;

// dzielimy "this" przez "second"
// w rest zapisujemy reszt�
Large Large::divide(Large v, Large& rest){
	Large u = Large(lista, base);
	u.setNegative(false);
	//na pocz�tku ci�gu cyfr chcemy mie� 0
	u.lista.insert(u.lista.begin(), 0);
	
	//przypadki bazowe
	//przypadek u<v
	if(u < v){
		rest = Large(u);
		return 0;
	}
	//pojedyncze liczby
	if(u.lista.size() == 1 && v.lista.size() == 1){
		if(rest.lista.size() == 1){
			rest.lista[0] = u.lista[0]%v.lista[0];
		}else{
			rest.lista.push_back(u.lista[0]%v.lista[0]);
		}
		return u.lista[0]/v.lista[0];
	}

	//zgodnie z algorytmem z zaj��
	Large q(base);
	q.setNegative(false);

	unsigned long j = u.lista.size() - v.lista.size() -1;
	unsigned long i=0;
	while(j >= i){
		//TODO: zak�adamy, �e mo�na wykona� "standardowe" dzielenie
		long num =0;
		if(u.lista.size()>i){
			num = u.lista[i]*base;
		}
		if(u.lista.size()>i+1){
			num += u.lista[i+1];
		}

		long _q = num / v.lista[0];
		long _r = num % v.lista[0];
		
		if(v.lista.size() > 1 && u.lista.size()>i+1 && _q*v.lista[1] > base*_r+u.lista[i+2]){
			_q--;
			_r = _r + v.lista[0];
			if(_q*u.lista[1] > base*_r+u.lista[i+1]){
				_q--;
			}
		}

		//TODO: kwestia znak�w
		Large temp = v*_q;
		//temp.setNegative(false);
		//przesu� kilka razy potem mozna ju� odejmowa�
		temp = temp<<(j-i);
		temp.setNegative(false);
		u = u-temp;

		q.lista.push_back(_q);

		if(u.isNegative()){
			q.lista[q.lista.size()-1]--;
			rest = u + v;
		}
		i++;
	}
	rest = u;
	return q;
}

//popraw liczbe:
// A|zmniejsz liczby w kom�rkach by pasowa�y do bazy
// B|obetnij 0 na pocz�tku
void Large::fix(){
	//A|
	long carry =0;
	for(int i=lista.size()-1; i>=0; i--){
		lista[i]+=carry;
		if(lista[i]>=base){
			carry = lista[i] / base;
			lista[i] = lista[i] % base;
		}
	}
	if(carry!=0){
		lista.insert(lista.begin(), carry);
	}

	//B|
	for(int i=0; i<lista.size();i++){
		vector<long>::iterator it;
		if(lista[i]==0){
			it++;
		}else{
			lista.erase(lista.begin(), it);
		}
	}
}