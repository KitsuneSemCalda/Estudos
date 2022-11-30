#include "iostream"
#include "cstdlib"
#include "cstring"
#include <cstring>

using namespace std;

typedef int dado;

class MaxHeap{
    private:
        dado* heap;
        int capacidade;
        int tamanho;
        inline int pai(int i){
            return (i-1/2);
        };
        inline int esquerdo(int i){
            return (2*i+1);
        };
        inline int direito(int i){
            return (2*i+2);
        };
        void arruma(){
            for (int i = (tamanho / 2 -1); i>=0; i--){
                corrigeDescendo(i);
            }
        };
        void corrigeSubindo(int i){
            int p = pai(i);
            if (heap[i] > heap[p]){
                swap(heap[i], heap[p]);
                corrigeSubindo(p);
            }
        };
        void corrigeDescendo(int i){
            int esq = esquerdo(i);
            int dir = direito(i);
            int maior = i;
            if ((esq < tamanho) and (heap[esq] > heap[i])){
                maior = esq;
            }

            if ((dir < tamanho) and (heap[dir] > heap[maior])){
                maior = dir;
            }

            if (maior != i){
                swap(heap[i], heap[maior]);
                corrigeDescendo(maior);
            }
        }; //heapify
    public:
        MaxHeap(int cap){
            capacidade = cap;
            heap = new dado[cap];
            tamanho = 0;
        };
        MaxHeap(dado vet[], int tam){
            capacidade = tam;
            heap = new dado[capacidade];
            /*
            for (int i = 0; i < tam; i++){
                heap[i] = vet[i];
            }
            */
            memcpy(heap,vet,tam * sizeof(dado));
            tamanho = tam;
            arruma();
        };
        ~MaxHeap(){
            delete[] heap;
        };
        void imprime(){
            for (int i = 0; i < tamanho; i++){
                cout << heap[i] << endl;
            }
        };
        dado espiaRaiz(){
            return heap[0];
        };
        dado retiraRaiz(){
            if (tamanho == 0){
                cerr << "Erro ao retirar a raiz" << endl;
                exit(EXIT_FAILURE);
            }
                dado aux = heap[0];
                swap(heap[0], heap[tamanho-1]);
                tamanho --;
                corrigeDescendo(0);
                return aux;
        };
        void insere(dado d){
            if (tamanho == capacidade){
                cerr << "Erro ao inserir" << endl;
                exit(EXIT_FAILURE);
            }
            heap[tamanho] = d;
        };
};

int main ()
{
    int tam = 13;
    dado vet[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
    
    MaxHeap *h = new MaxHeap(vet,tam);

    for (int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " ";
    }
    cout << endl;
    
    for (int i = 0; i < tam; i++){
        h->insere(vet[i]);
    }
    
    for (int i = 0; i < tam; i++){
        cout << h->retiraRaiz() << " ";
    }
    
    delete h;

    return 0;
}
