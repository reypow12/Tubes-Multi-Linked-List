#ifndef TUBES2_H_INCLUDED
#define TUBES2_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

#define nextbeasiswa(P) (P) -> nextbeasiswa
#define next(P) (P) -> next
#define first(list_student) ((list_student).first)
#define info(p) (p) -> info
#define nil NULL

typedef struct elm_student *adr_student;
typedef struct elm_beasiswa *adr_beasiswa;

struct student{
    string id;
    string nama;
    float ipk;
};

struct elm_student{
    student info;
    adr_student next;
    adr_beasiswa nextbeasiswa;
};

struct elm_beasiswa{
    string info;
    adr_beasiswa next;
};

struct mll{
    adr_student first;
};

void Create_list(mll &list_student);
void delrel(adr_student P);

void newElm_student(student info, adr_student &S);
void insertLast_student(mll &list_student, adr_student S);
void deleteFirst(mll &list_student, adr_student &P);
void deleteLast(mll &list_student, adr_student &P);
void deleteAfter(mll &list_student, adr_student prec);
void delete_student(mll &list_student, string srch_mah);
void show_student(mll list_student);
void showdata_student(mll list_student);
adr_student search_student(mll list_student, string id_student);
void showElm_student(mll list_student, adr_student S);

void newElm_Beasiswa(string info, adr_beasiswa &B);
void insertNew_Beasiswa(mll &list_student, adr_student S, adr_beasiswa B);
void deleteFirst_Beasiswa(mll &list_student, adr_student S, adr_beasiswa &B);
void deleteLast_Beasiswa(mll &list_student, adr_student &S, adr_beasiswa &B);
void deleteAfter_Beasiswa(mll &list_student, adr_student S, adr_beasiswa prec, adr_beasiswa &B);
void delete_Beasiswa(mll &list_student, string info);
void delete_BeasiswaofX(mll &list_student, string nim, string kategori);
void show_beasiswa(adr_student P);
void search_beasiswa(mll list_student, string kat);
void search_beasiswaofX(mll list_student, string nim, string kat);

#endif // TUBES2_H_INCLUDED
