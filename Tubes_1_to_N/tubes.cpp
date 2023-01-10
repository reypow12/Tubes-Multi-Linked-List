#include "tubes.h"

//Algoritma Mahasiswa
void create_mhs(list_mhs &L_mhs){
    first_mhs(L_mhs) = nil;
}

adr_mhs alokasi(infotype_mhs X){
    adr_mhs P = new elmlist_mhs;
    info_mhs(P) = X;
    next_mhs(P) = nil;
    return P;
}

void insertLast_mhs(list_mhs &L_mhs, adr_mhs S){
    if(first_mhs(L_mhs) == nil){
        first_mhs(L_mhs) = S;
    } else {
        adr_mhs P = first_mhs(L_mhs);
        while (next_mhs(P) != nil){
            P = next_mhs(P);
        }
        next_mhs(P) = S;
    }
}

void deleteFirst_mhs(list_mhs &L_mhs, adr_mhs &P){
    if(next_mhs(first_mhs(L_mhs)) == nil){
        first_mhs(L_mhs) = nil;
    } else {
        adr_mhs temp = first_mhs(L_mhs);
        first_mhs(L_mhs) = next_mhs(temp);
        next_mhs(temp) = nil;
    }
}

void deleteAfter_mhs(list_mhs &L_mhs, adr_mhs prec){
    adr_mhs Q = next_mhs(prec);
    next_mhs(prec) = next_mhs(Q);
    next_mhs(Q) = nil;
}

void delete_mhs(list_mhs &L_mhs, string srch_mhs){
    adr_mhs temp;
    if(info_mhs(first_mhs(L_mhs)) == srch_mhs){
        deleteFirst_mhs(L_mhs, temp);
    } else {
        adr_mhs P = first_mhs(L_mhs);
        adr_mhs Q = next_mhs(first_mhs(L_mhs));
        while (info_mhs(Q) != srch_mhs){
            P = Q;
            Q = next_mhs(Q);
        }
        deleteAfter_mhs(L_mhs, P);
    }
}

void show_mhs(list_mhs L_mhs){
    adr_mhs P;
    P = first_mhs(L_mhs);
    cout << "=== DATA MAHASISWA ===" << endl;
    while (P != nil){
        cout << info_mhs(P) << endl;
        P = next_mhs(P);
    }
    system("pause");
}

void Show_presofX(list_mhs &L_mhs, list_pres &L_pres, string srch_mhs){
    adr_mhs P = first_mhs(L_mhs);
    while (P != nil){
        if(info_mhs(P) == srch_mhs){
            adr_pres B = first_pres(L_pres);
            while (B != nil){
                if(mhs(B) == P){
                    cout << info_pres(B) << endl;
                }
                B = next_pres(B);
            }
        }
        P = next_mhs(P);
    }
    system("pause");
}

adr_mhs findElm_mhs(list_mhs L_mhs, infotype_mhs X){
    adr_mhs P = first_mhs(L_mhs);
    while (P != nil){
        if(info_mhs(P) == X){
            return P;
        }
        P = next_mhs(P);
    }
    return nil;
}

//Algoritma Prestasi
void create_pres(list_pres &L_pres){
    first_pres(L_pres) = nil;
}

adr_pres alokasi_pres(infotype_pres X){
    adr_pres P = new elmlist_pres;
    info_pres(P) = X;
    next_pres(P) = nil;
    mhs(P) = nil;
    return P;
}

void insertLast_pres(list_pres &L_pres, adr_pres B){
    if(first_pres(L_pres) == nil){
        first_pres(L_pres) = B;
    }else{
        adr_pres P = first_pres(L_pres);
        while (next_pres(P) != nil){
            P = next_pres(P);
        }
        next_pres(P) = B;
    }
}

void deleteFirst_pres(list_pres &L_pres, adr_pres &B){
    if(next_pres(first_pres(L_pres)) == nil){
        first_pres(L_pres) = nil;
    } else {
        adr_pres temp = first_pres(L_pres);
        first_pres(L_pres) = next_pres(temp);
        next_pres(temp) = nil;
    }
}

void deleteAfter_pres(list_pres &L_pres, adr_pres prec){
    adr_pres Q = next_pres(prec);
    next_pres(prec) = next_pres(Q);
    next_pres(Q) = nil;
}

void delete_pres(list_pres &L_pres, string nominasi){
    adr_pres temp;
    if(info_pres(first_pres(L_pres)) == nominasi){
        deleteFirst_pres(L_pres, temp);
    } else {
        adr_pres P = first_pres(L_pres);
        adr_pres Q = next_pres(first_pres(L_pres));
        while (info_pres(Q) != nominasi){
            P = Q;
            Q = next_pres(Q);
        }
        deleteAfter_pres(L_pres, P);
    }
}

void show_pres(list_pres L_pres){
    adr_pres P;
    P = first_pres(L_pres);
    cout << "=== DATA PRESTASI ===" << endl;
    while (P != nil){
        cout << info_pres(P) << endl;
        P = next_pres(P);
    }
    system("pause");
}

adr_pres findElm_pres(list_pres L_pres, infotype_pres X){
    adr_pres P = first_pres(L_pres);
    while (P != nil){
        if(info_pres(P) == X){
            return P;
        }
        P = next_pres(P);
    }
    return nil;
}

void sum_pres(list_mhs &L_mhs, list_pres &L_pres, string srch_mhs){
    int temp = 0;
    adr_mhs P = first_mhs(L_mhs);
    while (P != nil){
        if(info_mhs(P) == srch_mhs){
            adr_pres B = first_pres(L_pres);
            while (B != nil){
                if(mhs(B) == P){
                    temp = temp + 1;
                }
                B = next_pres(B);
            }
        }
        P = next_mhs(P);
    }
    cout << "Jumlah Prestasi : " << temp << " Lomba" << endl;
    system("pause");
}

//Algoritma Relasi

void connect(adr_mhs P, adr_pres &C){
    mhs(C) = P;
}

void disconect(adr_pres &C){
    mhs(C) = nil;
}

void show_relasi(list_pres L_pres){
    adr_pres P = first_pres(L_pres);
    cout << "=== DATA RELASI ===" << endl;
    while (P != nil){
        cout << info_pres(P) << " Dimenangi Oleh ";
        if(mhs(P) != nil){
            cout << info_mhs(mhs(P)) << endl;
        } else {
            cout << "NILL" << endl;
        }
        P = next_pres(P);
    }
    system("pause");
}

