#include "family.h"

int main()
{
    list_child lc;
    adr_child c;
    string anakbaru;
    createlist_child(lc);

    list_parent lp;
    adr_parent p;
    string ortubaru;
    createlist_parent(lp);

    list_relasi lr;
    adr_relasi r;
    createlist_relasi(lr);

    int total;

    cout << "SELAMAT DATANG DI APLIKASI HAPPY FAMILY" << endl;

    int n;
    int pilihan = menu();

    while(pilihan != 0){
        switch(pilihan){
        case 1 :
            cout << "\nMenambahkan List Anak" << endl;
            cout << "Jumlah data yang akan ditambahkan: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "Masukkan nama anak: ";
                cin >> anakbaru;
                createelm_child(anakbaru, c);
                insert_child(lc, c);
                cout << "Data berhasil dimasukkan." << endl;
            }
            break;
        case 2 :
            cout << "\nMenambahkan List Orang Tua" << endl;
            cout << "Jumlah data yang akan ditambahkan: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "Masukkan nama orang tua: ";
                cin >> ortubaru;
                createelm_parent(ortubaru, p);
                insert_parent(lp, p);
                cout << "Data berhasil dimasukkan." << endl;
            }
            break;
        case 3 :
            cout << "\nMenambahkan relasi orang tua dan anak" << endl;
            cout << "Masukkan nama orang tua: ";
            cin >> ortubaru;
            cout << "Masukkan nama anak: ";
            cin >> anakbaru;
            p = findelemparent(lp, ortubaru);
            c = findelemchild(lc, anakbaru);
            while(p == NULL || c == NULL){
                cout << "nama orang tua atau anak tidak ada dalam list. Silahkan coba lagi." << endl;
                cout << "Masukkan nama orang tua: ";
                cin >> ortubaru;
                cout << "Masukkan nama anak: ";
                cin >> anakbaru;
                p = findelemparent(lp, ortubaru);
                c = findelemchild(lc, anakbaru);
            }
            createelm_relasi(r,p,c);
            insert_relasi(lr,r);
            cout << "Data berhasil dimasukkan." << endl;
            break;
        case 4 :
            show_child(lc);
            break;
        case 5 :
            show_parent(lp);
            break;
        case 6 :
            show_relasi(lr);
            break;
        case 7 :
            cout << "\nMenghitung banyak anak dari orang tua tertentu" << endl;
            cout << "Masukkan nama orang tua: ";
            cin >> ortubaru;
            while(findelemparent(lp,ortubaru) == NULL){
                cout << "Orang tua tidak ditemukan. Silahkan coba lagi." << endl;
                cout << "Masukkan nama orang tua: ";
                cin >> ortubaru;
            }
            total = hitunganak(lr, findelemparent(lp,ortubaru));
            cout << "Banyak anak " << ortubaru << " adalah " << total << endl;
            break;
        case 8 :
            cout << "\nMencari orang tua dari anak tertentu" << endl;
            cout << "Masukkan nama anak: ";
            cin >> anakbaru;
            while(findelemchild(lc,anakbaru) == NULL){
                cout << "Anak tidak ditemukan. Silahkan coba lagi." << endl;
                cout << "Masukkan nama anak: ";
                cin >> anakbaru;
            }
            ortubaru = info(findparentfromchild(lr,anakbaru));
            cout << "Orang tua dari " << anakbaru << " adalah " << ortubaru << endl;
            break;
        case 9 :
            cout << "\nMenghapus data orang tua" << endl;
            cout << "Masukkan nama orang tua: ";
            cin >> ortubaru;
            while(findelemparent(lp,ortubaru) == NULL){
                cout << "Orang tua tidak ditemukan. Silahkan coba lagi." << endl;
                cout << "Masukkan nama orang tua: ";
                cin >> ortubaru;
            }
            p = findelemparent(lp,ortubaru);
            total = hitunganak(lr,p);
            for(int i = 0; i < total; i++){
                delete_relasi(lr,r,ortubaru);
            }
            delete_parent(lp,p,ortubaru);
            cout << "Data berhasil dihapus." << endl;
            break;
        case 10 :
            cout << "\nMenghapus data anak dari orang tua tertentu" << endl;
            cout << "Masukkan nama orang tua: ";
            cin >> ortubaru;
            while(findelemparent(lp,ortubaru) == NULL){
                cout << "Orang tua tidak ditemukan. Silahkan coba lagi." << endl;
                cout << "Masukkan nama orang tua: ";
                cin >> ortubaru;
            }
            p = findelemparent(lp, ortubaru);
            delete_child(lr,lc,p,c);
            delete_relasi(lr,r,ortubaru);
            cout << "Data berhasil dihapus" << endl;
            break;
        case 11 :
            r = tunjangan(lr);
            cout << "Keluarga yang memperoleh tunjangan anak terbanyak adalah keluarga " << info(nextParent(r)) << endl;
            break;
        }
        pilihan = menu();
    }

    cout << "Anda telah keluar dari program" << endl;



    // TEST CASE //

