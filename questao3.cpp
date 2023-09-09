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

int* maior_elemento(int**matriz, int linhas, int colunas, int* indice){
    int maior = matriz[0][0];
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            if(maior<matriz[i][j]){
                maior=matriz[i][j];
                indice[0]=i;
                indice[1]=j;
            }
        }
    }
}

int* menor_elemento(int**matriz, int linhas, int colunas, int* indice){
    int menor = matriz[0][0];
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            if(menor>matriz[i][j]){
                menor=matriz[i][j];
                indice[0]=i;
                indice[1]=j;
            }
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

    int**matriz = alocar_memo(linhas,colunas);
    ler_matriz(matriz, linhas, colunas);

    int indice_maior[]={0,0};
    int indice_menor[]={0,0};

    maior_elemento(matriz,linhas,colunas,indice_maior);
    menor_elemento(matriz,linhas,colunas,indice_menor);

    std::cout<<"Posição do maior: "<< indice_maior[0]+1<<","<<indice_maior[1]+1<<std::endl;
    std::cout<<"Valor do maior: "<< matriz[indice_maior[0]][indice_maior[1]]<<std::endl;

    std::cout<<"Posição do menor: "<< indice_menor[0]+1<<","<<indice_menor[1]+1<<std::endl;
    std::cout<<"Valor do menor: "<< matriz[indice_menor[0]][indice_menor[1]]<<std::endl;

    std::cout << std::endl;
    return 0;
}