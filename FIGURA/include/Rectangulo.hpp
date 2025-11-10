#pragma once

#include "Figura.hpp"

namespace Figuras 
    {
        class Rectangulo : public Figura 
            {
                private:
                    double ancho;
                    double alto;

                public:
                    Rectangulo(double a, double h, double posX = 0.0, double posY = 0.0);
                    
                    void dibujar() const override;
                    void borrar() const override;
                    void rotar() const override;
                    std::string getTipo() const override;
                    
                    double getAncho() const;
                    double getAlto() const;
                    void setAncho(double nuevoAncho);
                    void setAlto(double nuevoAlto);
            };
    }