#include <string>

using namespace std;


struct Human abstract {

	string name;
	int	   age;

};


//struct Kid : public Human {
struct Kid {

	string name;
	int	   age;

};


//struct Person : public Human {
struct Person {

	string		 name;
	int			 age;
	vector <Kid> kids;

};


vector <Person> pers_sample = {
    {
        "Ashotik",
        42,
        {
            { "Ash", 13 },
            { "Ass", 10 },
        }
    },
    {
        "Phosgen",
        43,
        {
            { "Pho", 19 },
        }
    },
    {
        "Avaness",
        44,
        {
            { "Ava", 13 },
            { "Avo", 10 },
            { "Aro", 10 },
        }
    },
};