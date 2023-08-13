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
     ArrayOperadores = new char[EquacaoSize];
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

    void get_numbers() {
        for (int num = 0; num < QtdNumeros; num ++){
            int casaDecimal = 0;
            int res = 0;
            for (int digito = MatrixIndex[num][1]; digito >= MatrixIndex[num][0]; digito--){
                res += GetInt(EquacaoExtensa[digito]) * (elevado(10,casaDecimal));
                casaDecimal++;
            }
            ArrayNumeros[num] = res;
        }
    }

    void get_operadores(){
        int index = 0;
        for (int i = 0; i < EquacaoSize; i ++) {
            if (Arraytipo[i] == 2){
                ArrayOperadores[index] = EquacaoExtensa[i];
                index++;
            }
        }
        QtdOperadores = index;
    }

    void get_finalAnswer(){
        resultado = 0;
        resultado += ArrayNumeros[0];
        for(int i = 0; i < QtdOperadores; i++) {
            resultado = operate(resultado, ArrayNumeros[i + 1], ArrayOperadores[i]);
        }
    }

    public :
     
     string EquacaoExtensa;
     int EquacaoSize;
     int *Arraytipo;
     int **MatrixIndex;
     int QtdNumeros;
     int *ArrayNumeros;
     char *ArrayOperadores;
     int QtdOperadores;
     int resultado;

     void calculate(){
        set_sizes();
        get_types();
        get_numberindexes();
        get_numbers();
        get_operadores();
        get_finalAnswer();
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

    cout << equacao1.resultado;
    return 0;
}