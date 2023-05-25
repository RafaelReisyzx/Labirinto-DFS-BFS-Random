#include "Labirinto.hpp"

int Initiation(Mapa *mat){
    int n=0,opcao;	
        cout << "\n******************************************************\n";
        cout << "-Menu-\n";
        cout << "1-Gerar nova matriz dentro de um arquivo (input.data)\n";
        cout << "2-Ler matriz de um arquivo (input.data)\n";
        cout << "******************************************************\n";
        cin >> opcao;
        cout << "\n";
    if(opcao == 1){
	cout << "Digite o tamanho da matriz quadrada: ";
    cin >> n;
	mat->Matriz.tam=n;
	GenerateMatrix(mat);
	PrintMatrix(mat);
    for(;;){
        cout <<"\nQual Caminhamento de matriz deseja testar?\n";
        cout << "1-Random\n";
        cout << "2-Bfs\n";
        cout << "3-Dfs\n";
        cout << "4-Sair\n";
        cin >> opcao;
        cout << "\n";
    if(opcao==1){
        auto start = chrono::high_resolution_clock::now();
	Random(mat);
        auto end = chrono::high_resolution_clock::now();      
        chrono::duration<double> duration = end - start;
        double seconds = duration.count();
        cout << "Tempo de execução: " << seconds << " segundos" << endl;

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
        ReadMatrix(mat);		       
    for(;;){
        cout <<"\nQual Caminhamento de matriz deseja testar?\n";
        cout << "1-Random\n";
        cout << "2-Bfs\n";
        cout << "3-Dfs\n";
        cout << "4-Sair\n";
        cin >> opcao;
        cout << "\n";
    if(opcao==1){
        auto start = chrono::high_resolution_clock::now();
	Random(mat);
        auto end = chrono::high_resolution_clock::now();      
        chrono::duration<double> duration = end - start;
        double seconds = duration.count();
        cout << "Tempo de execução: " << seconds << " segundos" << endl;
   }else if(opcao == 2){		
    // Bfs
    }else if(opcao == 3){		
    // Dfs
    }else{
    return 0;
         }       
   } 
   }
   return 0;
}

int GenerateMatrix(Mapa* mat){
    int i, j, data = 0,Row,Col, ok=0,n=0;
        remove("dataset/input.data");
        n=mat->Matriz.tam;
    FILE* f = fopen("dataset/input.data", "a");
    if (f == NULL) {
        cout << "Erro ao abrir o arquivo.\n";
        exit(EXIT_FAILURE);
    }
        fprintf(f, "%d %d\n", n, n);

     while(ok<1){
    // Gerar posição aleatória para o caractere "?"
        Row = rand() % n;
        Col = rand() % n;
        ok=1;
    if (Row == 0 && Col == 0){
        ok=0;
    }
    }  

    for (i = 0; i < n; i++){
    for (j = 0; j < n; j++) {
    if (i == Row && j == Col){
        mat->Matriz.map[i][j] = '?';
        fprintf(f, "%c ", mat->Matriz.map[i][j]);
    }else{
        data = rand() % 20;
        if (data <= 10) {
        mat->Matriz.map[i][j] = '1';
        fprintf(f, "%c ", mat->Matriz.map[i][j]);
    } else if ((data > 10) && (data < 16)) {
        mat->Matriz.map[i][j] = '*';
        fprintf(f, "%c ", mat->Matriz.map[i][j]);
    } else {
    if(i==0&&j==0){
        mat->Matriz.map[i][j] = '1';
        fprintf(f, "%c ", mat->Matriz.map[i][j]);
    }else{
        mat->Matriz.map[i][j] = '#';
        fprintf(f, "%c ", mat->Matriz.map[i][j]);
		}
          }
        }
    }
        fprintf(f, "\n");
    }

        fclose(f);

    return 0;
}

void PrintMatrix(Mapa *mat){
	int i,j,n;
	n=mat->Matriz.tam;
    for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
	 cout <<" "<< mat->Matriz.map[i][j];
	}
	 cout << "\n";
	}
}

