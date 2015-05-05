//
//http://tinodidriksen.com/2009/07/09/cpp-map-speeds/
//
//http://www.nerdblog.com/2006/12/how-slow-is-dynamiccast.html

#include <ctime>
#include <iostream>
#include <iomanip>
#include <tr1/unordered_map>
//#include <ext/hash_map>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>       // std::vector
#include "cycle.h"
using namespace std;

template<typename T>
void timemap(const int n=10000000, const int r=7) {
  
	std::map<std::string,std::vector<double> > timings;
	std::cout << std::fixed << std::setprecision(2);

	for (int j=0 ; j<r ; j++) {
		ticks start;
		T hsh;

		start = getticks();
		// Insert every 2nd number in the sequence
		for (int i=0 ; i<n ; i+=2) {
			hsh[i] = i*2;
		}
		timings["1: Insert"].push_back(elapsed(getticks(), start));

		start = getticks();
		// Lookup every number in the sequence
		for (int i=0 ; i<n ; ++i) {
			hsh.find(i);
		}
		timings["2: Lookup"].push_back(elapsed(getticks(), start));

		start = getticks();
		// Iterate over the entries
		for (typename T::iterator it=hsh.begin() ; it != hsh.end() ; ++it) {
			int x = it->second;
			++x;
		}
		timings["3: Iterate"].push_back(elapsed(getticks(), start));

		start = getticks();
		// Erase the entries
		for (int i=0 ; i<n ; i+=2) {
			hsh.erase(i);
		}
		timings["4: Erase"].push_back(elapsed(getticks(), start));
	}

	for (std::map<std::string,std::vector<double> >::iterator it=timings.begin() ; it!=timings.end() ; ++it) {
		double sum = 0.0;
		std::cout << it->first << " ( ";
		for (int i=1 ; i<r ; i++) {
			sum += it->second.at(i);
			std::cout << it->second.at(i) << " ";
		}
		std::cout << ") " << sum/double(r-1) << std::endl;
	}
}

int main() {
  	std::cout << std::endl << "timemap.exe" << std::endl;
	std::cout << "Timing std::tr1::unordered_map<int,int>" << std::endl;
	timemap<std::tr1::unordered_map<int,int> >();
	std::cout << std::endl;

	std::cout << "Timing __gnu_cxx::hash_map<int,int> " << std::endl;
   std::cout << "para __gnu_cxx::hash_map  --> el estandar c++11 es unordered_map" << std::endl;
	//timemap<__gnu_cxx::hash_map<int,int> >();	
	std::cout << std::endl;

	std::cout << "Timing std::map<int,int>" << std::endl;
	timemap<std::map<int,int> >();
	std::cout << std::endl;
}
