/*
	KELOMPOK 4
	PROJECT ABSENSI HARIAN DAYCARE
	1. Aldi Muharamdhani			(2205814) 
	2. Andina Renita Zahara			(2208991) 
	3. Muhammad Dzakkir Kilman S	(2204913) 
	4. Ummam Hoerussifa				(2203036)
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

///////////////// NOMOR INDUK /////////////////
int nomorInduk(){
	srand(time(nullptr));
	return rand()%100;
}

///////////////// MENU 1 PENDAFTARAN ANAK /////////////////
void pendaftaran(){
	string namaOrtu, namaAnak, alergiPenyakit, pekerjaanOrtu, alamatAsal, alamatSaatIni, alamatKantor;
	int usia;
	ofstream dataPendaftaran;

	cout<<" ===============================================\n";
	cout<<" ===============   PENDAFTARAN   ===============\n";
	cout<<" =================   DAYCARE   =================\n";
	cout<<" ===============================================\n";
	cout<<endl;
	cout<<" Masukkan Nama Orang Tua      : ";cin.ignore();getline(cin, namaOrtu);
	cout<<" Masukkan Nama Anak           : ";getline(cin, namaAnak);
	cout<<" Masukkan Usia Anak           : ";cin>>usia;
	cout<<" Riwayat Penyakit/Alergi Anak : ";cin.ignore();getline(cin, alergiPenyakit);
	cout<<" Pekerjaan Orang Tua          : ";getline(cin, pekerjaanOrtu);
	cout<<" Alamat Asal                  : ";getline(cin, alamatAsal);
	cout<<" Alamat Saat Ini              : ";getline(cin, alamatSaatIni);
	cout<<" Alamat Kantor                : ";getline(cin, alamatKantor);
	cout<<endl;

	///////////////// LAPORAN PENDAFTARAN /////////////////
	cout<<" ==============================================\n";
	cout<<" Nama \t\t\t\t: "<< namaAnak << endl;
	cout<<" Usia \t\t\t\t: "<< usia <<" Tahun"<< endl;
	cout<<" Riwayat Penyakit/Alergi \t: "<< alergiPenyakit << endl;
	cout<<" Nomor induk anak \t\t: "<< nomorInduk() << endl;
	cout<<" ==============================================\n";

	dataPendaftaran.open("Data Anak.csv", ios::app);
	dataPendaftaran<<"=============================================="<<endl;
	dataPendaftaran<<"Masukkan Nama Orang Tua       : " << namaOrtu << endl;
	dataPendaftaran<<"Masukkan Nama Anak            : " << namaAnak << endl;
	dataPendaftaran<<"Masukkan Usia Anak            : " << usia <<" Tahun"<< endl;
	dataPendaftaran<<"Riwayat Penyakit/Alergi Anak  : " << alergiPenyakit << endl;
	dataPendaftaran<<"Pekerjaan Orang Tua           : " << pekerjaanOrtu << endl;
	dataPendaftaran<<"Alamat Asal                   : " << alamatAsal << endl;
	dataPendaftaran<<"Alamat Saat Ini               : " << alamatSaatIni << endl;
	dataPendaftaran<<"Alamat Kantor                 : " << alamatKantor << endl;
	dataPendaftaran<<"Nomor induk anak              : " << nomorInduk() << endl;
	dataPendaftaran<<"=============================================="<<endl;
	dataPendaftaran.close();
}

///////////////// MENU 2 ABSENSI KEDATANGAN ANAK /////////////////
void absensiDatang(){
	int noInduk;
	cout<<" ================================================\n";
	cout<<" ============   Absensi Kedatangan   ============\n";
	cout<<" ================================================\n";
	cout<<endl;
	cout<<" ================================================\n";
	cout<<" Nomor induk anak \t: ";cin>>noInduk;
	cout<<" Tanggal \t\t: "<<__DATE__<<endl;
	cout<<" Pukul \t\t\t: "<<__TIME__<<endl;
	cout<<" ================================================\n";
}

///////////////// MENU 3 ABSENSI KEPULANGAN ANAK /////////////////
void absensiPulang(){
	int noInduk;
	cout<<" ================================================\n";
	cout<<" ============   Absensi Kepulangan   ============\n";
	cout<<" ================================================\n";
	cout<<endl;
	cout<<" ================================================\n";
	cout<<" Nomor induk anak\t: ";cin>>noInduk;
	cout<<" Tanggal\t\t: "<<__DATE__<<endl;
	cout<<" Pukul\t\t\t: "<<__TIME__<<endl;
	cout<<" ================================================\n";
}

///////////////// MENU 4 LAPORAN ABSENSI SELURUH ANAK DI DAYCARE /////////////////
void laporanAbsensi(){
	
}

///////////////// DAFTAR MENU BERANDA UTAMA /////////////////
int menu(){
	string ulang;
	int menu;
	
	do{
		system("cls");
		cout<<" =========================================\n";
		cout<<" ==============   BERANDA   ==============\n";
		cout<<" =========================================\n";
		cout<<endl;
		cout<<" [1] Pendaftaran\n";
		cout<<" [2] Absensi Datang\n";
		cout<<" [3] Absensi Pulang\n";
		cout<<" [4] Laporan Absensi\n";
		cout<<" \n Pilih Menu: ";cin>>menu;
		
		system("cls");
		switch(menu){
			case 1:
				system("cls");
				pendaftaran();
			break;
			case 2:
				system("cls");
				absensiDatang();
			break;
			case 3:
				system("cls");
				absensiPulang();
			break;
			case 4:
				system("cls");
				laporanAbsensi();
			break;
		default:
			cout<<" ERROR "<<endl;
		}
		cout<<" \n Ulangi? <y/n> ";cin>>ulang;
	}while(ulang == "y");
	cout<<endl;
	system("pause");
	
	return(menu);
}

///////////////// PAGE LOGIN PETUGAS /////////////////
void login(){
	string username, realusername, pass, realpass, kembali;
	
	for(int i = 2; i >= 0; --i){
		system("cls");
		cout<<" =========================================\n";
		cout<<" ===============   LOGIN   ===============\n";
		cout<<" =========================================\n";
		cout<<endl;
		cout<<" Masukkan Username : ";cin>>username;
		cout<<" Masukkan Password : ";cin>>pass;
		cout<<endl;
		
		realusername = "daycare";
		realpass = "kelompok4";
		
		if(username == realusername && pass == realpass){
			cout<<endl;
			menu();
			system("cls");
			system("pause");
			break;
		}else if(i > 0){
			cout<<" Password atau Username yang Anda Masukkan Salah. "<<endl;
			cout<<" Kesempatan Anda "<<i<<" Kali Lagi. "<<endl;
			cout<<endl;
			system("pause");
		}else{
			cout<<" ANDA TIDAK DIPERKENANKAN UNTUK MENGAKSES APLIKASI INI! "<<endl;
			break;
		}
	}
}
///////////////// MAIN FUNCITON ////////////////////
int main(){
	string logout;
	
	do{
		cout<<endl;
		system("cls");
		login();
		cout<<" \n Logout atau ulangi masukkan usename dan password? <y/n> ";cin>>logout;
	}while(logout == "y");
	cout<<endl;
	system("cls");
	cout<<"\t\t\t=========================================================================\n";
	cout<<"\t\t\t===================== Program Selesai, Terima Kasih.=====================\n";
	cout<<"\t\t\t=========================================================================\n";
	
	return 0;
}
