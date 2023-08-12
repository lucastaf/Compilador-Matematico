#include <string>
#include <iostream>
using namespace std;


class equacao {
    private:
    void set_sizes() {
     EquacaoSize = EquacaoExtensa.size();
     Arraytipo = new int[EquacaoSize];
     MatrixIndex = new int* [EquacaoSize];
     ArrayNumeros = new int [EquacaoSize];
     ArrayOperadores = new int[EquacaoSize];
    
     for (int i = 0; i < EquacaoSize; i++){
          MatrixIndex[i] = new int [2];
     }
    }


    public :
     
     string EquacaoExtensa;
     int EquacaoSize;
     int *Arraytipo;
     int **MatrixIndex;
     int *ArrayNumeros;
     int *ArrayOperadores;
     
     void calculate(){
        set_sizes();
     }

};

int main() {
    equacao teste;
    cin >> teste.EquacaoExtensa;
    teste.calculate();

    cout << teste.EquacaoSize;
    return 0;
}