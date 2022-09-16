#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node* prox;
    int valor;
};

Node* Sentinela = new Node;

void criar_lista(){
    Sentinela->prox = Sentinela;
}

void adicionar_elemento(int valor, Node* p){
    Node* q = new Node;
    Node* aux = p->prox;
    
    q->valor = valor;
    p->prox =  q;
    q->prox = aux;
}

void adicionar_inicio(int valor){
    adicionar_elemento(valor, Sentinela);
}

void mostrar_elementos(){
    if(Sentinela->prox != Sentinela){
        Node* q = Sentinela->prox;
        
        do{
            cout << q->valor << " ";
            q = q->prox;
        }while (q != Sentinela);
    }
}

void inverter_lista(){
    Node* aux_1 = Sentinela;
    Node* q = Sentinela->prox;
    Node* aux_2 = q->prox;
    
    do{
        q->prox = aux_1;
        aux_1 = q;
        q = aux_2;
        aux_2 = q->prox;
    }while(aux_1 != Sentinela);

}

int main() {
    criar_lista();
    
    adicionar_inicio(88);
    adicionar_inicio(4);
    adicionar_inicio(99);
    adicionar_inicio(0);
    adicionar_inicio(1);
    
    mostrar_elementos();
    
    inverter_lista();
    cout << endl;
    
    mostrar_elementos();
    
    return 0;
}
