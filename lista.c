#include <stdio.h>
#include<stdlib.h>

typedef struct lista{
    int info;
    struct lista* prox;
}Lista;
typedef Lista * LLista;

LLista lst_cria();
LLista lst_insere(Lista* lst_atual, int valor);
void lst_imprime(LLista lst_atual);
int lst_vazia(LLista lst_atual);
LLista lst_busca(LLista lst_atual,int num);

int main()
{
    LLista prim= lst_cria();
    prim= lst_insere(prim,1);
    prim= lst_insere(prim,2);
    prim= lst_insere(prim,3);
    prim= lst_insere(prim,4);
    lst_imprime(prim);
    return 0;
}

LLista lst_cria(){
    return NULL; 
}

LLista lst_insere(Lista* lst_atual, int valor){
    LLista novo= (LLista) malloc (sizeof(Lista));
    novo->info=valor;
    novo->prox= lst_atual;// recebe um ponteiro para a cabeça da lista atual
    return novo;
}

void lst_imprime(LLista lst_atual){
    LLista p;
    p= lst_atual;
    /*if(p!=NULL)
        printf("Elemento: %d ",p->info);
    p= p->prox;
    if(p!=NULL)
        printf("Elemento: %d ",p->info);*/
    
    for(p=lst_atual;p!=NULL;p= p->prox){
        printf("Elemento: %d ",p->info);
        printf("\n");

    }

}
int lst_vazia(LLista lst_atual){
    return (lst_atual==NULL);
}

LLista lst_busca(LLista lst_atual,int num){
    LLista p;
    for(p= lst_atual;p!= NULL;p=p->prox){
        if(p->info == num)
            return p;
    }
    return NULL; // não achou o elemento procurado
}

