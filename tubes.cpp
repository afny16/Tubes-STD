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
        cout << "Tidak ada Seat" << endl;
    }
}

void deleteSeat(listSeat &L3, int NIK, adrSeat &s) {
    if(firstSeat(L3) != nil) {
        adrSeat p = firstSeat(L3); int NIK = 1;
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

adrOrang searchOrang(listOrang L2, int NIK){
    adrOrang p = firstOrang(L2);
    while (p != nil && infoOrang(p).NIK != NIK) {
        p = next(p);
    }
    if (p != nil) {
        return p;
    }
    return NULL;
}

void inserLastOrang(listOrang &L2, adrOrang b){
    adrOrang p = firstOrang(L2);
    if (firstOrang(L2) == nil){
        firstOrang(L2) = b;
    }else{
        while (next(p) == nil){
            p = nextOrang(p);
        }
        nextOrang(p) = b;
    }
}

void connect(listSeat &L3, listOrang L2, int NIK, int nomorSeat){
    adrSeat s = searchSeat(L3, nomorSeat);
    adrRelation t=createElementRelation();
    adrOrang o=searchOrang(L2,NIK),g;
    infoOrang(g)=infoOrang(o);
    if(book(s)==nil){
        book(s)=t;
        Orang(book(s))=g;
    }else{
        adrRelation r=book(s);
        while(nextRelation(r)!=nil){
            r=nextRelation(r);
        }
        nextRelation(r)=t;
        Orang(t)=g;
    }
}

void showAllListSeat(listSeat L3);
adrOrang findOrang(listOrang &L2, int NIK){
    adrOrang p = firstOrang(L2);
    if (firstOrang(L2)!= nil){
        while (p != nil && infoOrang(p).NIK != NIK){
            p = nextOrang(p);
        }
    }
    return p;
}
void deleteOrang(listSeat &L3 , int NIK, adrOrang &j){
    listOrang(L4);
    if (firstSeat(L3) == nil){
        cout << "NIK kosong!!!" << endl;
    }else{
        j = findOrang(L4, NIK);

        if (j == nil){
            cout << "NIK tidak ditemukan!!!" << endl;
        }else if (firstSeat(L3) == nil){
            deleteSeat(L3, NIK, j);
        }else{
            adrOrang p = firstOrang(L3);
            while (infoOrang(nextOrang(p) != nama){
                   p = nextOrang(p);
            }
            nextOrang(p) = nextOrang(j);
            nextOrang(j) = nil;
        }
    }
}

int jumlahOrang(listSeat &L3, int NIK);
