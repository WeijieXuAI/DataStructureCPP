#include <iostream>
#include <stdlib.h>


#define OK 1
#define ERROR 0

typedef int Status; //status是函数类型

typedef int ElemType; 

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node, *linklist;
//结点与头指针

Status initList(linklist& L){
    L = (linklist) malloc(sizeof(Node));
    L->next = NULL;
    return OK;
}

//判断是否为空
int isEmpty(linklist L){
    if (L->next)
        return 0;
    else
        return 1;
}

//销毁
Status Destroy(linklist& L){
    Node* p;
    while(L){
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

//清空链表
Status Clear(linklist& L){
    Node* p;
    Node* q;
    p = L->next;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;
    return OK;
}

//求长度
int getLength(linklist L){
    linklist p;
    p = L->next;
    int i = 0;
    while(p){
        i ++;
        p = p->next;
    }
    return i;
}

//取第i个结点
Status getItem(linklist L, int i, ElemType& e){
    Node* p;
    p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j ++;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

//按值查找
Node* locateItem(linklist L, ElemType e){
    Node* p;
    p = L->next;
    while(p && p->data != e){
        p = p->next;
    }
    return p;
}

//按值查找返回位置序号
int locateItemIndex(linklist L, ElemType e){
    Node* p = L->next;
    int j = 1;
    while(p && p->data !=e){
        p = p->next;
        j ++;
    }
    if (p){
        return j;
    }
    else{
        return 0;
    }
}

//插入结点
Status insertList(linklist& L, int i, ElemType e){
    Node* p;
    p = L;
    int j = 0;
    while (p && j < i -1){
        p = p->next;
        j ++;
    }
    if (!p || j > i - 1)
        return ERROR;
    Node* s = (linklist) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除第i个结点
Status deleteList(linklist& L, int i, ElemType& e){
    Node* p = L;
    int j = 0;
    while(p->next && j < i - 1){
        p = p->next;
        ++ j;
    }
    if(!(p->next) || j > i -1) //删除位置不合理
        return ERROR;
    Node* q = p->next; 
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

//头插法建立链表
//O(n)
void createListHead(linklist& L, int n){
    L = (linklist) malloc(sizeof(Node));
    L->next = NULL;
    for (int i = n; i > 0; i --){
        Node* p = (linklist) malloc(sizeof(Node));
        std::cin >> p->data;
        p->next = L->next; //插入到表头
        L->next = p;
    }
}

//尾插法
//O(n)
void createListTail(linklist& L, int n){
    L = (linklist) malloc(sizeof(Node));
    L->next = NULL;
    Node* r = L;
    for (int i = 1; i <= n; i ++){
        Node* p = (linklist) malloc(sizeof(Node));
        std::cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void output(linklist L){
    Node* p;
    p = L->next;
    while(p){
        std::cout << p->data << "," ;
        p = p->next;
    }
    std::cout << std::endl;
}

int main(){
    std::cout << "hello world" << std::endl;
    std::cout << std::endl;
    linklist L;
    linklist L2;
    std::cout << "初始化链表" << std::endl;
    initList(L);
    initList(L2);
    std::cout << "判断是否为空" << std::endl;
    std::cout << isEmpty(L) << std::endl;
    std::cout << isEmpty(L2) << std::endl;
    std::cout << std::endl;

    std::cout << "尾插法建立链表" << std::endl;
    createListTail(L2, 5);
    std::cout << "判断是否为空" << std::endl;
    std::cout << isEmpty(L2) << std::endl;
    output(L2);
    std::cout << std::endl;

    std::cout << "头插法建立链表" << std::endl;
    createListHead(L, 5);
    std::cout << "判断是否为空" << std::endl;
    std::cout << isEmpty(L) << std::endl;
    output(L);
    std::cout << "当前链表长度为: " << getLength(L) << std::endl;
    std::cout << std::endl;
    std::cout << "尝试插入一个值，第四个位置" << std::endl;
    insertList(L, 4, 10);
    output(L);
    std::cout << "当前链表长度为: " << getLength(L) << std::endl;
    std::cout << std::endl;
    ElemType e;
    std::cout << "获取第5个位置的结点" << std::endl;
    getItem(L, 5, e);
    std::cout << "获得的结点为: " << e << std::endl;
    output(L);
    std::cout << std::endl;
    std::cout << "尝试删除一个值,第三个位置" << std::endl;
    deleteList(L, 3, e);
    std::cout << "删除的结点为: " << e << std::endl;
    output(L);
    std::cout << std::endl;
    std::cout << "按值查找" << std::endl;
    Node* p;
    p = locateItem(L, 1);
    std::cout << "获得的结点地址: " << p  << " 结点的值为 " << p->data << std::endl; 
    std::cout << std::endl;
    return 0;
}
