#define _CRT_SECURE_NO_DEPRECATE    
/*    ������	*/
/*    ��ͷ���    */
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
/*   �ṹ��    */
typedef struct LNode {		//�ڵ�ṹ��
	ElemType data;			//������
	struct LNode* next;		//ָ����
}LNode,*LinkList;
/*   LNodeΪ�ض���������     */
/*   LinkListΪstruct LNodeָ�� -> �ȼ��� -> typedef struct LNode * LinkList;*/

/*   ��ʼ��һ���ձ�    */
bool InitList(LinkList& L) {		//ʹ��&����Ϊ��Ҫ�ѳ�ʼ���Ŀձ���
	L = (LNode*)malloc(sizeof(LNode));		//����һ��ͷ���
	if (L == NULL) {
		return false;				//����ʧ�ܷ���false
	}
	L->next = NULL;					//ֻ��һ��ͷ��㣬ͷ�ڵ�֮��û���κν��
	return true;
}

bool EmptyList(LinkList	L) {		//�пպ���,��Ϊ�ձ��򷵻�true����֮�򷵻�false
	return (L->next == NULL);
}

/*    �ڵ�i��λ�ò���Ԫ��e    */
bool InsertList(LinkList& L, int i, ElemType e) {		//����һ��������λ��eΪ���������
	if (i < 1) {										//�ж�λ���Ƿ�Ϸ������Ϸ�����false
		return false;
	}
	LNode* p;							//����һ����㣬ָ��ǰɨ�赽�Ǹ����
	int j = 0;							//pָ����ǵڼ������
	p = L;								//pָ��ͷ���
	while (p != NULL && j < i - 1) {	//�ҵ�����λ��ǰ���Ǹ����
		p = p->next;
		j++;
	}
	if (p == NULL) {					//�ж�iֵ�Ƿ�Ϸ�
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));		//����һ���µĽ��
	new_node->next = p->next;			//�½���nextָ��ָ���ҵ��Ĳ���λ��ǰ����nextָ��Ľ��
	p->next = new_node;					//����λ��ǰ���Ǹ�����nextָ��ָ���½ڵ�
	new_node->data = e;					//��e�����½���������
	return true;						//����ɹ��򷵻�true
}

/*    ��ָ����������µĽڵ�    */
bool InsertNextLocate(LNode* p, ElemType e) {		//��ָ����������µĽ��
	if (p == NULL) {								//�жϽ��ĺϷ��ԣ����Ϸ�ֱ�ӷ���false
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));	//����һ���µĽ��
	if (new_node == NULL) {					//�ڴ����ʧ�ܵ����������false
		return false;
	}
	new_node->data = e;				//��e�����½ڵ��������
	new_node->next = p->next;		//�½ڵ��nextָ��ָ��p��nextָ��Ľ��
	p->next = new_node;				//p��nextָ��ָ���½��
	return true;					//����ɹ�������true
	}
