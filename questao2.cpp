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

void **somar_matriz(int**matriz1, int**matriz2, int**matriz_somada, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            matriz_somada[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }
}

void **subtrair_matriz(int**matriz1, int**matriz2, int**matriz_subtraida, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            matriz_subtraida[i][j]=matriz1[i][j]-matriz2[i][j];
        }
    }
}

int main(){
    int linhas;
    int colunas;
    
    std::cout<<"Quantas linhas você quer que o array tenha? ";
    std::cin>>linhas;

    std::cout<<"Quantas colunas você quer que o array tenha? ";
    std::cin>>colunas;

    int**matriz1 = alocar_memo(linhas,colunas);
    int**matriz2 = alocar_memo(linhas, colunas);
    int**matriz_somada = alocar_memo(linhas, colunas);
    int**matriz_subtraida = alocar_memo(linhas, colunas);

    ler_matriz(matriz1, linhas, colunas);
    ler_matriz(matriz2, linhas, colunas);

    somar_matriz(matriz1, matriz2, matriz_somada, linhas, colunas);
    subtrair_matriz(matriz1, matriz2, matriz_subtraida, linhas, colunas);
    imprimir_matriz(matriz_somada, linhas, colunas);
    imprimir_matriz(matriz_subtraida, linhas, colunas);
    
    std::cout << std::endl;
    return 0;
}