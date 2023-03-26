#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* basaEkle(struct node* head, int key) {
    if (head == NULL) {
        struct node* temp = new node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
        cout << "Ilk dugum olusturuldu." << endl;
    }
    else {
        struct node* temp = new node();
        temp->data = key;
        temp->next = head;
        head = temp; // Head guncellendi.
        cout << "Listenin basina dugum ekleme islemi yapildi." << endl;
    }
    return head; 
}

struct node* soneEkle(struct node* head, int key) {
    if (head == NULL) {
        struct node* temp = new node();
        temp->data = key;
        temp->next = NULL;
        head = temp;
        cout << "Ilk dugum olusturuldu." << endl;
    }
    else {
        struct node* temp = new node(); 
        temp->data = key;
        temp->next = NULL; // Sona eklediğimiz için head değil NULL
        struct node* temp2 = head;
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp;
        cout << "Listenin sonuna dugum ekleme islemi yapildi." << endl;
    }
    return head; 
}

void verileriYazdir(struct node* head) {
    struct node* temp = head; // gecici dugum ile dongu
    while (temp != NULL) {
    	cout << " Linkedlist elemanlari asagidaki gibidir: "<< endl;
        cout << temp->data << " ";
        temp = temp->next; // Bir sonraki dugume gecis
    }
    cout << endl; 
}

void tumBilgileriYazdir(struct node* head) {
    struct node* temp = head; // gecici dugum ile dongu
    while (temp != NULL) {
    	cout << " Veriler asagidaki gibidir: "<< endl;
        cout << "Adres: " << temp << ", Veri: " << temp->data << ", Next: " << temp->next << endl;
        temp = temp->next; // Bir sonraki dugume gecis
    }
}

int main() {
    struct node* head = NULL; 
    int sayi, secim;

    while (1) { // Sonsuz döngü oluşturmak için while 1
        cout << endl;
        cout << "***********" << endl;
        cout << "Tek yonlu dogrusal bagli liste uygulamasi" << endl;
        cout << "1-- basa eleman ekle" << endl;
        cout << "2-- sona eleman ekle" << endl;
        cout << "3-- verileri yazdir" << endl;
        cout << "4-- listedeki tum bilgileri yazdir" << endl; // corrected spelling
        cout << "5-- CIKIS" << endl;
        cout << "***********" << endl;

        cin >> secim;
        switch (secim) {
        case 1:
    		cout << "Basa eklenecek sayi: " << endl;
		    cin >> sayi;
		    head = basaEkle(head, sayi);
		break;
		case 2:
		    cout << "Sona eklenecek sayi: " << endl;
		    cin >> sayi;
		    head = soneEkle(head, sayi);
		break;
		case 3:
    		verileriYazdir(head);
        break;
        case 4:
		    tumBilgileriYazdir(head);
		break;
		case 5:
		    cout << "Cikis yapildi." << endl;
		exit(0);
	}
}
}


        



