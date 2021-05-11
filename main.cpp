#include <iostream>
#include "IOlib.h"
#include "process.h"
#include "plant.h"
using namespace std;

int main()
{
    int M, L, N,J;
    double Un, Uv, T;
    double Xn[100], Xv[100];

    Plant plant;
    plant_init(plant);

    Input(M, L, T, N, Un, Uv, J);
    cout << "The process will take "<< T*N*2 << " seconds."<<endl;
    for(int i=0; i<N; i++){
        Xn[i]=CWCA(M,L,Un,T,J, plant);
        Xv[i]=CWCA(M,L,Uv,T,J, plant);
    }

    Outabla(Xn,Xv, N);

    cout << "avg  "<<average(Xn,N)<<"   "<<average(Xv,N)<<endl;
    cout << "spr  "<<spread(Xn,N)<<"   "<<spread(Xv,N)<<endl;
    return 0;
    }
