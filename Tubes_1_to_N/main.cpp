#include <iostream>
#include "tubes.h"

using namespace std;

list_mhs LM;
list_pres LP;
adr_mhs M;
adr_pres P;
string id, nominasi;
char pilih_insrt, pilih_del, pilih_shw,pilih_adm, pilih_addons;

void insert_data(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Juara" << endl;
    cout << "3. Relasi" << endl;
    cout << "Pilihan : " << endl;
        cin >> (pilih_insrt);
        switch (pilih_insrt){
        case '1' :
            system("cls");
                cout << "Masukan Nama : ";
                cin >> (id);
                M = alokasi(id);
                insertLast_mhs(LM, M);
            break;
        case '2' :
            system("cls");
               cout << "Masukan Juara : ";
               cin >> (nominasi);
               P = alokasi_pres(nominasi);
               insertLast_pres(LP, P);
            break;
        case '3' :
            system("cls");
                cout << "Masukan Nama : ";
                cin >> (id);
                cout << "Masukan Juara : ";
                cin >> (nominasi);
                M = findElm_mhs(LM,id);
                P = findElm_pres(LP,nominasi);
                connect(M, P);
            break;
        }
}

void del_data(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Juara" << endl;
    cout << "3. Relasi" << endl;
    cout << "Pilihan : " << endl;
        cin >> (pilih_del);
        switch (pilih_del){
        case '1' :
            system("cls");
            cout << "Masukan Nama : ";
            cin >> (id);
            delete_mhs(LM, id);
            cout << endl;
        break;
        case '2' :
            system("cls");
            cout << "Masukan Juara : ";
            cin >> (nominasi);
            delete_pres(LP, nominasi);
        break;
        case '3' :
            system("cls");
            cout << "Masukan Juara : ";
            cin >> (nominasi);
            P = findElm_pres(LP, nominasi);
            disconect(P);
        break;
        }
}

void show_data(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Juara" << endl;
    cout << "3. Juara di mahasiswa tertentu" << endl;
    cout << "Pilihan : " << endl;
        cin >> (pilih_shw);
        switch (pilih_shw){
        case '1' :
            system("cls");
                show_mhs(LM);
                cout << endl;
        break;
        case '2' :
            system("cls");
                show_pres(LP);
                cout << endl;
        break;
        case '3' :
            system("cls");
                cout << "Masukan Nama : ";
                cin >> (id);
                Show_presofX(LM, LP, id);
                cout << endl;
        break;
    }
}

void addons(){
    cout << "1. Show Juara di semua mahasiswa" << endl;
    cout << "2. Jumlah Juara di mahasiswa tertentu" << endl;
    cout << "Pilihan : " << endl;
        cin >> (pilih_addons);
        switch(pilih_addons){
        case '1' :
            system("cls");
                show_relasi(LP);
                cout << endl;
        break;
        case '2' :
            system("cls");
                cout << "Masukan Nama : ";
                cin >> (id);
                sum_pres(LM, LP, id);
                cout << endl;
        break;
        }
}

void mainmenu(){
    while (pilih_adm != '0' ){
        cout<<"     |=======================================================|\n";
        cout<<"     |                                                       |\n";
        cout<<"     |            PENDATAAN PRESTASI MAHASISWA               |\n";
        cout<<"     |                                                       |\n";
        cout<<"     |_______________________________________________________|\n";
        cout<<"     |NO.|                       MENU                        |\n";
        cout<<"     |---|---------------------------------------------------|\n";
        cout<<"     |1. | MENAMBAHKAN DATA                                  |\n";
        cout<<"     |2. | MENAMPILKAN DATA                                  |\n";
        cout<<"     |3. | MENGHAPUS DATA                                    |\n";
        cout<<"     |4. | FITUR TAMBAHAN                                    |\n";
        cout<<"     |===|===================================================|\n";
        cout<<"     |0. | EXIT                                              |\n";
        cout<<"     |___|___________________________________________________|\n";
        cout<<"     Select Menu: ";
        cin >> (pilih_adm);
            if(pilih_adm == '1'){
                system("cls");
                insert_data();
            } if(pilih_adm == '2'){
                system("cls");
                show_data();
            } if(pilih_adm == '3'){
                system("cls");
                del_data();
            } if(pilih_adm == '4'){
                system("cls");
                addons();
            } else {
                system("cls");
            }
    }
}

int main(){
    create_mhs(LM);
    create_pres(LP);
    mainmenu();
    return 0;
}
