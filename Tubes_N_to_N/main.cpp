#include <iostream>
#include "Tubes2.h"

using namespace std;

mll list_student;
adr_beasiswa B, adr_find_bea;
adr_student S, adr_stud, adr_delrel, ada_s, adr_find_stu;
string srch_mah, delrel_mah, nama, id, kategori, pilihan1;
char pilih_adm, pilih_shw, pilih_del, select, pilih_find, pilih_addons;
float ipk;
int jml_beasiswa, hitung;

void insert_data(){
    cout << "Masukan NIM : ";
    cin >> (id);
    cout << "Masukan Nama : ";
    cin >> (nama);
    cout << "Masukan IPK : ";
    cin >> (ipk);
    while (ipk > 4.0){
        cout << "IPK kamu tidak valid. masukan lagi" << endl;
        cout << "Masukan IPK : ";
        cin >> (ipk);
    }
    ada_s = search_student(list_student, id);
    if (ada_s == nil){
        newElm_student({id,nama,ipk}, S);
        insertLast_student(list_student, S);
        cout << "Masukan Banyak Beasiswa : ";
        cin >> (jml_beasiswa);
        hitung = 0;
        while (hitung < jml_beasiswa) {
            cout << "Beasiswa : ";
            cin >> (kategori);
            newElm_Beasiswa(kategori, B);
            insertNew_Beasiswa(list_student, S, B);
            hitung = hitung + 1;
        }
    } else {
        cout << "Data telah dimasukan" << endl;
        system("pause");
    }
    cout << endl;
}

void Show(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Beasiswa" << endl;
    cout << "3. Relasi" << endl;
    cout<< "Pilihan : " <<endl;
        cin >> (pilih_shw);
        switch (pilih_shw){
        case '1' :
            system("cls");
                show_student(list_student);
                cout << endl;
            break;
        case '2' :
            system("cls");
            cout<< "NIM Mahasiswa : ";
            cin>> (srch_mah);
            adr_stud = search_student(list_student, srch_mah);
            if (adr_stud != nil){
                    show_beasiswa(adr_stud);
            } else {
                    cout << "BEASISWA TIDAK DITEMUKAN";
            }
            cout << endl;
        break;
        case '3' :
            system("cls");
            showdata_student(list_student);
            cout << endl;
        break;
    }
}

void del(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Beasiswa di Mahasiswa tertentu" << endl;
    cout << "3. Relasi" << endl;
    cout<< "Pilihan : " <<endl;
        cin >> (pilih_del);
        switch (pilih_del){
        case '1' :
            system("cls");
            cout<< "NIM Mahasiswa : "; //1301204091
            cin>> (srch_mah);
            delete_student(list_student, srch_mah);
            //showdata_student(list_student);
            cout << endl;
        break;
        case '2' :
            system("cls");
            cout<< "Nama Beasiswa : ";
            cin>> (kategori);
            cout<< "NIM mahasiswa : ";
            cin>> (srch_mah);
            delete_BeasiswaofX(list_student, srch_mah, kategori);
        break;
        case '3' :
            system("cls");
            cout<< "NIM Mahasiswa : ";
            cin>> (srch_mah);
            adr_delrel = search_student(list_student, srch_mah);
            delrel(adr_delrel);
        break;
    }
}

void find_elm(){
    cout << "1. Mahasiswa" << endl;
    cout << "2. Beasiswa di Mahasiswa tertentu" << endl;
    cout<< "Pilihan : " <<endl;
        cin >> (pilih_find);
        switch (pilih_find){
        case '1' :
            system("cls");
            cout<< "NIM Mahasiswa : ";
            cin>> (srch_mah);
            adr_find_stu = search_student(list_student, srch_mah);
            showElm_student(list_student, adr_find_stu);
            //showdata_student(list_student);
            cout << endl;
        break;
        case '2' :
            system("cls");
            cout<< "Nama Beasiswa : ";
            cin>> (kategori);
            cout<< "NIM mahasiswa : ";
            cin>> (srch_mah);
            search_beasiswaofX(list_student, srch_mah, kategori);
        break;
    }
}

void addons(){
    cout << "1. Cari Beasiswa di semua Mahasiswa" << endl;
    cout << "2. Delete Beasiswa di semua Mahasiswa" << endl;
    cout<< "Pilihan : " <<endl;
        cin >> (pilih_addons);
        switch(pilih_addons){
        case '1' :
            system("cls");
            cout<< "Nama Beasiswa : ";
            cin>> (kategori);
            search_beasiswa(list_student, kategori);
        break;
        case '2' :
            system("cls");
            cout<< "Nama Beasiswa : ";
            cin>> (kategori);
            delete_Beasiswa(list_student, kategori);
            cout << endl;
        break;
        }
}

void mainmenu(){
    while(pilih_adm != '0'){
        cout<<"     |=======================================================|\n";
        cout<<"     |                                                       |\n";
        cout<<"     |            PENDATAAN BEASISWA MAHASISWA               |\n";
        cout<<"     |                                                       |\n";
        cout<<"     |_______________________________________________________|\n";
        cout<<"     |NO.|                       MENU                        |\n";
        cout<<"     |---|---------------------------------------------------|\n";
        cout<<"     |1. | MENAMBAHKAN DATA                                  |\n";
        cout<<"     |2. | MENAMPILKAN DATA                                  |\n";
        cout<<"     |3. | MENGHAPUS DATA                                    |\n";
        cout<<"     |4. | MENCARI DATA                                      |\n";
        cout<<"     |5. | FITUR TAMBAHAN                                    |\n";
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
                Show();
            } if(pilih_adm == '3'){
                system("cls");
                del();
            } if(pilih_adm == '4'){
                system("cls");
                find_elm();
            } if(pilih_adm == '5'){
                system("cls");
                addons();
            } else{
             system("cls");
            }
    }
}

int main()
{
    Create_list(list_student);
    mainmenu();
    return 0;
}
