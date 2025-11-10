#include "../include/Circulo.hpp"

#include <iostream>
#include <cmath>

namespace Figuras 
    {
        // Constructor.
        Circulo::Circulo(double r, double posX, double posY) : radio(r) 
            {
                x = posX;
                y = posY;
            }

        // Implementación de métodos virtuales puros.
        void Circulo::dibujar() const 
            {
                const double PI = 3.14159265358979323846;

                std::cout << "🔵 DIBUJANDO CÍRCULO:" << std::endl;
                std::cout << "   Radio: " << radio << std::endl;
                std::cout << "   Posición: (" << x << ", " << y << ")" << std::endl;
                std::cout << "   Área: " << (PI * radio * radio) << " unidades²\n" << std::endl;
                
                // Representación visual de círculo.
                std::cout << "  Representación gráfica:\n" << std::endl;
                std::cout << "               🔵🔵🔵🔵" << std::endl;
                std::cout << "             🔵          🔵" << std::endl;
                std::cout << "           🔵             🔵" << std::endl;
                std::cout << "          🔵               🔵" << std::endl;
                std::cout << "           🔵             🔵 " << std::endl;
                std::cout << "             🔵         🔵" << std::endl;
                std::cout << "               🔵🔵🔵🔵" << std::endl;
                std::cout << "  💫 Círculo perfectamente simétrico.\n" << std::endl;
            }

        void Circulo::borrar() const 
            {
                std::cout << "🧹 BORRANDO CÍRCULO de radio " << radio << " en (" << x << ", " << y << ")." << std::endl;
            }

        // Sobrescritura opcional del método con comportamiento por defecto.
        void Circulo::rotar() const 
            {
                std::cout << " 🔵 ROTANDO CÍRCULO - Los círculos son simétricos en todas direcciones!" << std::endl;
                std::cout << "   No hay cambios visibles en la rotación." << std::endl;
            }

        // Implementación del método virtual puro de identificación.
        std::string Circulo::getTipo() const 
            {
                return "Círculo.";
            }

        // Getters y Setters.
        double Circulo::getRadio() const 
            {
                return radio;
            }

        void Circulo::setRadio(double nuevoRadio) 
            {
                if (nuevoRadio > 0) 
                    {
                        radio = nuevoRadio;
                        std::cout << "📏 Radio del círculo actualizado a: " << radio << std::endl;
                    } else 
                        {
                            std::cout << "❌ Error: El radio debe ser mayor que 0." << std::endl;
                        }
            }
    }