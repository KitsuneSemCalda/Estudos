# Estudos 2022 de ciencias da computação:

- **ED**: **E**strutura de **D**ados
- **PLP**: **P**aradigmas de **L**inguagens de **P**rogramação.

## Como testar os algoritmos

Caso deseje testar os algoritmos e as estruturas de dados, você pode precisar do compilador clang ou do g++.
Caso os tenha vá à pasta do algoritmo desejado e execute a instrução:<br> 
`clang++ {nome_do_algoritmo\estrutura desejado}` ou
`g++ {nome_do_algoritmo\estrutura desejado}`

Caso deseje testar os algoritmos feitos em plp. Caso o algoritmo tenha a extensão. **.hs** significa que o algoritmo foi escrito em Haskell, ou sjea você necessita executar a seguinte instrução:<br>
`ghc {nome do algoritmo\estrutura desejado}`

### Possíveis erros de compilação

Caso o clang++ reclame de que não encontrou alguma biblioteca mantenha a calma e respire fundo.

Possivelmente o clang funcionará se você utilizar `clang++-14`. Caso não funcione, abra uma issue neste repositório e eu farei o possivel para ajudar

### ED:
  - Pilha utilizando Classes:<br>
       A pilha é uma estrutura dados definido com LiFo (Last. In. First. Out.).<br>
       Aqui eu implementei uma pilha básica utilizando C++ e orientação a objetos.
  - Fila utilizando Classes:<br>
      A fila é uma estrutura de dados definida com Fifo (First. In. First. Out.).<br>
      A fila implementada foi criada de forma básica utilizando C++ e orientação a objetos.
<br>
  - Heap utilizando Classes:<br>
    Em ciência da computação , um heap é uma estrutura de dados baseada em árvore especializada que é essencialmente uma árvore quase completa [1] que satisfaz a propriedade de heap : em um heap máximo , para qualquer nó C, se P é um nó pai de C, então a chave (o valor ) de P é maior ou igual à chave de C. Em um min heap , a chave de P é menor ou igual à chave de C. [2] O nó no "topo" do heap (sem pais) é chamado de nó raiz .<br>
    - A heap é dividida em duas subclasses:
        - MaxHeap
        - MinHeap

### PLP:
    - Raizes reais de uma equação de segundo grau:<br>
