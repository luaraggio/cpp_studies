/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainFloat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:33:40 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 14:33:41 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a = 16777216.0f; // 2^24
    float b = a + 1;

    cout << setprecision(50);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    if (a == b)
        cout << "a e b são IGUAIS!" << endl;
    else
        cout << "a e b são diferentes!" << endl;
}
