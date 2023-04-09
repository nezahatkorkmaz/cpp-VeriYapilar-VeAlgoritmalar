#include <iostream>
#include <fstream>
using namespace std;
struct node {
	string plaka;
	string aracTipi;
	int ucret;
	struct node * next;
	struct node * prev;
};
struct node * head = NULL;

void ekle(string plaka, string aracTipi, int ucret){
	system("cls");
	system("cls");
	struct node * arac = new node();
	arac->plaka=plaka;
	arac->aracTipi=aracTipi;
	arac->ucret= ucret;
	if(head==NULL){
		head=arac;
		head->next=NULL;
		head->prev=NULL;
		cout<< head->plaka << " plakali arac otoparka alindi." <<endl;
	}
	else{
		arac->next=head;
		head->prev=arac;
		//Şimdi güncelleyelim headimizi=
		head=arac;
		head->prev=NULL;
		cout<< plaka << " plakali arac otoparka alindi." <<endl;
	}
}

void cikart(string plaka) {
	system("cls");
	if (head == NULL) {
	cout << "Otoparkta cikartilacak arac bulunmamaktadir." << endl;
	return;
	}
	if (head->plaka == plaka) {
	struct node* arac = head;
	head = head->next;
	delete arac;
	cout << plaka << " plakali arac otoparktan cikartilmistir." << endl;
	return;
	}
	struct node* temp = head;
	while (temp->next != NULL) {
		if (temp->next->plaka == plaka) {
			struct node* arac = temp->next;
			temp->next = arac->next;
			delete arac;
			cout << plaka << " plakali arac otoparktan cikartilmistir." << endl;
			return;
	}
	temp = temp->next;
}
cout << "Arac otoparkta bulunamadi." << endl;
}

void listele() {
	system("cls");
	if (head == NULL) {
	cout << "Otoparkta arac yoktur." << endl;
	return;
}
struct node* temp = head;
	while (temp != NULL) {
	cout << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
	temp = temp->next;
	}
}

void adet(){
    int adet= 0;
    if(head==NULL){
        cout << "Otoparkta arac yoktur."<< endl;
    }
    else{
        struct node * temp= head;
        while(temp->next!=NULL){
            adet++;
            temp=temp->next;
        }
        if(temp->next==NULL) adet++; // Son düğüm için
        cout << "Otoparktaki araç sayısı: " << adet << endl;
    }
}

void odeme(){
	int toplam= 0;
		if(head==NULL){
		cout << "Otoparkta arac yoktur."<< endl;
	}
	else{
		struct node * temp= head;
		while(temp->next!=NULL){
			toplam+=temp->ucret;
			temp=temp->next;
		}
		if(temp->next==NULL)toplam+=temp->ucret; // Son düğüm için
		cout << "Otoparktaki araclarin toplam ucreti "<< toplam << endl;
	}
}


int main(){
	
	int ucret, secim;
	string plaka, aracTipi;
	while(1)
{
	cout<<endl; // satır başı
	cout << " OTOPARK UYGULAMASI" << endl;
	cout << " 1-Arac Ekle" << endl;
	cout << " 2-Arac Cikart" << endl;
	cout << " 3-Otoparktaki Araclari Listele" << endl;
	cout << " 4-Arac Sayisini Hesapla" << endl;
	cout << " 5-Otoparktaki Araclarin Toplam Ucretini Hesapla" << endl;
	cout << " 0- Cikis" << endl;
	cin>>secim;
	switch(secim){
		case 1: cout <<"Otoparka eklemek istediginiz aracin bilgilerini giriniz."<< endl;
		cout<<" plaka : "; cin>>plaka;
		cout<<" plaka : "; cin>>aracTipi;
		cout<<" plaka : "; cin>>ucret;
		ekle(plaka,aracTipi,ucret);
		break;
		case 2: cout <<"Otoparktan cikartmak istediginiz aracin bilgilerini giriniz."; cin>>plaka;
		cikart(plaka);
		break;
		case 3: listele();
		break;
		case 4: adet();
		break;
		case 5: odeme();
		break;
		case 0:cout <<"Program sonlandiriliyor"<< endl;
		break;
		default: cout << "Gecersiz giris" << endl;
	}
}

	return 0;
}
