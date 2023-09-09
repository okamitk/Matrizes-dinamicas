#include <iostream>
using string = std::string;

double **alocar_memo(int linhas, int colunas){
    double **matriz = new double*[linhas];
    for (int i = 0; i < linhas; i++){
        matriz[i]=new double[colunas];
    }

    return matriz;
}

void **ler_matriz(double **matriz, int linhas, int colunas){
    for (int i=0; i<linhas; i++){
        for (int j=0; j<colunas; j++){
            std::cout<<"Digite a "<<j+1<<"º nota do "<<i+1<<"º aluno: ";
            std::cin>>matriz[i][j];
        }std::cout<<std::endl;
    }
}

void **imprimir_media(double **matriz, int linhas, int colunas){
    double media;
    for (int i=0; i<linhas; i++){
        media = ((matriz[i][0]+matriz[i][1])/2);
        if(media>=7){
            std::cout<<"Média "<<media<<", aprovado.";
        }else if(media>=4){
            std::cout<<"Média "<<media<<", prova final.";
        }else{
            std::cout<<"Média "<<media<<", reprovado.";
        }
        std::cout<<std::endl;
    }std::cout<<std::endl;
}

int main(){
    int linhas;
    const int colunas = 2;
    int index1;
    int index2;
    
    std::cout<<"Quantos alunos? ";
    std::cin>>linhas;

    double**matriz = alocar_memo(linhas,colunas);
    ler_matriz(matriz, linhas, colunas);
    imprimir_media(matriz, linhas, colunas);

    std::cout << std::endl;
    return 0;
}