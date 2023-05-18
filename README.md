
# Descrição do algoritmo

# Como foi desenvolvido

O código foi desenvolvido em linguagem C, utilizando três arquivos: Labirinto.h, Labirinto.c e main.c. O arquivo Labirinto.h contém as definições de structs 
utilizadas para representar as matrizes e o personagem, além das declarações das funções utilizadas no programa. O arquivo Labirinto.c contém as implementações das 
funções declaradas no arquivo Labirinto.h. Já o arquivo main.c é responsável por chamar a função Initiation() que inicia o programa.

# Regras Propostas

Atividade avaliativa sobre o caminhamento em labirinto. Nesta atividade, cada dupla ou trio de alunos deve entregar um trabalho contemplando três modelos de caminhamento em matriz: (a) randômico (já realizado, agora deve ser adaptado), (b) em largura (BFS) e; (c) em profundidade (DFS).

O caminhamento deve ocorrer em uma única matriz de tamanho N x N (considere testes para matrizes grandes, alto em torno de 50 x 50 ou maior). Nesta haverá quatro tipos de elementos importantes espalhados aleatoriamente: (a) item de passagem livre (número 1 na posição da matriz); (b) item de dano, indicado pelo carácter ‘*’; (c) paredes definidas como ‘#’ e; por fim, (d) uma ‘?’ que indica o ponto de parada da exploração. Esse, por sua vez, estará posicionado de forma randômica na matriz em qualquer uma das posições tidas como válidas. Além disso, tem-se como regra a condição de dano. Consideramos dano o item ‘*’, o qual obriga o algoritmo a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.

Ao sofrer um dano o algoritmo deve demarcar a posição com o item 1, neutralizando o mesmo e abrindo novas possibilidades de caminhamento / rotas até o estágio de finalização. Isso permitirá induzir custo adicional ao processo, o que nos ajudará a concluir várias questões sobre composição da entrada vs modelo de execução vs comportamento do algoritmo. Observe que a cada dano tomado o algoritmo deve ser reiniciado do zero, começando TODO o processo de caminhamento novamente a partir do estado inicial de execução.

# Discussão


# Funções 


# Funcionamento



### Tabela de Símbolos

| Símbolo              | Significado                                                                                                             | 
| ---------------------| -------------------------------------------------------------------------------------------------                       |
|  #                   | `Parede`   Não é possível passar por essa casa                                                                          |
|  *                   | `Perigo`  O caminhamento reinicia ao passar por essa casa e depois essa casa se transforma em '1'                       |
| 1                    | `passagem livre`   É possível passar por essa casa                                                                      |
| ?                    | `Objetivo`   O caminhamento finaliza ao passar por essa casa                                                            |


# Exemplo de Entrada
![This is an image](https://github.com/RafaelReisyzx/Labirinto-DFS-BFS-Random/blob/main/imgs/exemplo1.png)

# Exemplo de Saída


# Conclusão:


# Compilação e Execução

A pasta do repositorio possui um arquivo Makefile que contém as instruções para compilar e executar. Para usar essas instruções, você pode usar o terminal do seu sistema
operacional e navegar até o diretório raiz do projeto.

Existem três comandos principais que você pode usar no Makefile:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Em resumo, para executar o programa, você precisa navegar até o diretório raiz do projeto e executar o comando make para compilar o programa e, em seguida, 
executar o comando make run para executá-lo.Se você precisar limpar a compilação anterior, pode usar o comando make clean antes de executar a compilação.
