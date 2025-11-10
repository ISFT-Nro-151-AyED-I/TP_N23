#include "../include/Menu.hpp"

#include <iostream>
#include <limits>

namespace UI 
    {
        // Método principal de ejecución.
        void Menu::ejecutar() 
            {
                std::cout << "\n==========================================\n";
                std::cout << "     📐 SISTEMA DE FIGURAS GEOMÉTRICAS\n";
                std::cout << "==========================================\n";
                std::cout << "🚀 Inicializando sistema...\n\n";
                
                int opcion;
                do 
                    {
                        mostrarMenuPrincipal();

                        opcion = obtenerOpcion();

                        procesarOpcionPrincipal(opcion);
                        
                    } while (opcion != 6);
                
                std::cout << "👋 ¡Gracias por usar el Sistema de Figuras Geométricas!" << std::endl;
            }

        // Métodos de visualización.
        void Menu::mostrarMenuPrincipal() const 
            {
                std::cout << "================================\n";
                std::cout << "       📋 MENÚ PRINCIPAL\n";
                std::cout << "================================\n";
                std::cout << "1. ➕ Crear nueva figura\n";
                std::cout << "2. 🎨 Dibujar todas las figuras\n";
                std::cout << "3. 🧹 Borrar todas las figuras\n";
                std::cout << "4. 🔄 Rotar todas las figuras\n";
                std::cout << "5. 🚀 Mover todas las figuras\n";
                std::cout << "6. ❌ Salir del programa\n";
                std::cout << "================================";
                
                gestor.mostrarFiguras();
                
                std::cout << "================================\n";
                std::cout << "💡 Selecciona una opción (1-6): ";
            }

        void Menu::mostrarMenuFiguras() const 
            {
                std::cout << "\n🔷 TIPOS DE FIGURAS DISPONIBLES\n";
                std::cout << "================================\n";
                std::cout << "1. 🔵 Círculo\n";
                std::cout << "2. 🟩 Rectángulo\n";
                std::cout << "3. 🔺 Triángulo\n";
                std::cout << "4. ↩️  Volver al menú principal\n";
                std::cout << "================================";
                std::cout << "💡 Selecciona el tipo de figura (1-4): ";
            }

        // Métodos de procesamiento.
        void Menu::procesarOpcionPrincipal(int opcion) 
            {
                switch (opcion) 
                    {
                        case 1:
                            procesarCreacionFigura();
                            break;
                        case 2:
                            gestor.ejecutarDibujar();
                            pausar();
                            break;
                        case 3:
                            gestor.ejecutarBorrar();
                            pausar();
                            break;
                        case 4:
                            gestor.ejecutarRotar();
                            pausar();
                            break;
                        case 5:
                            gestor.ejecutarMover();
                            pausar();
                            break;
                        case 6:
                            std::cout << "👋 Saliendo del programa..." << std::endl;
                            break;
                        default:
                            std::cout << "❌ Opción no válida. Por favor, selecciona 1-6." << std::endl;
                            pausar();
                    }
            }

        void Menu::procesarCreacionFigura() 
            {
                if (gestor.estaLleno()) 
                    {
                        std::cout << "❌ El gestor está lleno (5/5 figuras). No se pueden crear más figuras." << std::endl;
                        std::cout << "💡 Usa la opción 'Borrar todas las figuras' para liberar espacio." << std::endl;

                        pausar();
                        return;
                    }
                
                int tipoFigura;
                do 
                    {
                        mostrarMenuFiguras();
                        tipoFigura = obtenerOpcion();
                        
                        switch (tipoFigura) 
                            {
                                case 1: // Círculo.
                                case 2: // Rectángulo.
                                case 3: // Triángulo.
                                    procesarTipoFigura(tipoFigura);
                                    break;
                                case 4: // Volver.
                                    std::cout << "↩️  Volviendo al menú principal..." << std::endl;
                                    break;
                                default:
                                    std::cout << "❌ Opción no válida. Por favor, seleccione 1-4." << std::endl;
                            }

                    } while (tipoFigura != 4);
            }

        void Menu::procesarTipoFigura(int tipoFigura) 
            {
                double param1, param2, x, y;
                
                std::cout << "\n📝 INGRESO DE DATOS DE LA FIGURA" << std::endl;
                std::cout << "=================================" << std::endl;
                
                // Solicita posición.
                std::cout << "📍 Posición de la figura:" << std::endl;
                std::cout << "   Coordenada X: ";
                std::cin >> x;
                std::cout << "   Coordenada Y: ";
                std::cin >> y;
                
                // Solicita parámetros específicos según el tipo de figura.
                switch (tipoFigura) 
                    {
                        case 1: // Círculo.
                            std::cout << "🔵 Parámetros del Círculo:" << std::endl;

                            std::cout << "   Radio: ";
                            std::cin >> param1;

                            param2 = 0; // No se usa para círculos.
                            break;
                            
                        case 2: // Rectángulo.
                            std::cout << "🟦 Parámetros del Rectángulo:" << std::endl;

                            std::cout << "   Ancho: ";
                            std::cin >> param1;

                            std::cout << "   Alto: ";
                            std::cin >> param2;
                            break;
                            
                        case 3: // Triángulo
                            std::cout << "🔺 Parámetros del Triángulo:" << std::endl;

                            std::cout << "   Base: ";
                            std::cin >> param1;
                            
                            std::cout << "   Altura: ";
                            std::cin >> param2;
                            break;
                    }
                
                // Valida entrada.
                if (std::cin.fail()) 
                    {
                        std::cout << "❌ Error: Entrada no válida. Por favor, ingresa números." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        pausar();
                        return;
                    }
                
                // Crea la figura a través del gestor.  
                Figuras::Figura* nuevaFigura = gestor.crearFigura(tipoFigura, param1, param2, x, y);
                
                if (nuevaFigura != nullptr) 
                    {
                        std::cout << "✅ ¡Figura creada exitosamente!" << std::endl;
                        std::cout << "📊 Tipo: " << nuevaFigura->getTipo() << std::endl;
                        
                    } else 
                        {
                            std::cout << "❌ No se pudo crear la figura. Verifica los parámetros." << std::endl;
                        }
                
                pausar();
            }

        void Menu::solicitarDatosFigura(int tipoFigura) 
            {
                procesarTipoFigura(tipoFigura);
            }

        // Métodos de utilidad.
        int Menu::obtenerOpcion() const 
            {
                int opcion;
                std::cin >> opcion;
                
                if (std::cin.fail()) 
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return -1; // Indicador de opción inválida.
                    }
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return opcion;
            }

        void Menu::mostrarResultados() const 
            {
                std::cout << "\n📊 RESUMEN DEL SISTEMA" << std::endl;
                std::cout << "=======================" << std::endl;
                
                gestor.mostrarFiguras();
            }

        void Menu::pausar() const 
            {
                std::cout << "\n⏸️  Presione Enter para continuar...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;
            }
    }