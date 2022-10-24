#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  node *prev, *next;
};

node *nodeinsert(int value) {
  node *temp = new node();
  temp->data = value;
  temp->prev = temp->next = NULL;
  return temp;
}
node *addnode(node *node, int data) {
  if (node == NULL)
    return nodeinsert(data);

  if (data < node->data)
    node->prev = addnode(node->prev, data);
  else
    node->next = addnode(node->next, data);

  return node;
}
// Search In BST
node* search(node *node,int key){
    if(node== NULL)return NULL;
    if(node->data == key)return node;
    if(node->data > key)return search(node->prev,key);
    return search(node->next,key);

}
int main() {
  node *s = NULL;
cout<<"Enter the size ";
int size;
cin>>size;
cout<<"Enter the values";
for (int i = 0; i < size; i++)
{
    int n;
    cin>>n;
    s=addnode(s,n);
}
int num;
  cout<<"Input the value to be Searched for "<<endl;
    cin>>num;
    if(search(s,num)==NULL)cout<<"No Such Node Found";
    else cout<<"Node Found";
  
}