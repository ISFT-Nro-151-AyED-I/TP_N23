#include "../include/Triangulo.hpp"

#include <iostream>
#include <cmath>

namespace Figuras 
    {

        // Constructor.
        Triangulo::Triangulo(double b, double h, double posX, double posY) : base(b), altura(h) 
            {
                x = posX;
                y = posY;
            }

        // Implementación de métodos virtuales puros.
        void Triangulo::dibujar() const 
            {
                std::cout << "🔺 DIBUJANDO TRIÁNGULO:" << std::endl;
                std::cout << "   Base: " << base << ", Altura: " << altura << std::endl;
                std::cout << "   Posición: (" << x << ", " << y << ")" << std::endl;
                std::cout << "   Área: " << (base * altura / 2) << " unidades²" << std::endl;
                std::cout << "   Hipotenusa: " << sqrt(base * base + altura * altura) << " unidades\n" << std::endl;
                
                // Representación visual de triángulo
                std::cout << "  Representación gráfica:\n" << std::endl;
                std::cout << "         🔺" << std::endl;
                std::cout << "        🔺🔺" << std::endl;
                std::cout << "       🔺  🔺" << std::endl;
                std::cout << "      🔺    🔺" << std::endl;
                std::cout << "     🔺      🔺" << std::endl;
                std::cout << "    🔺        🔺" << std::endl;
                std::cout << "   🔺🔺🔺🔺🔺🔺" << std::endl;
                std::cout << "  📏 Triángulo equilátero representativo.\n" << std::endl;
            }

        void Triangulo::borrar() const 
            {
                std::cout << "🧹 BORRANDO TRIÁNGULO de base " << base << " y altura " << altura << " en (" << x << ", " << y << ")." << std::endl;
            }

        // Sobrescritura opcional del método con comportamiento por defecto.
        void Triangulo::rotar() const 
            {
                std::cout << "🔄 ROTANDO TRIÁNGULO..." << std::endl;
                std::cout << "   El triángulo ha cambiado su orientación!" << std::endl;
            }

        // Implementación del método virtual puro de identificación
        std::string Triangulo::getTipo() const 
            {
                return "Triángulo.";
            }

        // Getters y Setters
        double Triangulo::getBase() const 
            {
                return base;
            }

        double Triangulo::getAltura() const 
            {
                return altura;
            }

        void Triangulo::setBase(double nuevaBase) 
            {
                if (nuevaBase > 0) 
                    {
                        base = nuevaBase;
                        std::cout << "📏 Base del triángulo actualizada a: " << base << std::endl;
                        
                    } else 
                        {
                            std::cout << "❌ Error: La base debe ser mayor que 0" << std::endl;
                        }
            }

        void Triangulo::setAltura(double nuevaAltura) 
            {
                if (nuevaAltura > 0) 
                    {
                        altura = nuevaAltura;
                        std::cout << "📏 Altura del triángulo actualizada a: " << altura << std::endl;

                    } else 
                        {
                            std::cout << "❌ Error: La altura debe ser mayor que 0" << std::endl;
                        }
            }

    }