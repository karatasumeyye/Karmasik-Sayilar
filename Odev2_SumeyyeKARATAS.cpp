
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI : 2
**				ÖĞRENCİ ADI : Sümeyye Karataş
**				ÖĞRENCİ NUMARASI :B221210005
**				DERS GRUBU : B 
****************************************************************************/


#include <iostream>
#include<locale>
#include<cmath>

using namespace std;

void Menu();
void Devam();
void Menu_Devam();
void Menu_Yazdirma();
class Karmasik_Sayi
{
private:
	float real;
	float sanal;
	float aci;
	float egim;
	float r;
	
public:
	Karmasik_Sayi() :real(0), sanal(0) {}

	// Karmaşık sayılarda işlem yapılması için operatörlere aşırı yüklemenin yapıldığı fonksiyonlar

	Karmasik_Sayi operator+(Karmasik_Sayi k1)
	{
		Karmasik_Sayi toplam;
		toplam.real = (real + k1.real);
		toplam.sanal = (sanal + k1.sanal);
		return toplam;
	}

	Karmasik_Sayi operator- (Karmasik_Sayi k1)
	{
		Karmasik_Sayi fark;
		fark.real = (real - k1.real);
		fark.sanal = (sanal - k1.sanal);
		return fark;
	}

	Karmasik_Sayi operator*(Karmasik_Sayi k1)
	{
		Karmasik_Sayi carpim;
		carpim.real = ((real * k1.real) - (sanal * k1.sanal));
		carpim.sanal = ((real * k1.sanal) + (k1.real * sanal));
		return carpim;
	}

	Karmasik_Sayi operator/(Karmasik_Sayi k1)
	{
		Karmasik_Sayi bolum;
		float real_sayi = k1.real * k1.real + k1.sanal * k1.sanal;
		bolum.real = (real * k1.real - sanal * (-1 * k1.sanal)) / real_sayi;
		bolum.sanal = (real * (-1 * k1.sanal) + sanal * k1.real) / real_sayi;
		return bolum;
	}
	Karmasik_Sayi operator +=(Karmasik_Sayi k1)
	{
		real = real + k1.real;
		sanal = sanal + k1.sanal;
		return *this;
	}
	Karmasik_Sayi operator -=(Karmasik_Sayi k1)
	{
		real = real - k1.real;
		sanal = sanal - k1.sanal;
		return *this;
	}
	Karmasik_Sayi operator *=(Karmasik_Sayi k1)
	{
		real = ((real * k1.real) - (sanal * k1.sanal));
		sanal = ((real * k1.sanal) + (k1.real * sanal));
		return *this;
	}
	Karmasik_Sayi operator /=(Karmasik_Sayi k1)
	{
		float real_sayi = k1.real * k1.real + k1.sanal * k1.sanal;
		real = (real * k1.real - sanal * (-1 * k1.sanal)) / real_sayi;
		sanal = (real * (-1 * k1.sanal) + sanal * k1.real) / real_sayi;
		return *this;
	}
    Karmasik_Sayi Kutupsal_Gosterim(Karmasik_Sayi k1)
	{
		egim = k1.sanal / k1.real;
		aci = atan(egim)*180/3.14;
		r = sqrt(pow(real, 2) + pow(sanal, 2));
		cout << "Kutupsal gösterim = " << "[ " << r << " , " << aci << "]" << endl;
		return *this;
	}

	// Karmaşık sayıların a+bi formatında ekrana yazdırılması için oluşturulan fonksiyon
	void Yazdirma()
	{
		if (sanal < 0)
			cout << real << " " << sanal << " i ";
		else
			cout << real << " + " << sanal << " i ";
	}
	// Kullanıcıdan karmaşık sayının real ve sanal kısımlarını girmesini sağlayan fonksiyon
	void  Kullanicidan_Isteme_1()
	{
		cout << " \nİşlem yapacağınız ilk karmaşık sayının reel kısmını girniz : "; cin >> real;
		cout << "İşlem yapacağınız ilk karmaşık sayının sanal kısmını girniz : "; cin >> sanal;
	}
	void Kullanicidan_Isteme_2()
	{
		cout << "\nİşlem yapacağınız ikinci karmaşık sayının reel kısmını girniz : "; cin >> real;
		cout << "İşlem yapacağınız ikinci karmaşık sayının sanal kısmını girniz : "; cin >> sanal;
	}

	// Bölme işleminde paydanın 0 olmaması için oluşturulan fonksiyon
	void bolen()
	{
		do
		{
			cout << "Bölme işlemi yapacaksınız.Paydadaki sayı sıfır olamayacak şekilde karmaşık sayınızı giriniz.";
			cout << "\nİşlem yapacağınız ikinci karmaşık sayının reel kısmını girniz : "; cin >> real;
			cout << "İşlem yapacağınız ikinci karmaşık sayının sanal kısmını girniz : "; cin >> sanal;
		} while (real == 0 && sanal == 0);   // payda 0 olduğunda kullanıcıdan tekrar değer girilmesi istenir.
	
	}

	Karmasik_Sayi(const Karmasik_Sayi&);    // copy constructor foksiyonu 

};

	Karmasik_Sayi::Karmasik_Sayi(const Karmasik_Sayi& nesne)
	{
		real = nesne.real;
		sanal = nesne.sanal;
	}

Karmasik_Sayi k1, k2,k3;
int devam,secim;

int main()
{
	setlocale(LC_ALL, "Turkish");            // Türkçe karakterlerin kullanımı

		Menu();
		do
		{
			cout << endl;
			Devam();
			
		} while (devam == 1);
}

