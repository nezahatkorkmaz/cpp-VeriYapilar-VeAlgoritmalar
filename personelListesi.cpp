#include <iostream>
#include <string>
using namespace std;

struct Personel {
    string adSoyad;
    int sicilNo;
    double maas;
    Personel* next;
};
void ekle(Personel*& head, string adSoyad, int sicilNo, double maas) {
    Personel* yeniPersonel = new Personel;
    yeniPersonel->adSoyad = adSoyad;
    yeniPersonel->sicilNo = sicilNo;
    yeniPersonel->maas = maas;
    yeniPersonel->next = head;
    head = yeniPersonel;
}

void yazdir(Personel* head) {
    cout << "Bütün Personeller Listesi:" << endl;
    while (head != NULL) {
        cout << head->adSoyad << ", " << head->sicilNo << ", " << head->maas << endl;
        head = head->next;
    }
}

void ismeGoreAra(Personel* head, string arananAdSoyad) {
	cout << "*****************" << endl;
    cout << "Arama sonuclari (isim):" << endl;
    cout << "Girdiginiz isim "<<arananAdSoyad<<endl;
    bool bulundu = false;
    while (head != NULL) {
        if (head->adSoyad == arananAdSoyad) {
            cout << head->adSoyad << ", " << head->sicilNo << ", " << head->maas << endl;
            bulundu = true;
        }
        head = head->next;
    }
    if (!bulundu) {
        cout << "Aranan personel bulunamadi." << endl;
    }
    cout << "*****************" << endl;
}

void sicilNoGoreAra(Personel* head, int arananSicilNo) {
	cout << "*****************" << endl;
    cout << "Arama sonuclari (sicil no):" << endl;
	cout << "Girdiginiz sicil no "<<arananSicilNo<<endl;
    bool bulundu = false;
    while (head != NULL) {
        if (head->sicilNo == arananSicilNo) {
            cout << head->adSoyad << ", " << head->sicilNo << ", " << head->maas << endl;
            bulundu = true;
        }
        head = head->next;
    }
    if (!bulundu) {
        cout << "Aranan personel bulunamadı." << endl;
    }
	cout << "*****************" << endl;
}
int main() {
    Personel* head = NULL;

    // Personel ekleme
    ekle(head, "Faruk Inal", 12345, 5000.0);
    ekle(head, "Derya Gucluer", 67890, 7000.0);
    ekle(head, "Emin Aydin", 24680, 6000.0);
    ekle(head, "Rabia Berrin", 12312, 5000.0);
    ekle(head, "Rabia Berrin", 77777, 5000.0);
    // Personel listesini yazdırma
    yazdir(head);

 // İsme göre arama
    ismeGoreAra(head, "Nezahat Korkmaz");
    ismeGoreAra(head, "Rabia Berrin");

    // Sicil no'ya göre arama
    sicilNoGoreAra(head, 67890);

    return 0;
}
