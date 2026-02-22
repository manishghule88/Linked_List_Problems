#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

void InsertFirst(struct node** first, int no)
{
    struct node* newn = NULL;

    newn = new struct node;

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else 
    {
        newn->next = *first;
        *first = newn;
    }
}

void InsertLast(struct node** first, int no)
{
    struct node* newn = NULL;
    struct node* temp = NULL;

    newn = new struct node;

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else 
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void Display(struct node* first)
{
    while(first != NULL)
    {
        cout << "| " << first->data;
        first = first->next;
    }
    cout << "|->NULL\n";
}

int Count(struct node* first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    return iCount;
}

void DeleteFirst(struct node** first)
{
    struct node* temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        delete *first;
        *first = NULL;
    }
    else 
    {
        temp = *first;

        *first = (*first)->next;
        delete temp;
    }
}

void DeleteLast(struct node** first)
{
    struct node* temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        delete *first;
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }
}

void DeleteAtPos(struct node** first, int pos)
{
    struct node* target = NULL;
    struct node* temp = NULL;
    int iCnt = 0;

    int iCount = Count(*first);

    if((pos < 1) || (pos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else 
    {
        temp = *first;

        for(iCnt = 0; iCnt < pos - 2; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;
    }
}

int main()
{
    struct node* head = NULL;
    int iRet = 0;

    InsertFirst(&head, 300);
    InsertFirst(&head, 200);
    InsertFirst(&head, 100);

    InsertLast(&head, 400);
    InsertLast(&head, 400);
    InsertLast(&head, 400);

    Display(head);

    DeleteAtPos(&head, 2);
    Display(head);
    iRet = Count(head);
    cout << "Count of the elements are : " << iRet;

}
