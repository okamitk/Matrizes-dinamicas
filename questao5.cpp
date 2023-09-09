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

void **imprimir_matriz(int **matriz, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            std::cout<<matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }std::cout<<std::endl;
}

void **trocar_linhas(int**matriz, int linhas, int colunas, int index1, int index2){
    int auxiliar;
    for(int i=0; i<linhas; i++){
        auxiliar = matriz[i][index1];
        matriz[i][index1]=matriz[i][index2];
        matriz[i][index2]=auxiliar;
    }
}

int main(){
    int linhas;
    int colunas;
    int index1;
    int index2;
    
    std::cout<<"Quantas linhas você quer que o array tenha? ";
    std::cin>>linhas;

    std::cout<<"Quantas colunas você quer que o array tenha? ";
    std::cin>>colunas;

    int**matriz = alocar_memo(linhas,colunas);
    ler_matriz(matriz, linhas, colunas);

    std::cout<<"Em qual coluna está o primeiro elemento?";
    std::cin>>index1;

    std::cout<<"Em qual coluna está o segundo elemento?";
    std::cin>>index2;
    
    imprimir_matriz(matriz, linhas, colunas);
    trocar_linhas(matriz, linhas, colunas, index1, index2);
    imprimir_matriz(matriz, linhas, colunas);

    std::cout << std::endl;
    return 0;
}