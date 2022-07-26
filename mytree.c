#include "mytree.h"

int main()
{
    printf("这是一个二叉树的测试程序！\n");
    int level = 1;
    BiTree T = NULL;
    createBiTree(&T);
    printf("test!\n");
    PreOrderTravers(T,level);
 
    return 0;
}

/* 创建一棵二叉树 */
void createBiTree(BiTree *T)
{
    char c;
    //Aprintf("请输入要存储的数据！\n");
    scanf("%c",&c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else{
        *T = (BitNode*)malloc(sizeof(BitNode));
        (*T)->data = c;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
}
/* 访问二叉树结点的具体操作 */
void visit(char c,int level)
{
    printf("%c位于第%d层\n",c,level);
}

/* 遍历二叉树 */
void PreOrderTravers(BiTree T,int level)
{
    //printf("遍历函数测试！\n");
    if(T)
    {
        printf("data:%c",T->data);
        visit(T->data,level);
        PreOrderTravers(T->lchild,level+1);
        PreOrderTravers(T->rchild,level+1);
    }
}
/* 线索二叉树 */
/* 创建一棵二叉树，约定用户遵照前序遍历的方式
    输入数据
 */
void creatBithrTree(BiThrTree *T)
{
    char c;
    scanf("%c",&c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        
    }
}