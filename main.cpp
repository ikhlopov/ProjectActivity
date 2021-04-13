#include <iostream>
#include "IOlib.h"
#include "process.h"
#include "plant.h"
using namespace std;

int main()
{
    int M, L, T, N,J;
    double Un, Uv;
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

    cout << "average Xn: "<<average(Xn,N)<<endl;
    cout << "average Xv: "<<average(Xv,N)<<endl;
    cout << "low spread: "<<spread(Xn, N)<<endl;
    cout << "high spread: "<<spread(Xv, N)<<endl;
    return 0;
    /*

    int M = 31,
        L = 7,
        T = 1,
        N = 10,
        J = 50;
         Plant plant;
         plant_init(plant);
    double Un = -70, Uv=-70;
    double Xn[10], Xv[150];
    for (Uv; Uv<71; Uv=Uv+5){

        for(int i=0; i<N; i++){
        Xn[i]=CWCA(M,L,Un,T,J, plant);
        Xv[i]=CWCA(M,L,Uv,T,J, plant);
        }
        cout<<average(Xv, N)-average(Xn, N)<<endl;
    }
    cout << "Я кончил!";
    */
}
