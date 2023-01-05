#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <string>

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
    string NIK;
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
void showAll(listSeat L3);
void deleteSeat(listSeat &L3, int noSeat);
adrSeat searchSeat(listSeat L3, int nomorSeat);
adrOrang searchOrang(listOrang L2, string NIK);
void inserLastOrang(listOrang &L2, adrOrang b);
void connect(listSeat &L3, listOrang L2, string NIK, int nomorSeat);
void showAllListSeat(listSeat L3);
void showAllListSeat2(listSeat L3);
void deleteOrang(listOrang &L2,string NIK,listSeat &L3);
int jumlahOrang(listSeat &L3, int noSeat);
void showAllListOrang(listOrang L3);
bool cekSeat(listSeat L3, int nomorSeat);
bool cekOrang(listOrang L2, string NIK);
#endif // TUBES_H_INCLUDED
