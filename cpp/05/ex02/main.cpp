/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:50:29 by davigome          #+#    #+#             */
/*   Updated: 2025/06/15 09:57:20 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void testConstruction() {
    std::cout << "\n--- Test de construcción válida ---" << std::endl;
    Bureaucrat a("Alice", 1);
    Bureaucrat b("Bob", 150);
    std::cout << a << "\n" << b << std::endl;

    std::cout << "\n--- Test de construcción inválida ---" << std::endl;
    try {
        Bureaucrat c("Charlie", 0); // Muy alto
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat d("David", 151); // Muy bajo
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test de construcción de AFormularios ---" << std::endl;
    try {
        AForm f1("AForm1", 50, 100);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        AForm f2("AForm2", 0, 50); // Invalido
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testGrades() {
    std::cout << "\n--- Test de incrementos y decrementos ---" << std::endl;
    Bureaucrat b("Bruce", 75);
    std::cout << b << std::endl;

    b.incrementGrade();
    std::cout << "Tras incrementar: " << b << std::endl;

    b.decrementGrade();
    std::cout << "Tras decrementar: " << b << std::endl;

    Bureaucrat top("Top", 1);
    Bureaucrat bottom("Bottom", 150);

    try {
        top.incrementGrade(); // Debe lanzar excepción
    } catch (const std::exception& e) {
        std::cerr << "Error al incrementar top: " << e.what() << std::endl;
    }

    try {
        bottom.decrementGrade(); // Debe lanzar excepción
    } catch (const std::exception& e) {
        std::cerr << "Error al decrementar bottom: " << e.what() << std::endl;
    }
}

void testSignatures() {
    std::cout << "\n--- Test de firmas ---" << std::endl;
    Bureaucrat low("LowRank", 100);
    Bureaucrat high("HighRank", 10);
    AForm f("Permiso", 50, 30);

    std::cout << f << std::endl;

    low.signAForm(f); // No debería poder firmar
    std::cout << f << std::endl;

    high.signAForm(f); // Debería poder firmar
    std::cout << f << std::endl;

    std::cout << "\n--- Intento de firmar ya firmado ---" << std::endl;
    high.signAForm(f); // Debe notificar que ya está firmado
}

int main() {
    std::cout << "========== INICIO DE TESTS ==========" << std::endl;
    testConstruction();
    testGrades();
    testSignatures();
    std::cout << "=========== FIN DE TESTS ============" << std::endl;
    return 0;
}
