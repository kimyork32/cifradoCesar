#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    //CIFRADO DE VÍGENERE
    // ABECEDARIO INGLES 0-26
    // string texto = "La circunferencia intergalactica de la galaxia espectralmente resplandece";
    string texto;
    string clave = "cielo";
    string claveAmpliada;
    string cifrado = "";
    string descifrado = "";
    int tam;

    // OBTENER TEXTO DE TXT
    ifstream archTexto("texto.txt");
    char c;
    while(archTexto.get(c)) texto += c;    
    archTexto.close();
    tam = texto.size();

    // CONVERTIR A MAYUSCULAS SI ES NECESARIO
    for(char& c : texto){
        c = tolower(c);
    }
    
    // AUMENTAR CLAVE AL MISMO TAMAÑO DE LA PALABRA A CIFRAR
    int k=0;
    for(int p=0; p<tam; p++){
        if(texto[p] == ' '){
            claveAmpliada += ' ';
            k=0;
        }else{
            if(k==clave.size()) k=0;
            claveAmpliada += clave[k];
            k++;
        }
        
    }
    
    // CREAR MATRIZ BIDIMENSIONAL
    int t=26;
    vector<vector<char>> matriz(t, vector<char>(t));

    // LLENAR MATRIZ 
    for (int i = 0; i < t; i++) {
        char valor = 'a' + i;
        for (int j = 0; j < t; ++j) {
            matriz[i][j] = valor;
            if(valor == 'z')
                valor = 'a';
            else
                valor = valor + 1;
        }
    }

    // IMPRIMIR MATRIZ
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    // CIFRADO
    // E(Xi)=(Xi+Xj)mod26

    //ESTA PARTE ES CON NUMEROS, YO QUIERO CON CHAR
    char Ei;
    int Xi;
    int Xj;
    for(int k=0; k<tam; k++){
        if(texto[k] == ' '){
            cifrado += ' ';
        }else{
            for(int i=0; i<t; i++){
                if(matriz[0][i]==texto[k])
                    Xi = i;
            }

            for(int j=0; j<t; j++){
                if(matriz[j][0]==claveAmpliada[k])
                    Xj=j;
            }
            Ei = matriz[Xi][Xj];
            cifrado += Ei;
        }
    }
    
    // GUARDAR TEXTO CIFRADO EN TXT
    ofstream archTextC("textoCifrado.txt");
    archTextC << cifrado;
    archTextC.close();

    // DESCIFRADO
    // para (Xi-Ki) > 0 -> Ek(x)=(Xi-Ki)mod26
    // para (Xi-Ki) < 0 -> Ek(x)=(Xi-Ki+26)mod26
    int Ki;
    for(int k=0; k<tam; k++){
        if(texto[k]==' '){
            descifrado += ' ';
        }else {
            for(int i=0; i<t; i++){
                if(matriz[0][i]==cifrado[k])
                    Xi=i;
            }
            for(int j=0; j<t; j++){
                if(matriz[j][0]==claveAmpliada[k])
                    Ki=j;
                    
            }
        
            Ei=matriz[26-Ki][Xi];
            
            descifrado += Ei;    
        }   
    }

    // GUARDAR TEXTO DESCIFRADO EN TXT
    ofstream archTextD("textoDescifrado.txt");
    archTextD << descifrado;
    archTextD.close();
    
    
    // IMPRIMIR
    cout << "Texto:\t\t" << texto << endl;
    cout << "Clave:\t\t" << clave << endl;
    cout << "Clave ampliada:\t" << claveAmpliada << endl;
    cout << "Cifado:\t\t" << cifrado << endl;
    cout << "Descifado:\t" << descifrado << endl;
    // cout << "hola" << endl;
    return 0;
}

