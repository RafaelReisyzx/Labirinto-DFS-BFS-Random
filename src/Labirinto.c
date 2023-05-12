#include "Labirinto.h"

int Initiation(Mapa *mat)
{
	int n=0,opcao;
	

	printf("\n******************************************************\n");	
	printf("-Menu-\n");
	printf("1-Gerar nova matriz dentro de um arquivo (input.data)\n");
	printf("2-Ler matriz de um arquivo (input.data)\n");
	printf("******************************************************\n");
	scanf("%d", &opcao);
	printf("\n");
	if(opcao == 1){
	printf("Digite o tamanho da matriz quadrada: ");
	scanf("%d", &n);
	GenerateMatrix(n,mat);
    for(;;)
	{
        PrintMatrix(n,mat);
      	printf("Qual Caminhamento de matriz deseja testar?\n");
      	printf("1-Random\n");
	    printf("2-Bfs\n");
        printf("3-Dfs\n");
        printf("4-Sair\n");
        scanf("%d", &opcao);
	    printf("\n");
       if(opcao==1){
      Random(n,mat);
	
       }else if(opcao == 2){		
       // Bfs
       }else if(opcao == 3){		
       // Dfs
       }else{
         return 0;
       }       
      }      
		}		
		else if(opcao == 2){			
		ReadMatriz(mat);		       
      for(;;)
	{
        PrintMatrix(n,mat);
      	printf("Qual Caminhamento de matriz deseja testar?\n");
      	printf("1-Random\n");
	    printf("2-Bfs\n");
        printf("3-Dfs\n");
        printf("4-Sair\n");
        scanf("%d", &opcao);
	    printf("\n");
       if(opcao==1){
        Random(n,mat);	
       }else if(opcao == 2){		
       // Bfs
       }else if(opcao == 3){		
       // Dfs
       }else{
         return 0;
       }       
      }      
		}else{
		printf("\nOpcao invalida\n");
		}
}

int GenerateMatrix(int n,Mapa *mat){
	int i,j,data=0,data2=0;
	FILE *f = fopen("input.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    } 
       fprintf(f, "%d %d\n",n, n);
   
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			data = rand()%20;
       if(data <= 10){     	
			mat->Matrizes.map[i][j] ='1';
			 fprintf(f, "%c ", mat->Matrizes.map[i][j]);
		}else if ((data > 10) && (data < 16)){
			mat->Matrizes.map[i][j] = '*';
			 fprintf(f, "%c ", mat->Matrizes.map[i][j]);
		} else{
			mat->Matrizes.map[i][j] = '#';
			 fprintf(f, "%c ", mat->Matrizes.map[i][j]);
		}
		
       
		}
		 fprintf(f, "\n");
		
	}
	data=0;
    data = rand() % n + 1;
    data2 = rand() % n + 1;
   	mat->Matrizes.map[data][data2] ='?';

    fclose(f);
 

	return 0;
}

void PrintMatrix(int n,Mapa *mat){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c ", mat->Matrizes.map[i][j]);
		}
		printf("\n");
	}

}


void ReadMatriz(Mapa *mat) {
    FILE *f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para leitura\n");
        exit(EXIT_FAILURE);
    }

    int linhas = 0, colunas = 0 , i, j;
    char c;

    fscanf(f, "%d %d", &linhas, &colunas);

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                c = fgetc(f);
                while (isspace(c)) {
                    c = fgetc(f);
                }
                if (c == '#') {
                    if (i == 0 && j == 0) {
                        int data = rand() % 20;
                        if (data <= 10) {     
                            mat->Matrizes.map[i][j] ='1';
                        } else if (data > 10 && data < 16) {
                            mat->Matrizes.map[i][j] = '*';
                        }
                    } else {
                        mat->Matrizes.map[i][j] = c;
                    }
                } else {
                    mat->Matrizes.map[i][j] = c;
                }
            }
      
    }


    fclose(f);
  
}

void AtualizarMatriz(int n,Mapa *mat){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			mat->Matrizes.mapAux[i][j]=mat->Matrizes.map[i][j];
		}
	}

}


