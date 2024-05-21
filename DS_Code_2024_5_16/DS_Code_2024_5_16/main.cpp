#define _CRT_SECURE_NO_DEPRECATE    
/*    单链表	*/
/*    不带头节点类型	*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
/*    节点结构体	*/
typedef struct LNode{			//定义单链表结构体类型
	ElemType data;				//数据域
	struct LNode* next;			//指针域
}LNode,*LinkList;				
/*    LNode为结构体重命名	*/
/*    LinkList为struct LNode型指针	->	等价于 ->	typedef struct LNode *LinkList;*/

/*    初始化一个空的链表	*/
bool InitList(LinkList &L){			//初始化函数
	L = NULL;			//空表，这时不包含任何元素
	return true;
}

bool EmptyList(LinkList L) {		//判空函数,空则返回true，反之返回false 
	return (L == NULL);
}
/*    按位置插入    */
/*    没有头结点，需要对插入第一个位置进行特殊的操作    */
bool InsertList(LinkList& L, int i, ElemType e) {		//引用一个单链表
	if (i < 1) {								//判断位序是否合法，不合法返回false
		return false;
	}
	if (i == 1) {				//判断是否是第一个结点，是第一个结点的话创建一个新节点，并把单链表指向这个结点
		LNode* new_node = (LNode*)malloc(sizeof(LNode));		//创建一个新节点
		new_node->next = L;							
		L = new_node;			//头指针指向第一个结点
		new_node->data = e;		//把e的值赋给新结点的数据域
		return true;			//插入成功返回true
	}
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i + 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));
	new_node->next = p->next;
	p->next = new_node;
	new_node->data = e;
	return true;
}
/*    求长度，无头结点    */
int Length(LinkList L) {				//非引用型
	int ret = 0;	
	LNode* p = L;						//结点指向表头		
	//if (p == NULL) {					//没有任何结点，则ret为0
	//	ret = 0;
	//}
	//else {
	while (p != NULL) {			//遍历链表，若是
		p = p->next;
		ret++;
	}
	//}
	return ret;
}
/*    头插法建立一个单链表    */
LinkList Head_Insert(LinkList& L, ElemType x) {				//引用单链表，需要插入的数据
	LNode* new_Node = (LNode*)malloc(sizeof(LNode));		//创建一个新结点
	new_Node->data = x;										//把要插入的数据赋给新结点的数据域
	new_Node->next = L;										//修改新节点的指针域
	L = new_Node;											//修改头结点
	return L;												//返回单链表
}
/*    尾插法创建单链表    */
LinkList end_Insert(LinkList& L,ElemType x) {				//引用，需要尾插的数据
	LNode* new_node = (LNode*)malloc(sizeof(LNode));		//创建一个新的结点，防止是空链表
	new_node->data = x;										//把x的值赋给新结点的数据域
	new_node->next = NULL;									//由于是尾插法，所以新节点的指针域直接设为NULL
	LNode* p = L;											//创建一个结点指向头指针
	if (p == NULL){											//链表为空的处理，直接将新结点设为头结点
		L = new_node;
	}
	else {													//链表不为空，需要遍历这个链表，找到最后一结点
		while (p->next != NULL){
			p = p->next;
		}
		p->next = new_node;									//修改最后的结点的指针域
	}
	return L;												//返回单链表
}
void printf_List(LinkList L) {
	//LNode* p = (LNode*)malloc(sizeof(LNode));
	LNode* p = L;
	while (p != NULL) {
		printf("%d->", p->data);							//根据宏定义的数据类型进行修改
		p = p->next;
	}
	printf("NULL\n");										//数据打印完成，输出NULL并换行
}
int main()
{
	int len = 0;
	LinkList L;			//声明一个指向单链表的指针
	InitList(L);		//初始化一个空表
	//Head_Insert(L, 3);
	end_Insert(L, 3);
	printf_List(L);
	len = Length(L);
	printf("%d\n", len);
	return 0;
}