/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:46:23 by adian             #+#    #+#             */
/*   Updated: 2023/05/24 21:49:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float calculate(float first, float second, const std::string& oper) {
    if (oper == "+") {
        return first + second;
    } else if (oper == "-") {
        return first - second;
    } else if (oper == "*") {
        return first * second;
    } else if (oper == "/") {
        if (second == 0) {
            std::cout << "Error: Division by zero." << std::endl;
            exit(1);
        }
        return first / second;
    } else {
        std::cout << "Error: Invalid operator." << std::endl;
        exit(1);
    }
}

void inputProcess(std::string input) {
    std::stack<float> numbers;
    std::string expression;
    std::istringstream iss(input);
    while (iss >> expression) {
        if (expression == "+" || expression == "-" || expression == "*" || expression == "/") {
            if (numbers.size() < 2) {
                std::cerr << "Error: Not enought operands for " << expression << " operator." << std::endl;
                exit (1);
            }
            const float second = numbers.top();
            numbers.pop();
            const float first = numbers.top();
            numbers.pop();
            const float res = calculate(first, second, expression);
            numbers.push(res);
        } else {
            for (int i = 0; expression[i] != '\0'; i++) {
                if ((expression[i] < '0' && expression[i] > '9') && expression[i] != '.') {
                    std::cerr << "Error" << std::endl;
                }
            }

            float num = 0.0;
            try {
				num = std::stof(expression);
			}
			catch (const std::invalid_argument& e) {
        		std::cout << "Error" << std::endl;
                exit (1);
			}
			numbers.push(num);
        }
    }
    if (numbers.size() != 1) {
        std::cerr << "Error: Invalid input expression." << std::endl;
        exit (1);
    }

    std::cout << numbers.top() << std::endl;
}