//preorder-postorder-inorder operations

#include <iostream>
using namespace std;

struct node //node definition operation
{
    int data;
   struct node* left;
   struct node* right;
   


};

typedef struct node BTREE;//object definition operation
BTREE* new_node(int data)
{
    BTREE* p=new BTREE;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}
BTREE * insert(BTREE* root,int sayi)//insert operation
{
    if (root!=NULL)
    {
        if (sayi < root->data)
            root->left = insert(root->left, sayi);
        else
            root->right = insert(root->right, sayi);
       
    }
    else
    {
        root = new_node(sayi);
       

    }
    

    return root;
}
void  preorder(BTREE*root)//preorder sort(root-left-right)
{
    if (root!=NULL)
    {
        cout << root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }


}
void inorder(BTREE*root)//inorder sort(left-root-right)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);

    }


}/
void postorder(BTREE* root)//postorder sort(left-right-root)
{
    if (root != NULL)
    {
        postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    }


}

int size(BTREE* root)// node size calculation
{
    if (root == NULL)
    {
        return 0;
        
    }
    else
    {
        
             return (size(root->left)) + (size(root->right) + 1);
    }
}


int height(BTREE* root) //node height calculation
{

    if (root == NULL)
        return -1;
    else
    {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);

        if (right_height > left_height)
        {
            return right_height + 1;
            cout << "Agac boyu" << right_height + 1 << endl;
        }
        else
        {
            return left_height + 1;
            cout << "Agac boyu" << left_height + 1 << endl;


        }
    }

}

int main()
{
	//insert values
    BTREE* agac = NULL;
    cout << "Veriler Ekleniyor" << endl;
    agac = insert(agac, 27);
    agac = insert(agac, 18);
    agac = insert(agac, 39);
    agac = insert(agac,14 );
    agac = insert(agac, 22);
    agac = insert(agac, 29);
    agac = insert(agac, 42);
    agac = insert(agac, 2);
    agac = insert(agac, 17);
    agac = insert(agac, 12);
    agac = insert(agac, 24);
    agac = insert(agac, 34);
    agac = insert(agac, 15);
    agac = insert(agac, 23);
    cout << "*****************"<<endl;
	//preorder sort
    cout << "preorder" << endl;
    preorder(agac);
    cout << endl;
    cout << "postorder" << endl;
	//postorder sort

    postorder(agac);
    cout << endl;
    cout << "inorder" << endl;
	//inorder sort

    inorder(agac);
    cout << endl;
    cout << "*****************" << endl;
    cout << "Dugum Sayisi : ";
   cout<< size(agac)<<endl;
   cout << "Agac Yuksekligi : ";

    cout<<height(agac);



}

