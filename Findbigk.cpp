#include <stdio.h>
#include <stdlib.h>

void buildheap(int *a, int len);
void heapadjust(int *a, int s, int len);

int main()
{
        printf("Find the k bigger!\nPlease input the number k\n");
        int k;
        do {
                scanf("%d", &k);
        } while (k < 1);
        int *a = (int *)malloc(k*sizeof(int));
        FILE *fd = fopen("data.txt", "r+");
        for (int i = 0; i < k; i++) {
                fscanf(fd, "%d", a+i);
        }
        buildheap(a, k);
        int tmp;
        while (fscanf(fd, "%d", &tmp) != EOF) {
                if (tmp > a[0]) {
                        a[0] = tmp;
                        heapadjust(a, 0, k);
                }
        }
        printf("The k biggest number:\n");
        for (int i = 0; i < k; i++)
                printf("%d ", a[i]);
        printf("\n");
}
/*big base heap
 */
void heapadjust(int *a, int s, int len)
{
        int tmp = a[s];
        int i = 2 * s + 1;
        while (i < len) {
                if (i + 1 < len && a[i+1] < a[i]) {
                        i++;
                }
                if (a[i] >= tmp)
                        break;
                a[s] = a[i];
                s = i;
                i = 2 * s + 1;
        }
        a[s] = tmp;
}

void buildheap(int *a, int len)
{
        for (int i = len/2-1; i >=0; i--)
                heapadjust(a, i, len);
}
