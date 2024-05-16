#define _CRT_SECURE_NO_DEPRECATE    
/*      ���Ա�     */
/*      ��̬����ʵ��      */
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MaxSize 10			//�궨������Ĵ�С
//typedef int ElemType;		//�ض���int��
//typedef struct				//����������ṹ��ΪSqList
//{
//	ElemType data[MaxSize];		//����һ������
//	int length;					//���ȱ���
//}SqList;						//�������������:SqList
//void InitList(SqList &L){		//��ʼ������
//	int length = 0;				//˳���ĳ����޸�Ϊ0
//}	
//bool ListInsert(SqList &L,int i,int x) {		//���뺯��   ,Ҫ�����˳���Ҫ�����λ�ã�Ҫ���������
//	int j = 0;
//	//�ڽ��в���ʱҪ��λ�úϷ��Խ����жϣ����Ҷ�˳����Ƿ��Ѿ����������ж�
//	if (i < 1 || i > L.length + 1) {		//�����±�λ�ò��Ϸ�
//		return false;
//	}
//	if (L.length == MaxSize) {				//��������ʱ��˳�������
//		return false;
//	}
//	for (j = L.length; j >= i;j--) {		//�����һ��λ�ÿ�ʼ��Ҫ�����λ�ã�ÿ����������ƶ�һλ
//		L.data[j] = L.data[j - 1];			//�����ƶ�
//	}						
//	L.data[i - 1] = x;						//��λ��Ϊi��λ�ò������ݣ�λ���1��ʼ���������±��0��ʼ����-1
//	L.length++;								//L�ĵ�ǰ����+1
//	return true;
//}
//int Length(SqList &L) {						//��ǰ������
//	return L.length;						//ֱ�ӷ��ص�ǰ�ĵ�length
//}
//int LocateElem(SqList &L,int x) {			//����ֵ���Һ���
//	int i = 0;
//	//if (x < 1 || x > L.length) {			//�ж�λ���Ƿ�Ϸ�
//	//	return -1;
//	//}
//	for (i = 0; i < L.length; i++) {		//����˳��������Ƿ��Ԫ�ش���
//		if (L.data[i] == x) {				//����
//			return i;						//���������±�
//		}
//	}
//	return -1;								//�������ڷ���-1
//}
//int GetElem(SqList &L, int i) {				//��λ�����Ԫ��
//	if (i < 1 || i > L.length) {			//�ж�λ��ĺϷ���
//		return -1;
//	}
//	return L.data[i - 1];					//����λ��Ϸ���ֱ�ӷ�����λ�����ڵ�����
//}
//void PrintfList(SqList &L) {					//��ӡ�������ӵ�һ��Ԫ�ؿ�ʼ��ӡ����ǰԪ�ص����һ��Ԫ��
//	int i = 0;
//	for(i = 0;i < L.length; i++){
//		printf("%d ", L.data[i]);
//	}
//}
//bool EmptyList(SqList &L) {					//�пպ���������bool����
//	if (L.length == 0) {
//		return true;
//	}
//	return false;
//}
//bool DestroyList(SqList &L) {				//������
//	int i = 0;	
//	for (i = 0; i < L.length; i++) {		
//		L.data[i] = 0;						//����λ��ȫ����Ϊ0
//	}
//	if (i + 1 == L.length) {
//		return true;						//������óɹ�return true
//	}
//	else {	
//		return false;						//�������ʧ����return false
//	}
//}
//bool DeleteList(SqList &L,int i, int &e) {		//��λ��ɾ��������ɾ����������e����
//	int j = 0;
//	if (i < 1 || i > L.length) {				//�ж�λ���Ƿ�Ϸ������Ϸ�����false
//		return false;						
//	}
//	e = L.data[i - 1];							//��e����ɾ����Ԫ��
//	for (j = i; j < L.length; j++) {			//�Ѻ����Ԫ��������ǰŲһ��λ��
//		L.data[j - 1] = L.data[j];
//	}
//	L.length--;									//˳����ĳ���-1
//	return true;								//ɾ���ɹ�����true
//}
//int main()						//������
//{
//	int locate = 0;
//	SqList L;			//����˳���
//	InitList(L);		//��ʼ��˳���
//	bool ret = ListInsert(L, 3, 3);		//���ݰ�λ�����
//	if (ret == true) {
//		printf("���ݲ���ɹ�!\n");
//	}
//	else {
//		printf("���ݲ���ʧ��!\n");
//	} 
//	Length(L);							//��ǰ�ı�
//	scanf("%d", &locate);
//	LocateElem(L, locate);						//����ֵ����Ԫ��
//	return 0;
//}



/*    ��̬����    */
#include <stdio.h>
#include <stdlib.h>
#define InitSize 50			//˳���ĳ�ʼ����
typedef int ElemType;
typedef struct {
	ElemType* data;				//ָ��̬����������ָ��
	int MaxSize = 0;			//��ʼ�����ɴ洢����������
	int length = 0 ;			//���ȳ�ʼ��	
}SqList;

void InitList(SqList &L) {		//��̬�����ʼ��
	L.data = (ElemType*)malloc(InitSize*sizeof(ElemType));	//ʹ��malloc��������һƬ�����Ĵ洢�ռ�
	L.length = 0;					//��������Ϊ0
	L.MaxSize = InitSize;			//���洢�����ڳ�ʼ������
}
ElemType GetElem(SqList& L, int x) {			//��λ�����
	if (x < 1 || x > L.length) {				//λ��ĺϷ����ж�
		return -1;
	}
	return L.data[x - 1];						//�Ϸ��Ļ�����λ��Ϊx������
}
int LocateList(SqList& L, int &e) {				//��ֵ����
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
		}
	}
	return -1;
}
bool ListInsert(SqList& L, int locate_num, int insert_num) {				//��ָ��λ�����
	/*							λ��		�������ֵ     */
	int i = 0;
	if (locate_num < 1 || locate_num > L.length+1) {			//�ж�λ���±��Ƿ�Ϸ�
		return false;								//λ�򲻺Ϸ���ֱ�ӷ���false
	}
	for (i = L.length; i >= locate_num; i--) {	//�����һ��Ԫ�ؿ�ʼ��������ƶ�һ��Ԫ��ֱ���������λ��
		L.data[i] = L.data[i - 1];				//�����ƶ�
	}
	L.data[locate_num - 1] = insert_num;		//��λ��Ϊi��λ�ò�������
	L.length++;									//L�ĳ���++
	return true;								//����ɹ��򷵻�true
}
bool EmptyList(SqList L) {						//�пպ���
	if (L.length == 0) {
		return true;
	}
	else {
		return false;
	}
}
int LengthList(SqList& L) {					//���Ⱥ���
	return L.length;
}
bool ListDelete(SqList& L, int i, int e) {			//ɾ��ָ��λ�������
	int num_Locate = 0;
	if (i < 1 || i > L.length) {					//�ж�λ���Ƿ�Ϸ�
		return false;								//���Ϸ�������false
	}
	e = L.data[i - 1];
	for (num_Locate = i; num_Locate < L.length; num_Locate++) {
		L.data[num_Locate - 1] = L.data[num_Locate];
	}
	L.length--;
	return true;
}
int main() 
{
	SqList L;
}
