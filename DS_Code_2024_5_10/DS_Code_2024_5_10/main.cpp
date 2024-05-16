#define _CRT_SECURE_NO_DEPRECATE    
/*      线性表     */
/*      静态分配实现      */
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MaxSize 10			//宏定义数组的大小
//typedef int ElemType;		//重定义int型
//typedef struct				//重命名这个结构体为SqList
//{
//	ElemType data[MaxSize];		//创建一个数组
//	int length;					//长度变量
//}SqList;						//重命名后的名字:SqList
//void InitList(SqList &L){		//初始化函数
//	int length = 0;				//顺序表的长度修改为0
//}	
//bool ListInsert(SqList &L,int i,int x) {		//插入函数   ,要插入的顺序表，要插入的位置，要插入的数字
//	int j = 0;
//	//在进行插入时要对位置合法性进行判断，并且对顺序表是否已经存满进行判断
//	if (i < 1 || i > L.length + 1) {		//插入下标位置不合法
//		return false;
//	}
//	if (L.length == MaxSize) {				//插入数据时，顺序表已满
//		return false;
//	}
//	for (j = L.length; j >= i;j--) {		//从最后一个位置开始到要插入的位置，每个数据向后移动一位
//		L.data[j] = L.data[j - 1];			//数据移动
//	}						
//	L.data[i - 1] = x;						//在位序为i的位置插入数据，位序从1开始，而数组下标从0开始，故-1
//	L.length++;								//L的当前长度+1
//	return true;
//}
//int Length(SqList &L) {						//求当前表长函数
//	return L.length;						//直接返回当前的的length
//}
//int LocateElem(SqList &L,int x) {			//按数值查找函数
//	int i = 0;
//	//if (x < 1 || x > L.length) {			//判断位序是否合法
//	//	return -1;
//	//}
//	for (i = 0; i < L.length; i++) {		//遍历顺序表，查找是否该元素存在
//		if (L.data[i] == x) {				//存在
//			return i;						//返回数组下标
//		}
//	}
//	return -1;								//若不存在返回-1
//}
//int GetElem(SqList &L, int i) {				//按位序查找元素
//	if (i < 1 || i > L.length) {			//判断位序的合法性
//		return -1;
//	}
//	return L.data[i - 1];					//若是位序合法，直接返回其位序所在的数据
//}
//void PrintfList(SqList &L) {					//打印函数，从第一个元素开始打印到当前元素的最后一个元素
//	int i = 0;
//	for(i = 0;i < L.length; i++){
//		printf("%d ", L.data[i]);
//	}
//}
//bool EmptyList(SqList &L) {					//判空函数，返回bool类型
//	if (L.length == 0) {
//		return true;
//	}
//	return false;
//}
//bool DestroyList(SqList &L) {				//销表函数
//	int i = 0;	
//	for (i = 0; i < L.length; i++) {		
//		L.data[i] = 0;						//所有位置全部置为0
//	}
//	if (i + 1 == L.length) {
//		return true;						//如果重置成功return true
//	}
//	else {	
//		return false;						//如果重置失败则return false
//	}
//}
//bool DeleteList(SqList &L,int i, int &e) {		//按位置删除，并把删除的数据用e返回
//	int j = 0;
//	if (i < 1 || i > L.length) {				//判断位置是否合法，不合法返回false
//		return false;						
//	}
//	e = L.data[i - 1];							//用e接受删除的元素
//	for (j = i; j < L.length; j++) {			//把后面的元素依次向前挪一个位置
//		L.data[j - 1] = L.data[j];
//	}
//	L.length--;									//顺序标表的长度-1
//	return true;								//删除成功返回true
//}
//int main()						//主函数
//{
//	int locate = 0;
//	SqList L;			//创建顺序表
//	InitList(L);		//初始化顺序表
//	bool ret = ListInsert(L, 3, 3);		//数据按位序插入
//	if (ret == true) {
//		printf("数据插入成功!\n");
//	}
//	else {
//		printf("数据插入失败!\n");
//	} 
//	Length(L);							//求当前的表长
//	scanf("%d", &locate);
//	LocateElem(L, locate);						//按数值查找元素
//	return 0;
//}



/*    动态分配    */
#include <stdio.h>
#include <stdlib.h>
#define InitSize 50			//顺序表的初始长度
typedef int ElemType;
typedef struct {
	ElemType* data;				//指向动态分配的数组的指针
	int MaxSize = 0;			//初始化最多可存储的数据数量
	int length = 0 ;			//长度初始化	
}SqList;

void InitList(SqList &L) {		//动态分配初始化
	L.data = (ElemType*)malloc(InitSize*sizeof(ElemType));	//使用malloc函数申请一片连续的存储空间
	L.length = 0;					//长度设置为0
	L.MaxSize = InitSize;			//最大存储量等于初始化长度
}
ElemType GetElem(SqList& L, int x) {			//按位序查找
	if (x < 1 || x > L.length) {				//位序的合法性判断
		return -1;
	}
	return L.data[x - 1];						//合法的话返回位序为x的数据
}
int LocateList(SqList& L, int &e) {				//按值查找
	int i = 0;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
		}
	}
	return -1;
}
bool ListInsert(SqList& L, int locate_num, int insert_num) {				//在指定位序插入
	/*							位序		插入的数值     */
	int i = 0;
	if (locate_num < 1 || locate_num > L.length+1) {			//判断位序下标是否合法
		return false;								//位序不合法，直接返回false
	}
	for (i = L.length; i >= locate_num; i--) {	//从最后一个元素开始依次向后移动一个元素直到到达插入位序
		L.data[i] = L.data[i - 1];				//数据移动
	}
	L.data[locate_num - 1] = insert_num;		//在位序为i的位置插入数据
	L.length++;									//L的长度++
	return true;								//插入成功则返回true
}
bool EmptyList(SqList L) {						//判空函数
	if (L.length == 0) {
		return true;
	}
	else {
		return false;
	}
}
int LengthList(SqList& L) {					//长度函数
	return L.length;
}
bool ListDelete(SqList& L, int i, int e) {			//删除指定位序的数据
	int num_Locate = 0;
	if (i < 1 || i > L.length) {					//判断位序是否合法
		return false;								//不合法，返回false
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
