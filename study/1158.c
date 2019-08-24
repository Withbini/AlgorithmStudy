#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

typedef struct list {
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
}List;

void ListInit(List *plist) {
	plist->tail = NULL;
	plist->before = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}
void SetNode(List *plist,int num) {
	Node *newNode = NULL;


	if (num < 1) return;
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->tail->data = 1;
	plist->tail->next = plist->tail;
	plist->numOfData++;

	for (int i = 2; i < num+1 ; i++) {
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->data = i;
		
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
		plist->numOfData++;
	}

	plist->cur = plist->tail->next;
	plist->before = plist->tail;

	return ;
}

int DelNode(List *plist) {
	int delData = plist->cur->data;
	Node *delNode = plist->cur;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(delNode);

	(plist->numOfData)--;
	return delData;
}

int WhoIsDelete(List* plist,int delby) {
	int result,count;
	count = delby; //커서를 몇번 넘길지
	if (plist->numOfData==0) return 0;

	if (plist->cur->data == 1 && plist->before->data == plist->tail->data) {
		while (count != 1)
		{
			plist->before = plist->cur;
			plist->cur = plist->cur->next;
			count--;
		}
		
		result=DelNode(plist);
		printf("%d", result);
		return result;
	}
	
	while (count != 0) {
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
		count--;
	}

	printf(", ");
	result=DelNode(plist);
	printf("%d", result);
	return result;
}

int main() {
	int numPeo,delBy;
	List list;

	ListInit(&list);

	scanf("%d", &numPeo);
	SetNode(&list, numPeo);

	scanf("%d", &delBy);
	
	printf("<");
	//사람이 제거될때까지 노드삭제,조회,보여주기 반복
	while (list.numOfData != 0) {
		WhoIsDelete(&list, delBy);
	}

	printf(">");
	return 0;
}
