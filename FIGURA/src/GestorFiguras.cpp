#include "../include/GestorFiguras.hpp"

#include <iostream>
#include <iomanip>

namespace Gestion 
    {
        // Constructor.
        GestorFiguras::GestorFiguras() : cantidad(0) 
            {
                // Inicializar el array de punteros a nullptr.
                for (int i = 0; i < 5; ++i) 
                    {
                        figuras[i] = nullptr;
                    }

                std::cout << "🚀 Gestor de Figuras inicializado." << std::endl;
            }

        // Destructor.
        GestorFiguras::~GestorFiguras() 
            {
                limpiarFiguras();

                std::cout << "🧹 Gestor de Figuras destruido." << std::endl;
            }

        // Métodos de creación de figuras.
        Figuras::Figura* GestorFiguras::crearFigura(int tipo, double param1, double param2, double x, double y) 
            {
                Figuras::Figura* nuevaFigura = nullptr;
                
                switch (tipo) 
                    {
                        case 1: // Círculo.
                            nuevaFigura = crearCirculo(param1, x, y);
                            break;
                        case 2: // Rectángulo.
                            nuevaFigura = crearRectangulo(param1, param2, x, y);
                            break;
                        case 3: // Triángulo.
                            nuevaFigura = crearTriangulo(param1, param2, x, y);
                            break;
                        default:
                            std::cout << "❌ Tipo de figura no válido: " << tipo << std::endl;
                            return nullptr;
                    }
                
                if (nuevaFigura && agregarFigura(nuevaFigura)) 
                    {
                        std::cout << "✅ Figura creada y agregada exitosamente!" << std::endl;
                        return nuevaFigura;

                    } else 
                        {
                            // Si no se pudo agregar, libera memoria (asigna nullptr al puntero).
                            delete nuevaFigura;

                            std::cout << "❌ No se pudo agregar la figura al gestor." << std::endl;
                            return nullptr;
                        }
            }

        Figuras::Figura* GestorFiguras::crearCirculo(double radio, double x, double y) 
            {
                if (radio <= 0) 
                    {
                        std::cout << "❌ Error: El radio debe ser mayor que 0." << std::endl;
                        return nullptr;
                    }

                std::cout << "🔵 Creando círculo con radio " << radio << " en (" << x << ", " << y << ")." << std::endl;
                return new Figuras::Circulo(radio, x, y);
            }

        Figuras::Figura* GestorFiguras::crearRectangulo(double ancho, double alto, double x, double y) 
            {
                if (ancho <= 0 || alto <= 0) 
                    {
                        std::cout << "❌ Error: Ancho y alto deben ser mayores que 0." << std::endl;
                        return nullptr;
                    }

                std::cout << "🟩 Creando rectángulo " << ancho << "x" << alto << " en (" << x << ", " << y << ")." << std::endl;
                return new Figuras::Rectangulo(ancho, alto, x, y);
            }

        Figuras::Figura* GestorFiguras::crearTriangulo(double base, double altura, double x, double y) 
            {
                if (base <= 0 || altura <= 0) 
                    {
                        std::cout << "❌ Error: Base y altura deben ser mayores que 0." << std::endl;
                        return nullptr;
                    }

                std::cout << "🔺 Creando triángulo base " << base << " altura " << altura << " en (" << x << ", " << y << ")." << std::endl;
                return new Figuras::Triangulo(base, altura, x, y);
            }

        // Métodos de gestión del array.
        bool GestorFiguras::agregarFigura(Figuras::Figura* figura) 
            {
                if (estaLleno()) 
                    {
                        std::cout << "❌ El gestor está lleno (máximo 5 figuras)." << std::endl;
                        return false;
                    }
                
                if (figura == nullptr) 
                    {
                        std::cout << "❌ Error: No se puede agregar una figura nula." << std::endl;
                        return false;
                    }
                
                figuras[cantidad] = figura;
                cantidad++;
                
                std::cout << "📥 Figura agregada en posición " << cantidad << "/5." << std::endl;
                return true;
            }

        // Métodos de ejecución polimórfica.
        void GestorFiguras::ejecutarDibujar() const 
            {
                std::cout << "\n🎨 EJECUTANDO DIBUJAR EN TODAS LAS FIGURAS:" << std::endl;
                std::cout << "===========================================" << std::endl;
                
                if (cantidad == 0) 
                    {
                        std::cout << "📭 No hay figuras para dibujar." << std::endl;
                        return;
                    }
                
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "\n--- Figura " << (i + 1) << " ---" << std::endl;
                                figuras[i]->dibujar();  // ✅ Polimorfismo: llama al dibujar correcto.
                            }
                    }
                    
                std::cout << "✅ Dibujo completado para " << cantidad << " figura(s)" << std::endl;
            }

        void GestorFiguras::ejecutarBorrar() const 
            {
                std::cout << "\n🧹 EJECUTANDO BORRAR EN TODAS LAS FIGURAS:" << std::endl;
                std::cout << "==========================================" << std::endl;
                
                if (cantidad == 0) 
                    {
                        std::cout << "📭 No hay figuras para borrar" << std::endl;
                        return;
                    }
                
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "Figura " << (i + 1) << ": ";

                                figuras[i]->borrar();  // ✅ Polimorfismo.
                            }
                    }

                std::cout << "✅ Borrado completado para " << cantidad << " figura(s)" << std::endl;
            }

        void GestorFiguras::ejecutarRotar() const 
            {
                std::cout << "\n🔄 EJECUTANDO ROTAR EN TODAS LAS FIGURAS:" << std::endl;
                std::cout << "=========================================" << std::endl;
                
                if (cantidad == 0) 
                    {
                        std::cout << "📭 No hay figuras para rotar" << std::endl;
                        return;
                    }
                
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "Figura " << (i + 1) << " (" << figuras[i]->getTipo() << "): ";

                                figuras[i]->rotar();  // ✅ Polimorfismo.
                            }
                    }

                std::cout << "✅ Rotación completada para " << cantidad << " figura(s)" << std::endl;
            }

        void GestorFiguras::ejecutarMover() const 
            {
                std::cout << "\n🚀 EJECUTANDO MOVER EN TODAS LAS FIGURAS:" << std::endl;
                std::cout << "=========================================" << std::endl;
                
                if (cantidad == 0) 
                    {
                        std::cout << "📭 No hay figuras para mover" << std::endl;
                        return;
                    }
                
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "Figura " << (i + 1) << " (" << figuras[i]->getTipo() << "): ";
                                figuras[i]->mover();  // ✅ Polimorfismo
                            }
                    }
                    
                std::cout << "✅ Movimiento completado para " << cantidad << " figura(s)" << std::endl;
            }

        // Métodos de utilidad.
        void GestorFiguras::limpiarFiguras() 
            {
                std::cout << "🧼 Limpiando todas las figuras..." << std::endl;
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "🗑️  Eliminando " << figuras[i]->getTipo() << "..." << std::endl;

                                delete figuras[i];  // ✅ Destrucción polimórfica segura
                                figuras[i] = nullptr;
                            }
                    }

                cantidad = 0;

                std::cout << "✅ Todas las figuras han sido eliminadas." << std::endl;
            }

        int GestorFiguras::getCantidad() const 
            {
                return cantidad;
            }

        bool GestorFiguras::estaLleno() const 
            {
                return cantidad >= 5;
            }

        void GestorFiguras::mostrarFiguras() const 
            {
                std::cout << "\n\n📊 ESTADO ACTUAL DEL GESTOR:" << std::endl;
                std::cout << "============================" << std::endl;
                std::cout << "Figuras almacenadas: " << cantidad << "/5" << std::endl;
                
                if (cantidad == 0) 
                    {
                        std::cout << "📭 El gestor está vacío" << std::endl;
                        return;
                    }
                
                std::cout << "\nLista de figuras:" << std::endl;
                for (int i = 0; i < cantidad; ++i) 
                    {
                        if (figuras[i] != nullptr) 
                            {
                                std::cout << "  " << (i + 1) << ". " << figuras[i]->getTipo() << std::endl;
                            }
                    }
            }
    }