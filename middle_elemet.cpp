/// Return the middle element of the list

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

int FindMiddleNode(struct node** first)
{
    struct node* slow = NULL;
    struct node* fast = NULL;

    slow = *first;
    fast = *first;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    struct node* head = NULL;
    int iRet = 0;

    InsertFirst(&head, 300);
    InsertFirst(&head, 200);
    InsertFirst(&head, 100);

    Display(head);

    InsertLast(&head, 400);
    InsertLast(&head, 500);

    iRet = FindMiddleNode(&head);
    cout << "Middle of the elements are : " << iRet;

    return 0;
}