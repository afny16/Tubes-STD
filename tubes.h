#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

#define infoOrang(P) (P)->infoOrang
#define nextOrang(P) (P)->nextOrang
#define infoSeat(P) (P)->infoSeat
#define nextSeat(P) (P)->nextSeat
#define book(P) (P)->book
#define Orang(P) (P)->Orang
#define nextRelation(P) (P)->nextRelation
#define firstSeat(L) ((L).firstSeat)
#define firstOrang(L) ((L).firstOrang)
#define nil NULL

using namespace std;


struct infoOrang{
    string nama;
    int umur;
    int NIK;
};

struct infoSeat{
    int nomorSeat;
    int kapasitas;
};

typedef struct elmOrang *adrOrang;
typedef struct elmSeat *adrSeat;
typedef struct elmRelation *adrRelation;

struct elmOrang{
    infoOrang infoOrang;
    adrOrang nextOrang;
};

struct elmSeat{
    infoSeat infoSeat;
    adrSeat nextSeat;
    adrRelation book;
};

struct elmRelation{
    adrOrang Orang;
    adrRelation nextRelation;
};

struct listSeat{
    adrSeat firstSeat;
};

struct listOrang{
    adrOrang firstOrang;
};

void createList(listOrang &L1, listSeat &L3);
adrSeat createElementSeat(infoSeat x);
adrOrang createElementOrang(infoOrang x);
adrRelation createElementRelation();
void insertLastSeat(listSeat &L3, adrSeat a);
void showAllSeat(listSeat L3);
void deleteSeat(listSeat &L3, int nomor, adrSeat &s);
adrSeat searchSeat(listSeat L3, int nomorSeat);
adrOrang searchOrang(listOrang L2, string nama);
void inserLastOrang(listOrang &L2, adrOrang b);
void connect(listOrang &L2, listSeat &L3, adrSeat p, adrOrang c);
void showAllListSeat(listSeat L3);
adrOrang findOrang(listOrang &L2, string nama, int nomor);
void deleteOrang(listSeat &L3 , string nama, adrOrang &j);
int jumlahOrang(listSeat &L3, int nomor);

#endif // TUBES_H_INCLUDED
