#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

struct charnum {
        char str[10];
        int num;
};

int main()
{
        FILE *fp = fopen("data.txt", "rw+");
        char tmp[10] = {0};
        struct charnum tmpstr;
        map<int, struct charnum> mystr;
        int num = 0;
        int cou = 0;
        bool found = false;
        while (fscanf(fp, "%s", tmp) != EOF && !found) {
                map<int, struct charnum>::iterator it;
                for (it = mystr.begin(); it != mystr.end(); it++) {
                        if (strcmp(it->second.str, tmp) == 0) {
                                it->second.num++;
                                if (it->second.num == 2) {
                                       cou++;
                                       if (cou == 4) {
                                                printf("The 4th str: %s", tmp);
                                                found = true;
                                                break;
                                       }
                                }
                        }
                }
                if (it == mystr.end()) {
                        memcpy(tmpstr.str, tmp, sizeof(tmp));
                        tmpstr.num = 1;
                        printf("%s\n", tmp);
                        mystr[num++] = tmpstr;
                }
        }
        fclose(fp);
}
