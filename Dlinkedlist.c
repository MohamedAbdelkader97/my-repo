#include <stdio.h>
#include <stdlib.h>
#include "Dlinkedlist.h"
struct client *createClient(int data)
{
    struct client *pclient = (struct client*)malloc(sizeof(struct client));
    if(pclient!=NULL)
    {
        clientNo++;
        pclient->data=data;
    }
    return (pclient);
}
int  add(int data)
{
    struct client *pclient=createClient(data);
    if(pclient)
    {
        //first element case
        if(phead==NULL)
        {
            phead = ptail = pclient;
        }
        //last element case == not first element case
        else
        {
            //ptail->pnext=pclient;
            pclient->pprev=ptail;
            ptail=pclient;
            pclient->pprev->pnext=ptail;

        }
        return 1;
    }
    return 0;
}
int insertclient(int data,int index)
{

    if(index == clientNo)
    {
        if(add(data))
            return 1;
        else
        {
            return 0;
        }
    }
    else if(index==0)
    {
        struct client* pclient=createClient(data);
        if(pclient)
        {
            phead->pprev=pclient;
            pclient->pnext=phead;
            phead=pclient;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        struct client *pclient = createClient(data);
        if(pclient)
        {
            struct client *pcur=phead;
            for(int i=0 ; i<index ; i++)
            {
                pcur=pcur->pnext;
            }
            pcur->pprev->pnext=pclient;
            pclient->pprev=pcur->pprev;
            pclient->pnext=pcur;
            pcur->pprev=pclient;

            return 1;
        }

    }
    return 0;

}


int deleteclient(int index)
{
    if (index ==0)
    {
        struct client *pclient= phead;
        phead= pclient-> pnext;
        phead-> pprev= NULL;
        free (pclient);
        clientNo--;
        return 1;
    }

    else if (index == (clientNo-1))
    {
        struct client *pclient= ptail;
        ptail=pclient->pprev;
        ptail->pnext=NULL;
        free (pclient);
        clientNo--;
        return 1;
    }

    else {

        struct client *pcur=phead;
            for(int i=0 ; i<index ; i++)
            {
                pcur=pcur->pnext;
            }
            pcur->pprev->pnext=pcur->pnext;
            pcur->pnext->pprev=pcur->pprev;
            free(pcur);
            clientNo--;
            return 1;
    }


}



