#pragma once

#include <iostream>
#include <string>

namespace Figuras 
    {
        class Figura 
            {
                public:
                    // Constructor y destructor públicos.
                    Figura() = default;
                    virtual ~Figura() = default;
                    
                    // MÉTODOS VIRTUALES PUROS.
                    virtual void dibujar() const = 0;
                    virtual void borrar() const = 0;
                    virtual std::string getTipo() const = 0;
                    
                    // MÉTODOS CON IMPLEMENTACIÓN POR DEFECTO.
                    virtual void rotar() const;
                    virtual void mover() const;

                protected:
                    double x = 0.0;  // Posición X.
                    double y = 0.0;  // Posición Y.
            };
    }