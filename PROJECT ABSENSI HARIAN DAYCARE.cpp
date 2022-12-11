#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

int nomorInduk(){
	srand(time(nullptr));
	return rand()%100;
}
///////////////// MENU 1 PENDAFTARAN ANAK //////////////////////////
void pendaftaran(){
	string namaOrtu, namaAnak, alergiPenyakit, pekerjaanOrtu, alamatAsal, alamatSaatIni, alamatKantor;
	int usia;
	ofstream dataPendaftaran;

	cout<<" ========================= "<<endl;
	cout<<" ====== PENDAFTARAN ====== "<<endl;
	cout<<" ======== DAYCARE ======== "<<endl;
	cout<<" ========================= "<<endl;
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
	cout<<" ============================================================================="<<endl;
	cout<<" Nama \t\t\t\t: "<< namaAnak << endl;
	cout<<" Usia \t\t\t\t: "<< usia <<" Tahun"<< endl;
	cout<<" Riwayat Penyakit/Alergi \t: "<< alergiPenyakit << endl;
	cout<<" Nomor induk anak \t\t: "<< nomorInduk() << endl;
	cout<<" ============================================================================="<<endl;

	dataPendaftaran.open("Data Anggota.txt", ios::app);
	dataPendaftaran<<"============================================================================="<<endl;
	dataPendaftaran<<"Masukkan Nama Orang Tua       : " << namaOrtu << endl;
	dataPendaftaran<<"Masukkan Nama Anak            : " << namaAnak << endl;
	dataPendaftaran<<"Masukkan Usia Anak            : " << usia <<" Tahun"<< endl;
	dataPendaftaran<<"Riwayat Penyakit/Alergi Anak  : " << alergiPenyakit << endl;
	dataPendaftaran<<"Pekerjaan Orang Tua           : " << pekerjaanOrtu << endl;
	dataPendaftaran<<"Alamat Asal                   : " << alamatAsal << endl;
	dataPendaftaran<<"Alamat Saat Ini               : " << alamatSaatIni << endl;
	dataPendaftaran<<"Alamat Kantor                 : " << alamatKantor << endl;
	dataPendaftaran<<"Nomor induk anak              : " << nomorInduk() << endl;
	dataPendaftaran<<"============================================================================="<<endl;
	dataPendaftaran.close();
}
//////////////// MENU 2 ABSENSI KEDATANGAN ANAK ////////////////////
void absensidatang(){
	int noInduk;
	cout<<" ======================"<<endl;
	cout<<" = Absensi Kedatangan ="<<endl;
	cout<<" ======================"<<endl;
	cout<<endl;
	cout<<" ======================================"<<endl;
	cout<<" Nomor induk anak \t: ";cin>>noInduk;
	cout<<" Tanggal \t\t: "<<__DATE__<<endl;
	cout<<" Pukul \t\t\t: "<<__TIME__<<endl;
	cout<<" ======================================"<<endl;
}
//////////////// MENU 3 ABSENSI KEPULANGAN ANAK ///////////////////
void absensipulang(){
	int noInduk;
	cout<<" ======================"<<endl;
	cout<<" = Absensi Kepulangan ="<<endl;
	cout<<" ======================"<<endl;
	cout<<endl;
	cout<<" ======================================"<<endl;
	cout<<" Nomor induk anak \t: ";cin>>noInduk;
	cout<<" Tanggal \t\t: "<<__DATE__<<endl;
	cout<<" Pukul \t\t\t: "<<__TIME__<<endl;
	cout<<" ======================================"<<endl;
}
//////////////// MENU 4 LAPORAN ABSENSI SELURUH ANAK DI DAYCARE ////////////////////////
void laporanabsensi(){
	
}
////////////// DAFTAR MENU UTAMA //////////////////////////
int menu(){
	string ulang;
	int menu;
	
	do{
		system("cls");
		cout<<" ==================="<<endl;
		cout<<" ====== MENU ======="<<endl;
		cout<<" ==================="<<endl;
		cout<<endl;
		cout<<" 1. Pendaftaran "<<endl;
		cout<<" 2. Absensi Datang "<<endl;
		cout<<" 3. Absensi Pulang "<<endl;
		cout<<" 4. Laporan Absensi "<<endl;
		cout<<" \n Pilih Menu: ";cin>>menu;
		
		system("cls");
		switch(menu){
			case 1:
				system("cls");
				pendaftaran();
			break;
			case 2:
				system("cls");
				absensidatang();
			break;
			case 3:
				system("cls");
				absensipulang();
			break;
			case 4:
				system("cls");
				laporanabsensi();
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
//////////// PAGE LOGIN PETUGAS /////////////////
void login(){
	string username, realusername, pass, realpass, kembali;
	
	for(int i = 2; i >= 0; --i){
		system("cls");
		cout<<" ===================="<<endl;
		cout<<" ====== LOGIN ======="<<endl;
		cout<<" ===================="<<endl;
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
/////////////// MAIN FUNCITON ////////////////////
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
	cout<<" ================================="<<endl;
	cout<<" = Program Selesai, Terima Kasih.= "<<endl;
	cout<<" ================================="<<endl;
	
	return 0;
}