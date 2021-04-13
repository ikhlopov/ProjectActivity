#ifndef PROCESS_HPP_INCLUDED
#define PROCESS_HPP_INCLUDED
#include <chrono>
#include <thread>
//#include <iostream>
#include "plant.h"

double CWCA (int SnsCh, int CtrlCh, double CtrlAct, int wait, int J, Plant plant){// control, wait, check, average

    plant_control(CtrlCh, CtrlAct, plant);//control
    std::this_thread::sleep_for(std::chrono::seconds(wait));//wait
    double sum=0;
    double a;
    for(int i=0; i<J; i++){
        a=plant_measure(SnsCh, plant); //check
        sum+=a;
        //std::cout<<a<<'\n';
    }
    sum = sum/J; //average
    return sum;
}

double average(double X[], int N){
    double sum = 0;
    for(int i=0; i<N; i++){
        sum+=X[i];
    }

    return sum/N;
}

double spread(double X[], int N){
    double min = X[0];
    double max = X[0];
    for(int i=0; i<N; i++){
        if (X[i]>max) max = X[i];
        if (X[i]<min) min = X[i];
    }
    return max-min;
}

#endif // PROCESS_HPP_INCLUDED
