#include<iostream>
using namespace std;
#define N 4
int k=0,temp[N*N],i=0;

struct node
{
    int row;
    int col;
    int data;
};
node* heap[N];
int inse(node *n)
{

        k=k+1;
        heap[k]=n;
        int ptr=k,pptr=ptr/2;
        while(pptr>=1 && heap[ptr]->data<heap[pptr]->data)
        {
            node*t=heap[pptr];
            heap[pptr]=heap[ptr];//swap ptr& pptr
            heap[ptr]=t;

            ptr=pptr;
            pptr=pptr/2;
        }
    return 0;
}

int shift_node()
{
    int ptr=1,flag=0,pptr;
    while(flag==0)
    {

        pptr=ptr;
    if((2*pptr)<=k && heap[ptr]->data>heap[pptr*2]->data)
        ptr=pptr*2;
    if((2*pptr+1)<=k && heap[ptr]->data>heap[2*pptr+1]->data)
        ptr=2*pptr+1;
    if(ptr==pptr)
        flag=1;
    else
    {
        node *t=heap[ptr];
        heap[ptr]=heap[pptr];
        heap[pptr]=t;
    }

    }
   return 0;
}

node * delet_root()
{
    node *root=heap[1];
    heap[1]=heap[k];
    cout<<" "<<root->data;
    k=k-1;
    shift_node();
    return root;
}

void printSorted(int mat[][N])
{
    for(int i=0;i<N;i++)
    {
        node *q=new node;
        q->row=i;
        q->col=0;
        q->data=mat[i][0];
        inse(q);
    }
    for(int i=0;i<N*N;i++)
    {
        node *p=delet_root();
        if(p->col+1<N)
        {
              node *t=new node;
              t->row=p->row;
              t->col=p->col+1;
              t->data=mat[p->row][p->col+1];
              inse(t);
        }
    }

}


int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}






/*#include<iostream>
using namespace std;
#define N 4
int k=0,temp[N*N],i=0;

struct node
{
    int row;
    int col;
    int data;
};
node *heap[N];
int inse(node *n)
{

        k=k+1;
        heap[k]=n;
        int ptr=k,pptr=ptr/2;
        while(pptr>=1 && heap[ptr]->data<heap[pptr]->data)
        {
            node*t=heap[pptr];
            heap[pptr]=heap[ptr];//swap ptr& pptr
            heap[ptr]=t;

            ptr=pptr;
            pptr=pptr/2;
        }
    return 0;
}

int shift_node()
{
    int ptr=1,flag=0,pptr;
    while(flag==0)
    {

        pptr=ptr;
    if((2*pptr)<=k && heap[ptr]->data>heap[pptr*2]->data)
        ptr=pptr*2;
    if((2*pptr+1)<=k && heap[ptr]->data>heap[2*pptr+1]->data)
        ptr=2*pptr+1;
    if(ptr==pptr)
        flag=1;
    else
    {
        node *t=heap[ptr];
        heap[ptr]=heap[pptr];
        heap[pptr]=t;
    }

    }
   return 0;
}

node * delet_root()
{
    node *root=heap[1];
    heap[1]=heap[k];
    cout<<" "<<root->data;
    k=k-1;
    shift_node();
    return root;
}

void printSorted(int mat[][N])
{
    node * heap=new node[N];
    for(int i=0;i<N;i++)
    {
        heap[i].row=i;
        heap[i].col=0;
        heap[i].data=mat[i][0];
        inse(&heap[i]);
    }
    for(int i=0;i<N*N;i++)
    {
        node *p=delet_root();
        if(p->col+1<N)
        {
              node *t=new node;
              t->row=p->row;
              t->col=p->col+1;
              t->data=mat[p->row][p->col+1];
              inse(t);
        }
    }

}


int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}
*/