int Random(int n,Mapa *mat)
{

	int i=0,j=0,r=0,x=0,k=0,data=0,a,c,b,ok=0,opcao,visualizacao=0,iteracao = 0;
	int Direita=0,Esquerda=0,Baixo=0,Cima=0,DiagonalEsquerdaSuperior=0,DiagonalDireitaSuperior=0,DiagonalEsquerdaInferior=0,DiagonalDireitaInferior=0;
    clock_t inicio, fim;
    double tempo_total = 0,desvio_padrao = 0,media=0;
    double *tempos_execucao = NULL;
	AtualizarMatriz(n,mat);
	for(;;)
	{
		
	inicio = clock();
	//1Â° Etapa Verificador de casa
	
		if(mat->Matrizes.mapAux[i][j]=='*'){	 
      mat->Matrizes.mapAux[i][j]=='1';
    	i=0;
        j=0;      

    	}else if(mat->Matrizes.mapAux[i][j]=='?'){
      
     // Calcula a média do tempo de execução
   media = tempo_total / (iteracao + 1);

    // Calcula o desvio padrão
    for (i = 0; i <= iteracao; i++) {
        desvio_padrao += pow(tempos_execucao[i] - media, 2);
    }
    desvio_padrao = sqrt(desvio_padrao / (iteracao + 1));

    printf("Tempo médio de execução: %lf segundos\n", media);
    printf("Desvio padrão: %lf segundos\n", desvio_padrao);

    // Libera a memória alocada para o vetor de tempos de execução
    free(tempos_execucao);

	   }
	   		  fim = clock();
        double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Realoca o vetor para armazenar o tempo de execução atual
        tempos_execucao = realloc(tempos_execucao, (iteracao + 1) * sizeof(double));
        tempos_execucao[iteracao] = tempo_execucao;
        tempo_total += tempo_execucao;
        

	//2Â° EtapaDemarcar Paredes
	//cima
	if(mat->Matrizes.mapAux[i-1][j]=='#')
	{
		Cima=-1;
	}
	//baixo
	if(mat->Matrizes.mapAux[i+1][j]=='#')
	{
		Baixo=-1;
	}
	//esquerda
	if(mat->Matrizes.mapAux[i][j-1]=='#')
	{
		Esquerda=-1;
	}
	//direita
	if(mat->Matrizes.mapAux[i][j+1]=='#')
	{
		Direita=-1;
	}
	//diagonal superior esquerda
	if(mat->Matrizes.mapAux[i-1][j-1]=='#')
	{
		DiagonalEsquerdaSuperior=-1;
	}
	//diagonal superior direita
	if(mat->Matrizes.mapAux[i-1][j+1]=='#')
	{
		DiagonalDireitaSuperior=-1;
	}
	//diagonal inferior esquerda
	if(mat->Matrizes.mapAux[i+1][j-1]=='#')
	{
		DiagonalEsquerdaInferior=-1;
	}
	//diagonal inferior direita
	if(mat->Matrizes.mapAux[i+1][j+1]=='#')
	{
		DiagonalDireitaInferior=-1;
	}
//3Â° Etapa Escolher caminho possivel de caminhar
	for(r=0;r<1;)
	{
	data = rand()%8;
	if(data==1&&Cima!=-1&&i>0)
	{
    r=1;
	}else if(data==2&&Baixo!=-1&&i<n-1){
	r=1;
	}else if(data==3&&Esquerda!=-1&&j>0){
	r=1;		
	}else if(data==4&&Direita!=-1&&j<n-1){
	r=1;
	}else if(data==5&&DiagonalDireitaSuperior!=-1&&i>0&&j<n-1){
	r=1;	
	}else if(data==6&&DiagonalEsquerdaSuperior!=-1&&i>0&&j>0){
	r=1;
	}else if(data==7&&DiagonalDireitaInferior!=-1&&i<n-1&&j<n-1){
	r=1;		
	}else if(data==8&&DiagonalEsquerdaInferior!=-1&&i<n-1&&j>0){
	r=1;	
	}	
   }
   //4Â° Etapa Caminhar
	
	if(data==1)
	{
		i=i-1;
	}else if(data==2){
		i=i+1;
	}else if(data==3){		
		j=j-1;
	}else if(data==4){
		j=j+1;
	}else if(data==5)
	{
		i=i-1;
		j=j+1;
	}else if(data==6){
		i=i-1;
		j=j-1;	
	}else if(data==7){
	    i=i+1;
	    j=j+1;
	}else if(data==8){
		i=i+1;
		j=j-1;
	}else
	{		
	}
		Cima=0;
		Baixo=0;
		Direita=0;
		Esquerda=0;
		DiagonalDireitaSuperior=0;
		DiagonalEsquerdaSuperior=0;
		DiagonalDireitaInferior=0;
		DiagonalEsquerdaInferior=0;
		r=0;
		

         iteracao++;

	}
	
	
		}
	

  
  
  
  
