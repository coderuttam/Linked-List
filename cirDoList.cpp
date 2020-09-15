#include<iostream>
using namespace std;
class node
{
  int data;
  node* nxt;
  node* pre;
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
void displayList()
{
  int;
}
void main()
{
  int n,ch=0;
  cout<<"Operations for Linked List are as follows.\n";
  while (ch!=10)
  {
    cout<<"Enter: \t1 for Creation\n\t2 for Displaying\n\t3 for Insertion from beginning\n\t4 for Insertion from end\n\t5 for Insertion in between\n\t6 for Deletion from beginning\n\t7 for Deletion from end\n\t8 for Deletion in between\n\t9 for Searching of Data\n\t10 for Exiting.\n";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter the no. of nodes you want to create.\n";
              cin>>n;
              createList(n);
              break;
      case 2: displayList();
              break;
    //case 3: insertBeg();
              break;
    //case 4: insertEnd();
              break;
    //case 5: insert();
              break;
    //case 6: delBeg();
              break;
    //case 7: delEnd();
              break;
    //case 8: delbet();
              break;
    //case 9: search();
              break;
      default:break;
    }
  }
  return 0;
}