/*    ǰ���������������ڸý��֮ǰ����Ԫ��e    */
bool InsertPriorNode(LNode* p, ElemType e) {		//ָ����㣬Ҫ�����Ԫ��e
	if (p == NULL) {								//�ж�p�ĺϷ��ԣ����p���Ϸ�������false
		return false;
	}
	LNode* new_node = (LNode*)malloc(sizeof(LNode));	//����һ���µĽ��
	if (new_node == NULL) {					//�ڴ治�㣬����ʧ�ܵ�����£�����false
		return false;
	}
	/*    �Ҹо�������������Բ�Ҫ    */
	ElemType temp = p->data;			//��ʱ����
	new_node->data = p->data;		//������
	new_node->next = p->next;		//ָ����
	p->next = new_node;				//�޸�p��nextָ��Ľ��
	p->data = e;					//�޸�p��������
	return true;					//����ɹ�������true
}
/*    ��λ��ɾ��    */
bool DeleteList(LinkList& L, int i, ElemType &e) {			//���õ�����λ����Ҫ���ص�e
	if (i < 1) {
		return false;
	}
	LNode* p;				//����һ����㣬�������ǵ�ǰɨ�赽�ĵ��жϽ��
	int j = 0;				//��ͷ��㿪ʼɨ��
	p = L;					//ָ��ͷ��㡣ͷ����ǵ�0����㣬�����洢����
	while (p != NULL && j < i - 1) {		//whileѭ���ҵ�i-1�����
		p = p->next;
		j++;	
	}
	if (p == NULL) {		//i��ֵ���Ϸ�������false
		return false;
	}
	if (p->next == NULL) {	//�����i-1�����֮��û�н���ˣ�����false
		return false;
	}
	LNode* q = p->next;		//����һ���µĽ�㣬��ʹ������Ҫ��ɾ���Ľ��
	e = q->data;			//��Ҫ��ɾ���Ľ����������e
	p->next = q->next;		//�޸�p��nextָ��Ϊqָ�����һ�����
	free(q);				//�ͷ�q���
	return true;			//���ɾ���ɹ�������true
}
/*    ɾ��ָ�����    */
bool DeleteList_Node(LNode* p) {			//ָ�����
	if (p == NULL) {						//�жϽ��ĺϷ��ԣ����Ϸ�ֱ�ӷ���false
		return false;
	}		
	LNode* q = p->next;						//����һ���µĽ�㣬����p�ĺ�̽�㸴�Ƹ���
	p->data = p->next->data;				//p�������������p�ĺ�̽��ĺ�̽ڵ��������
	p->next = q->next;						//�޸�p��ָ��
	free(q);								//�ͷ�q���
	return true;							//ɾ���ɹ�������true
}
/*    ��λ���ң����ص�i��Ԫ��    */
LNode* GetElem(LinkList L, int i) {			//������λ��
	if (i < 1) {							//�ж�λ��ĺϷ��ԣ����Ϸ�ֱ�ӷ���NULL
		return NULL;
	}
	LNode* p;								//����һ����㣬ָ��ǰɨ�赽�Ǹ����
	int j = 0;								//����pɨ�赽�ڼ������
	p = L;									//Lָ��ͷ��㣬ͷ��㲻���洢����
	while (p != NULL && j < i) {			//ѭ���ҵ�i�����
		p = p->next;						//p��next�޸�
		j++;
	}
	return p;								//�ҵ���i����㣬���ѵ�i����㷵��
}
/*    ��ֵ���ң��ҵ�������Ϊe�Ľ�㲢���ؽ���ָ��    */
LNode* LocateElem(LinkList L, ElemType e) {			//��������Ҫ�Աȵ�����e
	LNode* p = L->next;								//�ӵ�һ����㿪ʼ�Ա�
	while (p != NULL && p->data != e)				//ѭ���ҵ����������Ϊe�Ľ��
	{
		p = p->next;								//p����
	}
	return p;										//���ؽ��ָ��p
}
/*    ���ĳ���    */
int Length(LinkList L) { 
	int ret = 0;
	LNode* p = L;
	while (p->next != NULL) {
		p = p->next;
		ret++;
	}
	return ret;
}
/*    β�巨����һ��������    */
LinkList List_EndInsert(LinkList& L) {			//���õ�����
	ElemType x = 0;								//����Ԫ�������޸�������ж�
	L = (LNode*)malloc(sizeof(LNode));			//����ͷ���
	LNode* s = L;								//�������ָ��ͷ���
	LNode* r = L;								//βָ�룬��ʼʱָ��ͷ���
	scanf("%d", &x);							//������ֵ
	while (x != 9999) {							//����9999�˳�
		s = (LNode*)malloc(sizeof(LNode));		
		s->data = x;							//s���������򱻸�ֵ
		r->next = s;							//�޸�βָ���ָ����,ָ�����´����Ľ��
		r = s;									//�޸�β�ڵ�
		scanf("%d", &x);						//�������ݣ�����9999�˳�
	}	
	r->next = NULL;								//�޸�βָ���ָ����
	return L;									//���ص�����
}
/*     ͷ�巨����һ��������    */
LinkList Head_Insert(LinkList& L) {				//���õ�����
	LNode* s;									//����һ�����	
	int x = 0;
	L = (LNode*)malloc(sizeof(LNode));			//ͷ���Ĵ���
	L->next = NULL;								//ͷ����ָ���޸�
	scanf("%d", &x);							//�����������
	while (x != 9999) {							//Ĭ������9999�˳�ͷ����
		//LNode* s;
		s = (LNode*)malloc(sizeof(LNode));		//�½��Ĵ���
		s->data = x;							//�޸��½���������
		s->next = L->next;						//�޸��½���ָ����
		L->next = s;							//�޸�ͷ����ָ����
		scanf("%d", &x);						//�������ݣ�������Ĳ���9999����������㣬��֮���˳�������
	}
	return L;									//�Ѳ����Ľ�㷵��
}
/*    ������    */
int main()
{
	//todo;
	return 0;
}