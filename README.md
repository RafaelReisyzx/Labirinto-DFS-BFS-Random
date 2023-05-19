
# Descrição do algoritmo

O algoritmo tem como objetivo explorar um Labirinto, percorrendo suas casas seguindo regras de diferentes formas de caminhamento. O labirinto é representado por uma matriz quadrada, onde cada casa pode conter diferentes tipos de símbolos: '1' para caminhos livres, '#' para paredes ,'*' para perigos e '?' para a casa objetivo. O objetivo do caminhamento é chegar à casa objetivo a partir da casa inicial (canto superior esquerdo).
O algoritmo é iniciado com a geração ou leitura do labirinto, que é armazenado na estrutura de dados Mapa, contendo a matriz do labirinto e informações sobre seu tamanho. Após isso, o usuário pode escolher entre diferentes opções de caminhamento: Random, Bfs (busca em largura) ou Dfs (busca em profundidade).

No caminhamento aleatório (Random), o algoritmo identifica as direções possíveis de movimento (cima, baixo, esquerda, direita, diagonais) e escolhe aleatoriamente uma direção livre. Depois se move para a casa vizinha na direção escolhida. Esse processo é repetido até que a casa objetivo seja alcançada.

# Como foi desenvolvido

O código foi desenvolvido em linguagem C, utilizando três arquivos: Labirinto.h, Labirinto.c e main.c. O arquivo Labirinto.h contém as definições de structs 
utilizadas para representar as matrizes e o personagem, além das declarações das funções utilizadas no programa. O arquivo Labirinto.c contém as implementações das 
funções declaradas no arquivo Labirinto.h. Já o arquivo main.c é responsável por chamar a função Initiation() que inicia o programa.

# Regras Propostas

Atividade avaliativa sobre o caminhamento em labirinto. Nesta atividade, cada dupla ou trio de alunos deve entregar um trabalho contemplando três modelos de caminhamento em matriz: (a) randômico (já realizado, agora deve ser adaptado), (b) em largura (BFS) e; (c) em profundidade (DFS).

O caminhamento deve ocorrer em uma única matriz de tamanho N x N (considere testes para matrizes grandes, alto em torno de 50 x 50 ou maior). Nesta haverá quatro tipos de elementos importantes espalhados aleatoriamente: (a) item de passagem livre (número 1 na posição da matriz); (b) item de dano, indicado pelo carácter ‘*’; (c) paredes definidas como ‘#’ e; por fim, (d) uma ‘?’ que indica o ponto de parada da exploração. Esse, por sua vez, estará posicionado de forma randômica na matriz em qualquer uma das posições tidas como válidas. Além disso, tem-se como regra a condição de dano. Consideramos dano o item ‘*’, o qual obriga o algoritmo a voltar no estágio inicial de execução e reiniciar novamente do zero toda a execução.

Ao sofrer um dano o algoritmo deve demarcar a posição com o item 1, neutralizando o mesmo e abrindo novas possibilidades de caminhamento / rotas até o estágio de finalização. Isso permitirá induzir custo adicional ao processo, o que nos ajudará a concluir várias questões sobre composição da entrada vs modelo de execução vs comportamento do algoritmo. Observe que a cada dano tomado o algoritmo deve ser reiniciado do zero, começando TODO o processo de caminhamento novamente a partir do estado inicial de execução.

# Discussão

Ao lidar com esse algoritmo, algumas das principais questões que podem surgir incluem:

- Eficiência do algoritmo: Como o algoritmo se comporta em termos de tempo de execução e consumo de recursos, especialmente em labirintos grandes? O algoritmo consegue encontrar o caminho objetivo em um tempo razoável? Como o desempenho do algoritmo é afetado por diferentes tamanhos de labirinto, densidades de obstáculos e configurações específicas?
- Comportamento em labirintos complexos: Como o algoritmo se comporta em labirintos com múltiplas soluções ou com obstáculos e desvios? Ele é capaz de encontrar diferentes caminhos para o objetivo ou sempre segue o mesmo padrão?

# Funções 

- Initiation: é a função principal do programa, responsável por iniciar a execução. Ela exibe um menu com opções para gerar uma nova matriz ou ler uma matriz existente. Em seguida, solicita ao usuário a escolha do algoritmo de caminhamento a ser executado.

- GenerateMatrix: é responsável por gerar uma nova matriz aleatória e salvá-la em um arquivo chamado "input.data". A matriz é preenchida com caracteres que representam as células do labirinto, como '#' para paredes, '1' para caminhos livres, '*' para perigo e uma casa '?' para a objetivo do caminhante. O tamanho da matriz é definido pelo usuário.

