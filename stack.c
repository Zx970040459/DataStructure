#include "stack.h"

int main()
{
    char input[100];//定义数组输入缓存器
    while(0)
    {
        char string[100];  //定义栈 ，栈容量为100
        printf("请输入待检查字符串:\n");
        scanf("%s",&input);       //终端输入数据
        int top = -1;               //定义栈顶指针
        int length = strlen(input); //定义输入字符串长度:注：strlen()是函数，返回的长度不包含'\0'
        //sizeof是运算符，它的结果在编译器编译时就已经计算出来了
        for(int i = 0;i<length;i++) //实际上是数组下标的移动
        {
            if((input[i]=='(')||(input[i]=='[')||(input[i]=='{'))
            {
                top++; //数组下标先自增的原因：
                string[top]=input[i]; //压栈操作
            }
            if((input[i]==')'&&string[top]=='(') || (input[i]==']'&&string[top]=='[') ||(input[i]=='}'&&string[top]=='{'))
            {
                top--;
            }
        }
        if(top == -1)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
        //当前算法的问题：如果在所有左括号均出栈后，再次输入的是右括号，无法入栈；
}
    // printf("检查结束，请重新运行！\n");
    return 0;
    // /***数组栈测试***/
    // Stack_1_t stack1;
    // int x; //用于读取栈顶和出栈的元素值
    // Init_Stack_1(&stack1);

    // is_Empty_Stack_1(&stack1);
    // // get_Top_Stack_1(&stack1,&x);
    // push_Stack_1(&stack1,10);
    // push_Stack_1(&stack1,9);
    // push_Stack_1(&stack1,8);
    // push_Stack_1(&stack1,7);
    // push_Stack_1(&stack1,6);
    // int count = stack1.pTop;
    // for(int i = 0; i <= count ;i++)
    // {
    //     printf("i = %d \n",i);
    //     get_Top_Stack_1(&stack1,&x);
    //     printf("Get Top Data is:%d\n",x);
    //     pop_Stack_1(&stack1,&x);
    //     printf("Get Top Data is:%d\n",x);
    // }


    /***链栈测试***/
    // Stack_t *myStack = Init_Stack();
    // push_Stack(myStack,99);
    // push_Stack(myStack,88);
    // push_Stack(myStack,77);
    // while(isEmpty_Stack(myStack))
    // {
    //     printf("栈中元素为：\t%d\n",top_Stack(myStack));
    //     pop_Stack(myStack);
    // }
   
    // return 0;
}
/* 创建结点 */
LinkList *creatNode(int data)
{
    LinkList *newNode =(LinkList*)malloc(sizeof(LinkList));
    newNode->data = -1;
    newNode->next = NULL;
    return newNode;  
}
/* 栈初始化 */
Stack_t *Init_Stack()
{
    Stack_t *s = (Stack_t*)malloc(sizeof(Stack_t)); //动态内存申请
    s->stack_Top = NULL;
    s->stack_Size = 0;
    return s;
}

/* 入栈操作 */
void push_Stack(Stack_t *myStack,int data)
{
    LinkList *newNode = creatNode(data);
    newNode->data = data;
    newNode->next = myStack->stack_Top;
    myStack->stack_Top = newNode;
    myStack->stack_Size++;
}
/* 获取栈顶元素 */
int top_Stack(Stack_t *myStack)
{
    if(myStack->stack_Size == 0)
    {
        printf("栈为空，无法获取栈顶元素！\n");
        system("pause"); //防止闪屏
        return myStack->stack_Size;
    }
    return myStack->stack_Top->data;
}
/* 出栈操作 */
void pop_Stack(Stack_t *myStack)
{
    if(myStack->stack_Size == 0)
    {
        printf("栈为空，无法执行出栈操作！\n");
    }
    else
    {
        Stack_t *pNext = myStack->stack_Top->next;
        free(myStack->stack_Top);
        myStack->stack_Top = pNext;
        myStack->stack_Size --;
    }
}
/* 判断栈是否为空 */
int isEmpty_Stack(Stack_t *myStruct)
{
    if(myStruct->stack_Size == 0)return 0;
    else return 1;
}

/* 读栈顶元素，如若栈非空，返回栈顶元素 */
Stack_t get_Top(Stack_t *myStack)
{
    
}
/* 释放栈，并释放栈占用的空间 */
void DestroyStack(Stack_t *myStack)
{

}
/******************************顺序栈**********************************/
/* 初始化栈 */
bool Init_Stack_1(Stack_1_t *stack)
{
    stack->pTop = -1; //栈初始化,栈顶指针-1，表示栈空
    printf("栈初始化完成！\n");
    return true;
}
/* 判断栈是否为空 */
bool is_Empty_Stack_1(Stack_1_t *stack)
{
    if(stack->pTop == -1)
    {
        printf("栈为空！\n");
        return true; 
    }
    else
    {
        printf("栈非空！\n");
        return false;
    }
}
/* 入栈 */
bool push_Stack_1(Stack_1_t *stack,int data)
{
    if(stack->pTop == STACK_MAX_SIZE -1)
    {
        /* 栈满，报错 */
        printf("栈满，无法入栈!\n");
        return false;
    }
    stack->data[++stack->pTop] = data; //指针先加1再入栈
    return true;
}
/* 出栈 */
bool pop_Stack_1(Stack_1_t *stack,int *data)
{
    if(stack->pTop == -1)
    {
        printf("栈空，无法出栈\n");
        return false;
    }
    *data = stack->data[stack->pTop --];
    printf("出栈完了！\n");
    return true;
}
/* 读取栈顶元素 */
bool get_Top_Stack_1(Stack_1_t *stack,int *data)
{
    if(stack->pTop == -1)
    {
        printf("栈空，无法读取栈顶元素！\n");
        return false;
    }
    *data = stack->data[stack->pTop];
    return true;
}

bool BracketsCheck(char *string)
{
    //初始化栈
    int top = -1; //定义栈顶指针
    char stack[100]; //定义栈容器
    int i = 0; //定义数组下标
    while(string[i] != '\0')
    {
        switch (string[i])
        {
        case '(':
            /* 入栈操作 */
            top++;
            stack[top] = string[i];
            break;
        case '[':
            /* 入栈操作 */
            top++;
            stack[top] = string[i];
            break;
        case '{':
            /* 入栈操作 */
            top++;
            stack[top] = string[i];
            break;
        case ')':
            /* 检查栈顶元素是否与之匹配 */
            if(stack[top]== '(')
                top--;
            break;
        case ']':
            /* 检查栈顶元素是否与之匹配 */
            stack[top] = stack[top--];
            if(stack[top]!='(')return false;
            break;
        case '}':
            /* 检查栈顶元素是否与之匹配 */
            stack[top] = stack[top--];
            if(stack[top]!='(')return false;
            break;
        default:
            break;
        } //switch
        i++; //数组下标自增
    }//while
    if(top != -1)
    {
        printf("括号不匹配！\n");
        return false;
    }
    else{
        printf("括号匹配！\n");
        return true;
    }
}

int *twoSUM(int *nums,int numSize,int target,int *returnSize)
{
    int a,b;//定义两个变量，用于求和的两个变量
    int *result = NULL;//初始化返回值指针
    *returnSize = 2; //初始化返回数组容量
    for(a = 0;a<numSize-1;a++)
    {
        for(b = a+1;b<numSize;b++)
        {
            if(nums[a]+nums[b] == target)
            {
                result = (int*)malloc(sizeof(int)*2);
                result[0] = a;
                result[1] = b;
                return result;
            }
        }
    }
    return result;
}