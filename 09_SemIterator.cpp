#include <iostream>
#include <vector>

using namespace std;

void Joseph(int Numero, int passo);

int main()
{
    Joseph(7, 3);

    return 0;
}

void Joseph(int Numero, int passo){
    vector<int> vetor;
    
    for(int c = 0; c < Numero; c++){
        vetor.push_back(c);
    }
    
    int quantidade = vetor.size() - passo + 1;
    //auto atual = vetor.begin();
    int count = 0;
    
    for(int c = 0; c < vetor.size(); c++){
        cout << vetor[c] << " ";
    }
    cout << endl;
    
    for(int c = 0; c < quantidade; c++){//vetor.size() > passo - 1
        int aux = 0;
        
        while(aux != passo-1){
            do{
                //atual++;
                count++;
                
                if(count > vetor.size()-1){//atual > vetor.end()-1
                    count = 0;
                }
            }while(vetor[count] == -1);
            
            aux++;
        }
        
        int vitima = count;
        
        do{
            vitima++;
            
            if(vitima > vetor.size()-1){//vitima > vetor.end()-1
                vitima = 0;
            }
        }while(vetor[vitima] == -1);
        
        cout<< "atual:" << vetor[count] << " " << "vitima:" << vetor[vitima] << endl;
        
        vetor[vitima] = -1;
    }
    
    for(int c = 0; c < vetor.size(); c++){
        if(vetor[c] != -1){
            cout << vetor[c] << " ";
        }
    }
}
