#pragma once

#include "GestorFiguras.hpp"

namespace UI 
    {
        class Menu 
            {
                private:
                    Gestion::GestorFiguras gestor;  // COMPOSICIÓN: Menu posee Gestor.
                    // Métodos de creación de figuras.
                    void procesarCreacionFigura(); // Sin parámetros.
                    void procesarTipoFigura(int tipoFigura); // Nuevo método para tipo específico.
                    
                    // Métodos de visualización.
                    void mostrarMenuPrincipal() const;
                    void mostrarMenuFiguras() const;
                    
                    // Método de procesamiento.
                    void procesarOpcionPrincipal(int opcion);
                    
                    // Métodos de utilidad.
                    int obtenerOpcion() const;
                    void mostrarResultados() const;
                    void pausar() const;
                    void solicitarDatosFigura(int tipoFigura);

                public:
                    // Constructor y destructor.
                    Menu() = default;
                    ~Menu() = default;
                    
                    // Método principal de ejecución.
                    void ejecutar();
            };
    }