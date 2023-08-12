#include <string>
#include <iostream>
#include "functions.cpp"
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

    void get_types(){
        // 0 = Error, 1 = Numero, 2 = Operador
        for(int i = 0; i < EquacaoSize; i++){
            if(isOperator(EquacaoExtensa[i])){
                Arraytipo[i] = 2;
                continue;
            }
            if(isInt(EquacaoExtensa[i])){
                Arraytipo[i] = 1;
                continue;
            }
            Arraytipo[i] = 0;
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
        get_types();
     }

};

int main() {
    equacao equacao1;
    cin >> equacao1.EquacaoExtensa;
    equacao1.calculate();
    printArray(equacao1.Arraytipo,equacao1.EquacaoSize);


    return 0;
}