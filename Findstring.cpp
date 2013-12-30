#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
        string a = "abcdefghijk";
        string b = "bdhij";
        int help[26] = {0};
        int num = 0;
        for (int i = 0; i < b.length(); i++) {
                int index = b[i] - 'a';
                if (help[index] == 0) {
                        help[index] = 1;
                        num++;
                }
        }

        for (int j = 0; j < a.length(); j++) {
                int index = a[j] - 'a';
                if (help[index] == 1) {
                        help[index] = 0;
                        num--;
                }
        }

        if (num == 0)
                printf("true\n");
        else
                printf("false\n");
}
