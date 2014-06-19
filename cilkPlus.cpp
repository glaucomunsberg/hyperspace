/* 
 * File:   cilk.cpp
 * Author: glaucoroberto
 * 
 * Created on June 2, 2014, 3:40 PM
 */
#include <stdio.h>
#include <iostream>
#include <string>
#ifndef __cilk
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk_stub.h>
#include </opt/intel/composer_xe_2013_sp1.2.144/compiler/include/cilk/cilk.h>
#include <list>
#include "cilkPlus.h"

using namespace std;
cilkPlus::cilkPlus() {
    cilk::reducer_list_append<char> letters_reducer; // Build the list in parallel 
    cilk_for(char ch = 'a'; ch <= 'z'; ch++) { 
        simulated_work(); 
        letters_reducer.push_back(ch); 
    } 

    // Fetch the result of the reducer as a standard STL list 
    const std::list<char> &letters = letters_reducer.get_value(); 

    // Show the resulting list 
    std::cout << "Letters from reducer_list:"; 
    for(std::list<char>::const_iterator i = letters.begin(); i != letters.end(); i++) { 
        std::cout << " " << *i; 
    } 
    std::cout << std::endl;
}

cilkPlus::cilkPlus(const cilkPlus& orig) {
}

cilkPlus::~cilkPlus() {
}

