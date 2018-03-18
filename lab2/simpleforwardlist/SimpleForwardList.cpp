//
// Created by mikolaj on 05.03.18.
//

#include "SimpleForwardList.h"
ForwardList *CreateNode(int value)
{
    ForwardList *pierwszy,*nowy;
    pierwszy=nullptr;
    nowy=new ForwardList;
    nowy->value=value;
    nowy->next=pierwszy;
    pierwszy=nowy;
    return pierwszy;


}
void DestroyList(ForwardList *list)
{
    ForwardList *nastepny;
    while(list)
    {
        nastepny=list->next;
        delete list;
        list=nastepny;
    }
}

ForwardList *PushFront(ForwardList *list, int value)
{
    if (list)
    {
        ForwardList *nowy;
        nowy=new ForwardList;
        nowy->value=value;
        nowy->next=list;
        list=nowy;
        return list;
    }

}
void Append(ForwardList *list, ForwardList *tail)
{
    if (list)
    {
        while(list->next)
        {
            list=list->next;
        }
        list->next=tail;
    }
    else list=tail;
}