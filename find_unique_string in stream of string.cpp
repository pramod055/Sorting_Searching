#include <iostream>
#include<map>
#define MAX_CHAR 256
using namespace std;

// A linked list node
struct node
{
    string a;
    struct node *next, *prev;
};
node *w=new node;
// A utility function to append a character x at the end of DLL.
// Note that the function may change head and tail pointers, that
// is why pointers to these pointers are passed.
void appendNode(struct node **head_ref, struct node **tail_ref, string x)
{
    struct node *temp = new node;
    temp->a= x;
    temp->prev = temp->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}

// A utility function to remove a node 'temp' fromt DLL. Note that the
// function may change head and tail pointers, that is why pointers to
// these pointers are passed.
void removeNode(struct node **head_ref, struct node **tail_ref,
                struct node *temp)
{
    if (*head_ref == NULL)
        return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete(temp);
}

void findFirstNonRepeating()
{
    // inDLL[x] contains pointer to a DLL node if x is present in DLL.
    // If x is not present, then inDLL[x] is NULL
    //struct node *inDLL[MAX_CHAR];
     map < string,node*> m;

    // repeated[x] is true if x is repeated two or more times. If x is
    // not seen so far or x is seen only once. then repeated[x] is false
    //bool repeated[MAX_CHAR];
     map< string,node*> :: iterator it;
    // Initialize the above two arrays
    struct node *head = NULL, *tail = NULL;

    // Let us consider following stream and see the process
    string stream[]= {"asd","asd","qsder","asd","tscvd","dfdht","zxcv"};

    int len=sizeof(stream)/sizeof(stream[0]);
    for (int j = 0;j<len; j++)
    {
        string x= stream[j];
        cout << "\nAfter  Reading------>"<< x << "\n";

        //m.second.size();
        if(m[x]!=w)
        {
            if (m[x] == NULL)
            {
                //cout<<"\nhi";
                appendNode(&head, &tail, x);
                m[x]= tail;
            }
            else // Otherwise remove this caharacter from DLL
            {
                removeNode(&head, &tail, m[x]);
                m[x] =w;
                // Also mark it as repeated
            }

            if (head != NULL)
            cout << "\nFirst non-repeating character so far is-----> " << head->a << endl;
            else
                cout<<"\nNOT unique string:\n";

        }

        else
        if (head != NULL)
            cout << "\nFirst non-repeating character so far is ----->" << head->a << endl;
        else
            cout<<"\nNOT unique string:\n";



        // Print the current first non-repeating character from stream

    }
}

/* Driver program to test above function */
int main()
{
    findFirstNonRepeating();
    return 0;
}
