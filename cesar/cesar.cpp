#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// OBTENER CONTENIDO DE ARCHIVO TXT A STRING
string stringArchivo(string ruta){
    string texto;
    char caracter;
    ifstream arch(ruta);
    if(!arch.is_open()) return "";
    while(arch.get(caracter)){
        if(caracter == '\n') texto += " ";    
        else texto += caracter;
    }
    for(char& c:texto) c=toupper(c);
    arch.close();
    return texto;
}

// GUARDAR TEXTO A UN ARCHIVO TXT
void guardarTextoArchivo(string ruta, string texto){
    ofstream arch(ruta);
    arch << texto;
    arch.close();
}

// CONVERTIR UN STRING A VECTOR
vector<string> convertStringVector(string texto){
    stringstream ss(texto);
    string p;
    vector<string> vectP;
    while(ss >> p){
        vectP.push_back(p);
    }
    return vectP;
}

// CESAR CIFRAR
string cifrar(string texto, int k){
    string textoCifrado;
    char Ek;
    for(int i=0; i<texto.size(); i++){
        if(texto[i] == ' '){
            textoCifrado += ' ';
        }else{
            int x = static_cast<int>(texto[i]-'A');
            Ek = static_cast<char>((x+k)%26+'A');
            textoCifrado += Ek;   
        }
    }
    return textoCifrado;
}

// CESAR DESCIFRAR
string descifrar(string textoCifrado, int k){
    string textoDescifrado = "";
    char Ek;
    for(int i=0; i<textoCifrado.size(); i++){
        if(textoCifrado[i] == ' '){
            textoDescifrado += ' ';
        }else{
            int x = static_cast<int>(textoCifrado[i]-'A');
            if(x-k<0){
                Ek = static_cast<char>((x+26-k)%26+'A');
            }
            else{
                Ek = static_cast<char>((x-k)%26+'A');
            }
            textoDescifrado += Ek;   
        }
    }
    return textoDescifrado;
}

// FUERZA BRUTA PARA OBTENER K, PORCENTAJES Y TEXTO DESCRIFRADO CON FB
void fuerzaBruta(vector<string> diccionario, string textC, string& textoDescrifradoFB, int &Kp, vector<float>& pesos){
    string textoCifrado = textC;
    vector<string> palabrasCifradas;
    int coincidencias = 0;
    string palDic;
    for(int k = 0; k < 26; k++){
        textoCifrado = descifrar(textC, k);
        palabrasCifradas = convertStringVector(textoCifrado);
        for(int i=0; i< palabrasCifradas.size(); i++){
            for(int j = 0; j < diccionario.size(); j++){
                for(char &c : diccionario[j]){
                    palDic += toupper(c);
                }
                if(palabrasCifradas[i] == palDic){
                    coincidencias++;
                }
                palDic="";
            }
        }
        if(coincidencias>0){
            textoDescrifradoFB = textoCifrado;
            Kp = k;
            return;
        }
    }
    textoDescrifradoFB = descifrar(textC, Kp);
    return;
}

// IMPRIMIR UN VECTOR
template<typename T>
void print(vector<T> vect){
    for(T i : vect){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    string pathTexto = "texto.txt";
    string pathTextoCifrado = "textoCifrado.txt";
    string pathTextoDescifrado = "textoDescifrado.txt";
    string pathDiccionario = "diccionario.txt";
    string pathDiccionario2 = "diccionario2.txt";

    string texto = stringArchivo(pathTexto);
    string textoCifrado;
    string textoDescifrado;
    string textoDescifradoFB = "";

    vector<float> pesos;
    
    int Kp, k;
    cout << "k:"; cin >> k;
    cout << endl;

    textoCifrado = cifrar(texto, k);
    guardarTextoArchivo(pathTextoCifrado, textoCifrado);

    textoDescifrado = descifrar(textoCifrado, k);
    guardarTextoArchivo(pathTextoDescifrado, textoDescifrado);

    fuerzaBruta(convertStringVector(stringArchivo(pathDiccionario)), stringArchivo(pathTextoCifrado), textoDescifradoFB, Kp, pesos);

    cout << "Base k:" << k << endl << endl;
    cout << "Texto original\n" << stringArchivo(pathTexto) << endl << endl;
    cout << "Texto cifrado:\n" << stringArchivo(pathTextoCifrado) << endl << endl;
    cout << "Texto descifrado:\n" << stringArchivo(pathTextoDescifrado) << endl << endl;
    cout << "Texto descrifado (FB):\n" << textoDescifradoFB << endl << endl;
    cout << "k encontrado (FB):" <<  Kp << endl << endl;
    cout << "Porcentajes:\n";
    print(pesos);
    
    return 0;
}
