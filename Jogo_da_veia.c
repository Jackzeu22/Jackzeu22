#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//jogo da velha simples
char matrix[3][3]; //a matriz do jogo

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

void main(void)
{
char done;

printf("Este eh o jogo da velha.\n");
printf("Voce estara jogando contra o computador.\n");

done = ' ';
init_matrix();
do {
        disp_matrix();
        get_player_move();
        done = check();        //verifica se há vencedor
        if(done != ' ') break; //vencedor
        get_computer_move();
        done = check();        //verifica se há vencedor
} while(done == ' ');
if(done == 'X') printf("Voce ganhou!\n");
else printf("Eu ganhei!!!\n");
disp_matrix();                 //mostra as posicoes finais
}

//inicia a matriz
void init_matrix(void)
{
int i, j;

for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) matrix[i][j] = ' ';
}

//obtem a sua jogada
void get_player_move(void)
{
int x, y;

printf("Digite as coordenandas para o X: ");
scanf("%d%d", &x, &y);

x--; y--;

if(matrix[x][y] != ' ') {
        printf("Posicao invalida, tente novamente. \n");
        get_player_move();
}
else matrix[x][y] = 'X';
}

//obtem a jogada do computador
void get_computer_move(void)
{
    int i, j;
    srand(time(NULL));

    while (1) {
        i = rand() % 3; // Gera um número aleatório entre 0 e 2
        j = rand() % 3; // Gera um número aleatório entre 0 e 2

        if (matrix[i][j] == ' ') { // Verifica se a célula está vazia
            matrix[i][j] = 'O'; // Se estiver vazia, faz a jogada do computador
            break; // Sai do loop
        }
        // Se a célula não estiver vazia, o loop continua e gera um novo par de coordenadas
    }
}

//mostra a matriz na tela
void disp_matrix(void)
{
        int t;
        for(t = 0; t < 3; t++){
                printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t != 2) printf("\n---|---|---\n");
        }
        printf("\n");
}

//verifica se ha um vencedor.
char check(void)
{
        int i;

        for(i = 0; i < 3; i++) //verifica as linhas
                if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) return matrix[i][0];

        for(i = 0; i < 3; i++) //verifica as colunas
                if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) return matrix[0][i];

        //testa as diagonais
        if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) return matrix[0][0];
        if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) return matrix[0][2];

        return ' ';
}
