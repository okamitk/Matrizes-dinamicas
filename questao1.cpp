#include <iostream>

using string = std::string;
int **alocar_memo(int linhas, int colunas){
    int **matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++){
        matriz[i]=new int[colunas];
    }

    return matriz;
}

void **ler_matriz(int **matriz, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            std::cout<<"Digite um valor para a linha "<<i+1<<" coluna "<<j+1<<": ";
            std::cin>>matriz[i][j];
        }
    }
}

void transposta(int **nova_matriz, int **matriz, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; i++){
            nova_matriz[j][i]=matriz[i][j];
        }
    }
}

void **imprimir_matriz(int **matriz, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            std::cout<<matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int linhas;
    int colunas;
    
    std::cout<<"Quantas linhas você quer que o array tenha? ";
    std::cin>>linhas;

    std::cout<<"Quantas colunas você quer que o array tenha? ";
    std::cin>>colunas;

    int**matriz = alocar_memo(linhas,colunas);
    ler_matriz(matriz, linhas, colunas);
    imprimir_matriz(matriz, linhas, colunas);
    
    int**nova_matriz = alocar_memo(linhas,colunas);
    transposta(nova_matriz, matriz, linhas, colunas);
    imprimir_matriz(nova_matriz, linhas, colunas);

    std::cout << std::endl;
    return 0;
}