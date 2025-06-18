#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
int showBoard(int board[10][10]){
  char dict[10][2] = {"A","B","C","D","E","F","G","H","I","J"};
  for (int z = 0;z < 10;z++){printf("[%d]",z + 1);};
  printf("\n");
  for (int x = 0;x < 10;x++){
        for (int y = 0;y < 10;y++){
            if(board[x][y] == 0){
                printf("|%d|",board[x][y]);
            }else{
                printf("(%d)",board[x][y]);
            };
            
            
        };
        printf("[%s]\n",dict[x]);
  };
  return 0;
};

int isTouchingShape(int x, int y, int shap[6], int mod){
    //int x => coordenada x que a iteração está verificando
    //int y => coordenada y que a iteração está verificando
    //int[6] shapes => coordenadas das formas
    //retorna 1 para sim, 0 para não
    //1 -> uma parte de uma forma preenche esse thread_local
    //0 -> não há nenhuma forma preenchendo esse local
    int xa, ya, result, a, b, c = 0;
    
    for(int skill = 0;skill < 6;skill = skill + 2){
        //ponto de origem
        //skill = 0 / cone
        //        2 / octaedro
        //        4 / cruz
        if (mod){
            xa = shap[skill + 1]; //ponto de origem da cruz(y)
            ya = shap[skill]; // ponto de origem da cruz(x)
        }else{
            ya = shap[skill + 1]; //ponto de origem da cruz(y)
            xa = shap[skill]; // ponto de origem da cruz(x)
        };
        
        
        switch (skill){
            case 0:
                // cone
                /*
                OO1OO
                O1X1O ponto de origem
                11111
                
                basicamente cada linha vai calcular a posição de cada parte
                da habilidade
                */
                //ya está em X.y-1 e ele não ultrapassa o mapa
                //xa é igual a X.x
                
                result = (y == ya - 1) && (ya - 1 > -1) && (x == xa) ;
                
                //X.y = ya | X.x = xa 
                result += (y == ya) && (x == xa);
                
                //ya está em X.y+1 e ele não ultrapassa o mapa
                //xa é igual a X.x
                result += (y == ya + 1) && (ya + 1 < 10) && (x == xa);
                
                result += (x == xa - 1) && (xa - 1 > -1) && (y == ya);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya + 1) && (ya + 1 < 10);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya - 1) && (ya + 1 < 10);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya + 2) && (ya + 2 < 10);
                
                result += (x == xa + 1) && (xa + 1 > -1) && (y == ya - 2) && (ya - 2 > -1);
                
                
                
                
                a = result;
                
                
            break;
                
            case 2:
                // octaedro
                /*
                OO1OO
                O1X1O
                OO1OO                
                */

                result = (y == ya - 1) && (ya - 1 > -1) && (x == xa) ;
                
                result += (y == ya) && (x == xa);
                
                result += (y == ya + 1) && (ya + 1 < 10) && (x == xa);
                
                result += (x == xa - 1) && (xa - 1 > -1) && (y == ya);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya);
                
                b = result;
                
            break;
            
            case 4:
                // cruz
                /*
                OO1OO
                11X11
                OO1OO
                */
                //ya está em X.y-1 e ele não ultrapassa o mapa
                //xa é igual a X.x
                
                result = (y == ya - 1) && (ya - 1 > -1) && (x == xa) ;
                
                //X.y = ya | X.x = xa 
                result += (y == ya) && (x == xa);
                
                //ya está em X.y+1 e ele não ultrapassa o mapa, xa é igual a X.x
                result += (y == ya + 1) && (ya + 1 < 10) && (x == xa);
                
                result += (x == xa - 1) && (xa - 1 > -1) && (y == ya);
                
                result += (x == xa + 1) && (xa + 1 < 10) && (y == ya);
                
                result += (y == ya - 2) && (ya - 2 > -1) && (x == xa);
                
                result += (y == ya + 2) && (ya + 2 < 10) && (x == xa);
                
                c = result;
                
                
            break;
        };
            
        
    }

    return (a+b+c)>0?1:0;
};

int showBoardWithSkill(int board[10][10], int shapes[6], int alt){
    char dict[10][2] = {"A","B","C","D","E","F","G","H","I","J"};
  for (int z = 0;z < 10;z++){printf("[%d]",z + 1);};
  printf("\n");
    for (int x = 0;x < 10;x++){
        for (int y = 0;y < 10;y++){
            //usar um calculo para determinar qual seria a posição da habilidade
            if (isTouchingShape(x,y,shapes,alt)){
                printf(" 1 ");
            }else{
              //renderizar partes de návios
              if(board[x][y] == 0){
                printf("|%d|",board[x][y]);
                }else{
                    printf("(%d)",board[x][y]);
                };
            };
            
            
        };
        printf("[%s]\n",dict[x]);
    };
    
    return 0;
    
};

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    //(!)0 - água
    //(!)3 - návio
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    
    //(!) inicializar o tabuleiro 
    int tabuleiro[10][10];
    for (int y = 0;y < 10;y++){
        for (int x = 0;x < 10;x++){
            tabuleiro[x][y] = 0;
        };
    };
    //(!) návio horizontal
    tabuleiro[0][0] = 3;
    tabuleiro[0][1] = 3;
    tabuleiro[0][2] = 3;
    //(!)     Y  X
    tabuleiro[5][1] = 3;
    tabuleiro[6][1] = 3;
    tabuleiro[7][1] = 3;
    
    //(!) exibindo tabuleiro
    
    showBoard(tabuleiro);
    printf("\nNível novato e Aventureiro\n");
    
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    

    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
    //pontos de origem
    //             (cone)  (octaedro)  (cruz)
    //              x, y      x,y      x,y
    int formas[6] = {3,2  ,   8,5,     3,7};
    
    showBoardWithSkill(tabuleiro,formas,1);
    printf("\nHabilidades + Návios Normal\n");
    printf("\nNível Mestre\n\n\n");
    
    /*
    showBoardWithSkill(tabuleiro,formas,0);
    printf("\nHabilidades + Návios Alternativo\n");
    printf("\nNível Mestre\n");
    */

    return 0;
}
