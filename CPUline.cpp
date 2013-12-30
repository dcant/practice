#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
   const double SPLIT = 0.01;
   const int COUNT = 200;
   const double PI = 3.14159265;
   const int INTERVAL = 300;

   DWORD busy[COUNT];
   DWORD idle[COUNT];
   double half = INTERVAL/2;
   double radius = 0;
   int j = 0;
   DWORD starttime = 0;
   for(int i = 0; i < COUNT; i++)
   {
       busy[i] = (DWORD)half + sin(PI*radius)*half;
       idle[i] = (DWORD)INTERVAL - busy[i];
       radius += SPLIT;
   }

   while(true)
   {
       j = j%COUNT;
       starttime = GetTickCount();
       while(GetTickCount() - starttime < busy[j])
        ;
       Sleep(idle[j]);
       j++;
   }
   return 0;
}
