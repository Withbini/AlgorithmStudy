//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int compare(const void *a, const void *b)
//{
//	int num1 = *(int *)a;
//	int num2 = *(int *)b;
//
//	if (num1 < num2) 
//		return -1;
//
//	if (num1 > num2)
//		return 1;
//
//	return 0;
//}
//
//int main() {
//	int inArr[9] = { 0 };
//	int outArr[9] = { 0 };
//	int Arr[9][9] = { 0 };
//	int sum = 0;
//	int n, m;
//
//	for (int i = 0; i < 9; i++) {
//		scanf("%d",&inArr[i]);
//		getchar();
//		sum += inArr[i];
//	}
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			Arr[i][j] = sum;
//		}
//	}
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			Arr[i][j] -= (inArr[i]+inArr[j]);
//		}
//	}
//
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			if (Arr[i][j] == 100) {
//				n = i; m = j;
//			}
//		}
//	}
//
//	for (int i = 0; i < 9; i++) {
//		if (i != n && i != m) {
//			outArr[i] = inArr[i];
//		}
//	}
//
//	qsort(outArr, sizeof(outArr) / sizeof(int), sizeof(int), compare);
//
//	for (int i = 2; i < 9; i++) {
//		printf("%d\n", outArr[i]);
//	}
//	return 0;
//}