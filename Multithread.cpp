#include <stdio.h>
#include <windows.h>
volatile long g_nLoginCount;
const DWORD THREAD_NUM = 64;
DWORD WINAPI ThreadFun(void *pPM)
{
	Sleep(100);
	InterlockedIncrement(&g_nLoginCount);
	Sleep(50);
	return 0;
}
int main()
{
	int num= 20;
	while (num--)
	{
		g_nLoginCount = 0;
		int i;
		HANDLE  handle[THREAD_NUM];
		for (i = 0; i < THREAD_NUM; i++)
			handle[i] = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
		WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);
		printf("%d %d\n", THREAD_NUM, g_nLoginCount);
                for (int j=0; j < THREAD_NUM; j++) {
                        CloseHandle(handle[j]);
                }
	}
	return 0;
}
