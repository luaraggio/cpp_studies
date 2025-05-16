/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:25:27 by lraggio           #+#    #+#             */
/*   Updated: 2025/05/16 14:31:52 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float a = 0.1f;
    float b = 0.10000001f;

    cout << setprecision(30);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    if (a == b)
        cout << "iguais" << endl;
    else
        cout << "diferentes" << endl;
    return 0;
}

