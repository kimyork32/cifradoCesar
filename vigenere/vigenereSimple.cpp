#include <iostream>
#include <vector>
using namespace std;

int main() {
    //CIFRADO DE VÍGENERE
    // ABECEDARIO INGLES 0-26
    // ENTRADA SOLO MAYUSCULAS
    string texto = "MURCIELAGO VOLADOR EN ES MUCHISIMO";
    string clave = "LUZ";
    string claveAmpliada;
    string cifrado = "";
    string descifrado = "";
    int tam = texto.size();

    // CONVERTIR A MAYUSCULAS SI ES NECESARIO
    for(char& c : texto){
        c = toupper(c);
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
    
    // CIFRADO
    // E(Xi)=(Xi+Xj)mod26
    char Ei;
    for(int i=0; i<tam; i++){
        if(texto[i]==' '){
            cifrado += ' ';
        }else{
            int Xi = static_cast<int>(texto[i]-'A');
            int Xj = static_cast<int>(claveAmpliada[i]-'A');
            Ei = static_cast<char>((Xi+Xj)%26+'A');
            cifrado += Ei;
        }
    }
    
    // DESCIFRADO
    // para (Xi-Ki) > 0 -> Ek(x)=(Xi-Ki)mod26
    // para (Xi-Ki) < 0 -> Ek(x)=(Xi-Ki+26)mod26
    for(int i=0; i<tam; i++){
        if(texto[i]==' '){
            descifrado += ' ';
        }else {
            int Xi = static_cast<int>(cifrado[i]-'A');
            int Ki = static_cast<int>(claveAmpliada[i]-'A');
            if(Xi-Ki>0){
                Ei = static_cast<char>((Xi-Ki)%26+'A');
            }
            else{
                Ei = static_cast<char>((Xi-Ki+26)%26+'A');
            }
            descifrado += Ei;    
        }
    }
    
    cout << "Texto:\t\t" << texto << endl;
    cout << "Clave:\t\t" << clave << endl;
    cout << "Clave ampliada:\t" << claveAmpliada << endl;
    cout << "Cifado:\t\t" << cifrado << endl;
    cout << "Descifado:\t" << descifrado << endl;
       
    return 0;
}

