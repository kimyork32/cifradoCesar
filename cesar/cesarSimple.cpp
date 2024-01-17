#include <iostream>
#include <vector>
// #include <cctype>
using namespace std;

int main() {
    // CIFRADO DE CESAR
    // SOLO CIFRA Y DESCIFRA UN STRING
    // ABECEDARIO INGLES 0-26
    // ENTRADA SOLO MAYUSCULAS
    string texto = "HOlA MUNDO";
    string cifrado = "";
    int k=2;
    
    // CONVERTIR A MAYUSCULAS SI ES NECESARIO
    for(char& c : texto){
        c = toupper(c);
    }
    
    // Ek(x)=(x+k)mod26
    for(int i=0; i<texto.size(); i++){
        if(texto[i] == ' '){
            cifrado += ' ';
        }else{
            int x = static_cast<int>(texto[i]-'A');
            char Ek = static_cast<char>((x+k)%26+'A');
            cifrado += Ek;   
        }
    }
    
    cout << "Palabra:\t" << texto << endl;
    cout << "cifrado:\t" << cifrado << endl;
    
    return 0;
}

