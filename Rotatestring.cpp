#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void rotatestring(string & a, int num)
{
    int n = a.length();
    if(n == 0 || num <= 0)
        return;
    int m = num % n;
    if(0 == m)
        return;
    int p1 = 0;
    int p2 = m;
    int k = (n - m) - n % m;
    int r = n % m;
    while(k--)
    {
        swap(a[p1],a[p2]);
        p1++;
        p2++;
    }
    while(r--)
    {
        int i = p2;
        while(i > p1)
        {
            swap(a[i],a[i-1]);
            i--;
        }
        p1++;
        p2++;
    }
}

int main()
{
    cout << "Hello world!" << endl;
//    string a = "abcdefg";
    cout << "Please input the string!" <<endl;
    char ab[20];
    gets(ab);
    string a(ab);
    cout << "Before: " << a <<endl;
    rotatestring(a,3);
    cout << "After: " << a <<endl;
    return 0;
}
