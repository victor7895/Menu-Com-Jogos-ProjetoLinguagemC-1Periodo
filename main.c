#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

//Jogo da velha
char jogo[3][3];
int l, c;

// procedimento para inicializar todas as posições da matriz
void inicializarMatriz() { //void funcao que nao retorna valor
  for (l = 0; l < 3; l++) { // for repete quantas vezes quisermos a funcao
    for (c = 0; c < 3; c++)
      jogo[l][c] = ' ';
  }
}

// procedimento para imprimir o jogo na tela
void imprimir() {
  printf("\n\n\t 0   1   2\n\n");
  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++) {
      if (c == 0)
        printf("\t");
      printf(" %c ", jogo[l][c]);
      if (c < 2)
        printf("|");
      if (c == 2)
        printf("  %d", l);
    }
    printf("\n");
    if (l < 2)
      printf("\t-----------\n");
  }
}

/* 
   funcao para verificar vitoria por linha
   1 - ganhou
   0 - nao ganhou ainda
*/

int ganhouPorLinha(int l, char c) {
  if (jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c)
    return 1;
  else
    return 0;
}

/* 
   funcao para verificar vitoria por linhas
   1 - ganhou
   0 - não ganhou ainda
*/

int ganhouPorLinhas(char c) {
  int ganhou = 0;
  for (l = 0; l < 3; l++) {
    ganhou += ganhouPorLinha(l, c);
  }
  return ganhou;
}

/* 
   função para verificar vitória em uma coluna
   1 - ganhou
   0 - não ganhou ainda
*/

int ganhouPorColuna(int c, char j) {
  if (jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
    return 1;
  else
    return 0;
}

/* 
   função para verificar vitória por colunas
   1 - ganhou
   0 - não ganhou ainda
*/

int ganhouPorColunas(char j) {
  int ganhou = 0;
  for (c = 0; c < 3; c++) {
    ganhou += ganhouPorColuna(c, j);
  }
  return ganhou;
}

/* 
   função para verificar vitória na diagonal principal
   1 - ganhou
   0 - não ganhou ainda
*/

int ganhouPorDiagPrin(char c) {
  if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
    return 1;
  else
    return 0;
}

/* 
   função para verificar vitória na diagonal secundaria
   1 - ganhou
   0 - não ganhou ainda
*/

int ganhouPorDiagSec(char c) {
  if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
    return 1;
  else
    return 0;
}

/* 
   função que diz se uma coordenada é válida ou não
   1 - ganhou
   0 - não ganhou ainda
*/

int ehValida(int l, int c) {
  if (l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ')
    return 1;
  else
    return 0;
}

// procedimento para ler as coordenadas do jogador

void lerCoordenadas(char j) {
  int linha, coluna;

  printf("Digite linha e coluna: ");
  scanf("%d%d", & linha, & coluna);

  while (ehValida(linha, coluna) == 0) {
    printf("Coordenadas invalidas! Digite outra linha e coluna: ");
    scanf("%d%d", & linha, & coluna);
  }
  jogo[linha][coluna] = j;
}

// função que retorna a quantidade de posições vazias
int quantVazias() {
  int quantidade = 0;

  for (l = 0; l < 3; l++) {
    for (c = 0; c < 3; c++)
      if (jogo[l][c] == ' ')
        quantidade++;
  }
  return quantidade;
}

//procedimento para jogar com o loop principal do jogo
void jogar() {
  int jogador = 1, vitoriaX = 0, vitoria0 = 0;
  char jogador1 = 'X', jogador2 = '0';

  do {
    imprimir();
    if (jogador == 1) {
      lerCoordenadas(jogador1);
      jogador++;
      vitoriaX += ganhouPorLinhas(jogador1);
      vitoriaX += ganhouPorColunas(jogador1);
      vitoriaX += ganhouPorDiagPrin(jogador1);
      vitoriaX += ganhouPorDiagSec(jogador1);
    } else {
      lerCoordenadas(jogador2);
      jogador = 1;
      vitoria0 += ganhouPorLinhas(jogador2);
      vitoria0 += ganhouPorColunas(jogador2);
      vitoria0 += ganhouPorDiagPrin(jogador2);
      vitoria0 += ganhouPorDiagSec(jogador2);
    }

  } while (vitoriaX == 0 && vitoria0 == 0 && quantVazias() > 0);

  if (vitoria0 == 1)
    printf("\nParabens jogador 2. Voce venceu!!!\n");
  else if (vitoriaX == 1)
    printf("\nParabens jogador 2. Voce venceu!!!\n");
  else
    printf("\nQue pena perderam!!!\n");
}
//Jogo da forca
void forca(int estado) {
  if (estado == 0) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 1) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 2) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 3) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 4) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 5) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         /  ");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (estado == 6) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         / \\");
    printf("\n|");
    printf("\n| Perdeu o jogo!");
    printf("\n-");
  }
}

