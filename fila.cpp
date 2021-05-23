/*
https://www.urionlinejudge.com.br/judge/pt/problems/view/1110
*/

#include <iostream>

using namespace std;

template <class T> class Fila {
private:

    template <class TT> class Celula {
    public:
        Celula<TT> *prox;
        TT valor;

        Celula(TT v) {
           this->valor=v;
           prox=nullptr;
        }
    };
    int tamanho;
    Celula<T> *inicio, *fim;
        void esvazia(Celula <T> *aux) {
        if(aux != nullptr) {
            esvazia(aux->prox);
            delete aux;
        }
    }

public:

    Fila() {
        inicio = nullptr;
        fim = nullptr;
        tamanho=0;
    }
    ~Fila() {
        Celula<T> *aux;
        while(inicio != nullptr) {
            aux = inicio;
            inicio = inicio->prox;
            delete aux;
        }
    }
    void esvazia() {
        esvazia(inicio);
        inicio=fim=nullptr;
        tamanho=0;
    }
    int getTamanho() {
        return tamanho;
    }
    bool inserir(const T &valor) {
        if(this->inicio == nullptr) {
            inicio = new Celula<T>(valor);
            fim = inicio;
        } else {
            fim->prox = new Celula<T> (valor);
            fim = fim->prox;
        }
        ++tamanho;
        return true;
    }
    bool excluir(void) {
       if(inicio == nullptr) {
          return false;
        } else {
            Celula<T>*aux = inicio;
            inicio = inicio->prox;
            if(inicio == nullptr) {
                fim=inicio;
            }
            delete aux;
            --tamanho;
            return true;
        }
    }
    void mostrar (){
        if(this->inicio == nullptr){
            cout << "<<nada>>";
        } else {
            cout << this->inicio->valor;
        }
        //cout<<endl;
    }
    int getInicio() {
        if(inicio == nullptr) {
            return -1;
        } else {
            return this->inicio->valor;
        }
    }
};

int main() {
    int n, i;
    cin >> n;
    while(n > 0) {
        Fila<int> fila;
        for(i = 1; i <= n; i++) {
            fila.inserir(i);
        }
        cout << "Discarded cards: ";
        while(fila.getTamanho() > 2) {
            fila.mostrar();
            cout << ", ";
            fila.excluir();
            fila.inserir(fila.getInicio());
            fila.excluir();
        }
        if(fila.getTamanho() == 2) {
            fila.mostrar();
            fila.excluir();
        }
        cout << endl;
        cout << "Remaining card: ";
        fila.mostrar();
        cout << endl;
        cin >> n;
    }

    return 0;
}