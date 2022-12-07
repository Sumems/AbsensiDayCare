#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<fstream>
using namespace std;

///////////////// MENU 1 PENDAFTARAN ANAK //////////////////////////
void pendaftaran(){
	string namaortu, namaanak, alergipenyakit, pekerjaanortu, alamatasal, alamatsaatini, alamatkantor;
	int usia;
	ofstream dataPendaftaran;

	cout<<" ========================= "<<endl;
	cout<<" ====== PENDAFTARAN ====== "<<endl;
	cout<<" ======== DAYCARE ======== "<<endl;
	cout<<" ========================= "<<endl;
	cout<<endl;
	cout<<" Masukkan Nama Orang Tua      : ";cin.ignore();getline(cin, namaortu);
	cout<<" \n Masukkan Nama Anak           : ";getline(cin, namaanak);
	cout<<" \n Masukkan Usia Anak           : ";cin>>usia;
	cout<<" \n Riwayat Penyakit/Alergi Anak : ";cin.ignore();getline(cin, alergipenyakit);
	cout<<" \n Pekerjaan Orang Tua          : ";getline(cin, pekerjaanortu);
	cout<<" \n Alamat Asal                  : ";getline(cin, alamatasal);
	cout<<" \n Alamat Saat Ini              : ";getline(cin, alamatsaatini);
	cout<<" \n Alamat Kantor                : ";getline(cin, alamatkantor);
	cout<<endl;
	cout<<" ============================================================================="<<endl;
	cout<<" Nama \t\t\t\t: "<<namaanak<<endl;
	cout<<" Usia \t\t\t\t: "<<usia<<" Tahun"<<endl;
	cout<<" Riwayat Penyakit/Alergi \t: "<<alergipenyakit<<endl;
	cout<<" Nomor induk anak \t\t: "<<rand() % 100<<endl;
	cout<<" ============================================================================="<<endl;

	dataPendaftaran.open("Data Anggota.txt", ios::app);
	dataPendaftaran<<"Masukkan Nama Orang Tua		: " << namaortu << endl;
	dataPendaftaran<<"Masukkan Nama Anak			: " << namaanak << endl;
	dataPendaftaran<<"Masukkan Usia Anak			: " << usia <<" Tahun"<< endl;
	dataPendaftaran<<"Riwayat Penyakit/Alergi Anak	: " << alergipenyakit << endl;
	dataPendaftaran<<"Pekerjaan Orang Tua			: " << pekerjaanortu << endl;
	dataPendaftaran<<"Alamat Asal					: " << alamatasal << endl;
	dataPendaftaran<<"Alamat Saat Ini				: " << alamatsaatini << endl;
	dataPendaftaran<<"Alamat Kantor					: " << alamatkantor << endl;
	dataPendaftaran<<"Nomor induk anak				: "<<rand() % 100<<endl;
	dataPendaftaran.close();
}
//////////////// MENU 2 ABSENSI KEDATANGAN ANAK ////////////////////
void absensidatang(){
	int noinduk;
	cout<<" ======================"<<endl;
	cout<<" = Absensi Kedatangan ="<<endl;
	cout<<" ======================"<<endl;
	cout<<endl;
	cout<<" ======================================"<<endl;
	cout<<" Nomor induk anak \t: ";cin>>noinduk;
	cout<<" Tanggal \t\t: "<<__DATE__<<endl;
	cout<<" Pukul \t\t\t: "<<__TIME__<<endl;
	cout<<" ======================================"<<endl;
}
//////////////// MENU 3 ABSENSI KEPULANGAN ANAK ///////////////////
void absensipulang(){
	int noinduk;
	cout<<" ======================"<<endl;
	cout<<" = Absensi Kepulangan ="<<endl;
	cout<<" ======================"<<endl;
	cout<<endl;
	cout<<" ======================================"<<endl;
	cout<<" Nomor induk anak \t: ";cin>>noinduk;
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
		realpass = "kel4";
		
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