/*
Path Sum Root to Leaf
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
*/
void path_sum_rootToLeaf(node*root,vector<int>v1,int sum,int k)
{

    if(root==NULL)
    return; 
    
    v1.push_back(root->data);
    sum=sum+v1.back();
    if(root->lc==NULL && root->rc==NULL)
    {
           if(sum==k)
           {
               for(int i=0;i<v1.size();i++)
               cout<<v1[i]<<" ";
               
           }
           else 
		   {
		   	sum=sum-v1.back();
		   v1.pop_back();
	}
           cout<<endl;
    }
    path_sum_rootToLeaf(root->lc,v1,sum,k);
    path_sum_rootToLeaf(root->rc,v1,sum,k);

}
