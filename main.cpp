#include "tubes.h"
#include <iostream>

int main(){
	int x=1;
	listSeat L1;listOrang L2;
	createList(L2,L1);
	while (x!=0) {
		cout << "|=========================================================|" << endl;
		cout << "|                Tubes STD - Air Plane Seat               |" << endl;
		cout << "|                  Anggota : Afny Latifa                  |" << endl;
		cout << "|                  Nabiel Prayoga Budiana                 |" << endl;
		cout << "|=========================================================|" << endl;
		cout << "1.Tambah Seat" << endl;
		cout << "2.Tambah Orang" << endl;
		cout << "3.Show Seat" << endl;
		cout << "4.Show Orang" << endl;
		cout << "5.Pesan Seat" << endl;
		cout << "6.Hapus Seat" << endl;
		cout << "7.Hapus Orang" << endl;
		cout << "8.Show Seat & Pemesannya" << endl;
		cout << "Pilihan : ";cin >> x;
		if(x ==1){
			infoSeat s;
			cout << "Nomor Seat : ";cin >> s.nomorSeat;
			cout << "Kapasitas : ";cin >> s.kapasitas;
			adrSeat ss = createElementSeat(s);
			insertLastSeat(L1, ss);
		}else if (x==2) {
			infoOrang o;
			cout << "NIK : ";cin >> o.NIK;
			cout << "Nama : ";cin >> o.nama;
			cout << "Umur : ";cin >> o.umur;
			adrOrang oo = createElementOrang(o);
			inserLastOrang(L2, oo);
		}else if(x==3){
			showAllListSeat(L1);
		}else if(x==4){
			showAllListOrang(L2);
		}else if(x==5){
			int noseat;string nik;
			cout << "NIK pemesan : ";cin >> nik;
			cout << "Nomor Seat : ";cin >> noseat;
			connect(L1,L2,nik,noseat);
		}else if(x == 6){
			int n;
			cout <<"Nomor Seat : ";cin >> n;
			deleteSeat(L1,n);
		}else if(x==7){
			string n;
			cout <<"NIK : ";cin >> n;
			deleteOrang(L2,n,L1);
		}else if(x==8){
			showAllListSeat2(L1);
		}else if(x == 0){
			cout << "Sampai Jumpa" << endl;
		}

	}
}
