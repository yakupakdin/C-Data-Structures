// node operations (add to first queue /add to last queue/add to center queue)

#include <iostream>;

using namespace std;
struct node {
    int sayi;
    node* next;

};
node* ilk = NULL;
node* son = NULL;
node* q = NULL;


void basa_ekle(int ekle)//add to first queue
{
    node* p;
    p = new node();
    p->sayi = ekle;
    p->next = ilk;
    if (ilk == NULL)
        son = p;
    ilk = p;


}
int sona_ekle(node* ki) {//add to last queue
    if (son->next == NULL)
    {
        son->next = ki;
        son = ki;
        son->next = NULL;

    }


    return 0;
}
void araya_ekle(int y)//add to center queue
{

    node* ara;
    ara = new node();
    ara->sayi = y;

    q = ilk;
    while (q->next->sayi != 1)
    {
        q = q->next;
    }
    node* onune;
    onune = q->next;
    q->next = ara;
    ara->next = onune;
}
void ara()//searching operation and multiples of 3
{
    node* ara;
    ara = new node();
    ara = ilk;
    while (ara != NULL)
    {
        if (ara->sayi % 3 == 0)
        {
            cout << ara->sayi << "\t";

        }
        ara = ara->next;
    }



}
void bastan_sil()//deleting the first value
{
    node* ikinci = NULL;
    ikinci = ilk->next;
    free(ilk);
    ilk = ikinci;


}
void sondan_sil()//deleting the last value
{
    node* sononcesi;
    sononcesi = ilk;
    while (sononcesi->next->next != NULL)
    {
        sononcesi = sononcesi->next;
    }
    free(sononcesi->next);
    sononcesi->next = NULL;

}
void aradan_sil(int x)//deleting the center value
{
    if (ilk->sayi == x)
    {
        bastan_sil();//yanlışıkla ilk eleman girilirse hata vermesin baştan silsin...
    }
    node* orta = NULL;
    node* sonra = NULL;
    q = ilk;

    while (q->next->sayi != x)
    {
        q = q->next;
    }
    if (q->next == NULL)
    {
        sondan_sil();
    }
    orta = q;
    sonra = q->next->next;
    free(q->next);
    orta->next = sonra;


}

int yaz() {//writing to command window
    node* p;
    p = ilk;
    if (p == NULL)
    {
        cout << "Liste Bos" << endl;
        return -1;
    }
    while (p) {
        cout << p->sayi << endl;
        p = p->next;



    }

    return 0;
}


int main()
{
    node* x;

    cout << "basa_ekle fonksiyonu " << endl;//insert operation
    basa_ekle(9);
    basa_ekle(19);
    basa_ekle(29);
    basa_ekle(39);
    basa_ekle(49);



    yaz();
    cout << "********************************************" << endl;
    cout << "sona_ekle fonksiyonu " << endl;
    x = new node();
    x->sayi = 1;
    sona_ekle(x);
    x = new node();
    x->sayi = 21;
    sona_ekle(x);
    x = new node();
    x->sayi = 31;
    sona_ekle(x);
    x = new node();
    x->sayi = 41;
    sona_ekle(x);
    x = new node();
    x->sayi = 51;
    sona_ekle(x);


    yaz();
    cout << "********************************************" << endl;
    cout << "araya_ekle fonksiyonu " << endl;

    araya_ekle(5);

    araya_ekle(15);

    araya_ekle(25);

    araya_ekle(35);


    araya_ekle(45);


    yaz();
    cout << "********************************************" << endl;
    cout << "ara fonksiyonu ile 3 un katlari " << endl;
    ara();//searching function
    cout << "\n********************************************" << endl;
    cout << "bastan_sil fonksiyonu  " << endl;
    bastan_sil();
    bastan_sil();
    bastan_sil();
    yaz();
    cout << "********************************************" << endl;
    cout << "sondan_sil fonksiyonu  " << endl;
    sondan_sil();
    sondan_sil();
    sondan_sil();
    yaz();
    cout << "\n********************************************" << endl;
    cout << "aradan_sil fonksiyonu  " << endl;
    int a;
    cout << "Hangi eleman silinsin" << endl;
    cin >> a;
    aradan_sil(a);
    cout << "Guncel Liste" << endl;

    yaz();

}
