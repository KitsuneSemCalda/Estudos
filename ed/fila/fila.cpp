#include "iostream"

using namespace std;


// Aqui declaramos a classe Node onde será criada a lista ligada que decorrerá a fila.
class Node{
    friend class Fila;
    private:
        int dado;
        Node* next;
    public:
        Node(int data){
            dado = data;
            next = NULL;
        }
};

// Aqui declaramos a classe Fila, que contém o tamanho da fila (opcional) seu nó de inicio e seu nó de fim
class Fila{
    friend class Node;

    private:
        int tamanho;
        Node* inicio;
        Node* fim;
    public:
        bool vazia(){
            return (tamanho == 0);
        }

        Fila(){
            tamanho = 0;
            inicio = NULL;
            fim = NULL;
        };
        ~Fila(){
            while (tamanho > 0){
                desenfileira();
            }
        }
        
        int desenfileira(){
            int valor = inicio->dado;
            Node* temp = inicio;
            inicio = inicio->next;
            delete temp;
            tamanho --;
            if (tamanho == 0){
                fim = NULL;
            }
            return valor;
        }
        
        void enfileira(int valor){
            Node* novo = new Node(valor);
            if (tamanho == 0){
                inicio = novo;
            }else{
                fim->next = novo;
            }
            novo->next = fim;
            fim = novo;
            tamanho ++;
        }
};

// Aqui temos a função principal onde enfileira e desenfileira a fila
int main(){
    Fila fila;
    int num;
    cin >> num;

    while (num >= 0){
        fila.enfileira(num);
        cin >> num;
    }

    while (not fila.vazia()){
        cout << fila.desenfileira() << "\n";
    }
    cout << endl;

    return 0;
}
