#include <stdio.h>
//#define NIL NULL


typedef int TChave;
typedef struct{
    TChave Chave;
}TItem;

typedef struct SNo *TArvBin;
typedef struct SNo{
    TItem Item;
    TArvBin Esq, Dir;
    int cor; //cor: 0, negro; 1, rubro
}TNo;

TArvBin TArvBin_Inicia();
TArvBin TArvBin_CriaNo(TArvBin Esq, TArvBin Dir, TItem x);

TArvBin TArvBin_Pesquisa(TArvBin *No, TChave c);
int TArvBin_Insere(TArvBin *No, TItem x);
int TArvBin_Retira(TArvBin *No, TChave c);
void TArvBin_Imprime(TArvBin Arv);
//------------------------------------------------------------------
TArvBin TArvBin_Inicia(){
    return NULL;
}
TArvBin TArvBin_CriaNo(TArvBin Esq, TArvBin Dir, TItem x){
    TArvBin No = (TNo*)malloc(sizeof(TNo));
    No->Esq = Esq;
    No->Dir = Dir;
    No->Item = x;
    No->cor = 1;

    return No;
}
int TArvBin_Insere(TArvBin *No, TItem x){
    if((*No) != NULL){
        if((*No)->Item.Chave < x.Chave)
            TArvBin_Insere(&(*No)->Dir, x);
        else if((*No)->Item.Chave > x.Chave)
            TArvBin_Insere(&(*No)->Esq, x);
        else return 0;
    }
    else{
        (*No) = TArvBin_CriaNo(TArvBin_Inicia,TArvBin_Inicia, x);
        return 1;
    }
}
void TArvBin_Imprime(TArvBin Arv){
    if(Arv != NULL){
        TArvBin_Imprime(Arv->Esq);
        printf("%d ", Arv->Item.Chave);
        TArvBin_Imprime(Arv->Dir);
    }
}


int main(){
    TArvBin Arvore;
    Arvore = NULL;

    int qtd, i;
    scanf("%d", &qtd);

    TItem x;
    for(i=0;i<qtd;i++){
        scanf("%d", &x.Chave);
        TArvBin_Insere(Arvore, x);
    }
    TArvBin_Imprime(Arvore);
    return 0;
}
