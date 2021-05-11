#include <iostream>
#include "process.h"
#include "plant.h"
using namespace std;
int main() {
    int M = 31,
        L = 7,
        N = 10,
        J = 50;
    double T = 0.5;
         Plant plant;
         plant_init(plant);
    double Un = -70, Uv=-70;
    double Xn[10], Xv[150];
    for (Uv; Uv<71; Uv+=5){

        for(int i=0; i<N; i++){
            Xn[i]=CWCA(M,L,Un,T,J, plant);
            Xv[i]=CWCA(M,L,Uv,T,J, plant);
        }
        cout<<average(Xv, N)-average(Xn, N)<<endl;
    }
    cout << "Finish!";
}
