#include <iostream>
using namespace std;

void Input(int &M, int &L, double &T, int &N, double &Un, double &Uv, int &J){
    do {
            cout<<"Input sensor channel: ";
            cin>>M;
    } while (M<=0);
    do {
            cout<<"Input control channel: ";
            cin>>L;
    } while (L<=0);
    do {
            cout<<"Input time interval(in secs): ";
            cin>>T;
    } while (T<=0);
    do {
            cout<<"Input number of survey series: ";
            cin>>N;
    } while (N<=0);
            cout<<"Input low control action (Un): ";
            cin>>Un;
            cout<<"Input high control action (Uv): ";
            cin>>Un;
    do {
            cout<<"Input number of surveys in a series: ";
            cin>>J;
    } while (J<=0);
    return;
}

void Outabla(double X1[], double X2[], int N){

    cout<<"No.    Xn        Xv     "<<endl;

    for (int i = 0; i<N; i++){

        if (i<9) cout << " ";
        cout << i+1 << "   " << X1[i] << "   " <<  X2[i] << endl;

    }
    cout << "------------------------"<<endl;
}
