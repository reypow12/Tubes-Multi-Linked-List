#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

#define nil NULL

//Definisi Mahasiswa
#define first_mhs(L) L.first_mhs
#define next_mhs(P) P->next_mhs
#define info_mhs(P) P->info_mhs

//Definisi Prestasi
#define next_pres(P) P->next_pres
#define first_pres(L) L.first_pres
#define info_pres(P) P->info_pres
#define mhs(P) P->mhs

#define n

//Struct Mahasiswa
typedef string infotype_mhs;
typedef struct elmlist_mhs *adr_mhs;

struct elmlist_mhs{
    infotype_mhs info_mhs;
    adr_mhs next_mhs;
};

struct list_mhs{
    adr_mhs first_mhs;
};


//Struct Prestasi
typedef string infotype_pres;
typedef struct elmlist_pres *adr_pres;

struct elmlist_pres{
    infotype_pres info_pres;
    adr_pres next_pres;
    adr_mhs mhs;
};

struct list_pres{
    adr_pres first_pres;
};


//Func/proc Mahasiswa
void create_mhs(list_mhs &L_mhs);
adr_mhs alokasi(infotype_mhs X);
void insertLast_mhs(list_mhs &L_mhs, adr_mhs S);
void deleteFirst_mhs(list_mhs &L_mhs, adr_mhs &P);
void deleteAfter_mhs(list_mhs &L_mhs, adr_mhs prec);
void delete_mhs(list_mhs &L_mhs, string srch_mhs);
void show_mhs(list_mhs L_mhs);
adr_mhs findElm_mhs(list_mhs L_mhs, string X);
void Show_presofX(list_mhs &L_mhs, list_pres &L_pres, string srch_mhs);

//Func/proc Prestasi
void create_pres(list_pres &L_pres);
adr_pres alokasi_pres(infotype_pres X);
void insertLast_pres(list_pres &L_pres, adr_pres B);
void deleteFirst_pres(list_pres &L_pres, adr_pres &B);
void deleteAfter_pres(list_pres &L_pres, adr_pres prec);
void delete_pres(list_pres &L_pres, string nominasi);
void show_pres(list_pres L_pres);
adr_pres findElm_pres(list_pres L_pres, string X);
void sum_pres(list_mhs &L_mhs, list_pres &L_pres, string srch_mhs);

//Func/proc Relasi
void connect(adr_mhs P, adr_pres &C);
void disconect(adr_pres &C);
void show_relasi(list_pres L_pres);

#endif // TUBES_H_INCLUDED
