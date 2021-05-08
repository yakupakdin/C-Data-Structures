// 191307008 YAKUP YASİN AKDİN  

#include <iostream>
using namespace std;


struct node {

    int data;
    struct node* left;
    struct node* right;
};
typedef struct node BTREE;
BTREE* BSTTek = NULL;
BTREE* BSTCift = NULL;
BTREE* asil = NULL;

BTREE* new_node(int data) {
    BTREE* p = new BTREE;
        p->data = data;
        p->left = NULL;
        p->right = NULL;
        return p;
}
BTREE* insert(BTREE* root, int data) {
    if (root != NULL)//ağaç boş değilse
    {
        if (data < root->data)//ekelenecek veri rootun datasından küçükse
            root->left = insert(root->left, data);
        //ekelenecek veri rootun datasından büyük veya eşitse
        else
            root->right = insert(root->right, data);
    }
    else//ağaç boş ise
        root = new_node(data);//kök düğüm
    return root;



}
void preorder(BTREE* root)
{
    if (root != NULL)
    {
        cout << root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}//kök-sol-sağ
BTREE* ayrac(BTREE*root, int data)
{
    if (root!=NULL)
    {
        if (data%2==0)
        {
            BSTCift = insert(BSTCift, data);

            
         
        }
        else
        {
            BSTTek = insert(BSTTek, data);
        }

        
        

       
        
   
    }
    return NULL;
}
int toplamcarpim=0;
int carpim(BTREE* root, int data) 
{
    
    if (root != NULL)
    {
        if (toplamcarpim!=0)
        {
            toplamcarpim = root->data * root->left->data * root->right->data;
        }
        else
        {
            toplamcarpim= toplamcarpim* root->left->data * root->right->data;
        }
        if (toplamcarpim==data)
        {
            cout<< toplamcarpim<<" = "<<data ;
        }
        else
        {
            cout << "Girilen data ve carpimlar esit degil";
        }

    }
    return NULL;
}
bool  carpimbool(BTREE* root, int data) 
{

    if (root != NULL)
    {
        if (toplamcarpim != 0)
        {
            toplamcarpim = root->data * root->left->data * root->right->data;
        }
        else
        {
            toplamcarpim = toplamcarpim * root->left->data * root->right->data;
        }

        if (toplamcarpim == data)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;



}

int main()
{
    asil = insert(asil, 10);
    asil = insert(asil, 11);
    asil = insert(asil, 12);
    asil = insert(asil, 9);
    asil = insert(asil, 8);
    asil = insert(asil, 7);
    asil = insert(asil, 5);
    asil = insert(asil, 0);
    asil = insert(asil, 16);
    asil = insert(asil,13);

    preorder(asil);
    cout << endl;
    ayrac(asil, 10);
    ayrac(asil, 11);
    ayrac(asil, 12);
    ayrac(asil, 9);
    ayrac(asil, 8);
    ayrac(asil, 7);
    ayrac(asil, 5);
    ayrac(asil, 0);
    ayrac(asil, 16);
    ayrac(asil,13);
    cout << endl;
    cout << " BSTCift" << endl;
    preorder(BSTCift);
    cout << endl;
    cout << " BSTTek" << endl;
    preorder(BSTTek);
    cout << endl;
    cout << "Carpim Degeri Giriniz : ";
    int giris;
    cin >> giris;
    cout<<carpim(asil, giris);
    cout << endl;
   cout<< carpimbool(asil, giris);


}// double and single operations for node

#include <iostream>
using namespace std;


struct node { //node definiton

    int data;
    struct node* left;
    struct node* right;
};
typedef struct node BTREE; //so that we don't use pointers
BTREE* BSTTek = NULL;
BTREE* BSTCift = NULL;
BTREE* asil = NULL;

BTREE* new_node(int data) {//When the program runs, a new tree will be created.
    BTREE* p = new BTREE;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
BTREE* insert(BTREE* root, int data) {
    if (root != NULL)//if root not null
    {
        if (data < root->data)//if the data is less than the tree's data
            root->left = insert(root->left, data);
        //if the data to be added is greater than or equal to the root data
        else
            root->right = insert(root->right, data);
    }
    else//if root  null
        root = new_node(data);//new node
    return root;



}
void preorder(BTREE* root)//preorders sort(root,left,right)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
BTREE* ayrac(BTREE* root, int data)//single and double seperator operation
{
    if (root != NULL)
    {
        if (data % 2 == 0)
        {
            BSTCift = insert(BSTCift, data);



        }
        else
        {
            BSTTek = insert(BSTTek, data);
        }







    }
    return NULL;
}
int toplamcarpim = 0;
//int carpim(BTREE* root, int data)   I don't know what's going on here:((((
//{
//
//    if (root != NULL)
//    {
//        if (toplamcarpim != 0)
//        {
//            toplamcarpim = root->data * root->left->data * root->right->data;
//        }
//        else
//        {
//            toplamcarpim = toplamcarpim * root->left->data * root->right->data;
//        }
//        if (toplamcarpim == data)
//        {
//            cout << toplamcarpim << " = " << data;
//        }
//        else
//        {
//            cout << "Girilen data ve carpimlar esit degil";
//        }
//
//    }
//    return NULL;
//}
//bool  carpimbool(BTREE* root, int data)
//{
//
//    if (root != NULL)
//    {
//        if (toplamcarpim != 0)
//        {
//            toplamcarpim = root->data * root->left->data * root->right->data;
//        }
//        else
//        {
//            toplamcarpim = toplamcarpim * root->left->data * root->right->data;
//        }
//
//        if (toplamcarpim == data)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//
//    }
//    return false;
//
//
//
//}

int main()
{
    asil = insert(asil, 10);
    asil = insert(asil, 11);
    asil = insert(asil, 12);
    asil = insert(asil, 9);
    asil = insert(asil, 8);
    asil = insert(asil, 7);
    asil = insert(asil, 5);
    asil = insert(asil, 0);
    asil = insert(asil, 16);
    asil = insert(asil, 13);

    preorder(asil);
    cout << endl;
    ayrac(asil, 10);
    ayrac(asil, 11);
    ayrac(asil, 12);
    ayrac(asil, 9);
    ayrac(asil, 8);
    ayrac(asil, 7);
    ayrac(asil, 5);
    ayrac(asil, 0);
    ayrac(asil, 16);
    ayrac(asil, 13);
    cout << endl;
    cout << " BSTCift" << endl;
    preorder(BSTCift);
    cout << endl;
    cout << " BSTTek" << endl;
    preorder(BSTTek);
    cout << endl;
    /*cout << "Carpim Degeri Giriniz : ";
    int giris;
    cin >> giris;
    cout << carpim(asil, giris);
    cout << endl;
    cout << carpimbool(asil, giris);*/


}



