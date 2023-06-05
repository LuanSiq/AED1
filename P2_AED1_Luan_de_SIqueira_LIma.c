#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }

    return raiz;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirEmOrdem(raiz->esquerda);
    printf(" %d", raiz->valor);
    imprimirEmOrdem(raiz->direita);
}

void imprimirPreOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    printf(" %d", raiz->valor);
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

void imprimirPosOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf(" %d", raiz->valor);
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    int numCasos;
    scanf("%d", &numCasos);

    for (int i = 1; i <= numCasos; i++) {
        int numElementos;
        scanf("%d", &numElementos);

        No* raiz = NULL;

        for (int j = 0; j < numElementos; j++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserirNo(raiz, valor);
        }

        printf("Case %d:\n", i);
        printf("Pre.:");
        imprimirPreOrdem(raiz);
        printf("\n");
        printf("In..:");
        imprimirEmOrdem(raiz);
        printf("\n");
        printf("Post:");
        imprimirPosOrdem(raiz);
        printf("\n\n");
        liberarArvore(raiz);
    }

    return 0;
}