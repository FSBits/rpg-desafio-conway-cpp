#include "../include/Estilo.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

namespace Estilo {
    void impressaoEscrita(const std::string& texto, int delayMs) {
        
        for (char c : texto) {
            
            std::cout << c << std::flush; 
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        }
        std::cout << "\n";
    }

    void limpaTela() {

        #ifdef _WIN32
            std::system("cls");
        #else
             std::system("clear");
        #endif
    }
}
