#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//Prosedur untuk menampilkan tanggal saat login
string datetime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,80,"%d/%m/%Y | %H:%M:%S",timeinfo);
    return std::string(buffer);
}

//Prosedur untuk menghitung biaya pengiriman
int perhitunganBiaya (int jrk, int brt, int pch){
    int bayar;

    return bayar=jrk*2000+brt*1000+pch;
}

int main()
{
	int i, login, pilihan, jarak, berat, pecah, ya1;
	char ch, awal, ulang, menu, ulang2, ulang3, pbarang, kode, error[30]="AntiError";
	char error2[30]="AntiError", namapengirim[30], alamatpengirim[30], hppengirim[30];
	char namapenerima[30], alamatpenerima[30] , hppenerima[12], namab[30], bpecah, jawab;
	char date [10];

    //Screen Login
	system("title Aplikasi Manajement POS - Login");
	system("color B1");
	system("cls");
	cout<<"\t\t\t    *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*"<<endl;
	cout<<"\t\t\t    !=============================!"<<endl;
	cout<<"\t\t\t    |   LOGIN ADMINISTRATOR       | "<<endl;
	cout<<"\t\t\t    |_____________________________|"<<endl;
	cout<<"\t\t\t                              "<<endl;
	for (i=1; i<=3; i++)
	{
		string user = "";
		string pass = "";
		cout << "\t\t\t       	    Username : "; cin >> user;
		cout << "\t\t\t       	    Password : ";
		ch = _getch();
		while(ch != 13)
			{
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
		if (user == "admin" && pass == "admin")
			{
				cout << "\n\nAnda berhasil login. \n" << endl;

                //Handling file untuk membuat log login berhasil
				fstream file;
                file.open ("log.txt", ios::out | ios::in | ios::app);

                file << "Login berhasil dilakukan pada " << datetime() << endl;
				goto menu;
			}
			else
			{
			    system("color C0");
				system("cls");
				cout<<"\t\t\t    *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*"<<endl;
				cout<<"\t\t\t    !=============================!"<<endl;
				cout<<"\t\t\t    |   LOGIN ADMINISTRATOR       | "<<endl;
				cout<<"\t\t\t    |_____________________________|"<<endl;
				cout <<"\t\t\tMaaf Username & Password anda masukan salah.\n\n";

				//Handling file untuk membuat log login gagal
				fstream file;
                file.open ("log.txt", ios::out | ios::in | ios::app);
                file << "Percobaan login gagal pada " << datetime() << endl;
			}
		}
		while (i <= 3);
			{
				cout << "Anda telah 3x memasukan Username & Password yang salah.\n";
				cout << "Mohon maaf akun anda kami blokir untuk sementara. \n";
				cout << "Silahkan hubungi kami melalui e-mail support@email.com, Terima Kasih..";
				getch();
				return 0;
			}
    //Screen Menu
	menu:
	system("title Aplikasi Manajemen POS - Menu");
    _strdate(date);
    system("cls");
    system("color f1");
    cout<< "\t\t      *----------------------------------------------*"<<endl;
    cout<< "\t\t      |==============================================|"<<endl;
    cout<< "\t\t      |               MENU ADMINISTRATOR   "<<date<<"  |"<<endl;
    cout<< "\t\t      |==============================================|"<<endl;
    cout<< "\t\t      |                                              |"<<endl;
    cout<< "\t\t      |	      1.Pengiriman Barang                    |"<<endl;
    cout<< "\t\t      |	      2.Tentang Kami                         |"<<endl;
    cout<< "\t\t      |                                              |"<<endl;
    cout<< "\t\t      +----------------------------------------------+"<<endl;
    cout<< "\t\t       Pilihan Anda: ";cin>>pilihan;
    system("CLS");
    switch(pilihan)
    {
    	case 1:
    		{
    			    Pbarang:
					system("title Aplikasi Manajemen POS - Pengiriman Barang");
					system("cls");
					cout<< "\t\t      *----------------------------------------------*"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |               BIODATA PENGIRIM               |"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t                                            "<<date<<""<<endl;cin.ignore();
				    cout<< "\t\t       	      1.Nama Pengirim     : ";gets(namapengirim);
				    cout<< "\t\t      	      2.Alamat Pengirim   : ";gets(alamatpengirim);
				    cout<< "\t\t      	      3.No.HP Pengirim    : ";gets(hppengirim);
				    cout<< "\t\t                                                      "<<endl;
				    cout<< "\t\t      +----------------------------------------------+"<<endl;
				    system("cls");
				    cout<< "\t\t      *----------------------------------------------*"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |               BIODATA PENERIMA               |"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t                                            "<<date<<""<<endl;
				    cout<< "\t\t       	      1.Nama Penerima     : ";gets(namapenerima);
				    cout<< "\t\t      	      2.Alamat Penerima   : ";gets(alamatpenerima);
				    cout<< "\t\t      	      3.No.HP Penerima    : ";gets(hppenerima);
				    cout<< "\t\t                                                      "<<endl;
				    cout<< "\t\t      +----------------------------------------------+"<<endl;
				    ulang2:
				    system("cls");
    			    cout<< "\t\t      *----------------------------------------------*"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |                 JENIS BARANG                 |"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t                                            "<<date;cin.ignore();
				    cout<< "\n\t\t       	      1.Nama Barang       	  : ";gets(namab);
				    cout<< "\t\t       	      2.Berat Barang (per KG) 	  : ";cin>>berat;
				    cout<< "\t\t              3.Mudah Pecah (Y/T) 	  : ";cin>>bpecah;
				    cout<< "\t\t              4.Jarak Pengiriman (per KM) : ";cin>>jarak;
				    cout<< "\t\t                                                      "<<endl;
				    cout<< "\t\t      +----------------------------------------------+"<<endl;
				    ya1:
					if(bpecah == 'y'|| bpecah=='Y')
					{
						pecah=5000;
					}
					else
					if(bpecah=='t'||bpecah=='T')
					{
						pecah=0;
					}
					else
					{
						cout<<"\n\t\t      Perintah yang anda masukkan salah !\n";
		    			system("pause");
		    			goto ulang2;
					}
					perhitunganBiaya(jarak, berat, pecah);
					ulang3:
					system("cls");
    			    cout<< "\t\t      *----------------------------------------------*"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |                KONFIRMASI DATA               |"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t                                            "<<date<<""<<endl;
				    cout<< "\t\t       	      1.Nama Pengirim     : "<<namapengirim<<endl;
				    cout<< "\t\t      	      2.Alamat Pengirim   : "<<alamatpengirim<<endl;
				    cout<< "\t\t      	      3.No.HP Pengirim    : "<<hppengirim<<endl;
				    cout<< "\t\t       	      4.Nama Penerima     : "<<namapenerima<<endl;
				    cout<< "\t\t      	      5.Alamat Penerima   : "<<alamatpenerima<<endl;
				    cout<< "\t\t      	      6.No.HP Penerima    : "<<hppenerima<<endl;
				    cout<< "\t\t       	      7.Nama Barang       : "<<namab<<endl;
				    cout<< "\t\t       	      8.Berat Barang      : "<<berat<<endl;
				    cout<< "\t\t              9.Mudah Pecah (Y/T) : "<<bpecah<<endl;
				    cout<< "\t\t              10.Jarak Pengiriman : "<<jarak<<endl;
				    cout<< "\t\t                                                      "<<endl;
				    cout<< "\t\t      +----------------------------------------------+"<<endl;
				    cout<<endl;
					cout<<"\t\t\t       	    Apakah Benar? (Y/T)	: ";cin>>jawab;
					if(jawab=='y'||jawab=='Y')
				    {
				    	cout<<"\n\t\t       	      Total Pembayaran adalah : Rp"<<perhitunganBiaya(jarak, berat, pecah)<<""<<endl;
						cout<<"\n\t\t       	      Kembali ke Menu Awal? (Y/T)	: ";cin>>ulang;
				    	if(ulang=='y'||ulang=='Y')
				    	{
				    		goto menu;
				    	}
				    	else
				    	{
				    		break;
				    	}
				    }
				    else
				    if(jawab=='t'||jawab=='T')
				    {
				    	goto Pbarang;
				    	system("cls");
				    }
				    else
				    {
				    	cout<<"\n\t\t      Perintah yang anda masukkan salah !\n";
		    			system("pause");
		    			goto ulang3;
				    }
    		}
    		case 2:
    		{
    			    system("title Aplikasi Manajemen POS - Tentang Kami");
					cout<< "\t\t      *----------------------------------------------*"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |                  KELOMPOK 20        "<<date<<"  |"<<endl;
				    cout<< "\t\t      |==============================================|"<<endl;
				    cout<< "\t\t      |           1. Valleryan Arga (20102199)       |"<<endl;
				    cout<< "\t\t      |           2. Vangga Fibo Eprila (20102200)   |"<<endl;
				    cout<< "\t\t      +----------------------------------------------+"<<endl;

				    cout<<"\t\t      Kembali ke Menu Awal? (Y/T)	: ";cin>>ulang;
				    if(ulang=='y'||ulang=='Y')
				    	{
				    		goto menu;
				    	}
				    	else
				    	return 0;
    		}
    		default:
    		{
    			cout<<"\n\t\t      Perintah yang anda masukkan salah !\n";
    			system("pause");
    			goto menu;
    		}
    }
	}
