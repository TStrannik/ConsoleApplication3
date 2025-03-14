#pragma region



#pragma once
#include <string>
#include <iomanip>
#include <tuple>
#include <random>

using namespace std;



#pragma endregion head



struct Empl {

	//Empl (
	//	  string surname  = "Surname"
	//	, string    name  = "Name"
	//	, string    sname = "Sname"
	//	, unsigned  month = 00
	//	, unsigned  day   = 00
	//	, unsigned  year  = 00
	//)
	//
	//	: _surname(surname)
	//	, _name(name)
	//	, _sname(sname)
	//	, _month(month)
	//	, _day(day)
	//	, _year(year)
	//
	//{ }

	string   _surname;
	string   _name   ;
	string   _sname  ;
	unsigned _month  ;
	unsigned _day	 ;
	unsigned _year   ;

	string   _id;

};



struct EmplHasher {

	size_t operator() (const Empl& s) const {
		
		//size_t hsh =
		// (size_t)
		//		(s._year * 10000 + s._day * 100 + s._month);
		//
		//return hsh;

		size_t r1 = ihash(s._year);
		size_t r2 = ihash(s._month);
		size_t r3 = ihash(s._day);

		size_t x = 42;		
		return (r1 * x * x + r2 * x + r3);

	}

	hash <int> ihash;

};



struct Gener_empl {

	Empl make_Random_Chel() {

		Empl e;

		e._year  = Yr(DRE);
		e._month = Dy(DRE);
		e._day   = Mt(DRE);
		
		e._name    = "Имязвон";
		e._surname = "Фамилия";
		e._sname   = "Отецович";

		e._id = to_string(EmplHasher()(e));

		return e;

	}

private:
	default_random_engine          DRE;
	uniform_int_distribution <int> Yr{ 1900, 2005 };
	uniform_int_distribution <int> Dy{ 1,    28   };
	uniform_int_distribution <int> Mt{ 1,    12   };

};


ostream& operator << (ostream& out,  const Empl& e) {

	out << e._id << "\t" 
		<<							  e._surname << " "
		<<							  e._name    << " "
		<<							  e._sname   << "\t"
		<< setw(2) << setfill('0') << e._day     << "."
		<< setw(2) << setfill('0') << e._month   << "."
		<< setw(2) << setfill('0') << e._year;

	return out;

}
bool operator     <  (const Empl& l, const Empl& r) {

	return tie(l._name, l._surname, l._sname, l._day, l._month, l._year)
		 < tie(r._name, r._surname, r._sname, r._day, r._month, r._year);

}
bool operator     == (const Empl& l, const Empl& r) {

	return tie(l._name, l._surname, l._sname, l._day, l._month, l._year)
		== tie(r._name, r._surname, r._sname, r._day, r._month, r._year);

}