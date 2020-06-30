// Kaique Cairan Chaves Costa ;
// RA : 383947467463 ;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define COL 3
#define LIN 3

int main(void){
	int opcao_final;

// estrutura de repetição para fazer mais de um cálculo para o programa;
	do{
	// Seta a linguagem para o português do brasil.
		
		
		setlocale(LC_ALL, "portuguese");
		
	//declaração de variáveis;
		
		int matriz [LIN][LIN];
		int matriz_preenchida[3][5]; 
		int matriz_inversa[3][5];
		int i, j;

		int diagonal_primaria[3] = {1, 1, 1};
		int diagonal_Secundaria[3] = {1, 1, 1};
		int Dprincipal, Dsecundaria;
		int determinante;
		
		//primeira impressão do programa
		printf("\n\n\t\t Seja bem vindo a um programa que calcula matriz.\n");
		// recebimento da matriz pelo usuário;
		for(i = 0; i < LIN; i++) {
			for(j = 0; j < COL; j++) {
				do{
					printf("\t\t\t\t Linha %d Coluna %d :", i+1, j+1);
					scanf("%d", &matriz[i][j]);
					
				}while(matriz[i][j] <= -50000 || matriz[i][j] > 50000);
			}
		}
		//atribuição do valor para completar a matriz 3x3
		for(i=0; i<3; i++){
			int contador = 0;
			for(j= 0; j < 3; j++){
				matriz_preenchida[i][j] = matriz[i][contador];
				contador++;
			}
		}
		//atribuição do valor para completar a matriz 3x5
		for(i=0; i<3; i++){
			int contador = 0;
			for(j= 3; j < 5; j++){
				matriz_preenchida[i][j] = matriz[i][contador];
				contador++;
			}
		}
		printf("\n\t\t\t  Sua matriz aplicando a fórmula de Sarrus: \n\n");

		//for(res) para cálcular  as diagonais primárias;
		for(i = 0; i < 3;  i++){
			diagonal_primaria[0] *= matriz_preenchida[i-1][j+i];	
		}
		for(i = 0; i < 3;  i++){			
			diagonal_primaria[1] *= matriz_preenchida[i][i+1];
		}
		for(i = 0; i < 3;  i++){
			diagonal_primaria[2] *= matriz_preenchida[i][i+2];
		}
		//impressão para a tela da matriz em formato de matriz;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 5; j++) {
				printf("\t\t |%d| ", matriz_preenchida[i][j]);	    
			}
			printf("\n\n");
		}
		//inversão da matriz; basicamente o que vc me falou sobre m,n; outras variáveis, estava quase acabando;
		for(i=0; i<3; i++){
			int contador = 0;
			for(j= 4; j >= 0; j--){
				matriz_inversa[i][contador] = matriz_preenchida[i][j];
				contador++;
			}
		}
		//for(es) para calcular as diagonais secundárias	
		for(i = 0; i < 3;  i++){	
			diagonal_Secundaria[0] *= (-1) * matriz_inversa[i][i];	
		}
		for(i = 0; i < 3;  i++){		
			diagonal_Secundaria[1] *= (-1) * matriz_inversa[i][i+1];
		}
		for(i = 0; i < 3;  i++){
			diagonal_Secundaria[2] *= (-1) * matriz_inversa[i][i+2];
		}
	//processamento final dos dados para o cálculo do determinante;
		Dprincipal  =  diagonal_primaria[0] + diagonal_primaria[1] + diagonal_primaria[2];
		Dsecundaria =  diagonal_Secundaria[0] + diagonal_Secundaria[1] + diagonal_Secundaria[2];
		determinante = Dprincipal + Dsecundaria;

    //Saída de dados/ impressão do valor principal da matriz.
		printf("\t\t\t   Resultados Finais :\n");

		determinante = Dprincipal + Dsecundaria;
		
		printf("\t\t\t\t\t\t\t\t\t\n        Diagonal Principal     : [%d]", Dprincipal);
		printf("\n\t\t\t-------------------------------------------------------------");
		printf("\t\t\t\t\t\t\t\t\t\n        Diagonal Secundária    : [%d] ", Dsecundaria);
		printf("\n\t\t\t-------------------------------------------------------------");
		printf("\n\t\t\t\t\t\t\t\t\t\n      Determinante da matriz : [%d]", determinante);
		printf("\n\t\t\t-------------------------------------------------------------\n\n");
		
		printf("\n\t\t Se você deseja Fazer outro cálculo de determinante, Digite 1");
		printf("\n\t\t Se você deseja encerrar o programa, Digite 2 ");
		printf("\n\t\t Sua opção:");
		scanf("%d", &opcao_final );
		//limpa a tela para novos cálculos;
		system("cls");
		
	}while(opcao_final == 1);
	//quando a opção for 2, encerra o programa;
	if(opcao_final == 2){
		printf("Encerrando o programa.........\n");
		exit(0);
	}
	system("PAUSE");
	return 0;

}