int main() {
  int opcao;
  setlocale(LC_ALL, "Portuguese");
  while (1) {
    printf("----- MENU DE JOGOS -----\n");
    printf("1. Jogo da Adivinhação\n");
    printf("2. Jogo da Velha\n");
    printf("3. Jogo da Forca\n");
    printf("0. Sair\n");
    printf("-------------------------\n");
    printf("Digite uma opção referente ao número do jogo: ");
    scanf("%d", & opcao);
    getchar();
    
    switch (opcao) {
    case 1:
      printf("Você escolheu o Jogo 1.\n");

      setlocale(LC_ALL, "Portuguese"); // Setando a linguagem portuguesa
      int nivel, tamanho, numeroTentativas = 0, numeroAleatorio;

      printf("\t\t\tFOI GERADO UM NÚMERO ALEATÓRIO!\n");
      printf("\t\t\t       TENTE ADIVINHAR\n\n");

      printf("(1) Nivel fácil! (20 Tentativas e o numero é de 0 ate 10)\n\n");
      printf("(2) Nivel intermediario! (10 Tentativas e o numero é de 0 ate 100)\n\n");
      printf("(3) Nivel difícil! (5 Tentativas e o numero é de 0 ate 1000)\n\n");
      printf("Escolha o nivel que deseja jogar: ");
      scanf("%d", & nivel);
      switch (nivel) {
      case 1:
        tamanho = 10;
        numeroTentativas = 20;
        break;

      case 2:
        tamanho = 100;
        numeroTentativas = 10;
        break;

      case 3:
        tamanho = 1000;
        numeroTentativas = 5;
        break;

      default: //Caso não corresponda à nenhum nível
        printf("\nOpção inválida!\n");
        printf("\nPressione enter para continuar...\n");
        while (getchar() != '\n'); // Getchar pra ler o numero informado pra ser usado nos cases
        getchar();
        return 0;
      }

      srand(time(NULL)); // SRAND pra gerar um numero randomico e time null é pra declarar o valor dele como nulo
      numeroAleatorio = rand() % tamanho + 1; // limitaçao do numeroAleatorio a ser definido pelo case na variavel tamanho
      int numero, minimo = 0, maximo = tamanho, jogadas = 0, cont = 0; // cont = contador de jogadas erradas

      do {
        //printf("%d", numeroAleatorio);
        printf("Digite o número: \n");
        scanf("%d", &numero);
        jogadas++;

        if (numero > numeroAleatorio) {
          maximo = numero;
          printf("O número está entre %d e %d\n", minimo, maximo);
          printf("Você têm %d jogadas restantes...\n", numeroTentativas - jogadas);
        } else if (numero < numeroAleatorio) {
          minimo = numero;
          printf("O número está entre %d e %d\n", minimo, maximo);
          printf("Você têm %d jogadas restantes...\n", numeroTentativas - jogadas);
        } else {
          printf("\nParabéns! você acertou com %d jogadas!\n", jogadas);
          cont = numeroTentativas; //Encerra o loop
        }

        cont++;
      } while (cont < numeroTentativas); //Limite de jogadas

      if (jogadas == numeroTentativas && cont <= numeroTentativas) {
        printf("\nVocê errou todas as jogadas! Você perdeu!");
        printf("\nO número sorteado era: %d\n", numeroAleatorio);
      } else {
        printf("\nVocê errou %d jogadas!\n", jogadas - 1);
      }

      return 0;
      break;
    case 2:
      printf("Você escolheu o Jogo 2.\n");
      int opcao;

      do {
        inicializarMatriz();
        jogar();

        printf("\nDigite 1 para jogar novamente: ");
        scanf("%d", & opcao);
      } while (opcao == 1);

      return 0;
      break;
    case 3:
      printf("Você escolheu o Jogo 3.\n");
      char p_sec[100]; //palavra secreta
      printf("Jogador 1 \n");
      printf("Digite a palavra secreta: \n");
      fgets(p_sec, 100, stdin); //le uma cadeia de caracteres
      printf("A palavra secreta eh: %s", p_sec);
      printf("A palavra tem %lu caracteres", strlen(p_sec) - 1); //mede o tamanho da string
	  int i;
      for ( i = 0; i < 30; i++) {
        printf("\n");
      }

      //retira o ultima caracter de p_sec que esta a mais devido a captura ser com fgets()
      p_sec[strlen(p_sec) - 1] = '\0';
      char p_tela[100]; //palavra para tela
      strcpy(p_tela, p_sec); //copia de uma string para outra
     
      for ( i = 0; i < strlen(p_tela); i++) {
        p_tela[i] = '_';
      }

      int erros = 0;
      while (1) {
        // imprimir a forca
        forca(erros);
        //imprimir os underline/underscores
        //'_' para cada letra da palavra secreta, ou sejam imprimir p_tela
        printf("\nAdivinhe: ");
        for (i= 0; i < strlen(p_tela); i++) {
          printf("%c ", p_tela[i]);
        }

        //recebe a letra
        printf("\nLetra: ");
        char letra;
        scanf(" %c", & letra); // espaço é por conta do replit via web
        // se letra correta atualiza a palavra na tela
        //verifica a letra esta correta
        int sera_que_errou = 1; //1=sim 0=nao
        for ( i = 0; i < strlen(p_tela); i++) {
          if (letra == p_sec[i]) { //certo
            p_tela[i] = letra;
            sera_que_errou = 0;
          }
        }
        // senao, incrementa erros
        if (sera_que_errou == 1) {
          erros++;
        }
        //verifica se o jogo acabou
        //verifica se ganhou
        //verifica se p_sec eh a igual a p_tela
        if (strcmp(p_tela, p_sec) == 0) {
          //entao ganhou
          printf("\nAcertou: ");
          for ( i = 0; i < strlen(p_tela); i++) {
            printf("%c ", p_tela[i]);
          }
          printf("\nVenceu! Parabens!!!");
          printf("\nYou win!");
          break;
        }
        //verifica se perdeu
        if (erros == 6) {
          //perdeu
          forca(erros);
          break;
        }
      }
      return 0;
      break;
    case 0:
      printf("Saindo do programa.\n");
      return 0;
    default:
      printf("Opção inválida! Por favor, escolha novamente.\n");
      break;
    }
  }

  return 0;
}
