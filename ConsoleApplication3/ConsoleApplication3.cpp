#pragma region 



#pragma once
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

#include "sugar.h"
#include "Class.h"

using namespace std;



#pragma endregion head



#pragma region int
int main() {
    setlocale(LC_ALL, "RU_ru");
    system("color 70\n cls\n");

    system("mode con cols=100 lines=30");
    //HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD bufferSize = { 100, 50 };
    //SetConsoleScreenBufferSize(hWnd, bufferSize);


    #include "SimpleTimer.h"
    SimpleTimer STimer;
#pragma endregion main() {  

    Empl Alex;
    Alex._day     = 11;
    Alex._month   = 03;
    Alex._year    = 1911;
    Alex._name    = "Алексей";
    Alex._surname = "Сорокин";
    Alex._sname   = "Валерьевич";
    Alex._id      = to_string(EmplHasher()(Alex));



    Gener_empl ge;
    const int N = 20;



    unordered_set <Empl, EmplHasher> us;
    us.insert(Alex);

    for (int i = 0; i < N; ++i)
        us.insert(ge.make_Random_Chel());



    for (const auto& el : us)
        wl(el);
    wl();



#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion 
