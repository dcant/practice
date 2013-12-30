#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int _partition(string &a, int s, int e);
void _quicksort(string &a, int s, int e);
void quick(string &a);

int main()
{
        string a = "dgcehafb";
        printf("Before sort: %s\n",a.c_str());
        quick(a);
        printf("After sort: %s\n",a.c_str());
        return 0;
}

int _partition(string &a, int s, int e)
{
        /*based on the first value to partition
         *
         */
        int tmp = a[s];
        while (s < e) {
                while (s < e && a[e] >= tmp) {
                        e--;
                }
                if (s < e) {
                        a[s] = a[e];
                        s++;
                }
                while (s < e && a[s] < tmp) {
                        s++;
                }
                if (s < e) {
                        a[e] = a[s];
                        e--;
                }
        }
        a[s] = tmp;
        return s;
}

void _quicksort(string &a, int s, int e)
{
        if (s < e) {
                int pa = _partition(a, s, e);
                _quicksort(a, s, pa - 1);
                _quicksort(a, pa + 1, e);
        }
}

void quick(string &a)
{
        int length = a.length();
        _quicksort(a, 0, length - 1);
}
