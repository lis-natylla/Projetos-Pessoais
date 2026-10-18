#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

void gerarMatriz(vector<vector<char>> &matriz, int x, int y) {
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            matriz[i][j] = rand()%26 + 97;
        }
    }
}

void mostrarMatriz(vector<vector<char>> &matriz, int x, int y) {
    for (int i=0; i< x; i++){
        for (int j=0; j<y; j++){
            cout<< left<< setw(3)<< matriz[i][j];
        }
        cout<<endl;
    }
}

int main() {
    srand(time(0));
    char opcaoContinuar;

    do {
        int x = 0, y = 0;
        string chaveBusca;
        bool flag = false;

        cout << "Insira as dimensões da matriz (linha por coluna):\n";
        cin >> x >> y;

        while (x <= 0 || y <= 0) {
            cout << "As duas dimensões precisam ser maiores que zero. Insira de novo:\n";
            cin >> x >> y;
        }
        cout<<endl;

        vector<vector<char>> matriz(x, vector<char>(y));

        gerarMatriz(matriz, x, y);

        mostrarMatriz(matriz, x, y);
        cout<<endl;

        cout<< "Informe a palavra que deseja buscar:\n";
        cin >> chaveBusca;
        cout<<endl;

        int tamanhoChave = 0;
        while (chaveBusca[tamanhoChave] != '\0'){
            tamanhoChave++;
        }

        for (int k=0; k< tamanhoChave; k++){
            chaveBusca[k] = tolower(chaveBusca[k]);
        }

        if (tamanhoChave>x && tamanhoChave>y){
            cout<< "Sua palavra não pode ser encontrada por que é maior do que as dimensões da matriz :( \n";
            cout<<endl;
            cout<<"Deseja jogar novamente? (s/n): ";
            cin>> opcaoContinuar;
            cout<<"\n========================================\n\n";
            continue;
        }

        for (int i=0; i <x; i++){
            for (int j=0; j <= y - tamanhoChave; j++){
                bool igual = true;
                for (int k=0; k< tamanhoChave; k++){
                    if (matriz[i][j + k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout << "Palavra encontrada! Na horizontal da esquerda para a direita"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i+1 << ", coluna " << j+tamanhoChave <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i=0; i < x; i++){
            for (int j = tamanhoChave-1; j < y; j++){
                bool igual = true;
                for (int k=0; k < tamanhoChave; k++){
                    if (matriz[i][j - k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                } if (igual){
                    cout << "Palavra encontrada! Na horizontal da direita para a esquerda"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i+1 << ", coluna " << j-tamanhoChave+2 <<endl;
                    flag =true;
                }
            }
        }
        cout<<endl;

        for (int i = 0; i <= x - tamanhoChave; i++) {
            for (int j = 0; j < y; j++) {
                bool igual = true;
                for (int k = 0; k < tamanhoChave; k++) {
                    if (matriz[i + k][j] != chaveBusca[k]) {
                        igual = false;
                        break;
                    }
                }
                if (igual) {
                    cout << "Palavra encontrada! Na vertical de cima para baixo"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i+tamanhoChave << ", coluna " << j+1 <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i = tamanhoChave - 1; i<x; i++){
            for (int j=0; j < y; j++) {
                bool igual = true;
                for (int k=0; k < tamanhoChave; k++){
                    if (matriz[i - k][j] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout << "Palavra encontrada! Na vertical de baixo para cima"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i-tamanhoChave+2 << ", coluna " << j+1 <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i=0; i<= x-tamanhoChave; i++){
            for (int j=0; j<= y - tamanhoChave; j++){
                bool igual = true;
                for (int k = 0; k< tamanhoChave; k++){
                    if (matriz[i + k][j + k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout<< "Palavra encontrada! Na diagonal de cima para baixo e da esquerda para a direita"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna "<< j+1 <<endl;
                    cout<< "Posição final: linha " << i+tamanhoChave << ", coluna " << j+tamanhoChave <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i = tamanhoChave-1; i<x; i++){
            for (int j = tamanhoChave-1; j<y; j++){
                bool igual = true;
                for (int k=0; k< tamanhoChave; k++){
                    if (matriz[i - k][j - k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout<< "Palavra encontrada! Na diagonal de baixo para cima e da direita para a esquerda"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna "<< j+1 <<endl;
                    cout<< "Posição final: linha " << i-tamanhoChave+2 << ", coluna " << j-tamanhoChave+2 <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i=0; i <= x - tamanhoChave; i++){
            for (int j=tamanhoChave-1; j<y; j++){
                bool igual = true;
                for (int k=0; k<tamanhoChave; k++){
                    if (matriz[i+k][j-k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout<< "Palavra encontrada! Na diagonal de cima para baixo e da direita para a esquerda"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i+tamanhoChave << ", coluna " << j-tamanhoChave+2 <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        for (int i=tamanhoChave-1; i<x; i++){
            for (int j=0; j<=y-tamanhoChave; j++){
                bool igual = true;
                for (int k=0; k<tamanhoChave; k++){
                    if (matriz[i-k][j+k] != chaveBusca[k]){
                        igual = false;
                        break;
                    }
                }
                if (igual){
                    cout<< "Palavra encontrada! Na diagonal de baixo para cima e da esquerda para a direita"<<endl;
                    cout<< "Posição inicial: linha " << i+1 << ", coluna " << j+1 <<endl;
                    cout<< "Posição final: linha " << i-tamanhoChave+2 << ", coluna " << j+tamanhoChave <<endl;
                    flag = true;
                }
            }
        }
        cout<<endl;

        if (flag == false){
            cout<< "Infelizmente sua palavra não foi encontrada, mas você pode tentar de novo! :) \n";
        }
        cout<<endl;

        cout<< "Deseja jogar novamente? (s/n): ";
        cin>> opcaoContinuar;
        cout<< "\n========================================\n\n";

    } while (opcaoContinuar== 's' || opcaoContinuar=='S');

    return 0;
}
