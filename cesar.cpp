#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
string cifrar(string texto, int k);
string descifrar(string textoCifrado, int k);
string stringArchivo(string ruta);
void guardarTextoArchivo(string ruta, string texto);
string obtenerTextoArchivo(string ruta);
void fuerzaBruta(vector<string> diccionario, string textC, string& textoDescrifradoFB, int &p);
vector<string> convertStringVector(string texto);

string cifrar(string texto, int k){
    string textoCifrado;
    vector<char> vec(texto.begin(), texto.end());
    for(char l : vec){
        if(l == 32) // evitar cifrar el espacio
            textoCifrado += ' ';
        else{
            textoCifrado += static_cast<char>((l - 'A' + k) % 26 + 'A');
        }
    }
    return textoCifrado;
}

string descifrar(string textoCifrado, int k){

    string textoDescifrado;
    vector<char> vec(textoCifrado.begin(), textoCifrado.end());

    for(char l : vec){
        if(l == 32) // evitar cifrar el espacio
            textoDescifrado += ' ';
        else{
            textoDescifrado += static_cast<char>((l - 'A' - k) % 26 + 'A');
        }
    }
    return textoDescifrado;
}

string stringArchivo(string ruta){
    string texto;
    ifstream arch(ruta);
    char caracter;
    while(arch.get(caracter)){
        if(caracter == '\n'){
            texto += " ";    
        }else{
            texto += caracter;
        }
    }
    return texto;
}

void guardarTextoArchivo(string ruta, string texto){
    ofstream arch(ruta);
    arch << texto;
    arch.close();
}

string obtenerTextoArchivo(string ruta){
    ifstream arch(ruta);
    if (!arch.is_open()) return "";
    string texto;
    char c;
    while(arch.get(c)){
        texto += c;
    }
    arch.close();
    return texto;
}

vector<string> convertStringVector(string texto){
    stringstream ss(texto);
    string p;
    vector<string> vectP;
    while(ss >> p){
        vectP.push_back(p);
    }
    return vectP;
}

void fuerzaBruta(vector<string> diccionario, string textC, string& textoDescrifradoFB, int &Kp){
    string textoCifrado = textC;
    vector<string> palabrasCifradas;
    int coincidencias = 0;
    for(int k = 0; k < 26; k++){
        textoCifrado = descifrar(textC, k);
        palabrasCifradas = convertStringVector(textoCifrado);
        for(int i=0; i< palabrasCifradas.size(); i++){
            for(int j = 0; j < diccionario.size(); j++){

                string palDic;
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
    return;
}

int main(){
    string pathTexto = "texto.txt";
    string pathTextoCifrado = "textoCifrado.txt";
    string pathTextoDescifrado = "textoDescifrado.txt";
    string pathDiccionario = "diccionario.txt";
    string pathDiccionario2 = "diccionario2.txt";

    string texto = obtenerTextoArchivo(pathTexto);
    string textoCifrado;
    string textoDescifrado;
    string textoDescifradoFB = "";
    
    int Kp, k = 2;

    textoCifrado = cifrar(texto, k);
    guardarTextoArchivo(pathTextoCifrado, textoCifrado);

    textoDescifrado = descifrar(textoCifrado, k);
    guardarTextoArchivo(pathTextoDescifrado, textoDescifrado);

    cout << "Base k: " << k << endl;
    cout << "Texto original: " << stringArchivo(pathTexto) << endl;
    cout << "Texto cifrado: " << stringArchivo(pathTextoCifrado) << endl;
    cout << "Texto descifrado: " << stringArchivo(pathTextoDescifrado) << endl;

    fuerzaBruta(convertStringVector(stringArchivo(pathDiccionario)), stringArchivo(pathTextoCifrado), textoDescifradoFB, Kp);

    cout << "Texto descrifado por fuerza bruta: " << textoDescifradoFB << endl;
    cout << "Valor k encontrado por fuerza bruta: " <<  Kp << endl;
    return 0;
}

