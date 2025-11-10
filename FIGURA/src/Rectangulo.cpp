#include "../include/Rectangulo.hpp"

#include <iostream>

namespace Figuras 
    {
        // Constructor
        Rectangulo::Rectangulo(double a, double h, double posX, double posY) : ancho(a), alto(h) 
            {
                x = posX;
                y = posY;
            }

        // Implementación de métodos virtuales puros.
        void Rectangulo::dibujar() const 
            {
                std::cout << "🟩 DIBUJANDO RECTÁNGULO:" << std::endl;
                std::cout << "   Ancho: " << ancho << ", Alto: " << alto << std::endl;
                std::cout << "   Posición: (" << x << ", " << y << ")" << std::endl;
                std::cout << "   Área: " << (ancho * alto) << " unidades²" << std::endl;
                std::cout << "   Perímetro: " << (2 * (ancho + alto)) << " unidades.\n" << std::endl;
                
                // Representación visual de rectángulo
                std::cout << "  Representación gráfica:\n" << std::endl;
                std::cout << "  🟩🟩🟩🟩🟩🟩🟩🟩" << std::endl;
                std::cout << "  🟩               🟩" << std::endl;
                std::cout << "  🟩               🟩" << std::endl;
                std::cout << "  🟩               🟩" << std::endl;
                std::cout << "  🟩               🟩" << std::endl;
                std::cout << "  🟩               🟩" << std::endl;
                std::cout << "  🟩🟩🟩🟩🟩🟩🟩🟩" << std::endl;
                std::cout << "  📐 Forma rectangular perfecta.\n"<< std::endl;
            }

        void Rectangulo::borrar() const 
            {
                std::cout << "🧹 BORRANDO RECTÁNGULO " << ancho << "x" << alto << " en (" << x << ", " << y << ")." << std::endl;
            }

        // Sobrescritura opcional del método con comportamiento por defecto.
        void Rectangulo::rotar() const 
            {
                std::cout << "🔄 ROTANDO RECTÁNGULO 90 grados..." << std::endl;
                std::cout << "   Nuevas dimensiones: " << alto << " (ancho) x " << ancho << " (alto)." << std::endl;
            }

        // Implementación del método virtual puro de identificación.
        std::string Rectangulo::getTipo() const 
            {
                return "Rectángulo.";
            }

        // Getters y Setters
        double Rectangulo::getAncho() const 
            {
                return ancho;
            }

        double Rectangulo::getAlto() const 
            {
                return alto;
            }

        void Rectangulo::setAncho(double nuevoAncho) 
            {
                if (nuevoAncho > 0) 
                    {
                        ancho = nuevoAncho;
                        std::cout << "📏 Ancho del rectángulo actualizado a: " << ancho << std::endl;

                    } else 
                        {
                            std::cout << "❌ Error: El ancho debe ser mayor que 0." << std::endl;
                        }
            }

        void Rectangulo::setAlto(double nuevoAlto) 
            {
                if (nuevoAlto > 0) 
                    {
                        alto = nuevoAlto;
                        std::cout << "📏 Alto del rectángulo actualizado a: " << alto << std::endl;
                        
                    } else 
                        {
                            std::cout << "❌ Error: El alto debe ser mayor que 0." << std::endl;
                        }
            }
    }