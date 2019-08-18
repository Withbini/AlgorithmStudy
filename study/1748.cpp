#include <iostream>
using namespace std;
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int N;
        cin >> N;
        long long sum = 0;
        int len = 1;

        //길이가 len인 범위
        long long prev = 1;
        long long next = 10;
        while (1)
        {
                 bool exit = false;
                 for (int i = prev; i < next; i++)
                 {
                         if (i > N)
                         {
                                 exit = true;
                                 break;
                         }
                         sum += len;
                 }
                 if (exit)
                         break;
                 prev *= 10;
                 next *= 10;
                 len++;

        }
        cout << sum << "\n";
        return 0;

}