//    anakbaru = "Diva";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    anakbaru = "Kimberly";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    anakbaru = "Christian";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    anakbaru = "Rafli";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    anakbaru = "Keita";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    anakbaru = "Anthony";
//    createelm_child(anakbaru,c);
//    insert_child(lc, c);
//
//    show_child(lc);
//
//
//
//    ortubaru = "Sujono";
//    createelm_parent(ortubaru, p);
//    insert_parent(lp, p);
//
//    ortubaru = "Sumiyati";
//    createelm_parent(ortubaru, p);
//    insert_parent(lp, p);
//
//    ortubaru = "Rusmini";
//    createelm_parent(ortubaru, p);
//    insert_parent(lp, p);
//
//    ortubaru = "Tata";
//    createelm_parent(ortubaru, p);
//    insert_parent(lp, p);
//
//    show_parent(lp);
//    cout << endl;
//
//    p = findelemparent(lp,"Sujono");
//    c = findelemchild(lc,"Christian");
//
//    createelm_relasi(r,p,c);
//    insert_relasi(lr,r);
//
//    p = findelemparent(lp,"Sumiyati");
//    c = findelemchild(lc,"Anthony");
//
//    createelm_relasi(r,p,c);
//    insert_relasi(lr,r);
//
//    p = findelemparent(lp, "Tata");
//    c = findelemchild(lc, "Kimberly");
//
//    createelm_relasi(r,p,c);
//    insert_relasi(lr,r);
//
//    p = findelemparent(lp, "Rusmini");
//    c = findelemchild(lc, "Diva");
//
//    createelm_relasi(r,p,c);
//    insert_relasi(lr,r);
//
//    p = findelemparent(lp, "Sumiyati");
//    c = findelemchild(lc, "Rafli");
//
//    createelm_relasi(r,p,c);
//    insert_relasi(lr,r);
//
//    show_relasi(lr);
//    cout << endl;
//
//    cout << "Anak " << info(p) << ": " << hitunganak(lr,p) << endl;
//    cout << "Anak Sujono: " << hitunganak(lr,findelemparent(lp,"Sujono")) << endl;
//
//    cout << endl;
    //cout << info(findparentfromchild(lr,"Diva")) << endl;

//    cout << endl << "Hapus Sumiyati dan relasinya" << endl;
//    p = findelemparent(lp, "Sumiyati");
//    total = hitunganak(lr,p);
//
//    adr_parent ppp = findelemparent(lp,"Sumiyati");
//    delete_child(lr,lc,ppp,c);
//    show_child(lc);
//
//    for(int i = 0; i < total; i++){
//        delete_relasi(lr,r,"Sumiyati");
//    }
//
//    delete_parent(lp,p,"Sumiyati");
//    show_parent(lp);
//    show_relasi(lr);

//    adr_relasi tun = tunjangan(lr);
//    cout << info(nextParent(tun)) << endl;

}
