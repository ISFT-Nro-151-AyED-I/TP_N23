#pragma once

#include "Figura.hpp"
#include "Circulo.hpp"
#include "Rectangulo.hpp"
#include "Triangulo.hpp"

namespace Gestion 
    {
        class GestorFiguras 
            {
                private:
                    Figuras::Figura* figuras[5];  // Array de punteros polimórficos.
                    int cantidad;                 // Contador actual de figuras.

                public:
                    // Constructor y destructor.
                    GestorFiguras();
                    ~GestorFiguras();
                    
                    // ✅ MÉTODOS DE CREACIÓN (Gestor crea las figuras - COMPOSICIÓN).
                    Figuras::Figura* crearFigura(int tipo, double param1, double param2, double x = 0.0, double y = 0.0);
                    Figuras::Figura* crearCirculo(double radio, double x = 0.0, double y = 0.0);
                    Figuras::Figura* crearRectangulo(double ancho, double alto, double x = 0.0, double y = 0.0);
                    Figuras::Figura* crearTriangulo(double base, double altura, double x = 0.0, double y = 0.0);
                    
                    // Métodos de gestión del array.
                    bool agregarFigura(Figuras::Figura* figura);
                    
                    // Métodos de ejecución polimórfica.
                    void ejecutarDibujar() const;
                    void ejecutarBorrar() const;
                    void ejecutarRotar() const;
                    void ejecutarMover() const;
                    
                    // Métodos de utilidad.
                    void limpiarFiguras();  // ✅ CORREGIDO: Ahora tiene sentido en composición.
                    int getCantidad() const;
                    bool estaLleno() const;
                    void mostrarFiguras() const;
                };
    }