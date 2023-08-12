#include <string>
#define length 50


class equacao {
    private:
    void set_sizes() {
     Arraytipo = new int[EquacaoSize];
     MatrixIndex = new int* [EquacaoSize];
     ArrayNumeros = new int [EquacaoSize];
     ArrayOperadores = new int[EquacaoSize];
    
     for (int i = 0; i < EquacaoSize; i++){
          MatrixIndex[i] = new int [2];
     }
    }


    public :
     
     char EquacaoExtensa [10];
     int EquacaoSize = length;
     int *Arraytipo;
     int **MatrixIndex;
     int *ArrayNumeros;
     int *ArrayOperadores;


};

int main() {

    return 0;
}