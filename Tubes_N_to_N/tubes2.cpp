#include "Tubes2.h"

void Create_list(mll &list_student){
    first(list_student) = nil;
}

void showdata_student(mll list_student){ //nampilin semua data
    if (first(list_student) ==  nil){
        cout << "LIST KOSONG !!" << endl;
    } else {
        adr_student S;
        S = first(list_student);
        cout << "=== DATA MAHASISWA ===" << endl;
        while (S != nil){
            cout << info(S).id << endl;
            adr_beasiswa B = nextbeasiswa(S);
            while(B != nil){
                cout << info(B) << endl;
                B = next(B);
            }
            if(nextbeasiswa(S) != nil){
                cout << endl << endl;
            }
            S = next(S);
        }
        cout << "= Data mahasiswa telah di tampilkan =";
        cout << endl;
    }
    system("pause");
}

// Algoritma Mahasiswa

void newElm_student(student info, adr_student &S){
    adr_student P = new elm_student;
    info(P) = info;
    next(P) = nil;
    nextbeasiswa(P) = nil;
    S = P;
}


void insertLast_student(mll &list_student, adr_student S){
    if (first(list_student) == nil){
        first(list_student) = S;
    } else {
        adr_student P = first(list_student);
        while (next(P) != nil){
            P = next(P);
        }
        next(P) = S;
    }
}

void deleteFirst(mll &list_student, adr_student &P){
    if (next(first(list_student)) == nil){
        first(list_student) = nil;
    } else {
        adr_student temp;
        temp = first(list_student);
        first(list_student) = next(temp);
        next(temp) = nil;
    }
}

/*
void deleteLast(mll &list_student, adr_student &P){
    if (next(first(list_student)) == nil){
        first(list_student) = nil;
    } else {
        adr_student Q = next(first(list_student));
        adr_student R = first(list_student);
        while(next(Q) != nil){
            R = Q;
            Q = next(Q);
        }
        next(R) = nil;
    }
}

*/

void deleteAfter(mll &list_student, adr_student prec){
    adr_student Q = next(prec);
    next(prec) = next(Q);
    next(Q) = nil;
}

void delete_student(mll &list_student, string srch_mah){
    adr_student temp;
    if (info(first(list_student)).id == srch_mah){
        deleteFirst(list_student, temp);
    } else {
        adr_student P = first(list_student);
        adr_student Q = next(first(list_student));
        while (info(Q).id != srch_mah){
            P = Q;
            Q = next(Q);
        }
        deleteAfter(list_student, P);
    }
}

void show_student(mll list_student){ //nampilin khusus student
    adr_student P;
    P = first(list_student);
    cout << "=== Data Mahasiswa ===" << endl;
    cout << "NIM";
    cout << "\t \t \t" << "NAMA";
    cout << "\t \t" << "IPK";
    cout << endl;
    while (P != nil) {
        cout << info(P).id;
        cout << "\t \t" << info(P).nama;
        cout << "\t \t" << info(P).ipk;
        cout << endl;
        P = next(P);
    }
    system("pause");
}

adr_student search_student(mll list_student, string id_student){
        adr_student P = first(list_student);
        while (P != nil && info(P).id != id_student){
            P = next(P);
        }
        return P;
}

void showElm_student(mll list_student, adr_student S){
    cout << "=== Data Mahasiswa ===" << endl;
    cout << "NIM";
    cout << "\t \t \t" << "NAMA";
    cout << "\t \t" << "IPK";
    cout << endl;
    cout << info(S).id;
    cout << "\t \t" << info(S).nama;
    cout << "\t \t" << info(S).ipk;
    cout << endl;
    system("pause");
}

void delrel(adr_student P){
    nextbeasiswa(P) = nil;
}


// Algoritma Beasiswa

void newElm_Beasiswa(string info, adr_beasiswa &B){
    adr_beasiswa P = new elm_beasiswa;
    info(P) = info;
    next(P) = nil;
    B = P;
}

void insertNew_Beasiswa(mll &list_student, adr_student S, adr_beasiswa B){
    if (first(list_student) != nil){
        adr_beasiswa Q = nextbeasiswa(S);
        if (Q != nil){
            while (next(Q) != nil){
                Q = next(Q);
            }
            next(Q) = B;
        } else {
            nextbeasiswa(S) = B;
        }
    }
}

