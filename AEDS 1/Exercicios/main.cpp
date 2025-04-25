#include<iostream>
#include<locale.h>
using namespace std;

int main(){ 
    setlocale(LC_ALL, "Portuguese");
    cout << "Olá mundo" << endl;
    return 0;
}