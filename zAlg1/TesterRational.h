
#include "LargeRational.h"

using namespace std;

class TesterRational{
	private:
		long base;
		long in_base;

	public:
		TesterRational(){
			base = 100;
			in_base = 16;
		}
		
		//uruchom seriê testów
		void run();

		//funkcje testuj¹ce Large
		// 1 funkcja testuje 1 operacjê na ró¿nych przypadkach
		void test_set();
		void test_divide();
		void test_substract();
		void test_GDC();
		void test_add();
};