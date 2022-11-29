#include "iostream"

using namespace std;

class Node{
    // A classe Node é amiga da classe Pilha, isso significa que a classe node pode acessar campos privados e protegidos da classe Pilha, além disso é uma classe util a classe pilha pois dela virá o encadeamento que será utilizado na pilha.
    friend class Pilha;
    private:
        // No campo privado definimos os atributos da classe Node, o dado que foi guardado no campo atual e qual o campo seguinte gerando um encadeamento similar ao dá lista ligada.
        int node_dado;
        Node* node_proximo;
    public:
        // No campo publico definimos uma função do construtor que pode ser acessada de qualquer lugar que instancie a classe o construtor garante a atribuição de todo os valores da classe para que seja utilizado corretamente.
        Node(int dado){
            node_dado = dado;
            node_proximo = NULL;
        };
};

class Pilha{
    // A classe Pilha necessita de 1 campo essencial e 1 campo opcional, sendo o campo essencial chamado de Topo. Que identifica o ponto inicial da pilha e de onde deve começar a ser lindo quando for desempilhado.
    private:
        Node* topo;
        unsigned int tamanho;
    public:
        // Definimos uma função chamada limpaPilha para limpar a pilha após o uso, isso é uma função opcional que é usada no Destrutor mas, também pode ter seu método implementado diretamente no destructor.
        void limpaPilha(){
            while (tamanho > 0){
                desempilha();
            };
        }
        // aqui é definido o construtor da classe Pilha, inicializando os valores da Pilha ao instacia-la.
        Pilha(){
            topo = NULL;
            tamanho = 0;
        };
        // aqui é definido o destructor da classe Pilha, deletando todos os valores da pilha.
        ~Pilha(){
            limpaPilha();
        };
        // aqui é definido uma função que expõe globalmente o tamanho da pilha podendo ser acessado de onde ela for instanciada
        unsigned int getTamanho(){
            return tamanho;
        };
        // retorna verdadeiro ou falso caso tamanho da pilha seja igual a zero
        bool vazia(){
            return (tamanho == 0);
        }

        // função para remover cada elemento da pilha retirando-o da lista ligada e reapontando os valores
        int desempilha(){
            int valor = topo->node_dado;
            Node* temp = topo;
            topo = topo->node_proximo;
            delete temp;
            tamanho --;
            return valor;
        };
        // gera um novo valor para a pilha alocando um novo nó no final da mesma.    
        void empilha(int dado){
            Node* novo = new Node(dado);
            novo->node_proximo = topo;
            topo = novo;
            tamanho ++;
        };
};


// Função principal que aloca valores até chegar a um número negativo, e depois desaloca começando do ultimmo para o começo Fifo
int main(){
    Pilha pilha;
    int num;
    cin >> num;
    while (num >= 0){
        pilha.empilha(num);
        cin >> num;
    }
    
    while (pilha.getTamanho() > 0){
        cout << pilha.desempilha() << endl;
    }

    return 0;
}
