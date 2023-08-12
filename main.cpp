#include <string>
#include <iostream>
#include "functions.cpp"
using namespace std;



class equacao {
    private:
    void set_sizes() {
     EquacaoSize = EquacaoExtensa.size();
     Arraytipo = new int[EquacaoSize];
     ArrayNumeros = new int [EquacaoSize];
     ArrayOperadores = new int[EquacaoSize];
     MatrixIndex = new int* [EquacaoSize];
     for (int i = 0; i < EquacaoSize; i++){
        MatrixIndex[i] = new int[2];
     }
     MatrixIndex[0][0] = 0;
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

    void get_numberindexes(){
        int stage = 0; //0 = Esperando começo de Numero, 1 = Esperando final do numero
        int index = 0;

        for (int i = 0; i < EquacaoSize; i++){
            if (stage == 0){
                if (Arraytipo[i] == 1){                    
                    MatrixIndex[index][0] = i; //Define o começo de um numero qualquer
                    stage = 1; //achei começo de numero, estou procurando final
                }
            }
            if (stage == 1){
                if (Arraytipo[i] != 1){
                    MatrixIndex[index][1] = i-1; //Defibe o final de um numero qualquer
                    stage = 0; //achei final do numero, fico em standby
                    index++;
                }
                if (i == EquacaoSize - 1) MatrixIndex[index][1] = i;
            }
        }
        QtdNumeros = index + 1;

    }


    public :
     
     string EquacaoExtensa;
     int EquacaoSize;
     int *Arraytipo;
     int **MatrixIndex;
     int QtdNumeros;
     int *ArrayNumeros;
     int *ArrayOperadores;

     void calculate(){
        set_sizes();
        get_types();
        get_numberindexes();
     }

     void print_Indexes() {
        for (int i = 0; i < QtdNumeros; i ++){
            cout << "Print_Indexes " << MatrixIndex[i][0] << "  " << MatrixIndex[i][1] << "\n";
        }
        cout << "\n";
     }

};

int main() {
    equacao equacao1;
    cin >> equacao1.EquacaoExtensa;
    equacao1.calculate();

    equacao1.print_Indexes();


    return 0;
}