int ReadMatrix(Mapa *mat){
    int linhas = 0, colunas = 0 , i, j;
    char c;
    FILE *f = fopen("dataset/input.data", "r");
    if (f == NULL){
        cout << "Erro ao abrir o arquivo.\n";
        exit(EXIT_FAILURE);
    }
        fscanf(f, "%d %d", &linhas, &colunas);

    for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
        c = fgetc(f);
    while (isspace(c)){
        c = fgetc(f);
    }
    if (c == '#'){
    if (i == 0 && j == 0){  
        c ='1';
    }
    } 
        mat->Matriz.map[i][j] = c;

    }  
    }
        mat->Matriz.tam=linhas;
        fclose(f);
        PrintMatrix(mat);
    return 0; 
}

int Random(Mapa *mat){

	int i=0,j=0,r=0,data=0,n,Direita=0,Esquerda=0,Baixo=0,Cima=0,DiagonalEsquerdaSuperior=0,DiagonalDireitaSuperior=0,DiagonalEsquerdaInferior=0,DiagonalDireitaInferior=0;   
	n=mat->Matriz.tam;
	mat->Matriz.passos=0;
	for(;;){		 

	//1° Etapa Verificador de casa
	
    if(mat->Matriz.map[i][j]=='*'){	 
        mat->Matriz.map[i][j]='1';
        i=0;
        j=0;      
    }else if(mat->Matriz.map[i][j]=='?'){	
        cout<<"\nQuantidade de Passos: "<<mat->Matriz.passos;
        cout << "\n";
	Finalization(mat);
     break;
    }
	//2° Etapa Demarcar Paredes
	//cima
	if(mat->Matriz.map[i-1][j]=='#'){
		Cima=-1;
	}
	//baixo
	if(mat->Matriz.map[i+1][j]=='#'){
		Baixo=-1;
	}
	//esquerda
	if(mat->Matriz.map[i][j-1]=='#'){
		Esquerda=-1;
	}
	//direita
	if(mat->Matriz.map[i][j+1]=='#'){
		Direita=-1;
	}
	//diagonal superior esquerda
	if(mat->Matriz.map[i-1][j-1]=='#'){
		DiagonalEsquerdaSuperior=-1;
	}
	//diagonal superior direita
	if(mat->Matriz.map[i-1][j+1]=='#'){
		DiagonalDireitaSuperior=-1;
	}
	//diagonal inferior esquerda
	if(mat->Matriz.map[i+1][j-1]=='#'){
		DiagonalEsquerdaInferior=-1;
	}
	//diagonal inferior direita
	if(mat->Matriz.map[i+1][j+1]=='#'){
		DiagonalDireitaInferior=-1;
	}
    //3° Etapa Escolher caminho possivel de caminhar
	for(r=0;r<1;){
	    data = rand()%8;
	if(data==1&&Cima!=-1&&i>0){
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
    //4° Etapa Caminhar
	
	if(data==1){
	    i=i-1;
	    mat->Matriz.passos++;
	}else if(data==2){
	    i=i+1;
	    mat->Matriz.passos++;
	}else if(data==3){		
	    j=j-1;
	    mat->Matriz.passos++;
	}else if(data==4){
	    j=j+1;
	    mat->Matriz.passos++;
	}else if(data==5){
	    i=i-1;
	    j=j+1;
	    mat->Matriz.passos++;
	}else if(data==6){
	    i=i-1;
	    j=j-1;
	    mat->Matriz.passos++;	
	}else if(data==7){
	    i=i+1;
	    j=j+1;
	    mat->Matriz.passos++;
	}else if(data==8){
        i=i+1;
	    j=j-1;
	    mat->Matriz.passos++;
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

	}

	return 0;
		}
	void Finalization(Mapa *mat)
{
	int i,j,n;
	n=mat->Matriz.tam;;
	FILE *g = fopen("dataset/outputRandom.data", "a");
    if (g == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
	
	printf("\nMapa Atualizado:\n\n");
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%c ", mat->Matriz.map[i][j]);
			 fprintf(g, "%c ", mat->Matriz.map[i][j]);
		}
		printf("\n");
		 fprintf(g, "\n");
	}
		
	
}


  
  
  
  
