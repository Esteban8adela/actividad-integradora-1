// E1. Actividad Integradora 1
// Esteban Ochoa - A01643234
// Edgardo Medina - 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Lee el contenido completo de un archivo y lo devuelve como un string.
// Devuelve un string con el contenido del archivo. Devuelve un string vacio si el archivo no se puede abrir.
string leerArchivo(string archivo) {
    ifstream texto;
    string contenido;

    texto.open(archivo);
    if (texto.is_open()) {
        stringstream buffer;
        buffer << texto.rdbuf();
        contenido = buffer.str();
    }
    return contenido;
}

// Analiza si una cadena de codigo malicioso se encuentra en una cadena de transmision.
// Imprime 'true' y la posicion (1-indexed) si se encuentra, o 'false' si no.
void analizarCodigo(string transmission, string mcode) {
    size_t posicion = transmission.find(mcode);

    if (posicion != string::npos) {
        cout << "true" << " " << (posicion + 1) << endl;
    } else {
        cout << "false" << endl;
    }
}


// Verifica si una cadena de texto es un palindromo.
// Devuelve true si la cadena es un palindromo, false en caso contrario.
bool esPalindromo(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        } else {
            i++;
            j--;
        }
    }
    return true;
}

// Encuentra el palindromo mas largo dentro de una cadena de texto.
// Imprime la posicion inicial y final (1-indexed) del palindromo encontrado.
void encuentraPalindromo(string texto) {
    int inicio = 0;
    int maxLen = 0;
    string sub;

    // Si el texto esta vacio, no hay nada que hacer. El palindromo mas largo es de longitud 0.
    if (texto.empty()) {
        cout << "1 0" << endl; // Posicion inicial 1, posicion final 0 (no encontrado)
        return;
    }
    
    maxLen = 1; // Por defecto, el palindromo mas largo es el primer caracter.

    for (int i = 0; i < texto.length(); i++) {
        for (int j = i; j < texto.length(); j++) {
            sub = texto.substr(i, j - i + 1);
            if (esPalindromo(sub)) {
                if (sub.length() > maxLen) {
                    maxLen = sub.length();
                    inicio = i;
                }
            }
        }
    }
    cout << inicio + 1 << " " << maxLen + inicio << endl;
}

// Encuentra el substring comun mas largo entre dos cadenas.
// Imprime la posicion inicial y final (1-indexed) del substring en la primera cadena.
void encontrarSubstringComun(string s1, string s2) {
    int maxLen = 0;
    int endPos = -1; // Iniciar en -1 para manejar el caso donde no hay nada en comun

    vector<vector<int>> tabla(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                tabla[i][j] = tabla[i - 1][j - 1] + 1;
                if (tabla[i][j] > maxLen) {
                    maxLen = tabla[i][j];
                    endPos = i - 1;
                }
            }
        }
    }

    if (maxLen == 0) {
        cout << "1 0" << endl; // No se encontro substring comun
    } else {
        int startPos = endPos - maxLen + 1;
        cout << startPos + 1 << " " << endPos + 1 << endl;
    }
}

int main() {
    // Lectura de todos los archivos
    string t1_str = leerArchivo("transmission1.txt");
    string t2_str = leerArchivo("transmission2.txt");
    string m1_str = leerArchivo("mcode1.txt");
    string m2_str = leerArchivo("mcode2.txt");
    string m3_str = leerArchivo("mcode3.txt");

    // PARTE 1: Busqueda de codigo malicioso
    analizarCodigo(t1_str, m1_str);
    analizarCodigo(t1_str, m2_str);
    analizarCodigo(t1_str, m3_str);
    analizarCodigo(t2_str, m1_str);
    analizarCodigo(t2_str, m2_str);
    analizarCodigo(t2_str, m3_str);

    // PARTE 2: Busqueda del palindromo mas largo
    encuentraPalindromo(t1_str);
    encuentraPalindromo(t2_str);

    // PARTE 3: Busqueda del substring comun mas largo
    encontrarSubstringComun(t1_str, t2_str);

    return 0;
}