#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

using namespace std;
void leftshift(char*a, int n, int m);

int main()
{
    char q = 0;
    do{
        char *a = (char *)malloc(20*sizeof(char));
        memset(a,0,20);
        int num = 0;
        int times = 0;
        if(q != 0)
            getchar();
//        cout << "Please input the string!" << endl;
        printf("Please input the string\n");
        gets(a);
        while(a[num] != 0)
        {
            printf("%c %d\n",a[num],num);
            num++;

        }
    //    while(scanf("%c",a+num) && a[num] != "\0")
    //    {
    //        num++;
    //    }
        cout << "The length of the input string " << num << endl;
        cout << "Please input the number you want to shift!" << endl;
        while(scanf("%d",&times) && times <= 0)
        {
            //接受完输入后，下次再获取时，需要先将回车键获取，以免下次获取的内容中含回车键
            printf("Please input a positive number!\n");
            //标准输出中的回车键跟这个不相关
        }
        leftshift(a,num,times);
        printf("After shift: %s\n",a);
        free(a);
        printf("Continue?y:n\n");
        getchar();
//        do{
//            scanf("%c",&q);
//        }while(q!='y' || q!='n');
        scanf("%c",&q);

    }while(q=='y');
    return 0;
}


void leftshift(char*a,int n,int m)
{
    while(m--)
    {
        char tmp = a[0];
        for(int i = 1; i <= n; i++)
        {
            a[i-1] = a[i];
        }
        a[n-1] = tmp;
    }
}