void deleteFirst_Beasiswa(mll &list_student, adr_student S, adr_beasiswa &B){
    adr_beasiswa Q = nextbeasiswa(S);
    if (next(Q) == nil){
        Q = nil;
    } else {
        adr_beasiswa temp = nextbeasiswa(S);
        Q = next(Q);
        next(temp) = nil;
    }
    nextbeasiswa(S) = Q;
}

void deleteLast_Beasiswa(mll &list_student, adr_student &S, adr_beasiswa &B){
    if(first(list_student) != nil) {
        adr_beasiswa Q = nextbeasiswa(S);
        while (next(next(Q)) != nil){
            Q = next(Q);
        }
        B = Q;
        next(B) = nil;
    }
}

void deleteAfter_Beasiswa(mll &list_student, adr_student S, adr_beasiswa prec, adr_beasiswa &B){
    if(first(list_student) != nil){
        B = next(prec);
        next(prec) = next(B);
        next(B) = nil;
    }
}

void delete_Beasiswa(mll &list_student, string kategori){
    if(first(list_student) != nil){
        adr_student S = first(list_student);
        while(S != nil){
            adr_beasiswa B = nextbeasiswa(S);
            while(B != nil){
                adr_beasiswa temp;
                if(info(B) == kategori){
                    if(B == nextbeasiswa(S)){
                        deleteFirst_Beasiswa(list_student, S, B);
                    } else if (next(B) == nil){
                        deleteLast_Beasiswa(list_student, S, B);
                    } else {
                        adr_beasiswa X = next(B);
                        deleteAfter_Beasiswa(list_student, S, temp, B);
                        B = X;
                        continue;
                    }
                }
                temp = B;
                B = next(B);
            }
            S = next(S);
        }
    } else {
        cout << "LIST KOSONG!";
    }
}

void delete_BeasiswaofX(mll &list_student, string nim, string kategori){
    if(first(list_student) != nil){
        adr_student S = first(list_student);
        while(S != nil){
            if(info(S).id == nim) {
            adr_beasiswa B = nextbeasiswa(S);
            while(B != nil){
                adr_beasiswa temp;
                if(info(B) == kategori){
                    if(B == nextbeasiswa(S)){
                        deleteFirst_Beasiswa(list_student, S, B);
                    } else if (next(B) == nil){
                        deleteLast_Beasiswa(list_student, S, B);
                    } else {
                        adr_beasiswa X = next(B);
                        deleteAfter_Beasiswa(list_student, S, temp, B);
                        B = X;
                        continue;
                    }
                }
                temp = B;
                B = next(B);
            }
            }
            S = next(S);
        }
    } else {
        cout << "LIST KOSONG!";
    }
}

void show_beasiswa(adr_student P){
    adr_beasiswa Q;
    Q = nextbeasiswa(P);
    cout << "=== Data Beasiswa ===" << endl;
    while (Q != nil){
        cout << info(Q);
        cout << endl;
        Q = next(Q);
    }
    system("pause");
}

void search_beasiswaofX(mll list_student, string nim, string kat){
    adr_student S = first(list_student);
    while (S != nil){
        if (info(S).id == nim){
            adr_beasiswa B = nextbeasiswa(S);
            while(B != nil){
                if(info(B) == kat){
                    cout << endl;
                    cout << "Mahasiswa dengan nim " << info(S).id << " punya beasiswa " << kat << endl;
                    cout << endl;
                }
            B = next(B);
            }
        }
    S = next(S);
    }
    system("pause");
}

void search_beasiswa(mll list_student, string kat){
    adr_student S = first(list_student);
    cout << "=== Data Mahasiswa ===" << endl;
    cout << "NIM";
    cout << "\t \t \t" << "NAMA";
    cout << "\t \t" << "IPK";
    cout << endl;
    while(S != nil){
        adr_beasiswa B = nextbeasiswa(S);
        while(B != nil){
            if(info(B) == kat){
                cout << info(S).id;
                cout << "\t \t" << info(S).nama;
                cout << "\t \t" << info(S).ipk;
                cout << endl;
            }
            B = next(B);
        }
        S = next(S);
    }
    system("pause");
}

