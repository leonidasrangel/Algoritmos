#include <iostream>
using namespace std;

float ponderada (float n1, float n2, float n3){
    float media = 0;
    if (n1 > n2 || n1 > n3){
        media = ((n1*4) + (n2*3) + (n3*3)) / (4+3+3);        
    } else if (n2 > n1 || n2 > n3){
        media = ((n1*3) + (n2*4) + (n3*3)) / (3+4+3);       
    } else {
        media = ((n1*3) + (n2*3) + (n3*4)) / (3+3+4);
    }
    cout <<"Sua media pondera e: " << media <<endl;
    return media;
}

void passou (float media){
    if (media >= 50){
        cout <<"Aprovado";
    } else{
        cout <<"Reprovado";
    }
}

int main (){
    float n1 = 0, n2 = 0, n3 = 0;

    cout << "Digite sua primeira nota: ";
    cin >> n1;
    cout << "Digite sua segunda nota: ";
    cin >> n2;
    cout << "Digite sua terceira nota: ";
    cin >> n3;

    float media = ponderada(n1,n2,n3);
    passou(media);
    return 0;
}