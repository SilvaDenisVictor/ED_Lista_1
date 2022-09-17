
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void Reversa_Parentisada(string& reversa){
    string Parentisada;
    stack<string> fatores;
    
    for(int c = 0; c < reversa.size(); c++){
        if(reversa[c] == '+' || reversa[c] == '-' || reversa[c] == '*' || reversa[c] == '/'){
            
            string primeiro(fatores.top());
            fatores.pop();
            string segundo(fatores.top());
            fatores.pop();
            string fator('(' + segundo + reversa[c] + primeiro + ')');

            fatores.push(fator);
        }else{
            string d;
            d = reversa[c];
            fatores.push(d);
        }
    }
    
    cout << fatores.top() << endl;
}

void Polonesa_Parentisada(string& reversa){
    string Parentisada;
    stack<string> fatores;
    
    for(int c = reversa.size()-1; c >= 0; c--){
        if(reversa[c] == '+' || reversa[c] == '-' || reversa[c] == '*' || reversa[c] == '/'){
            
            string primeiro(fatores.top());
            fatores.pop();
            string segundo(fatores.top());
            fatores.pop();
            string fator('(' + primeiro + reversa[c] + segundo + ')');

            fatores.push(fator);
        }else{
            string d;
            d = reversa[c];
            fatores.push(d);
        }
    }
    
    cout << fatores.top() << endl;
}

int main()
{
    string Reversa("*-+/ABCDF");
    
    Polonesa_Parentisada(Reversa);
    
    return 0;
}
