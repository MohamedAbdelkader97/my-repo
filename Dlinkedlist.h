#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED
int clientNo ;
struct client
{
    int data;
    struct client *pprev;
    struct client *pnext;

}*phead,*ptail;
struct client *createClient(int data);
int  add(int data);
int insertclient(int data,int index);
int deleteclient(int index);
#endif // DLINKEDLIST_H_INCLUDED
