#include "STimer.h"
#include <iostream>
#include <chrono>
#include <thread>


#define vv(x) std::cout << #x << " - " << x << std::endl;
#define kv(x) vv(x);
#define ba(b) \
	b == true ? std::cout << #b << " - true"  << std::endl : \
				std::cout << #b << " - false" << std::endl;

//#define v(x) to_string()



template <typename T>
inline void w (T s) { std::cout << s;			}
template <typename T>
inline void wl(T s) { std::cout << s << '\n'; }
inline void wt()    { std::cout << '\t';		}
inline void w()     { std::cout << ' ' ;		}
inline void wl()	{ std::cout << '\n';		}

inline void ttsleep(float t) { 
  std::this_thread::sleep_for(
	  std::chrono::milliseconds((int)(t * 1000))
  );
}

inline void cls()   { system("cls");   }
inline void pause() { system("pause"); }


template <typename T>
inline void test(T func, T val) {

	if (func == val) {
		w("Тест пройден. Строка: "); wl(__LINE__);
	}
	else {
		w("ОШИБКА: Отказ теста. Строка: "); wl(__LINE__);
		w("Файл: "); wl(__FILE__);
		exit(-1);
	}	

}

#include <bitset>

template <typename T>
string _bytes_spaces(T& bset) {

	int size = sizeof(bset) * 8;

	string sample = (bitset <sizeof(bset) * 8>(bset)).to_string();
	string result = "";

	result = sample[0];
	for (int i = 1; i < size; ++i) {
		if (i % 4 == 0) result += " ";
		if (i % 8 == 0) result += " ";
		result += sample[i];
	}

	return result;

}
string _bytes(uint8_t&  bset) { return _bytes_spaces(bset); }
string _bytes(uint16_t& bset) { return _bytes_spaces(bset); }
string _bytes(uint32_t& bset) { return _bytes_spaces(bset); }
string _bytes(uint64_t& bset) { return _bytes_spaces(bset); }
void print_bytes(uint8_t& bset)  { wl(_bytes(bset)); }
void print_bytes(uint16_t& bset) { wl(_bytes(bset)); }
void print_bytes(uint32_t& bset) { wl(_bytes(bset)); }
void print_bytes(uint64_t& bset) { wl(_bytes(bset)); }
