/* 
 * File:   OpenMP.cpp
 * Author: glaucoroberto
 * 
 * Created on June 2, 2014, 10:41 AM
 */
#include <omp.h>
#include "Open.h"
#include <iostream>
#include <string>
using namespace std;
Open::Open() {
    cout << "Start a Class OpenMP\n";
}
Open::~Open(){
    cout << "Tchau :)\n";
}
int main(int argc, char *argv[])
{
    int th_id, nthreads;
    omp_set_num_threads(12);
    #pragma omp parallel private(th_id)
    {
        th_id = omp_get_thread_num();
        std::cout << "Hello!! I'm the number " << th_id << "\n";
        #pragma omp barrier
        if (th_id == 0) {
            nthreads = omp_get_num_threads();
            std::cout << "There are " << nthreads << " threads.\n";
        }
    }
    return 0;
}