#include "sugar.h"
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Class.h"
using namespace std;
using json = nlohmann::json;



#pragma region int
int main() {
    setlocale(LC_ALL, "RU_ru");
    system("color 70\n cls\n");

    //system("mode con cols=100 lines=30");
    //HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD bufferSize = { 100, 50 };
    //SetConsoleScreenBufferSize(hWnd, bufferSize);

    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    DURTMR(main);    // == SimpleTimer ST;
#pragma endregion main() {

    {

        vector <Person> pers = pers_sample;


        string str;
        
        str += "{\n";
        str += "  \"kids_size\": [ ";
        
        for (int i = 0; i < pers.size(); ++i) {
            str += to_string(pers.at(i).kids.size());
            if (i < pers.size() - 1) str += ", ";
        }
        
        str += " ], \n";
        
        str += "  \"pers\": [\n";
        for (int i = 0; i < pers.size(); ++i) {
        
            str += "    {\n      \"name\": \""; str += pers.at(i).name;           str += "\",\n";
            str += "      \"age\": ";           str += to_string(pers.at(i).age); str += ",";
            str += _kids(pers.at(i));
            str += "    }";
        
            if (i < pers.size() - 1) str += ",";
            str += "\n";
        
            
        }
        str += "  ],\n";
        str += "  \"pers_size\": "; str += to_string(pers.size());
        str += "\n}";
        
        
        
        //w(str);
        
        
        
        fstream out("json2.json");
        out << str;
        out.close();


    }
    
    
    
    {

        json jn;

        try {

            fstream in("json2.json");
            in >> jn;
            in.close();



            int pers_size = jn["pers_size"].get <int>();
            vector <Person> pers(pers_size);



            for (int i = 0; i < pers_size; ++i) {

                pers.at(i).name = jn["pers"][i]["name"].get <string>();
                pers.at(i).age  = jn["pers"][i]["age" ].get <int>();

                int kids_size = jn["kids_size"][i].get <int>();

                pers.at(i).kids = vector <Kid> (kids_size);

                for (int j = 0; j < kids_size; ++j) {
                    pers.at(i).kids.at(j).name = jn["pers"][j]["name"].get <string>();
                    pers.at(i).kids.at(j).age =  jn["pers"][j]["age" ].get <int>();
                }

            }
            
            for (const auto& el : pers) {
                w(el.name); wt(); wl(el.age);
                for (const auto& k : pers) {
                    wt(); w(k.name); wt(); wl(k.age);
                }
                wl();
            }

        }
        catch (const json::exception& jex) {
            wl(jex.what());
        }

    }
     
#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion