//operations on hash table.
#include <iostream>
using namespace std;
#define size 250


class Hash // hash define operation.
{
public:
	int data;
	int data2;
	Hash(int data,int data2) 
	{
		this->data = data;
		this->data2 = data2;
	}

};

class Hashtablosu { //hash table define operation.
private:
	Hash ** t;
public:
	Hashtablosu() {
		t = new Hash * [size];
		for (int i = 0; i < size; i++)
		{
			t[i] = NULL;
		}
	}
	int Hashfonk(int k) { return k % size; }


	void insert(int data, int data2)//Adding data to the hash table
	{
		int H = Hashfonk(data);
		while (t[H]!=NULL && t[H]->data!=data)
		{
			H = Hashfonk(H + 1);

		}
		if (t[H]!=NULL)
			delete t[H];
		t[H] = new Hash(data, data2);
		
	}
	int Search(int data)//Searching data to the hash table
	{
		int H = Hashfonk(data);
		while (t[H]!=NULL&&t[H]->data!=data)
		{
			H = Hashfonk(H + 1);
		}
		if (t[H]==NULL)
		{
			return -1;
		}
		else
		{
			return t[H]->data2;
		}
	}
	void remove(int data)//Deleting data to the hash table
	{
		int H = Hashfonk(data);
		while (t[H]!=NULL)
		{
			if (t[H]->data == data)
				break;
			H = Hashfonk(H + 1);

			
		}
		if (t[H]==NULL)
		{
			cout << "Eleman Bulunamadi" << endl;
			return;
		}
		else {
			delete t[H];
		}
		cout << "Eleman silindi" << endl;
	}
	

};

int main()
{

	//option section
	Hashtablosu hash;
	int data, data2;
	int giris;
	while (1) {
		cout << "1.Tabloya eleman ekle" << endl;
		cout << "2.Eleman arama" << endl;
		cout << "3.Tablodan eleman silme" << endl;
		cout << "4.Cikis" << endl;
		cout << "Secimini giriniz: ";
		cin >> giris;
		switch (giris) {
		case 1:
			cout << "~ Eklenecek Elemani gir ~ ";
			cout << endl;
			cin >> data2;
			cout << "Eklenen elemanin anahtarini gir: ";
			
			cin >> data;
			hash.insert(data, data2);
			break;
		case 2:
			cout << "~ Aranacak elemanin anahtarini gir ~ ";
			cout << endl;
			cin >> data;
			if (hash.Search(data) == -1) {
				cout << "Anahtarda oge bulunamadi " << data << endl;
				cout << endl;
				
			}
			
			else {
				cout << "Anahtardaki oge " << data << " : ";
				cout << hash.Search(data) << endl;
			}
			break;
		case 3:
			cout << " ~ Silinecek ogenin anahtarini giriniz ~ ";
			cout << endl;
			cin >> data;
			hash.remove(data);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nLutfen dogru secenegi secin\n";
		}
	}
	return 0;
}