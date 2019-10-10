#include <stdio.h>

typedef struct Year {
   int SEM[3];
}year;

int main() {
   int E, S, M;
   scanf("%d %d %d", &E, &S, &M);
	year arr[8000];
	arr[0].SEM[0] = 1;
	arr[0].SEM[1] = 1;
	arr[0].SEM[2] = 1;
   for (int i = 1; i < 8000; i++) {
      arr[i].SEM[0] = arr[i - 1].SEM[0] + 1;
      if (arr[i].SEM[0] % 16 == 0) arr[i].SEM[0] = 1;

      arr[i].SEM[1] = arr[i - 1].SEM[1] + 1;
      if (arr[i].SEM[1] % 29 == 0) arr[i].SEM[1] = 1;

      arr[i].SEM[2] = arr[i - 1].SEM[2] + 1;
      if (arr[i].SEM[2] % 20 == 0) arr[i].SEM[2] = 1;
      
   }

   for (int i = 0; i < 8000; i++) {
      if (arr[i].SEM[0] == E && arr[i].SEM[1] == S && arr[i].SEM[2] == M) {
         printf("%d", i+1);
          break;
      }

   }
   return 0;
}
