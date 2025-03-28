#include "SimpleTimer.h"
#include <iostream>
#include <string>
#include <deque>
#include <queue>

#include <algorithm>

#include "sugar.h"
#include "Class.h"
using namespace std;



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

    DURTMR(Этап 1);

    int i = 10;
    float f = 20.0;
    bool b = 0;

    vv(i);
    vv(f);
    vv(b);

    ba(b);


#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion