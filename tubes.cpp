#include "tubes.h"
#include <ostream>
#include <string>

void createList(listOrang &L1, listSeat &L2){
    firstSeat(L2) = nil;
	firstOrang(L1) = nil;
}

adrSeat createElementSeat(infoSeat x){
    adrSeat p = new elmSeat;
    infoSeat(p) = x;
    book(p) = nil;
    nextSeat(p) = nil;
    return p;
}

adrOrang createElementOrang(infoOrang x){
    adrOrang p = new elmOrang;
    infoOrang(p) = x;
    nextOrang(p) = nil;
    return p;
}

adrRelation createElementRelation(){
    adrRelation p = new elmRelation;
    Orang(p) = nil;
    nextRelation(p) = nil;
    return p;
}

void insertLastSeat(listSeat &L3, adrSeat a){
    adrSeat c;
	c = firstSeat(L3);
	if(firstSeat(L3) != nil){
		while (nextSeat(c) != nil){
			c = nextSeat(c);
		}
		nextSeat(c) = a;
	}else{
		firstSeat(L3) = a;
    }
	cout << "Seat berhasil ditambahkan" << endl << endl;
}
void showAll(listSeat L3){
    adrSeat p = firstSeat(L3); int i = 1;
    if (firstSeat(L3) != nil){
        while (p != nil){
            if (i == 3){
                cout << infoSeat(p).nomorSeat << " " << infoSeat(p).kapasitas << " " << endl;
            }
            i++;
            p = nextSeat(p);
        }
        if (i < 3){
            cout << "Seat Tidak Ditemukan" << endl;
        }
    }else{
        cout << "List seat kosong" << endl;
    }
}

void deleteSeat(listSeat &L3, int noSeat) {
	bool ans = false;
    adrSeat p = firstSeat(L3);
	adrSeat q = p;
    while (p != nil) {
		if(infoSeat(p).nomorSeat == noSeat){
			ans = true;
			break;
		}
		q =p;
        p = nextSeat(p);
    }
	if(ans){
		if(p == q && p == firstSeat(L3)){
			firstSeat(L3) = nil;
		}else{
			(q)->nextSeat = (p)->nextSeat;
		}
		cout << "Berhasil dihapus" << endl;
	}else{
		cout << "Seat tidak ditemukan "<<endl;
	}
}

adrSeat searchSeat(listSeat L3, int nomorSeat){
	adrSeat ans;
    adrSeat p = firstSeat(L3);
    while (p != nil) {
		if(infoSeat(p).nomorSeat == nomorSeat){
			ans = p;
			break;
		}
        p = nextSeat(p);
    }
    return ans;
}
bool cekSeat(listSeat L3, int nomorSeat){
	bool ans = false;
    adrSeat p = firstSeat(L3);
    while (p != nil) {
		if(infoSeat(p).nomorSeat == nomorSeat){
			ans = true;
			break;
		}
        p = nextSeat(p);
    }
    return ans;
}
adrOrang searchOrang(listOrang L2, string NIK){
	adrOrang ans;
    adrOrang p = firstOrang(L2);
    while (p != nil) {
		if(infoOrang(p).NIK == NIK){
			ans = p;
			break;
		}
        p = nextOrang(p);
    }
    return ans;
}

bool cekOrang(listOrang L2, string NIK){
	bool ans = false;
    adrOrang p = firstOrang(L2);
    while (p != nil) {
		if(infoOrang(p).NIK == NIK){
			ans = true;
			break;
		}
        p = nextOrang(p);
    }
    return ans;
}
void inserLastOrang(listOrang &L2, adrOrang b){
    adrOrang p = firstOrang(L2);
    if (firstOrang(L2) == nil){
        firstOrang(L2) = b;
    }else{
        while (nextOrang(p) != nil){
            p = nextOrang(p);
        }
        nextOrang(p) = b;
    }
	cout << "Orang berhasil ditambahkan" << endl << endl;
}

