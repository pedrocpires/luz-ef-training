#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node *esq;
    struct node *dir;
    struct node *pai;
} Node;

Node *esquerda(Node *raiz)
{
    Node *aux = raiz;
    if (aux->esq != NULL)
        aux = aux->esq;
    else
        return NULL;
    return aux;
}

Node *direita(Node *raiz)
{
    Node *aux = raiz;
    if (aux->dir != NULL)
        aux = aux->dir;
    else
        return NULL;
    return aux;
}

Node *pai(Node *raiz)
{
    Node *aux = raiz;
    if (aux->pai != NULL)
        aux = aux->pai;
    else
        return NULL;
    return aux;
}

Node *irmao(Node *raiz)
{
    Node *aux = raiz;

    if (aux == aux->pai->esq)
    {
        if (aux->pai->dir != NULL)
        {
            aux = aux->pai->dir;
            return aux;
        }
        else
        {
            return NULL;
        }
    }

    if (aux == aux->pai->dir)
    {
        if (aux->pai->esq != NULL)
        {
            aux = aux->pai->esq;
            return aux;
        }
        else
        {
            return NULL;
        }
    }
    return aux;
}

Node *criaAB(int dado)
{
    // Aloca memória para o novo nó.
    Node *node = (Node *)malloc(sizeof(Node));
    // Define o dado do nó.
    node->dado = dado;
    // Inicializa os filhos da esquerda e direita e o pai como NULL.
    node->esq = NULL;
    node->dir = NULL;
    node->pai = NULL;
    return node;
}

int filhoEsq(Node *raiz, int dado)
{
    Node *node = criaAB(dado);
    if (raiz->esq == NULL)
    {
        raiz->esq = node;
        raiz->esq->pai = raiz;
        return 1;
    }
    else
    {
        return 0;
    }
}

int filhoDir(Node *raiz, int dado)
{
    Node *node = criaAB(dado);
    if (raiz->dir == NULL)
    {
        raiz->dir = node;
        raiz->dir->pai = raiz;
        return 1;
    }
    else
    {
        return 0;
    }
}

void pre_ordem(Node *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    printf("%d\n", raiz->dado);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}

void em_ordem(Node *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    pre_ordem(raiz->esq);
    printf("%d\n", raiz->dado);
    pre_ordem(raiz->dir);
}

void pos_ordem(Node *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
    printf("%d\n", raiz->dado);
}

int buscaAB(Node *raiz, int dado)
{
    if (raiz->dado == dado)
        return 1;
    else
    {
        if (dado > raiz->dado)
            raiz = direita(raiz);
        else
            raiz = esquerda(raiz);

        if (raiz == NULL)
            return 0;
        buscaAB(raiz, dado);
    }
}

int insereAB(Node *raiz, int dado)
{
    if (raiz->dado == dado)
    {
        return 0;
    }
    else
    {
        if (dado > raiz->dado)
        {
            if (direita(raiz) != NULL)
            {
                raiz = direita(raiz);
                insereAB(raiz, dado);
            }
            else
            {
                filhoDir(raiz, dado);
                return 1;
            }
        }
        else
        {
            if (esquerda(raiz) != NULL)
            {
                raiz = esquerda(raiz);
                insereAB(raiz, dado);
            }
            else
            {
                filhoEsq(raiz, dado);
                return 1;
            }
        }
    }
}

int removeAB(Node *raiz, int dado)
{
    Node *pai = raiz;

    while (raiz != NULL && raiz->dado != dado)
    {
        pai = raiz;
        if (dado > raiz->dado)
            raiz = direita(raiz);
        else
            raiz = esquerda(raiz);
    }

    if (raiz != NULL)
    {
        // Se tiver duas subárvores.
        if (esquerda(raiz) != NULL && direita(raiz) != NULL)
        {
            Node *aux = raiz;
            pai = raiz;
            raiz = direita(raiz);
            while (esquerda(raiz) != NULL)
            {
                pai = raiz;
                raiz = esquerda(raiz);
            }
            aux->dado = raiz->dado;
        }
        //Se tiver uma subárvore à esquerda.
        if (esquerda(raiz) == NULL && direita(raiz) != NULL)
        {
            if (pai->esq == raiz)
                pai->esq = direita(raiz);
            else
                pai->dir = direita(raiz);
        }
        //Se tiver uma subárvore à direita.
        else if (esquerda(raiz) != NULL && direita(raiz) == NULL)
        {
            if (pai->esq == raiz)
                pai->esq = esquerda(raiz);
            else
                pai->dir = esquerda(raiz);
        }
        //Se for uma folha.
        else if (esquerda(raiz) == NULL && direita(raiz) == NULL)
        {
            if (pai->esq == raiz)
                pai->esq = NULL;
            else
                pai->dir = NULL;
        }
        free(raiz);
    }
}
