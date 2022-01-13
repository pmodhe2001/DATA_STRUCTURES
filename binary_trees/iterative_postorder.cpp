#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class node{
    public:
    node*lc,*rc;
    int data;
    node(int data){
        this->data=data;
        lc=rc=NULL;
    }
};
class tree{
    public:
    node*root;

};
node*create_bt(){
    queue<node*>q;
    int x,y,r;
    cout<<"enter root data :";
    cin>>r;
    node*root=new node(r);
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        cout<<"enter left cbild of "<<temp->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            node*ln=new node(x);
            temp->lc=ln;
            q.push(ln);

        }
        cout<<"enter right child of "<<temp->data<<endl;
        cin>>y;
        if(y!=-1)
        {
            node*rn=new node(y);
            temp->rc=rn;
            q.push(rn);
        }
    }

    return root;
}
void postorder(node*root){
    stack<node*>st;
    node*temp=root;
    node*temp2;
    while(temp!=NULL || !st.empty())
    {
        if(temp!=NULL)
        {
            st.push(temp);
            temp=temp->lc;
        }
        else{
        temp=st.top();
        st.pop();
        temp=temp->rc;
    

    }
    }
}
int main()
{
    node*root=create_bt();
    postorder(root);
}