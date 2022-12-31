#include "tubes.h"

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
    while (nextSeat(c) != nil){
        c = nextSeat(c);
    }
    nextSeat(c) = a;
}

void showAllSeat(listSeat L3){
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
        cout << "Tidak ada Seat" << endl;
    }
}

void deleteSeat(listSeat &L3, int nomor, adrSeat &s) {
    if(firstSeat(L3) != nil) {
        adrSeat p = firstSeat(L3); int nomor = 1;
        while(nextSeat(nextSeat(p)) != firstSeat(L3)) {
            p = next(p);
        }
        s = nextSeat(p);
        nextSeat(p) = firstSeat(L3);
        nextSeat(s) = nil;
    }else{
        s = nil;
    }
}

adrSeat searchSeat(listSeat L3, int nomorSeat){
    adrSeat p = firstSeat(L3);
    while (p != nil && infoSeat(p).nomorSeat != nomorSeat) {
        p = next(p);
    }
    if (p != nil) {
        return p;
    }
    return NULL;
}

adrOrang searchOrang(listOrang L2, string nama){
    adrOrang p = firstOrang(L2);
    while (p != nil && infoOrang(p).nama != nama) {
        p = next(p);
    }
    if (p != nil) {
        return p;
    }
    return NULL;
}

void inserLastOrang(listOrang &L2, adrOrang b);
void connect(listOrang &L2, listSeat &L3, adrSeat p, adrOrang c);
void showAllListSeat(listSeat L3);
adrOrang findOrang(listOrang &L2, string nama, int nomor);
void deleteOrang(listSeat &L3 , string nama, adrOrang &j);
int jumlahOrang(listSeat &L3, int nomor);
