/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:13:52 by davigome          #+#    #+#             */
/*   Updated: 2025/06/18 13:01:23 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp" // Include your template

// Function to print any element (works if << is defined)
template <typename T>
void print(T &x) {
    std::cout << x << std::endl;
}

// Function to increment an integer value
void increment(int &x) {
    ++x;
}

// Function to append "!" to a string
void addExclamation(std::string &s) {
    s += "!";
}

// Test program
int main() {
    // Test 1: Integer array
    std::cout << "=== Integer Array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);
    iter(intArray, 5, increment);
	std::cout << "===Post increment" << std::endl;
    iter(intArray, 5, print<int>);

    // Test 2: String array
    std::cout << "\n=== String Array ===" << std::endl;
    std::string strArray[] = {"hello", "world", "iter"};
    iter(strArray, 3, print<std::string>);
    iter(strArray, 3, addExclamation);
	std::cout << "===Post add exclamation===" << std::endl;
    iter(strArray, 3, print<std::string>);
    return 0;
}
