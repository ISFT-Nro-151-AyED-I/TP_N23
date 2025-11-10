#include "../include/Figura.hpp"

#include <iostream>

namespace Figuras 
    {
    // Implementación de métodos con comportamiento por defecto.
        void Figura::rotar() const 
            {
                std::cout << "🔄 Rotando figura genérica en posición (" << x << ", " << y << ")..." << std::endl;
            }

        void Figura::mover() const 
            {
                std::cout << "🚀 Moviendo figura genérica desde (" << x << ", " << y << ")..." << std::endl;
            }
    }