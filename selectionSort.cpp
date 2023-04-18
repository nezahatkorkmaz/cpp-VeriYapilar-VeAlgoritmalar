#include <iostream >
using namespace std;

//Bubble sort ( kobarcik sıralama) algoritması. En büyük sayıyı bul, en sona taşı


void selectionSort(int dizi[], int n )
{
	for(int i = 0; i<n-1 ; i++)
	{
		int kucuk = dizi[i];
		int indis = i;
		for(int k=i; k<n -1 ; k++)
		{
			if(kucuk > dizi [k])
			{
				kucuk=dizi[k];
				indis= k;
				//Burada yaptığımız işlem, yer değiştirmedir.
			}
		}
		dizi[indis]= dizi[i];   // dizideki küçük sayı başa alındı.
		dizi[i] = kucuk;
	}
}
int main()
{
	int n;
	cout<<" kac adet sayi girmek istersiniz: " ; cin>>n;
	int i=0;
	int dizi[i];
	while(i<n)
	{
			cout<<" sayi :" ; cin>>dizi[i];
			i++;
	}
	
		selectionSort(dizi, n);
		cout<<"Siralana islemi tamamlandi" << endl;
		for (int i=0; i<n; i++ )
		{
			cout<<dizi[i]<< " " ;
		}
}
