#include<bits/stdc++.h>
using namespace std;
class node
{
  public:
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
    start->nxt=start;
    start->pre=start;
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
        if(i==n) start->pre=nxtNode;
        nxtNode->pre=temp;
        if(i==n) nxtNode->nxt=start;
        else nxtNode->nxt=NULL;
        temp=nxtNode;
      }
    }
  }
}
void displayList()
{
  node *tmpdisp=start;
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
void insertBeg()
{
  int begData;
  node *tempbeg;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    tempbeg=new node;
    if(tempbeg==NULL) cout<<"Insertion not possible.\n";
    else
    {
      cout<<"Enter the data value you want to store at the beginning of the list. \n";
      cin>>begData;
      tempbeg->data=begData;
      if ((start->nxt==start) && (start->pre==start))
      {
        tempbeg->nxt=start;
        tempbeg->pre=start;
        start->pre=tempbeg;
        start->nxt=tempbeg;
        start=tempbeg;
      }
      else
      {
        tempbeg->pre=start->pre;
        start->pre=tempbeg;
        tempbeg->nxt=start;
        (tempbeg->pre)->nxt=tempbeg;
        start=tempbeg;
      }
    }
  }
}
void insertEnd()
{
  int endData;
  node *tempend;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    tempend=new node;
    if (tempend==NULL) cout<<"Insertion at the end not possible.\n";
    else
    {
      cout<<"Enter the data value you want to store at the ending of the list. \n";
      cin>>endData;
      tempend->data=endData;
      tempend->pre=start->pre;
      (start->pre)->nxt=tempend;
      tempend->nxt=start;
      start->pre=tempend;
    }
  }
}
void insertBet()
{
  int betData,pos,i=2;
  node *tempbet,*temp;
  temp=start;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    cout<<"Enter the position at which you want to store your data in list.\n";
    cin>>pos;
    do
    {
      if (i==pos)
      {
        tempbet=new node;
        if (tempbet==NULL) cout<<"Insertion not possible.\n";
        else
        {
          cout<<"Enter the data value which you want to store in list.\n";
          cin>>betData;
          tempbet->data=betData;
          tempbet->pre=temp;
          tempbet->nxt=temp->nxt;
          (temp->nxt)->pre=tempbet;
          temp->nxt=tempbet;
        }
      }
      temp=temp->nxt;
      i++;
    } while (temp!=start);
    if (i!=pos) cout<<"Position entered is incorrect.\n";
  }
}
void delBeg()
{
  node *temp;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    if ((start->nxt==start) && (start->pre)) start=NULL;
    else
    {
      temp=(start->nxt);
      temp->pre=start->pre;
      (start->pre)->nxt=temp;
      delete start;
      start=temp;
    }
  }
}
void delEnd()
{
  node *temp;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    if ((start->pre==start) && (start->nxt==start)) start=NULL;
    else
    {
      temp=(start->pre)->pre;
      temp->nxt=start;
      delete start->pre;
      start->pre=temp;
    }
  }
}
void delBet()
{
  int pos,i=1;
  node *tempbet=start,*temp;
  if(start==NULL) cout<<"Linked List not found/created.\n";
  else
  {
    cout<<"Enter the position of the node which you want to delete.\n";
    cin>>pos;
    do
    {
      if (i==pos)
      {
        if ((start->nxt==start) && (start->pre==start)) start=NULL;
        else if ((start->nxt==start->pre) && (start->pre!=start))
        {
          temp=start->nxt;
          delete start;
          temp->nxt=temp;
          temp->pre=temp;
          start=temp;
        }
        else
        {
          temp=tempbet;
          (temp->nxt)->pre=temp->pre;
          (temp->pre)->nxt=temp->nxt;
          delete tempbet;
        }
        break;
      }
      tempbet=tempbet->nxt;
      i++;
    } while (tempbet!=start);
    if (i!=pos) cout<<"Position entered is incorrect.\n";
  }
}
void search()
{
  int sdata,i=1,flag=0;
  node *temp=start;
  if(start==NULL) cout<<"Starting Node Absent. Cannot search data in the Linked list.\n";
  else
  {
    cout<<"Enter the data to be searched in the linked list.\n";
    cin>>sdata;
    do
    {
      if (temp->data==sdata)
      {
        flag=1;
        cout<<"Data to be searched was found at "<<i<<" position in the linked list.\n";
      }
      temp=temp->nxt;
      i++;
    } while (temp!=start);
    if (flag==0) cout<<"Data to be searched couldn't be found in the linked list.\n";
  }
}
int main()
{
  int n,ch,c1,c2;
  cout<<"Operations for Linked List are as follows.\n";
  while (ch!=6)
  {
    cout<<"Enter: \t1 for Creation\n\t2 for Displaying\n\t3 for Insertion\n\t4 for Deletion\n\t5 for Searching of Data\n\t6 for Exiting.\n";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter the no. of nodes you want to create.\n";
              cin>>n;
              createList(n);
              break;
      case 2: displayList();
              break;
      case 3: cout<<"Enter: \t1 for inserting data at the beginning\n\t2 for inserting data at the end\n\t3 for inserting data in between of the circular linked list.\n";
              cin>>c1;
              switch (c1)
              {
                case 1: insertBeg();
                        break;
                case 2: insertEnd();
                        break;
                case 3: insertBet();
                        break;
                default:cout<<"Invalid Choice. Please perform operation again.\n";
              }
              break;
      case 4: cout<<"Enter: \t1 for deleting data at the beginning\n\t2 for deleting data at the end\n\t3 for deleting data in between of the circular linked list.\n";
              cin>>c2;
              switch (c2)
              {
                case 1: delBeg();
                        break;
                case 2: delEnd();
                        break;
                case 3: delBet();
                        break;
                default:cout<<"Invalid Choice. Please perform operation again.\n";
              }
              break;
      case 5: search();
      case 6: break;
      default:cout<<"Invalid Choice. Please perform operation again.\n";
    }
  }
  return 0;
}
