#include <stdio.h>
#include <stdlib.h>

struct item{
    int cod;
};
typedef struct item Item;

struct node{
    Item item;
    struct node *left;
    struct node *right;
};
typedef struct node Node;


Node* treeInicialize(){
    return NULL;
}

Item itemCreate(int cod){
    Item item;
    item.cod = cod;
    return item;
}

Node* treeInsert(Node* root, Item x){
    if(root==NULL){
        Node *aux = (Node*)malloc(sizeof(Node));
    // (*aux).item = x;
    // |__NULL__|__x__|__NULL__|
        aux->item = x;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else{
        if(x.cod > root->item.cod){
            root->right = treeInsert(root->right,x);
        }else{
            if(x.cod < root->item.cod){
                root->left = treeInsert(root->left,x);
            }
        }
    }
    
    return root;
}

void treePrint(Node* root){
    if(root != NULL){
        printf("%d ", root->item.cod);
        treePrint(root->left);
        treePrint(root->right);
    }
}

void treeFree(Node* root){
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
}

Node* treeSearch(Node* root, int cod){

    if(root != NULL){
        if(root->item.cod == cod)
            return root;
        else{
            if(cod > root->item.cod)
                return treeSearch(root->right, cod);
            else
                return treeSearch(root->left, cod);
        }
    }
    return NULL;
}

int main(){
    
    Node *root = treeInicialize();
    root = treeInsert(root,itemCreate(10));
    root = treeInsert(root,itemCreate(15));
    root = treeInsert(root,itemCreate(20));
    root = treeInsert(root,itemCreate(12));
    root = treeInsert(root,itemCreate(5));
    root = treeInsert(root,itemCreate(2));

    treePrint(root);

    Node* tmp = treeSearch(root,1);
    if(tmp==NULL)
        printf("\n>> ELEMENTO NÃO ENCONTRADO !");
    else
        printf("\n>> ELEMENTO ENCONTRADO !!");

    printf("\n");
    treeFree(root);
    return 0;
}