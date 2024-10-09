#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int info;
    struct tree *l,*r;
}*Tree,TreeSize;

Tree binarySearchTree(int v[],int n){
    int i;
    Tree r = malloc(sizeof(TreeSize));
    r->info= v[0];
    r->l = NULL;
    r->r=NULL;

    for(i = 1 ; i < n; i++){
        Tree new = malloc(sizeof(TreeSize));
        new->info = v[i];
        new->l = NULL;
        new->r = NULL;

        Tree p=r;
        Tree ant = r;
        while(p){
            ant = p;
            if(new->info < p->info){
                p = p->l;
            }
            else{
                p = p->r;
            }

        }
        
            if(v[i] < ant->info)
                ant->l = new;
            else    
                ant->r = new;
    }
    return r;
}


void inOrderBrowsing(Tree t){
    if(!t) return;
    inOrderBrowsing(t->l);
    printf("%d ",t->info);
    inOrderBrowsing(t->r);
}

void postOrderBrowsing(Tree t){
    if(!t) return;
    postOrderBrowsing(t->l);
    postOrderBrowsing(t->r);
    printf("%d ",t->info);
}

void preOrderBrowsing(Tree t){
    if(!t) return;
    printf("%d ",t->info);
    preOrderBrowsing(t->l);
    preOrderBrowsing(t->r);
}

int isComplete(Tree t){
    if(t == NULL)
        return 1;
    if((t->l == NULL && t->r != NULL) ||(t->l != NULL && t->r == NULL))
        return 0;
   return  isComplete(t->l) &&isComplete(t->r);

    return 1;
}

int main(){
    int v[]={15,7,2,10,8,25,27};
    int n = 7;
    Tree t;
    t = binarySearchTree(v, n);
    inOrderBrowsing(t);

}