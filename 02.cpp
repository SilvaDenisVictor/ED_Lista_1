#include <bits/stdc++.h>

using namespace std;

int BuscaBinaria(vector<double>& vetor, double elemento);

int main(){
    
    vector<double> vetor = {0,50,5,49,6,37,88,1,99};
    
    cout << BuscaBinaria(vetor, 99) << endl;

    return 0;
}

int BuscaBinaria(vector<double>& vetor, double elemento){
    int ultimo_cre = (vetor.size() % 2 == 1) ? vetor.size() - 1 : vetor.size() - 2;
    int ultimo_dec = (vetor.size() % 2 == 0) ? vetor.size() - 1 : vetor.size() - 2;
   
    if(elemento >= vetor[0] && elemento <= vetor[ultimo_cre]){
        int ini = 0;
        int fim = ultimo_cre;

        while(ini <= fim){
            int meio = ((int)((ini+fim)/2) % 2 == 0)? ((ini+fim)/2) : ((ini+fim)/2) - 1;
            
            if(elemento > vetor[meio]) ini = meio + 2;
            else if(elemento < vetor[meio]) fim = meio - 2;
            else return meio;
        }
    }
    
    if(elemento <= vetor[1] && elemento >= vetor[ultimo_dec]){
        int ini = 1;
        int fim = ultimo_dec;
        
        while(ini <= fim){
            int meio = ((int)((ini+fim)/2) % 2 == 0)? ((ini+fim)/2) - 1 : ((ini+fim)/2);
            
            if(elemento > vetor[meio]) fim = meio - 2;
            else if(elemento < vetor[meio]) ini = meio + 2;
            else return meio;
        }
    }
   
    return -1;
}






