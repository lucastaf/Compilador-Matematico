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

float operate(int a, int b, char operador) {
        //Na tabela Ascii:
        //43 = +, 45 = -, 47 = /, 42 = *.
        switch(operador){
        case '+':
         return a + b;
        break;
        case '-':
         return a - b;
        break;
        case '/':
         return a / b;
        break;
        case '*':
         return a * b;
        break;
        }


        return 0;
}

void shift_array(int array[], int size, int index){
    for (int i = index; i < size - 1; i ++){
        array[i] = array[i+1];
    }
    array[size-1] = 0;
}

void shift_array_char(char array[], int size, int index){
    for (int i = index; i < size - 1; i ++){
        array[i] = array[i+1];
    }
    array[size-1] = 0;
}