
#include <iostream>
#include <vector>

using namespace std;

void Joseph(int Numero, int passo);

int main()
{
    Joseph(3, 2);

    return 0;
}

void Joseph(int Numero, int passo){
    vector<int> vetor;
    
    for(int c = 0; c < Numero; c++){
        vetor.push_back(c);
    }
    
    int quantidade = vetor.size() - passo + 1;
    auto atual = vetor.begin();
    /*
    for(int c = 0; c < vetor.size(); c++){
        cout << vetor[c] << " ";
    }
    cout << endl;
    */
    for(int c = 0; c < quantidade; c++){//vetor.size() > passo - 1
        int aux = 0;
        
        while(aux != passo-1){
            do{
                atual++;
                
                if(atual > vetor.end()-1){
                    atual = vetor.begin();
                }
            }while(*atual == -1);
            
            aux++;
        }
        
        auto vitima = atual;
        
        do{
            vitima++;
            
            if(vitima > vetor.end()-1){
                vitima = vetor.begin();
            }
        }while(*vitima == -1);
        
       // cout<< "atual:" << *atual << " " << "vítima:" << *vitima << endl;
        
        *vitima = -1;
    }
    
    for(int c = 0; c < vetor.size(); c++){
        if(vetor[c] != -1){
            cout << vetor[c] << " ";
        }
    }
}
