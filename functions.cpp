#include <iostream>
using namespace std;

int isInt(char value){
    if (value == '0'||value == '1'|| value == '2' || value == '3'|| value == '4'|| value == '5'|| value == '6'|| value == '7'|| value == '8'|| value == '9'){
        return 1;
    }
    return 0;
}

int isOperator(char value){
    if (value == '+'|| value == '-'|| value == '*'|| value == '/'){
        return 1;
    }
    return 0;
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i ++){
        cout << array[i] << " ";
    }
    cout << "\n";
    
}

int GetInt(int Charnumber){
    //Esse codigo serve para tirar proveito de uma propriedade da tabela ascii.
    return Charnumber - 48;
}

int elevado(int base, int expoente){
    int res = 1;
    for (int i = 0; i < expoente; i ++){
        res = res * base;
    }
    return res;

}