void connect(listSeat &L3, listOrang L2, string NIK, int nomorSeat){
	if(cekOrang(L2,NIK) == false){
		cout << "Orang dengan NIK " << NIK << " tidak ditemukan" << endl;
		return;
	}
	if(cekSeat(L3,nomorSeat) == false){
		cout << "Seat dengan nomor " << nomorSeat << " tidak ditemukan" << endl;
		return;
	}
    adrSeat s = searchSeat(L3, nomorSeat);
    adrRelation t=createElementRelation();
    adrOrang o=searchOrang(L2,NIK);
	if((s)->infoSeat.kapasitas <= 0){
		cout << "Kapasitas Seat sudah penuh " << endl;
		return;
	}
    if(book(s)==nil){
		cout << "1" << endl;
        book(s)=t;
        Orang(book(s))=o;
		infoSeat(s).kapasitas -=1;
    }else{
		cout << "2" << endl;
        adrRelation r=book(s);
        while(nextRelation(r)!=nil){
            r=nextRelation(r);
        }
        nextRelation(r)=t;
        Orang(t)=o;
		infoSeat(s).kapasitas -=1;
    }
	cout << "Seat Berhasil Dipesan" << endl;
}
void showAllListSeat2(listSeat L3){
    if(firstSeat(L3)==nil){
        cout<<"Tidak ada seat"<<endl;
    }else{
        adrSeat s=firstSeat(L3);
		cout << "=== Data Seat ===" << endl;
		int cc = 0;
        while(s!=nil){
            cout<< "Nomor Seat : " <<infoSeat(s).nomorSeat<<endl;
			cout <<"Kapasitas : " <<infoSeat(s).kapasitas<<endl << endl;
			if(book(s) != nil){
				adrRelation r=book(s);
				cout << "=== Pemesan Seat Nomor "<<infoSeat(s).nomorSeat <<" ===" << endl;
				int c = 0;
				while(r!=nil){
					adrOrang oo = (r)->Orang;
					infoOrang myo = (oo)->infoOrang;
					cout << "NIK : " << myo.NIK << endl;
					cout << "Nama : " << myo.nama << endl;
					cout << "Umur : " << myo.umur << endl << endl;
					r=nextRelation(r);
					c++;
				}
				cout << "Jumlah Pemesan Seat Nomor " << infoSeat(s).nomorSeat << " : " << c <<endl;
				cout << "===========================" << endl << endl;
			}
			s=nextSeat(s);
			cc++;
        }
		cout << "Total Jumlah Seat : " << cc << endl;
    }
}
void showAllListSeat(listSeat L3){
    if(firstSeat(L3)==nil){
        cout<<"Tidak ada seat"<<endl;
    }else{
        adrSeat s=firstSeat(L3);
		cout << "=== Data Seat ===" << endl;
		int c = 0;
        while(s!=nil){
            cout<< "Nomor Seat : " <<infoSeat(s).nomorSeat<<endl;
			cout <<"Kapasitas : " <<infoSeat(s).kapasitas<<endl << endl;
			s=nextSeat(s);
			c++;
        }
		cout << "Jumlah Seat : " << c << endl;
    }
}
void showAllListOrang(listOrang L3){
    if(firstOrang(L3)==nil){
        cout<<"Tidak ada orang"<<endl;
    }else{
		cout << "=== Data Orang ===" << endl;
        adrOrang s=firstOrang(L3);
		int c = 0;
        while(s!=nil){
            cout<< "NIK : " << infoOrang(s).NIK<<"\n"
				<< "Nama : " <<  infoOrang(s).nama<<"\n"
				<<"Umur : "<< infoOrang(s).umur<<"\n" << endl;
            s=nextOrang(s);
			c++;
        }
		cout << "Jumlah Orang : " << c <<endl;
		cout << endl;
    }
}

void deleteOrang(listOrang &L2,string NIK,listSeat &L3){
	bool ans = false;
	adrOrang myo;
    adrOrang p = firstOrang(L2);
	adrOrang q = p;
    while (p != nil) {
		if(infoOrang(p).NIK == NIK){
			ans = true;
			myo = p;
			break;
		}
		q =p;
        p = nextOrang(p);
    }
	if(ans){
		adrSeat s=firstSeat(L3);
        while(s!=nil){
			if(book(s) != nil){
				adrRelation r=book(s);
				adrRelation rr =r;
				while(r!=nil){
					if(((r)->Orang)->infoOrang.NIK == NIK){
						if (r == rr && r == book(s)) {
							book(s) = nil;
						}else{
							(rr)->nextRelation = (r)->nextRelation;
						}
					}
					rr =r;
					r=nextRelation(r);
				}
			}
			s=nextSeat(s);
        }

		if(p == firstOrang(L2) && p == q){
			firstOrang(L2) = nil;
		}else{
			(q)->nextOrang = (p)->nextOrang;
		}
		cout << "Berhasil dihapus" << endl;
	}else{
		cout << "NIK tidak ditemukan "<<endl;
	}
}

int jumlahOrang(listSeat &L3, int noSeat){
    int i=0;
    adrSeat s=searchSeat(L3,noSeat);
    adrRelation r=book(s);
    while(r!=NULL){
        r=nextRelation(r);
        i++;
    }
    return i;
}
