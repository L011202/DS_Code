#define _CRT_SECURE_NO_DEPRECATE    
/*    单链表	*/
/*    带头结点    */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
/*   结构体    */
typedef struct LNode {		//节点结构体
	ElemType data;			//数据域
	struct LNode* next;		//指针域
}LNode,*LinkList;
/*   LNode为重定义后的名字     */
/*   LinkList为struct LNode指针 -> 等价于 -> typedef struct LNode * LinkList;*/

/*   初始化一个空表    */
bool InitList(LinkList& L) {		//使用&是因为需要把初始化的空表返回
	L = (LNode*)malloc(sizeof(LNode));		//分配一个头结点
	if (L == NULL) {
		return false;				//分配失败返回false
	}
	L->next = NULL;					//只有一个头结点，头节点之后并没有任何结点
	return true;
}

bool EmptyList(LinkList	L) {		//判空函数,若为空表，则返回true，反之则返回false
	return (L->next == NULL);
}

/*    在第i个位置插入元素e    */
bool InsertList(LinkList& L, int i, ElemType e) {		//声明一个单链表，位序，e为插入的数据
	if (i < 1) {										//判断位序是否合法，不合法返回false
		return false;
	}
	LNode* p;							//创建一个结点，指向当前扫描到那个结点
	int j = 0;							//p指向的是第几个结点
	p = L;								//p指向头结点
	while (p != NULL && j < i - 1) {	//找到插入位置前的那个结点
		p = p->next;
		j++;
	}
	if (p == NULL) {					//判断i值是否合法
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));		//创建一个新的结点
	new_node->next = p->next;			//新结点的next指针指向找到的插入位置前结点的next指向的结点
	p->next = new_node;					//插入位置前的那个结点的next指针指向新节点
	new_node->data = e;					//把e赋给新结点的数据域
	return true;						//插入成功则返回true
}

/*    在指定结点后插入新的节点    */
bool InsertNextLocate(LNode* p, ElemType e) {		//在指定结点后插入新的结点
	if (p == NULL) {								//判断结点的合法性，不合法直接返回false
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));	//创建一个新的结点
	if (new_node == NULL) {					//内存分配失败的情况，返回false
		return false;
	}
	new_node->data = e;				//将e赋给新节点的数据域
	new_node->next = p->next;		//新节点的next指针指向p的next指向的结点
	p->next = new_node;				//p的next指针指向新结点
	return true;					//插入成功，返回true
	}
/*    前插操作，给定结点在该结点之前插入元素e    */
bool InsertPriorNode(LNode* p, ElemType e) {		//指定结点，要插入的元素e
	if (p == NULL) {								//判断p的合法性，如果p不合法，返回false
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));	//创建一个新的结点
	if (new_node == NULL) {					//内存不足，分配失败的情况下，返回false
		return false;
	}
	/*    我感觉下面这句代码可以不要    */
	ElemType temp = p->data;			//临时变量
	new_node->data = p->data;		//数据域
	new_node->next = p->next;		//指针域
	p->next = new_node;				//修改p的next指向的结点
	p->data = e;					//修改p的数据域
	return true;					//插入成功，返回true
}
/*    按位序删除    */
bool DeleteList(LinkList& L, int i, ElemType &e) {			//引用单链表，位序，需要返回的e
	if (i < 1) {
		return false;
	}
	LNode* p;				//定义一个结点，这个结点是当前扫描到哪的判断结点
	int j = 0;				//从头结点开始扫描
	p = L;					//指向头结点。头结点是第0个结点，并不存储数据
	while (p != NULL && j < i - 1) {		//while循环找第i-1个结点
		p = p->next;
		j++;	
	}
	if (p == NULL) {		//i的值不合法，返回false
		return false;
	}
	if (p->next == NULL) {	//如果第i-1个结点之后没有结点了，返回false
		return false;
	}
	LNode* q = p->next;		//创建一个新的结点，并使他等于要被删除的结点
	e = q->data;			//把要被删除的结点的数据域给e
	p->next = q->next;		//修改p的next指针为q指向的下一个结点
	free(q);				//释放q结点
	return true;			//如果删除成功，返回true
}
/*    删除指定结点    */
bool DeleteList_Node(LNode* p) {			//指定结点
	if (p == NULL) {						//判断结点的合法性，不合法直接返回false
		return false;
	}		
	LNode* q = p->next;						//创建一个新的结点，并把p的后继结点复制给他
	p->data = p->next->data;				//p结点的数据域等于p的后继结点的后继节点的数据域
	p->next = q->next;						//修改p的指针
	free(q);								//释放q结点
	return true;							//删除成功，返回true
}
/*    按位查找，返回第i个元素    */
LNode* GetElem(LinkList L, int i) {			//单链表，位序
	if (i < 1) {							//判断位序的合法性，不合法直接返回NULL
		return NULL;
	}
	LNode* p;								//创建一个结点，指向当前扫描到那个结点
	int j = 0;								//当亲p扫描到第几个结点
	p = L;									//L指向头结点，头结点不不存储数据
	while (p != NULL && j < i) {			//循环找第i个结点
		p = p->next;						//p的next修改
		j++;
	}
	return p;								//找到第i个结点，并把第i个结点返回
}
/*    按值查找，找到数据域为e的结点并返回结点的指针    */
LNode* LocateElem(LinkList L, ElemType e) {			//单链表，需要对比的数据e
	LNode* p = L->next;								//从第一个结点开始对比
	while (p != NULL && p->data != e)				//循环找到结点数据域为e的结点
	{
		p = p->next;								//p后移
	}
	return p;										//返回结点指针p
}
/*    求表的长度    */
int Length(LinkList L) { 
	int ret = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		ret++;
	}
	return ret;
}
/*    尾插法建立一个单链表    */
LinkList List_EndInsert(LinkList& L) {			//引用单链表
	ElemType x = 0;								//根据元素类型修改下面的判断
	L = (LNode*)malloc(sizeof(LNode));			//建立头结点
	LNode* s = L;								//创建结点指向头结点
	LNode* r = L;								//尾指针，初始时指向头结点
	scanf("%d", &x);							//输入数值
	while (x != 9999) {							//输入9999退出
		s = (LNode*)malloc(sizeof(LNode));		
		s->data = x;							//s结点的数据域被赋值
		r->next = s;							//修改尾指针的指针域,指向最新创建的结点
		r = s;									//修改尾节点
		scanf("%d", &x);						//输入数据，输入9999退出
	}	
	r->next = NULL;								//修改尾指针的指针域
	return L;									//返回单链表
}
/*     头插法创建一个单链表    */
LinkList Head_Insert(LinkList& L) {				//引用单链表
	LNode* s;									//创建一个结点	
	int x = 0;
	L = (LNode*)malloc(sizeof(LNode));			//头结点的创建
	L->next = NULL;								//头结点的指针修改
	scanf("%d", &x);							//输入插入数据
	while (x != 9999) {							//默认输入9999退出头插结点
		//LNode* s;
		s = (LNode*)malloc(sizeof(LNode));		//新结点的创建
		s->data = x;							//修改新结点的数据域
		s->next = L->next;						//修改新结点的指针域
		L->next = s;							//修改头结点的指针域
		scanf("%d", &x);						//输入数据，若输入的不是9999则继续插入结点，反之则退出插入结点
	}
	return L;									//把插入后的结点返回
}
/*    主函数    */
int main()
{
	//todo;
	return 0;
}