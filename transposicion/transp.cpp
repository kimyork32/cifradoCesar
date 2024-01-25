#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// FUNCION CIFRAR
void cifrar(string texto, string& cifrado){
    int tam = texto.size();
    string temp;
    string tempT;
    vector<int> posEsp;

    for(int i=0; i<tam; i++){
        if(texto[i]==' ')
            posEsp.push_back(i);
        else
            tempT.push_back(texto[i]);
    }

    for(int i=0; i<tempT.size(); i++){
        if(i%2!=0)
            temp.push_back(tempT[i]);
    }
    // temp.push_back(' ');
    for(int i=0; i<tempT.size(); i++){
        if(i%2==0)
            temp.push_back(tempT[i]);
    }
    
    int count=0;
    for(int i=0; i<temp.size(); i++){
        if(i==posEsp[count]){
            temp.insert(temp.begin() + posEsp[count], ' ');
            count++;
        }
    }
    cifrado=temp;
}

//FUNCION DESCIFRAR
void descifrar(string cifrado, string& descifrado){
    int tam = cifrado.size();
    string temp;
    string tempT;
    vector<int> posEsp;

    for(int i=0; i<tam; i++){
        if(cifrado[i]==' ')
            posEsp.push_back(i);
        else
            tempT.push_back(cifrado[i]);
    }

    int tamP = 5;
    for(int i=0; i<tamP; i++){
        temp.push_back(tempT[tamP+i]);
        temp.push_back(tempT[i]);
    }
    
    int count=0;
    for(int i=0; i<temp.size(); i++){
        if(i==posEsp[count]){
            temp.insert(temp.begin() + posEsp[count], ' ');
            count++;
        }
    }
    descifrado=temp;
}

void cifrarP(string texto, string& cifrado){
    int tam = texto.size();
    string temp;
    string tempT;
    vector<int> posEsp;

    for(int i=0; i<tam; i++){
        if(texto[i]==' ')
            posEsp.push_back(i);
        else
            tempT.push_back(texto[i]);
    }

    for(int i=0; i<tempT.size(); i++){
        if(i%2==0)
            temp.push_back(tempT[i]);
    }
    // temp.push_back(' ');
    for(int i=0; i<tempT.size(); i++){
        if(i%2!=0)
            temp.push_back(tempT[i]);
    }
    
    int count=0;
    for(int i=0; i<temp.size(); i++){
        if(i==posEsp[count]){
            temp.insert(temp.begin() + posEsp[count], ' ');
            count++;
        }
    }
    cifrado=temp;
}

//FUNCION DESCIFRAR
void descifrarP(string cifrado, string& descifrado){
    int tam = cifrado.size();
    string temp;
    string tempT;
    vector<int> posEsp;

    for(int i=0; i<tam; i++){
        if(cifrado[i]==' ')
            posEsp.push_back(i);
        else
            tempT.push_back(cifrado[i]);
    }

    int tamP = 5;
    for(int i=0; i<tamP; i++){
        temp.push_back(tempT[i]);
        temp.push_back(tempT[tamP+i]);
    }
    
    int count=0;
    for(int i=0; i<temp.size(); i++){
        if(i==posEsp[count]){
            temp.insert(temp.begin() + posEsp[count], ' ');
            count++;
        }
    }
    descifrado=temp;
}


int main() {
    string texto;
    string cifradoI = "";
    string descifradoI = "";
    string cifradoP = "";
    string descifradoP = "";
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

    // PAR
    //CIFRAR
    cifrarP(texto, cifradoP);
    // GUARDAR TEXTO CIFRADO EN TXT
    ofstream archTextCP("cifradoP.txt");
    archTextCP << cifradoP;
    archTextCP.close();

    // DESCIFRAR
    descifrarP(cifradoP, descifradoP);

    // // GUARDAR TEXTO DESCIFRADO EN TXT
    ofstream archTextDP("descifradoP.txt");
    archTextDP << descifradoP;
    archTextDP.close(); 

    // IMPAR
    // CIFRADO
    cifrar(texto, cifradoI);

    // GUARDAR TEXTO CIFRADO EN TXT
    ofstream archTextC("cifradoI.txt");
    archTextC << cifradoI;
    archTextC.close();

    // DESCIFRADO
    descifrar(cifradoI, descifradoI);

    // GUARDAR TEXTO CIFRADO EN TXT
    ofstream archTextDI("descifradoI.txt");
    archTextDI << descifradoP;
    archTextDI.close();

    // IMPRIMIR
    std::cout << "Texto:\t\t" << texto << endl << endl;
    std::cout << "PAR:" << endl;
    std::cout << "Cifado:\t\t" << cifradoI << endl;
    std::cout << "Descifado:\t" << descifradoI << endl;
    std::cout << "IMPAR:" << endl;
    std::cout << "Cifado:\t\t" << cifradoP << endl;
    std::cout << "Descifado:\t" << descifradoP << endl;
    return 0;
}

