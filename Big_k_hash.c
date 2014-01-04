#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define F 0.6180329
#define N 1024
/* random multiplier hash method recommended value.
 * double f = 0.6180329;
 * (int)hash(k) = (int)n*(f*k-(int)f*k);
 */
#define HASHSIZE 10000
#define HEAPSIZE 16
#define handle_error(msg)\
        do {\
                perror(msg);\
                exit(EXIT_FAILURE);\
        } while(0)

typedef struct datanode
{
        int data;
        int total;
        struct hashtable *next;
}datanode;

datanode *hashtable[HASHSIZE];

int hash_function(int data)
{
        double tmp = F * data;
        return (int)N*(tmp-(int)tmp);
}

datanode *createnode(int data)
{
        datanode *tmp = (datanode *)malloc(sizeof(datanode));
        if(NULL == tmp)
                handle_error("malloc error!");
        tmp->data = data;
        tmp->total = 1;
        tmp->next = NULL;
        return tmp;
}

void insert(int data)
{
        int tmp = hash_function(data);
        datanode *p = hashtable[tmp];
        while (NULL != p) {
                if (p->data == data) {
                        p->total++;
                        return;
                }
                p = p->next;
        }
        p = createnode(data);
        p->next = hashtable[tmp];
        hashtable[tmp] = p;
}

void freemem()
{
        datanode *tmp = NULL;
        datanode *p = NULL;
        int i;
        for (i=0; i<HASHSIZE; i++) {
                p = hashtable[i];
                while (p != NULL) {
                        tmp = p;
                        p = p->next;
                        free(tmp);
                        tmp = NULL;
                }
        }
}

typedef struct min_heap
{
        int data;
        int total;
}min_heap;

min_heap minheap[HEAPSIZE];

void heap_adjust(min_heap *mh, int s, int len)
{
        min_heap tmp = mh[s];
        int index = s * 2 + 1;
        while (index < len) {
                if (index+1 < len && mh[index].total > mh[index+1].total)
                        index++;
                if (mh[index].total > tmp.total)
                        break;
                mh[s] = mh[index];
                s = index;
                index = s * 2 + 1;
        }
        mh[s] = tmp;
}

void build_heap(min_heap *mh, int len)
{
        int i;
        for (i=len/2-1; i>=0; i--)
                heap_adjust(mh, i, len);
}

void traverse_hashtable()
{
        datanode *p = NULL;
        int i;
        for (i=0; i<HEAPSIZE; i++) {
                p = hashtable[i];
                while (p) {
                        if (p->total > minheap[0].total) {
                                minheap[0].data = p->data;
                                minheap[0].total = p->total;
                                heap_adjust(minheap, 0, HEAPSIZE);
                        }
                        p = p->next;
                }
        }
}

int main()
{
        int i,j;
        for (i=0; i<HEAPSIZE; i++) {
                minheap[i].data = i;
                minheap[i].total = -i;
        }
        build_heap(minheap, HEAPSIZE);
        FILE *fp = fopen("data.txt", "r+");
        int tmpdata;
        while (fscanf(fp, "%d ", &tmpdata) != EOF) {
                insert(tmpdata);
        }
        traverse_hashtable();
        printf("The top %d total count number:\n", HEAPSIZE);
        printf("%5s\t%5s,%5s\n", "rank", "value", "total");
        for (j=HEAPSIZE; j>0; j--) {
                min_heap tmp = minheap[0];
                minheap[0] = minheap[j-1];
                minheap[j-1] = tmp;
                heap_adjust(minheap, 0, j-1);
        }
        for (j=0; j<HEAPSIZE; j++) {
                printf("%4d.\t%5d\t%5d\n", j+1,minheap[j].data, minheap[j].total);
        }
        freemem();
        fclose(fp);
}
