#include <iostream>
#include <chrono>
#include <thread>



template <typename T> inline void w (T s) { std::cout << s;				 }
template <typename T> inline void wl(T s) { std::cout << s << std::endl; }
					  inline void wl()	  { std::cout << std::endl;	     }

					  inline void ttsleep(float t) { 
						  std::this_thread::sleep_for(
							  std::chrono::milliseconds((int)(t * 1000))
						  );
					  }
					  
					  inline void cls()   { system("cls");   }
					  inline void pause() { system("pause"); }