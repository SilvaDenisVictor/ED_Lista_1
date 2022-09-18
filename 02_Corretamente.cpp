#include <bits/stdc++.h>

using namespace std;

int BuscaBinaria(vector<double>& vetor, double elemento);

int main(){
    
    vector<double> vetor = {0,50,5,49,6,37,88,1,99};
    
    cout << BuscaBinaria(vetor, 49) << endl;

    return 0;
}

int BuscaBinaria(vector<double>& vetor, double elemento){
    int tamanho = vetor.size();
    int inicio, fim, atual;
    
    inicio = 1;
    fim = (tamanho+1)/2;//SOMA UM PARA O CASO DE O VETOR N SER MULTIPLO DE 2
    while(inicio <= fim){
        atual = (inicio+fim)/2;
        
        if(elemento > vetor[(atual*2 - 1) - 1]) inicio = atual + 1;
        else if(elemento < vetor[(atual*2 - 1) - 1]) fim = atual - 1;
        else return (atual*2 - 1) - 1;
    }
    
    inicio = 1;
    fim = tamanho/2;
    while(inicio <= fim){
        atual = (inicio+fim)/2;
        
        if(elemento > vetor[(atual*2) - 1]) fim = atual - 1;
        else if(elemento < vetor[(atual*2) - 1]) inicio = atual + 1;
        else return (atual*2) - 1;
    }
   
    return -1;
}
