#include <iostream >

using namespace std;

struct node {
int no;
string ad;
string soyad;
int ort;
bool durum;
struct node * next;
};

struct node * yeniKayit (struct node * head, int no, string ad, string soyad, int ort)

{

	struct node *ogrenci = new node();
	ogrenci->no= no;
	ogrenci->ad= ad;
	ogrenci->soyad= soyad;
	ogrenci->ort= ort;
	ogrenci->durum = ort>=50 ? true: false;  // Durumu basarili mi degil mi diye karsilastirma


if ( head ==NULL)

	{
	head= ogrenci;
	head->next= NULL;
	cout<<head->no<<" numarali ogrenci listeye ilk kayit yapildi "<<endl;
	}
else
	{
	ogrenci->next= head;
	head= ogrenci;
	cout<<head->no<<" numarali ogrenci listeye kayit yapildi "<<endl;
	}

return head;
}
struct node * bastanSil( struct node * head)
{
	if(head==NULL)
	{
		cout<< " Liste bos, herhangi bir ogrenci kaydi yoktur.. " << endl;
	}
	else
	{
		if(head->next==NULL)
		{
			cout << head->no <<" numaralı ogrenci listeden silindi.. " << endl;
			delete head;
			head=NULL;
		}
		else
		{
			struct node * temp = head -> next;
			cout << head->no <<" numaralı ogrenci listeden silindi.. " << endl;
			delete head;
			head=temp;
		}
	}
	
	return head;
}
struct node * sondanSil( struct node * head)
{
	if(head==NULL)
	{
		cout<< " Liste bos, herhangi bir ogrenci kaydi yoktur.. " << endl;
	}
	else
	{
		if(head->next==NULL)
		{
			cout << head->no <<" numaralı ogrenci listeden silindi.. " << endl;
			delete head;
			head=NULL;
		}
		else
		{
			struct node * temp = head -> next;
			while( temp->next->next!= NULL)
			{
				temp= temp -> next;
			}
			cout << temp->next->no <<" numaralı ogrenci listeden silindi.. " << endl;
			delete temp->next;
			temp->next=NULL;
		}
	}
	
	return head; 
}

struct node* ara ( struct node * head, int key )
{
	bool sonuc=false;
	if (head==NULL)
	{
		cout<< " Liste bostur. " <<endl;
	}
	else
	{
		struct node* temp= head;
		while(temp!=NULL)
		{
			if(temp->no==key)
			{
				sonuc= true;
				cout<<key<< " numaralı ogrenci bilgileri su sekildedir: " << endl;
				
				cout<< " adi:   " << temp->ad << endl;
				cout<< " soyad:   " << temp->soyad << endl;
				cout<< " ortalama:   " << temp->ort << endl;
				cout<< " durum:   " << temp->durum << endl;
				break;
			}
		}
		if(!sonuc)
		{
			cout<<key<< " numarali kayit listede yoktur..."<< endl;
		}
	}
	return head;
}
struct node* bilgileriGetir ( struct node * head)
{
	if (head==NULL)
	{
		cout<< " Liste bostur. " <<endl;
	}
	else
	{
		struct node*temp= head;
		while(temp==NULL)
		{
			cout << temp->no << " numarali ogrencinin adi: "<< temp->ad <<
			" , soyadi: "<< temp->soyad<<" , ortalamasi: "<< temp->ort<< ", durumu: "<< temp->durum<< endl;
		}
		
	}
	return head;
}
int main(){
	int no, sayi , ort, secim;
	string ad, soyad;
	bool durum;
	struct node* head= NULL;
	
	while(1)
	{
		cout<< endl; // satir basi
		cout<<" Tek yonlu dogrusal bagli liste ile Ogrenci Kayit Uygulamasi " << endl;
		cout << "**********" << endl;
		cout << "1-- Yeni Kayit" << endl;
		cout << "2-- Bastan Sil" << endl;
		cout << "3-- Sondan Sil" << endl;
		cout << "4-- Kayit Ara" << endl;		
		cout << "5-- Tum bilgileri getir"<< endl;
		cout << "0-- CIKIS"<<endl;
		cin>> secim;
		switch(secim) 
		{
		case 1:
			cout<<" Yeni kaydi yapilacak ogrencinin bilgilerini giriniz.."<<endl;
			cout<<" numara :"; cin>>no;	
			cout<<" ad :"; cin>>ad;
			cout<<" soyad :"; cin>>soyad;
			cout<<" ortalama :"; cin>>ort;
			//Durumu almadık çünkü biz hesaplayacağız.
			head= yeniKayit( head, no, ad, soyad, ort);
		break;
		
		case 2: 
			head= bastanSil(head);
		break;
		
		case 3:
			head= sondanSil(head);
		break;
		
		case 4:
			cout <<" ogrenci numarasi :"; cin>>no;
			head=ara(head,no);	// Böyle bir numarali ogrenci var mi diye arama yapacak
		break;
		
		case 5:
			head= bilgileriGetir(head);
		break;
		
		case 0: cout << " Programdan cikiliyor..." << endl;
		return 0;
		
		default: cout <<" Hatali secim yaptiniz..." << endl;
		break;
    	}
	}
	return 0;
}
