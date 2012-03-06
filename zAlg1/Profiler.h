#ifndef _PROFILER_h_included_
#define _PROFILER_h_included_

#include <string>

using namespace std;

class Profiler {
	public: 
		Profiler(string _report);

		void profile();
	private:
		//nazwa pliku do którego zapiszemy raport
		string report;
};

#endif