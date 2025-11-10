#pragma once

#include "Figura.hpp"

namespace Figuras 
    {
        class Circulo : public Figura 
            {
                private:
                    double radio;

                public:
                    Circulo(double r, double posX = 0.0, double posY = 0.0);
                    
                    void dibujar() const override;
                    void borrar() const override;
                    void rotar() const override;
                    std::string getTipo() const override;
                    
                    double getRadio() const;
                    void setRadio(double nuevoRadio);
            };
    }