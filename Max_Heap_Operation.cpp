//Max Heap Operation

#include <iostream>
using namespace std;
struct node {
    int data;

    struct node* left;
    struct node* right;
};
typedef struct node MaxHeap;
int number = 0;
MaxHeap* new_node(int data) {
    MaxHeap* p = new MaxHeap;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    number++;
    return p;
}
//ekleme 
MaxHeap* insert(MaxHeap* root, int data)//insert for max heap

{
    if (root != NULL)
    {

        if (number % 2 == 1)
        {
            root->left = insert(root->left, data);

        }


        else if (number % 2 == 0)
        {
            root->right = insert(root->right, data);

        }


    }
    else//if tree null
        root = new_node(data);//kök düğüm

    return root;
}

MaxHeap* swap(MaxHeap* root, int data)
{
    MaxHeap* gecici;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->left > root)
        {
            gecici = root->left;
            root->left = root;
            root = gecici;
        }
        else if (root->right > root)
        {
            gecici = root->right;
            root->right = root;
            root = gecici;
        }

    }
}

int leftheight(MaxHeap* root)//Heap left lenght
{

    if (root == NULL)
        return -1;
    else
    {
        int left_height;
        left_height = leftheight(root->left);


        return left_height + 1;
        cout << "Agac boyu" << left_height + 1 << endl;



    }

}
MaxHeap* sil(MaxHeap* root, int data) {//  delete operation for heap
    MaxHeap* p, * q;
    if (root == NULL)//if tree is null
    {
        return NULL;
    }
    if (root->data == data)//If the wanted is found
    {
        //1.case (yaprak düğüm) leaf loop
        if (root->left == root->right)
        {
            free(root);

            return NULL;
        }
        //2.case (tek çocuklu düğüm silinecekse) If a single-child node is to be deleted
        else
        {
            if (root->left == NULL)
            {
                p = root->right;
                free(root);
                return p;
            }
            else if (root->right == NULL)
            {
                p = root->left;
                free(root);
                return p;
            }
            //3.case 
            else
            {
                p = q = root->right;//20
                while (p->left != NULL)//20 nini alt tarafında çocuk olduğunu
                    p = p->left;
                p->left = root->left;
                free(root);
                return q;


            }
        }
    }
    else if (root->data < data)//If the search is not found
    {
        root->right = sil(root->right, data);

    }
    else
    {
        root->left = sil(root->left, data);

    }
    return root;

}
int rightheight(MaxHeap* root)
{
    if (root == NULL)
        return -1;
    else
    {
        int right_height;
        right_height = rightheight(root->right);
        return right_height + 1;
        cout << "Agac boyu" << right_height + 1 << endl;
    }
}
void inorder(MaxHeap* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

}//sol-kok-sağ
int main()
{
    MaxHeap* ykp = NULL;
    //  15, 7, 12, 28, 36, 1, 37, 13, 4, 25, 3, 9, 27, 2, 5, 16
    ykp = insert(ykp, 15);
    ykp = insert(ykp, 7);
    ykp = insert(ykp, 12);
    ykp = insert(ykp, 28);
    ykp = insert(ykp, 36);
    ykp = insert(ykp, 1);
    ykp = insert(ykp, 37);
    ykp = insert(ykp, 13);
    ykp = insert(ykp, 4);
    ykp = insert(ykp, 25);
    ykp = insert(ykp, 3);
    ykp = insert(ykp, 9);
    ykp = insert(ykp, 27);
    ykp = insert(ykp, 2);
    ykp = insert(ykp, 5);
    ykp = insert(ykp, 16);


    cout << "Yigin insa ediliyor" << endl;
    cout << "Olusan agacin inorder siralamasi" << endl;
    inorder(ykp);
    cout << endl;
    cout << "**************" << endl;
    cout << "Kok Dugum: " << 37 << endl;
    sil(ykp, 37);
    cout << "**************" << endl;
    cout << "Kok Dugum Cikarildi" << endl;
    cout << "Yeni agacin inorder siralamasi" << endl;
    inorder(ykp);










}


