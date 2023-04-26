#include <iostream>
using namespace std;

#define SIZE 10
#define PIDE_UCRETI 3

struct node{
	string ad;
	int adet;
	int ucret;
	struct node * next;
};
struct queue{
	int index;
	struct node * front;
	struct node * rear;
};
void baslangicDegerleriniAta(queue * q){
	q->index = 0;
	q->rear= q->front = NULL;
}
bool doluMu(queue * q){
	return (q->index==SIZE);
}
bool bosMu(queue * q){
	return (q->index==0);
}
void ekle(queue* q, string ad, int adet) {
    if (doluMu(q)) {
        cout << "Kuyrugumuz doludur..Yeni musteri alamayiz..." << endl;
        exit(0);
    }
    else {
        node* eleman = new node;
        eleman->ad = ad;
        eleman->adet = adet;
        eleman->ucret = adet * PIDE_UCRETI;
        eleman->next = NULL;

        if (bosMu(q)) {
            q->front = q->rear = eleman;
        }
        else {
            eleman->next = q->rear;
            q->rear = eleman;
        }
        q->index++;
    }
    cout << ad << " kuyruga girdi." << endl;
}

void sil(queue*q, string ad, int adet){
	if(bosMu(q)){
	cout<<"Kuyrukta bekleyen musteri yoktur.."<<endl;
	exit(0);
	}
	else if(q->index==1){
		delete q->front;
		q->front = q->rear = NULL;
		q->index --; //Sıfırlandı
	}
	else{
		struct node * temp = q-> rear;
		while(temp->next!= q->front){
			temp= temp->next;
		}
		string ad = q->front->ad;
		int ucret = q->front->ucret;
		
		delete q->front;
		q->front=temp;
		q->front->next=NULL;
		q->index--;
	}
	int ucret=PIDE_UCRETI*adet;
	cout<<ad<<" pidesini aldi ve "<<ucret<<" TL odeme yaparak siradan ayrildi.. "<<endl;
}

void yazdir(queue * q){
	system("cls");
	
	if(bosMu(q)) cout<<"Bekleyen musteri yoktur.."<<endl;
	else{
		struct node * temp = q->rear;
		while(temp->next!=NULL){
			cout<<temp->ad<< " -> ";
			temp=temp->next;
		}
		cout<<temp->ad<< " "; // En sonuncu müşteri için
	}
}


int main(){
	queue qu;
	baslangicDegerleriniAta(&qu);
	int adet, secim;
	string ad;
	while(1){
		cout<<endl<<"PIDECI KUYRUGU UYGULAMASI"<<endl;
		cout<<"1--musteri ekle"<<endl;
		cout<<"2--musteri cikart"<<endl;
		cout<<"3--sirada bekleyen musterileri goster"<<endl;
		cout<<"0--cikis"<<endl;
		cin>>(secim);
			switch(secim)
		{
			case 1: cout<< "Kuyruga girecek musteri bilgiler: "<< endl;
			cout<<"ad 					:"; cin>>ad;
			cout<<"alacagi pide adedi 					:"; cin>>adet;
			ekle(&qu, ad ,adet);
			break;
			case 2: cout<< "Kuyruktan silinecek musteri bilgiler: "<< endl;
			cout<<"ad 					:"; cin>>ad;
			cout<<"aldigi pide adedi 					:"; cin>>adet;
			sil(&qu, ad, adet);
			break;
			case 3: yazdir(&qu);
			break;
			case 0: cout <<"Cikisa yonlendiriliyorsunuz.. "<<endl;
			return 0;
			break;
			default: cout<<"Hatali islem yapildi."<<endl;
			break;
		}
	}
}
