#pragma once

#include "Figura.hpp"

namespace Figuras 
    {
        class Triangulo : public Figura 
            {
                private:
                    double base;
                    double altura;

                public:
                    Triangulo(double b, double h, double posX = 0.0, double posY = 0.0);
                    
                    void dibujar() const override;
                    void borrar() const override;
                    void rotar() const override;
                    std::string getTipo() const override;
                    
                    double getBase() const;
                    double getAltura() const;
                    void setBase(double nuevaBase);
                    void setAltura(double nuevaAltura);
            };
    }