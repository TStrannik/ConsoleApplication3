#include <iostream>
#include <chrono>
#include <thread>



#define vv(x) std::cout << #x << " - " << x << std::endl;
#define ba(b) \
	b == true ? std::cout << #b << " - true"  << std::endl : \
				std::cout << #b << " - false" << std::endl;

//#define v(x) to_string()



template <typename T> inline void w (T s) { std::cout << s;			}
template <typename T> inline void wl(T s) { std::cout << s << '\n'; }
					  inline void wt()    { std::cout << '\t';		}
					  inline void w()     { std::cout << ' ' ;		}
					  inline void wl()	  { std::cout << '\n';		}

					  inline void ttsleep(float t) { 
						  std::this_thread::sleep_for(
							  std::chrono::milliseconds((int)(t * 1000))
						  );
					  }
					  
					  inline void cls()   { system("cls");   }
					  inline void pause() { system("pause"); }