- PrintMatrix: é utilizada para exibir a matriz na saída padrão, mostrando a configuração atual do labirinto.

- ReadMatriz: lê uma matriz existente de um arquivo chamado "input.data". A matriz é armazenada na estrutura de dados do programa para ser manipulada posteriormente.

- Random: é o algoritmo de caminhamento aleatório na matriz. Ele inicia na posição inicial do caminhante e realiza movimentos aleatórios em direções possíveis (cima, baixo, esquerda, direita e diagonais) até encontrar a casa objetivo marcada com '?'. Durante o caminhamento, o algoritmo demarca as paredes do labirinto, evitando passar por elas. O número de passos realizados é contado e armazenado na estrutura de dados do programa.

# Funcionamento

O programa inicia solicitando ao usuário que escolha uma das opções disponíveis no menu. Caso o usuário escolha a opção 1, o programa gera uma matriz quadrada aleatória e a armazena em um arquivo de texto chamado "input.data". Em seguida, é chamado outro menu contendo as opções de caminhamento de matriz e uma opção de finalização. Caso o usuário escolha a opção 2, o programa lê a matriz presentes no arquivo "input.data" e a armazena em uma estrutura de dados. Novamente, o menu secundário é chamado para o usuário escolher entre as opções de caminhamento.

### Tabela de Símbolos

| Símbolo              | Significado                                                                                                             | 
| ---------------------| -------------------------------------------------------------------------------------------------                       |
| #                    | `Parede`   Não é possível passar por essa casa                                                                          |
| *                    | `Perigo`  O caminhamento reinicia ao passar por essa casa, depois disso essa casa se transforma em '1'                  |
| 1                    | `Passagem Livre`   É possível passar por essa casa                                                                      |
| ?                    | `Objetivo`   O caminhamento finaliza ao passar por essa casa                                                            |

# Funcionamento Função Random

Ordem de etapas dentro da função Random:
1. **Verificar casa** : Nesta etapa, o algoritmo verifica o tipo de casa em que está atualmente. Existem duas possibilidades:

+ Perigo: Se a casa atual for um perigo, o caminhamento é reiniciado e a casa atual se torna uma casa '1' de passagem livre

+ Objetivo: Se a casa atual for o objetivo, isso significa que o algoritmo chegou ao destino desejado. Nesse caso, a execução do algoritmo pode é encerrada.

2. **Demarcar paredes**: Após verificar o tipo de casa atual, o algoritmo demarca as paredes da casa. Isso significa que registra as direções que não podem ser seguidas, por causa da presença de casas '#'. 
3. **Escolher caminho**: Com base nas informações coletadas na etapa anterior, o algoritmo escolhe forma aleatória um caminho possível para prosseguir. Ele seleciona uma direção disponível que não esteja marcada como parede.
4. **Caminhar**: Nesta etapa, o algoritmo efetivamente caminha pela opção selecionada na etapa anterior.

# Exemplo de Entrada 1
![This is an image](https://github.com/RafaelReisyzx/Labirinto-DFS-BFS-Random/blob/main/imgs/exemplo1.png)


# Exemplos de Saída da Entrada 1

## Randômico

![This is an image](https://github.com/RafaelReisyzx/Labirinto-DFS-BFS-Random/blob/main/imgs/exemplo2.png)
![This is an image](https://github.com/RafaelReisyzx/Labirinto-DFS-BFS-Random/blob/main/imgs/exemplo3.png)

# Conclusão:

## Randômico

- O desempenho do algoritmo de caminhamento aleatório em termos de tempo de execução e consumo de recursos pode variar dependendo do tamanho do labirinto e da densidade de obstáculos. Em labirintos grandes ou com muitos obstáculos, o algoritmo pode levar mais tempo para encontrar o caminho objetivo, pois a probabilidade de escolher uma direção livre diminui. Além disso, o consumo de recursos, como memória, é geralmente baixo, já que o algoritmo não requer armazenamento de estruturas de dados complexas.
- O algoritmo de caminhamento aleatório pode se comportar de maneira diferente em labirintos com múltiplas soluções ou com obstáculos e desvios. Em labirintos com múltiplas soluções, o algoritmo pode encontrar caminhos diferentes em execuções diferentes, explorando as várias opções disponíveis. No entanto, em labirintos com obstáculos complexos e desvios, o algoritmo pode ter dificuldade em encontrar o caminho objetivo devido à aleatoriedade de suas escolhas.

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
