/// Insert a node at the beginning of the list.

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

void InsertBegin( struct node** aFirst, int aNo ) {
    struct node* newn = NULL;

    newn = new struct node;
    newn->data = aNo;
    newn->next = NULL;

    if ( *aFirst == NULL ) {
        *aFirst = newn;
    }
    else {
        newn->next = (*aFirst);
        *aFirst = newn;
    }
}

void Display( struct node* aFirst ) {
    
    while( aFirst != NULL ) {
        cout << "| " << aFirst->data;
        aFirst = aFirst->next;
    }
    cout << " |->NULL\n";
}

int main()
{
    struct node* head = NULL;

    InsertBegin( &head, 300 );
    InsertBegin( &head, 200 );
    InsertBegin( &head, 100 );

    Display( head );

    return 0;
}