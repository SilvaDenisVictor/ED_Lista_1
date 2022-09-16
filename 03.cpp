

#include <bits/stdc++.h>

using namespace std;

void min_hipfy(vector<double>& vetor, int posicao, int inicio, int fim);

void Heap_sort(vector<double>& vetor, int inicio, int fim);

void InsersionSort(vector<double>& vetor, int inicio, int fim);
       

int main()
{
    vector<double> vetor = {10,9,8,7,6,5,4,3,2,1,0};
 
    for(int c = 0; c < vetor.size(); c++){
        cout << vetor[c] << " ";
    }
    
    InsersionSort(vetor, 0, vetor.size()-1);
    cout << endl;
    
    for(int c = 0; c < vetor.size(); c++){
        cout << vetor[c] << " ";
    }
    
    return 0;
}

void trocar(double& x, double& y){
    double z = x;
    x = y;
    y = z;
}

void min_hipfy(vector<double>& vetor, int posicao, int inicio, int fim){
    int Esq = 2*(posicao - inicio + 1)+ inicio - 1;
    int Dir = Esq + 1;
    int menor = posicao;
    
    if(Esq <= fim && vetor[posicao] > vetor[Esq]) menor = Esq;
    if(Dir <= fim && vetor[menor] > vetor[Dir]) menor = Dir;
    if(posicao != menor){
        trocar(vetor[posicao], vetor[menor]);
        min_hipfy(vetor, menor, inicio, fim);
    }
    
}

void Heap_sort(vector<double>& vetor, int inicio, int fim){  
    for(int c = (fim + inicio - 1)/2; c >= inicio; c--){//(posicao - inicio + 1)/2+ inicio - 1
        min_hipfy(vetor, c, inicio, fim);
    }
    
    for(int c = fim; c < inicio; c--){
        trocar(vetor[inicio], vetor[fim]);
        
        fim = fim - 1;
        min_hipfy(vetor, inicio, inicio, fim);
    }
}

void InsersionSort(vector<double>& vetor, int inicio, int fim){
    int i = inicio + 1;
    
    for(int i = inicio + 1; i <= fim; i++){
        int j = i-1;
        
        while(j >= inicio && vetor[j] > vetor[i]){
            double aux = vetor[i];
            
            vetor[i] = vetor[j];
            vetor[j] = aux;
            j--;
            i--;
        }
    }
}
