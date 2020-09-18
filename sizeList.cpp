#include<bits/stdc++.h>
using namespace std;
static int a=0;
class node
{
  public:
    int data;
    node* nxt;
    node* pre;
}*start;
void createList()
{
  /*int data;
  node *nxtNode;
  if ()
  cout<<"Enter the data to be inserted in the list.\n";
  cin>>data;
  if()*/
  a++;
}
int main()
{
  int n;
  while (n!=2)
  {
    //cout<<"Welcome:\t1)To enter the data on the doubly linked list --> PRESS 1.\n\t2)If Doubly Linked List is complete and you want to exit list creation --> PRESS 2.\n";
    cin>>n;
    createList();
    //if (n==1) createList();
    //if ((n!=1) && (n!=2)) cout<<"ERROR! Pressed incorrect key.\n";
  }
  cout<<a;
  return 0;
}
