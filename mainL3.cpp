#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <string.h>
#include <string>

char* createCharArray(int);
void freeCharArray(char*);
void printCharArray(char*,int);
void initArrayE1(char*,int);
void printIntArray(int*, int);
void initArrayInt(int*, int);


int menu() {
    int flag = 0;
    while(flag == 0) {
        cout<<endl<<endl<<" --- MENÚ ---"
        <<endl<<"1.- Ejercicio 1: Adivinar el Número"
        <<endl<<"2.- Ejercicio 2: Conversión Binaria"
        <<endl<<"3.- Ejercicio 3: Conjugar Verbos"
        <<endl<<endl<<"4.- Salir."
        <<endl<<endl<<"Por favor, ingrese una opción: ";
        cin>>flag;

        if (flag < 1 || flag > 4) {
            flag = 0;
            cout<<"Opción inválida. Por favor, intente de nuevo."<<endl<<endl;
        }
        
    }
    return flag;
}

int main() {
    int opt = 0;
    do {
        opt = menu();
        if (opt == 1) {
            char* SNum = NULL;
            SNum = createCharArray(4);
            initArrayE1(SNum, 4);
            for (int i = 0; i < 4; i++) {
                int x = rand() % 9 + 1;
                while (x == SNum[0] || x == SNum[1] || x == SNum[2] || x == SNum[3]) {
                    x = rand() % 9 + 1;
                }
                char temp = std::to_string(x)[0];
                SNum[i] = temp;
            }
            int vidas = 5;
            char Resp2[4];
            while (vidas >= 0) {
                cout<<endl<<"¡Adivina el número!"<<endl<<endl<<"Vidas: "<<vidas<<endl<<"Inténtalo: ";
                cin>>Resp2;
                if (strcmp(SNum,Resp2) == 0 ) { 
                    cout<<endl<<"¡Has adivinado correctamente!"<<endl;
                    vidas = 0;
                } else {
                     for (int i = 0; i < 4; i++) {
                         if (Resp2[i] == SNum[i]) {
                                cout<<endl<<Resp2[i]<<" está en la posición correcta.";
                         } else {
                         for (int j = 0; j < 4; j++) {
                            if (SNum[j] == Resp2[i]) {
                                cout<<endl<<Resp2[i]<<" es un número correcto pero en la posición incorrecta.";
                                  }
                             } 
                         }
                      }
                }
            vidas = vidas - 1;
            }
            if (vidas == 0) {
                cout<<endl<<"GAME OVER."<<endl;
            }
            freeCharArray(SNum);
        } else if (opt == 2) {
        int bin[8];
        int Sbin[50];
        int i = 0;
        int cont = 7;
        int num = 0;
        initArrayInt(bin,8);
        initArrayInt(Sbin,50);
        cout<<endl<<"Ingrese un número decimal: ";
        cin>>num;
        cout<<endl<<"Decimal "<<num<<endl<<"Binario ";
        if (num > 0 ) { 
        while (num > 0) {  
             Sbin[i] = num % 2; 
             bin[i] = num % 2;
             num = num / 2; 
             i++; 
        } 
        for (int j = i - 1; j >= 0; j--) { 
        cout << Sbin[j]; 
        }
        cout << endl<<  "Arreglo ";
        for (int j = i - 1; j >= 0; j--) { 
        cout <<"["<< bin[j]<<"]";     
        }
 
  
      } else {
        cout<<endl<<"El número ingresado no es un número positivo."<<endl;
        }
        } else if (opt == 3) {
        std::string word;
        cout<<endl<<"Ingrese un verbo: ";
        cin>>word;
        int len = word.length();
        char Word2[len+1];
        int len2 = len+1;
        word.copy(Word2,len2,0);

        while (Word2[len2-2] != 'r') {
            cout<<"La palabra que ha ingresado no es un verbo."<<endl<<"Por favor, ingrese una palabra nueva: ";
            cin>>word;
            len = word.length();
            Word2[len+1];
            len2 = len+1;
            word.copy(Word2,len2,0);
        }       
        cout<<endl<<"Conjugaciones: "<<endl<<endl;
        if (Word2[len2-3] == 'a') {
            Word2[len2-3] = 'o';
            Word2[len2-2] = ' ';
            cout<<"PRESENTE: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'e';
            cout<<"PASADO: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'a';
            Word2[len2-2] = 'r';
            Word2[len2-1] = 'e';
            cout<<"FUTURO: Yo ";
            printCharArray(Word2, len2);
        } else if (Word2[len2-3] == 'e') {
            Word2[len2-3] = 'o';
            Word2[len2-2] = ' ';
            cout<<"PRESENTE: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'i';
            cout<<"PASADO: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'e';
            Word2[len2-2] = 'r';
            Word2[len2-1] = 'e';
            cout<<"FUTURO: Yo ";
            printCharArray(Word2, len2);
        } else if (Word2[len2-3] == 'i') {
            Word2[len2-3] = 'o';
            Word2[len2-2] = ' ';
            cout<<"PRESENTE: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'i';
            cout<<"PASADO: Yo ";
            printCharArray(Word2, len2);
            Word2[len2-3] = 'i';
            Word2[len2-2] = 'r';
            Word2[len2-1] = 'e';
            cout<<"FUTURO: Yo ";
            printCharArray(Word2, len2);
        } else {
            cout<<"La palabra ingresada no es un verbo."<<endl;
        } 
}
    
} while (opt != 4);
    return 0;
}




char* createCharArray(int size) {
    return new char[size];
}

void initArrayE1(char* array, int size) {
    if (array != NULL) {
        for(int i = 0;  i < size; i++) {
            array[i] = '0';
        }
    }
}

void initArrayInt(int* array, int size) {
    if (array != NULL) {
            for(int i = 0;  i < size; i++) {
                array[i] = 0;
         }
     }
}


void freeCharArray(char* array) {
    if (array != NULL) {
        delete[] array;
    }
}

void printCharArray(char* arreglo, int size) {
    if (arreglo != NULL) {
        for(int i = 0; i<size; i++) {
            cout<<arreglo[i];
        }
    cout<<endl;
    }
}

