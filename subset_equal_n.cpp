#include <stdlib.h>
#include <stdio.h>
#include <list>

/*this is problem about the 0-1 bag
 *find the subset of a set added up to a sum
 */


using namespace std;
list<int> all;
void subset(int sum, int num);
int main()
{
        int sum,num;
        printf("Please input the sum:\n");
        scanf("%d", &sum);
        printf("Please input the num:\n");
        scanf("%d", &num);
        subset(sum, num);
        return 0;
}
void subset(int sum, int num)
{
        if (sum <= 0 || num <= 0)
                return;
        if (sum == num) {
                all.reverse();
                list<int>::iterator it = all.begin();
                for (; it!=all.end(); it++) {
                        printf("%d + ", *it);
                }
                printf("%d\n", num);
                all.reverse();
        }
        all.push_front(num);
        subset(sum-num, num-1);
        all.pop_front();
        subset(sum, num-1);
}
