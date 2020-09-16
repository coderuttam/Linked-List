#include<bits/stdc++.h>
using namespace std;
class node
{
  public:
    int data;
    node* nxt;
}*start;
void createList(int n)
{
  node *nxtNode,*temp;
  start=new node;
  if(start==NULL) cout<<"Memory cannot be allocated.\n";
  else
  {
    cout<<"Enter the data in 1st node.\n";
    cin>>start->data;
    start->nxt=start;
    temp=start;
    for(int i=2;i<=n;i++)
    {
      nxtNode=new node;
      if(nxtNode==NULL) cout<<"Cannot create node further.\n";
      else
      {
        cout<<"Enter the data in "<<i<<"st node.\n";
        cin>>nxtNode->data;
        temp->nxt=nxtNode;
        if(i==n) nxtNode->nxt=start;
        temp=nxtNode;
      }
    }
  }
}
void displayList()
{
  node *tmpdisp=start,*tmpnxt=tmpdisp->nxt;
  if (start==NULL) cout<<"Unable to display linked list. List is either not created or it is currently empty.\n";
  else
  {
    printf("Data entered in the list is :\n");
    int a=1;
    do
    {
      cout<<"The data at "<<a<<" node is. "<<tmpdisp->data<<endl;
      a++;
      tmpdisp=tmpdisp->nxt;
    } while (tmpdisp!=start);
  }
}
int main()
{
  int n;
  cout<<"Enter the no. of nodes you want to create.\n";
  cin>>n;
  createList(n);
  displayList();
  return 0;
}
