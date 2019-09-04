#include <stdio.h>

typedef struct _element {
	int key;
}element;

typedef struct _heap {
	element heap[100001];
	int size;
}Heap;

void Init(Heap *h) {
	h->size = 0;
}
void insertHeap(Heap *h, element item) {
	int i = ++(h->size);
	h->heap[i] = item;

	while (i != 1 && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}

	h->heap[i] = item;

}

void delHeap(Heap *h) {
	element tmp, item;
	int parent = 1, child = 2;
	if (h->size == 0) {
		printf("0\n"); return;
	}

	item = h->heap[1]; //반환할 노드
	tmp = h->heap[(h->size)--]; //제일 마지막 노드 임시로 저장

	while (child <= h->size) {
		if (h->heap[child].key < h->heap[child + 1].key) child++;
		if (tmp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	
	printf("%d\n", item.key);
}

void resultOp(Heap *h, int op) {
	element item;
	item.key = op;
	if (op == 0) delHeap(h);
	else insertHeap(h, item);
	return;
}

int main() {
	Heap h1;
	int num, Opr;
	scanf("%d", &num);
	getchar();
	Init(&h1);

	for (int i = 0; i < num; i++) {
		scanf("%d", &Opr);
		getchar();

		resultOp(&h1, Opr);
	}


	return 0;
}
