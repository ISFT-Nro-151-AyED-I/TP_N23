#include "../include/Menu.hpp"

#include <windows.h>
#include <iostream>

int main() 
    {
        // Configura consola para soportar UTF-8 y emojis.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        // Verifica que la configuración UTF-8 se aplicó correctamente.
        std::cout << "\n🔧 Configurando consola para UTF-8...\n";
        
        // Mensaje de prueba para verificar que los emojis funcionan.
        std::cout << "✅ Consola configurada correctamente\n";
        std::cout << "🎨 Emojis de prueba: 🔵 🟦 🔺 ➕ 🧹 🔄 🚀 ❌\n";
        std::cout << std::endl;
        
        // Crea y ejecuta el menú principal.
        try 
            {
                UI::Menu menu;
                menu.ejecutar();
            }
            catch (const std::exception& e) 
                {
                    std::cout << "❌ Error crítico en la ejecución: " << e.what() << std::endl;
                    std::cout << "💡 El programa se cerrará por seguridad." << std::endl;
                    return 1;
                }
                catch (...) 
                    {
                        std::cout << "❌ Error desconocido en la ejecución." << std::endl;
                        std::cout << "💡 El programa se cerrará por seguridad." << std::endl;
                        return 1;
                    }
        
        std::cout << std::endl;
        std::cout << "🏁 Programa finalizado correctamente." << std::endl;
        
        return 0;
    }