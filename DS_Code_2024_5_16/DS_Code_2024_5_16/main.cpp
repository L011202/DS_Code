#define _CRT_SECURE_NO_DEPRECATE    
/*    ������	*/
/*    ����ͷ�ڵ�����	*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
/*    �ڵ�ṹ��	*/
typedef struct LNode{			//���嵥����ṹ������
	ElemType data;				//������
	struct LNode* next;			//ָ����
}LNode,*LinkList;				
/*    LNodeΪ�ṹ��������	*/
/*    LinkListΪstruct LNode��ָ��	->	�ȼ��� ->	typedef struct LNode *LinkList;*/

/*    ��ʼ��һ���յ�����	*/
bool InitList(LinkList &L){			//��ʼ������
	L = NULL;			//�ձ���ʱ�������κ�Ԫ��
	return true;
}

bool EmptyList(LinkList L) {		//�пպ���,���򷵻�true����֮����false 
	return (L == NULL);
}
/*    ��λ�ò���    */
/*    û��ͷ��㣬��Ҫ�Բ����һ��λ�ý�������Ĳ���    */
bool InsertList(LinkList& L, int i, ElemType e) {		//����һ��������
	if (i < 1) {								//�ж�λ���Ƿ�Ϸ������Ϸ�����false
		return false;
	}
	if (i == 1) {				//�ж��Ƿ��ǵ�һ����㣬�ǵ�һ�����Ļ�����һ���½ڵ㣬���ѵ�����ָ��������
		LNode* new_node = (LNode*)malloc(sizeof(LNode));		//����һ���½ڵ�
		new_node->next = L;							
		L = new_node;			//ͷָ��ָ���һ�����
		new_node->data = e;		//��e��ֵ�����½���������
		return true;			//����ɹ�����true
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
/*    �󳤶ȣ���ͷ���    */
int Length(LinkList L) {				//��������
	int ret = 0;	
	LNode* p = L;						//���ָ���ͷ		
	//if (p == NULL) {					//û���κν�㣬��retΪ0
	//	ret = 0;
	//}
	//else {
	while (p != NULL) {			//������������
		p = p->next;
		ret++;
	}
	//}
	return ret;
}
/*    ͷ�巨����һ��������    */
LinkList Head_Insert(LinkList& L, ElemType x) {				//���õ�������Ҫ���������
	LNode* new_Node = (LNode*)malloc(sizeof(LNode));		//����һ���½��
	new_Node->data = x;										//��Ҫ��������ݸ����½���������
	new_Node->next = L;										//�޸��½ڵ��ָ����
	L = new_Node;											//�޸�ͷ���
	return L;												//���ص�����
}
/*    β�巨����������    */
LinkList end_Insert(LinkList& L,ElemType x) {				//���ã���Ҫβ�������
	LNode* new_node = (LNode*)malloc(sizeof(LNode));		//����һ���µĽ�㣬��ֹ�ǿ�����
	new_node->data = x;										//��x��ֵ�����½���������
	new_node->next = NULL;									//������β�巨�������½ڵ��ָ����ֱ����ΪNULL
	LNode* p = L;											//����һ�����ָ��ͷָ��
	if (p == NULL){											//����Ϊ�յĴ���ֱ�ӽ��½����Ϊͷ���
		L = new_node;
	}
	else {													//����Ϊ�գ���Ҫ������������ҵ����һ���
		while (p->next != NULL){
			p = p->next;
		}
		p->next = new_node;									//�޸����Ľ���ָ����
	}
	return L;												//���ص�����
}
void printf_List(LinkList L) {
	//LNode* p = (LNode*)malloc(sizeof(LNode));
	LNode* p = L;
	while (p != NULL) {
		printf("%d->", p->data);							//���ݺ궨����������ͽ����޸�
		p = p->next;
	}
	printf("NULL\n");										//���ݴ�ӡ��ɣ����NULL������
}
int main()
{
	int len = 0;
	LinkList L;			//����һ��ָ�������ָ��
	InitList(L);		//��ʼ��һ���ձ�
	//Head_Insert(L, 3);
	end_Insert(L, 3);
	printf_List(L);
	len = Length(L);
	printf("%d\n", len);
	return 0;
}