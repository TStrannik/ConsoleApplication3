// Eto visokotexnologichniy profiler za 500 deneg

#pragma once
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;


#define UNIQ_ID_IMPL(Lineno) _SimpleTimer_from_line_##Lineno
#define UNIQ_ID(Lineno) UNIQ_ID_IMPL(Lineno)

#define DURTMR(name) \
	SimpleTimer UNIQ_ID(__LINE__)(#name);



struct SimpleTimer {

	SimpleTimer() {

		_name = "";
		_start = high_resolution_clock::now();
		_exist = true;

	}
	explicit SimpleTimer(string name) {

		_name = name;
		_start = high_resolution_clock::now();
		_exist = true;

	}
	~SimpleTimer() {

		if (_exist) {
			_end = high_resolution_clock::now();
			duration <float> duration = _end - _start;

			if (_name == "") cout << "DURATION: " << duration.count() << " sec" << endl;
			else			 cout << "DURATION [" << _name << "]: " << duration.count() << " sec" << endl;
		}
		_exist = false;

	}

	void stop() { this->~SimpleTimer(); }

private:
	bool   _exist = false;
	string _name = "";
	time_point <steady_clock> _start, _end;

};