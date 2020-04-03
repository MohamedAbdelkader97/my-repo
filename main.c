#include <stdio.h>
#include <stdlib.h>
#include "Dlinkedlist.h"

int main()
{
    for(int i=0; i<50; i++)
    {
        add (i);
//printf("data = %d\n",ptail->data);
    }
    struct client*pcur=phead;
    if(insertclient(99,10))
    {
        printf("succes\n");
    }
    else
    {
        printf("fail\n");
    }


    deleteclient(0);
   pcur=phead;
    for(int i=0; i<clientNo; i++)
    {

        printf("data = %d\n",pcur->data);
        pcur = pcur->pnext;
    }
    return 0;
}