void Menu()
{
	Menu_Yazdirma();
	cout << "Yapmak istediğiniz işlem için (1-9) seçeneklerinden birini seçiniz.";
	cin >> secim;

	while (!cin.good())                            // Kullanıcın girdiği değerin istenilen veri tipinde girip girmediğini sorgular.
	{
		cin.clear();
		cin.ignore(1, '\n');
		cout << "Geçerli değer giriniz.";
		cin >> secim;
		cout << endl;
	}

	while ((secim <= 0 || secim > 9))           // Kullanıcının seçtiği işlemin geçerli olup olmadığı kontrol edilir.
	{
		cout << "\nGeçerli bir seçim yapınız.";
		cin >> secim;
	}


	if (secim == 1)
	{
		k1.Kullanicidan_Isteme_1();
		k2.Kullanicidan_Isteme_2();
		k3 = k1 + k2;
		k3.Yazdirma();

	}
	else if (secim == 2)
	{
		k1.Kullanicidan_Isteme_1();
		k2.Kullanicidan_Isteme_2();
		k3 = k1 - k2;
		k3.Yazdirma();
	}
	else if (secim == 3)
	{
		k1.Kullanicidan_Isteme_1();
		k2.Kullanicidan_Isteme_2();
		k3 = k1 * k2;
		k3.Yazdirma();
	}
	else if (secim == 4)    
	{
		k1.Kullanicidan_Isteme_1();
		k2.bolen();
		k3 = k1 / k2;
		k3.Yazdirma();
	}

	else if (secim == 5)
	{
		k1.Kullanicidan_Isteme_1();
		k3.Kullanicidan_Isteme_2();
		k3 += k1;
		k3.Yazdirma();
	}
	 
	else if (secim == 6)
	{
		k1.Kullanicidan_Isteme_1();
		k3.Kullanicidan_Isteme_2();
		k3 -= k1;
		k3.Yazdirma();
	}

	else if (secim == 7)
	{
		k1.Kullanicidan_Isteme_1();
		k3.Kullanicidan_Isteme_2();
		k3 *= k1;
		k3.Yazdirma();
	}

	else if (secim == 8)
	{
		k1.Kullanicidan_Isteme_1();
		k3.Kullanicidan_Isteme_2();
		k3 /= k1;
		k3.Yazdirma();
	}

	else if (secim == 9)
	{
		k3.Kullanicidan_Isteme_1();
		k3.Kutupsal_Gosterim(k3);
	}

}

// Kullanıcının işlemine devam etmek isteyip istemediğini sorgulayan fonksiyon.
void Devam()
{   
	        do{
			cout << endl;
			cout << "Devam etmek istiyorsanız 1'e basınız.İstemiyorsanız 0'a basınız.";
			cin >> devam;

				while (!cin.good())                            // Kullanıcın girdiği değerin istenilen veri tipinde girip girmediğini sorgular.
				{
					cin.clear();
					cin.ignore(1, '\n');
					cout << "Geçerli değer giriniz.";
					cin >> devam;
					cout << endl;
				}
			} while (!(devam == 1 || devam == 0));
			
			if (devam == 1)
				Menu_Devam();
			else if (devam == 0)
				cout << "\nİşleminiz bitmiştir." << endl;
			
		
	}

	// Kullacının yaptığı işlemden elde edilen sonuç üzerine tekrar işlem yapmak istediğinde çalışacak olan fonskiyon
void Menu_Devam()
{
	Menu_Yazdirma();
	cout << "Yapmak istediğiniz işlem için (1-9) seçeneklerinden birini seçiniz.";
	cin >> secim;
	while ((secim <= 0 || secim > 9))             // Kullanıcının seçtiği işlemin geçerli olup olmadığı kontrol edilir.
	{
		cout << "Geçerli bir seçim yapınız.";
		cin >> secim;
	}

	Karmasik_Sayi k1 (k3);        // copy constructor fonksiyonu çağrıldı ve k3 , k1 e kopyalandı.

	if (secim == 1)
	{
		k2.Kullanicidan_Isteme_2();
		k3 = k1 + k2;
		k3.Yazdirma();
	}
	else if (secim == 2)
	{
        k2.Kullanicidan_Isteme_2();
        k3 = k1 - k2;
		k3.Yazdirma();
	}
	else if (secim == 3)
	{
		k2.Kullanicidan_Isteme_2();
        k3 = k1 * k2;
		k3.Yazdirma();
	}
	else if (secim == 4)   
	{
		k2.bolen();
        k3 = k1 / k2;
		k3.Yazdirma();
	}

	else if (secim == 5)
	{
		k2.Kullanicidan_Isteme_2();
		k3 += k2;
		k3.Yazdirma();
	}
	else if (secim == 6)
	{
		k2.Kullanicidan_Isteme_2();
		k3 -= k2;
		k3.Yazdirma();
	}
	else if (secim == 7)
	{
		k2.Kullanicidan_Isteme_2();
		k3 *= k2;
		k3.Yazdirma();
	}
	else if (secim == 8)
	{
		k2.Kullanicidan_Isteme_2();
		k3 /= k2;
		k3.Yazdirma();
	}
	else if (secim == 9)
	{
		k3.Kutupsal_Gosterim(k3);
	}

}

void Menu_Yazdirma()
{
	cout << "\n\n MENÜ\n\n " << endl;

	cout << "1) Toplama " << endl;
	cout << "2) Çıkarma " << endl;
	cout << "3) Çarpma " << endl;
	cout << "4) Bölme " << endl;
	cout << "5) += " << endl;
	cout << "6) -= " << endl;
	cout << "7) *= " << endl;
	cout << "8) /= " << endl;
	cout << "9) Kutupsal gösterim " << endl;
}

