#include <iostream >
using namespace st;

//Bubble sort ( kobarcik sıralama) algoritması. En büyük sayıyı bul, en sona taşı


void bubbleSort(int dizi[]], int n )
{
	for(int i = 0; i<n-1 ; i++)
	{
		for(int k=0; k<n-i -1 ; k++)
		{
			if(dizi[k] > dizi [k+1])
			{
				int gecici = dizi[k];
				dizi[k]= dizi[k+1];
				dizi[k+1] =gecici;
				//Burada yaptığımız işlem, yer değiştirmedir.
			}
		}
	}
}
int main()
{
	int n;
	coutc<<" kac adet sayi girmek istersiniz: " ; cin>>n;
	int dizi[n];

	int i=0;
	while(i<n )
	{
	coutc<<" sayi :" ; cin>>dizi[i];
	i++;
	}	
	
	bubbleSort(dizi, n);
	cout<<"Siralana islemi tamamlandi" << endl;
	for (int i=0; i<n; i++ )
	{
		cout<<dizi[n]<< " " ;
	}

}
