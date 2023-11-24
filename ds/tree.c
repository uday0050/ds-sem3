#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *lchild;
    struct node *rchild;
};
struct node *create(int val){
    int x;
    if(val!=-1){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->value=val;
        printf("Enter the lchild of %d ",val);
        scanf("%d",&x);
        temp->lchild=create(x);
        printf("Enter the rchild of %d ",val);
        scanf("%d",&x);
        temp->rchild=create(x);
        return temp;
    }
    return NULL;//for base case -1 when no child
}
void inorder(struct node *root){
    if(root){
        inorder(root->lchild);
        printf("%d ",root->value);
        inorder(root->rchild);
    }
}
int main(){
    int item;
    struct node *root=NULL;
    printf("Creating the tree[Enter -1 to exit]");
    scanf("%d",&item);
    root=create(item);

    printf("Inorder traversal is:");
    inorder(root);
    return 0;
}