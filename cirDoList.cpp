#include<iostream>
using namespace std;
class node
{
  int data;
  node* nxt;
  node* pre;
}*start;
void createNodeList(int n)
{
  node *nxtNode,*temp;
  start=new node;
  if(start==NULL) cout<<"Memory cannot be allocated.\n";
  else
  {
    cout<<"Enter the data in 1st node.\n";
    cin>>start->data;
    start->nxt=NULL;
    start->pre=NULL;
    temp=start;
    for(int i=2;i<=n;i++)
    {
      nxtNode=new node;
      if(nxtNode==NULL) cout<<"Cannot create node further.\n";
      else
      {
        cout<<"Enter the data in "<<i<<"st node.\n";
        cin>>nxtNode->data;
        nxtNode->pre=temp;
        nxtNode->nxt=NULL;
        temp->nxt=nxtNode;
        temp=nxtNode;
      }
    }
  }
}
void main()
{

}
