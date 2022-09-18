/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Dupla_Pilha {
    private:
        vector<double> vetor;
        int topo_1;
        int topo_2;
        int Tamanho;
    
    public:
        Dupla_Pilha(int Tamanho);
        
        void push_1(double valor);
        void pop_1();
        void mostrar_1();
        
        void push_2(double valor);
        void pop_2();
        void mostrar_2();
};

int main()
{
    Dupla_Pilha pilha(10);
  
    return 0;
}

Dupla_Pilha::Dupla_Pilha(int n){
    n++;
    for(int c = 0; c < n; c++){
        vetor.push_back(0);
    }
    
    Tamanho = n;
    topo_1 = 0;
    topo_2 = Tamanho - 1;
    
}

void Dupla_Pilha::push_1(double valor){
    if (topo_1 != topo_2){
        vetor[topo_1] = valor;
        topo_1++;
    }
}

void Dupla_Pilha::push_2(double valor){
    if (topo_1 != topo_2){
        vetor[topo_2] = valor;
        topo_2--;
    }
}

void Dupla_Pilha::pop_1(){
    if(topo_1 != 0){
        topo_1--;
    }
}

void Dupla_Pilha::pop_2(){
    if(topo_2 != Tamanho-1){
        topo_2++;
    }
}

void Dupla_Pilha::mostrar_1(){
    for(int c = 0; c < topo_1; c++){
        cout << vetor[c] << " ";
    }
}

void Dupla_Pilha::mostrar_2(){
    for(int c = Tamanho-1; c > topo_2; c--){
        cout << vetor[c] << " ";
    }
}
