#include <stdio.h>
#include <malloc.h>

int myFun(int, int);
int* myFun1(int, int);

typedef int (*sum)(int, int);

int main() {

    int (*p)(int, int)=myFun;
    int ret = (*p)(10, 20);
    printf("\nret=%d\n",ret);

    sum pFun = myFun;
    ret = (*pFun)(20, 20);
    printf("\nret=%d\n",ret);

    int* (*p1)(int, int)=myFun1;
    int* p_ret = (*p1)(10, 30);
    printf("\npointer value=%d\n", &p_ret);

    return 0;
}

int myFun(int i, int j) {
    int k = i + j;
    printf("%d + %d", i, j);
    return k;
}

int* myFun1(int i, int j) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + j;
    printf("\npointer address=%p\n", p);
    return p;
}