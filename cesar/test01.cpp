#include <iostream>
using namespace std;
int main() {
    // Declarar un carácter
    // char16_t letra = u'\u00E1';  // Valor Unicode de 'á'

    // Imprimir el valor Unicode de la letra
    // std::cout << "El valor Unicode de '" << letra << "' es: " << static_cast<int>(letra) << std::endl;

    // Incrementar el valor Unicode
    // letra++;

    // Imprimir el nuevo valor Unicode
    // std::cout << "El valor Unicode después de incrementar es: " << static_cast<int>(letra) << std::endl;

    // int n = 256;
    for(int i=0; i<128; i++){
        cout << i << ": " << static_cast<char>(i) << endl;
    }
    
    return 0;
}
