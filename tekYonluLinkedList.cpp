#include <iostream>
using namespace std; // cout fonksiyonun vs. çalýþmasý için

struct node {

int data;

struct node * next;

}; // yapýmýzý oluþturduk

struct node * basaEkle ( struct node * head, int key)

{

	if (head ==NULL )
	{
		struct node * temp = new node();
		
		temp->data= key;
		
		temp->next=NULL;
		
		head = temp;
		
		cout << " Ilk dugum oluþturuldu." << endl;
	
	}
	
	else {
	
		struct node * temp = new node();
		
		temp->data= key;
		
		temp->next=head ; // head yerine NULL yazarsan da sona ekleme iþlemi yapmýþ olursun.
		// Son düðüm hep NULL'u gösterir.  
		
		head = temp;
		
		cout << " Dugume ekleme islemi gerceklestirildi." << endl; // head ekleme yapýlarak güncellendi.
	
	}
return head;
}

int main() {
	struct node * head = NULL;
	head = basaEkle (head, 11);
	head = basaEkle (head, 22);
	head = basaEkle (head, 33);
	
	cout << head -> data << " ";
	cout << head -> next -> data<< " ";
	cout << head -> next -> next -> data<< " ";
	//En son eklenen sayý hep baþa geliyor.
	
	struct node * temp = head;
	while ( temp!=NULL)
	{
		cout<< temp -> data << " ";
		temp = temp -> next; // düðümler arasýnda trevars iþlemi gerçekleþtiriliyor. (gezinme)
	}
}
