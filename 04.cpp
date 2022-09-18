#include <iostream>
#include <vector>

using namespace std;

void minheapfy(vector<int>& vetor, int posicao, int inicio, int fim);

void heapfy(vector<int>& vetor, int inicio, int fim);

void trocar(int& x, int& y);

int main()
{
    vector<int> vetor = {113210,6,90,24,2,749, 44,33};
    
    heapfy(vetor, 0, 7);
    
    for(int c = 0; c < vetor.size() - 1; c++){
        cout << vetor[c] << " ";
    }

    return 0;
}

void trocar(int& x, int& y){
    int z = x;
    x = y;
    y = z;
}

void minheapfy(vector<int>& vetor, int posicao, int inicio, int fim){

    int esq = fim - 2*(fim - posicao + 1) + 1;
    int dir =  esq - 1;
    int menor = posicao;
    
    if((esq >= inicio)  && (vetor[posicao] > vetor[esq])) menor = esq;
    if((dir >= inicio) && (vetor[menor] > vetor[dir])) menor = dir;
    if(menor != posicao){
        trocar(vetor[menor], vetor[posicao]);
        minheapfy(vetor, menor, inicio, fim);
    }
}

void heapfy(vector<int>& vetor, int inicio, int fim){
    
    for(int c = (fim + inicio +2)/2; c <= fim; c++){//
        minheapfy(vetor, c, inicio, fim);
    }
    
    for(int c = 0; c < fim; c++){
        trocar(vetor[c], vetor[fim]);
        inicio++;
        minheapfy(vetor, fim, inicio, fim);
    }
}
