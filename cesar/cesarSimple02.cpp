#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {

    // CIFRADO DE CESAR
    // PUEDE ABRIR ARCHIVOS TXT
    // ABECEDARIO INGLES 0-26
    // ENTRADA SOLO MAYUSCULAS
    // string texto = "HOlA MUNDO";
    string texto = "";
    string textoCifrado = "";
    string textoDescifrado = "";
    int k=2;

    // OBTENIENDO TEXTO DE TXT 
    ifstream archTexto("texto.txt");
    char c;
    while(archTexto.get(c)) texto += c;
    archTexto.close();

    // CONVERTIR A MAYUSCULAS SI ES NECESARIO
    for(char& c:texto) c=toupper(c);
    
    //CIFRADO
    // Ek(x)=(x+k)mod26
    for(int i=0; i<texto.size(); i++){
        if(texto[i] == ' '){
            textoCifrado += ' ';
        }else{
            int x = static_cast<int>(texto[i]-'A');
            char Ek = static_cast<char>((x+k)%26+'A');
            textoCifrado += Ek;   
        }
    }
    
    //GUARDAR TEXTO CIFRADO A TXT
    ofstream archCifrado("textoCifrado.txt");
    archCifrado << textoCifrado;
    archCifrado.close();

    // DESCIFRADO
    // Ek(x)=(x-k)mod26
    for(int i=0; i<texto.size(); i++){
        if(texto[i] == ' '){
            textoDescifrado += ' ';
        }else{
            int x = static_cast<int>(texto[i]-'A');
            char Ek = static_cast<char>((x-k)%26+'A');
            textoDescifrado += Ek;   
        }
    }

    // OUTPUT
    cout << "Palabra:\t" << texto << endl;
    cout << "cifrado:\t" << textoCifrado << endl;

    
    return 0;
}

