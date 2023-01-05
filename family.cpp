#include "family.h"

void createlist_child(list_child &lc){
    first(lc) = NULL;
}

void createelm_child(string x, adr_child &c){
    c = new elm_child;
    info(c) = x;
    next(c) = NULL;
}

void insert_child(list_child &lc, adr_child c){
    if(first(lc) == NULL){
        first(lc) = c;
    }else{
        adr_child q = first(lc);
        while(next(q) != NULL){
            q = next(q);
        }
        next(q) = c;
    }
}

void show_child(list_child lc){
    if(first(lc) == NULL){
        cout << "List kosong" << endl;
    }else{
        adr_child q = first(lc);
        cout << "List anak: ";
        while(next(q) != NULL){
            cout << info(q) << ", ";
            q = next(q);
        }
        cout << info(q) << endl;
    }
}

adr_child findelemchild(list_child lc, string x){
    adr_child c = first(lc);
    while(c != NULL){
        if(info(c) == x){
            return c;
        }
        c = next(c);
    }
    return NULL;
}

void deletefirst_child(list_child &lc, adr_child &c){
    c = first(lc);
    first(lc) = next(c);
    next(c) = NULL;
}

void deletelast_child(list_child &lc, adr_child &c){
    adr_child cc = first(lc);
    while(next(next(cc)) != NULL){
        cc = next(cc);
    }
    c = next(cc);
    next(cc) = NULL;
}

void deleteafter_child(list_child &lc, adr_child prec, adr_child &c){
    c = next(prec);
    next(prec) = next(c);
    next(c) = NULL;
}

void delete_child(list_relasi &lr, list_child &lc, adr_parent p, adr_child &c){
    adr_relasi r = first(lr);
    while(r != NULL){
        if(nextParent(r) == p){
            if(nextChild(r) == first(lc)){
                deletefirst_child(lc,c);
            }else{
                adr_child cc = first(lc);
                while(next(next(cc)) != NULL && cc != nextChild(r)){
                    cc = next(cc);
                }
                if(next(next(cc)) == NULL){
                    deletelast_child(lc,c);
                }else{
                    deleteafter_child(lc,cc,c);
                }
            }
            nextChild(r) = NULL;
        }
        r = next(r);
    }
}

void createlist_parent(list_parent &lp){
    first(lp) = NULL;
}

void createelm_parent(string x, adr_parent &p){
    p = new elm_parent;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
}

void insert_parent(list_parent &lp, adr_parent p){
    if(first(lp) == NULL){
        first(lp) = p;
        next(p) = p;
        prev(p) = p;
    }else{
        adr_parent q = first(lp);
        while(next(q) != first(lp)){
            q = next(q);
        }
        next(q) = p;
        prev(p) = q;
        next(p) = first(lp);
        prev(first(lp)) = p;
    }

}
void show_parent(list_parent lp){
    if(first(lp) == NULL){
        cout << "List kosong" << endl;
    }else{
        adr_parent q = first(lp);
        cout << "List orang tua: ";
        while(next(q) != first(lp)){
            cout << info(q) << ", ";
            q = next(q);
        }
        cout << info(q) << endl;
    }
}

adr_parent findelemparent(list_parent lp, string x){
    adr_parent p = first(lp);
    while(next(p) != first(lp)){
        if(info(p) == x){
            return p;
        }
        p = next(p);
    }
    if(info(p) == x){
        return p;
    }
    return NULL;
}

void deletefirst_parent(list_parent &lp, adr_parent &p){
    if(next(first(lp)) == NULL){
        p = first(lp);
        next(p) = NULL;
        prev(p) = NULL;
        first(lp) = NULL;
    }else{
        p = first(lp);
        next(prev(first(lp))) = next(first(lp));
        prev(next(first(lp))) = prev(first(lp));
        first(lp) = next(first(lp));
        next(p) = NULL;
        prev(p) = NULL;
    }
}

void deletelast_parent(list_parent &lp, adr_parent &p){
    deleteafter_parent(lp,p,prev(prev(first(lp))));
}

void deleteafter_parent(list_parent &lp, adr_parent &p, adr_parent prec){
    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    prev(p) = NULL;
    next(p) = NULL;
}

void delete_parent(list_parent &lp, adr_parent &p, string x){
    adr_parent ppp = first(lp);
    while(ppp != NULL){
        if(info(ppp) == x){
            if(ppp == first(lp)){
                deletefirst_parent(lp,p);
            }else{
                adr_parent pp = first(lp);
                while(next(pp) != first(lp) && ppp != pp){
                    pp = next(pp);
                }
                if(pp == prev(first(lp))){
                    deletelast_parent(lp,p);
                }else{
                    deleteafter_parent(lp,p,prev(pp));
                }
            }
        }
        ppp = next(ppp);
    }
}

void createlist_relasi(list_relasi &lr){
    first(lr) = NULL;
}

void createelm_relasi(adr_relasi &r, adr_parent p, adr_child c){
    r = new elm_relasi;
    nextChild(r) = c;
    nextParent(r) = p;
    next(r) = NULL;
}

void insert_relasi(list_relasi &lr, adr_relasi r){
    if(first(lr) == NULL){
        first(lr) = r;
    }else{
        adr_relasi rr = first(lr);
        while(next(rr) != NULL){
            rr = next(rr);
        }
        next(rr) = r;
        prev(r) = rr;
    }
}

adr_relasi findelemrelasi(list_relasi lr, string x){
    adr_relasi r = first(lr);
    while(r != NULL){
        if(info(nextParent(r)) == x){
            return r;
        }
        r = next(r);
    }
    return NULL;
}

void show_relasi(list_relasi lr){
    adr_relasi r = first(lr);
    if(first(lr) == NULL){
        cout << "List kosong" << endl;
    }else{
        cout << "List Relasi Orang Tua dan Anaknya" << endl;
        while(r != NULL){
            cout << info(nextParent(r)) << " -> " << info(nextChild(r)) << endl;
            r = next(r);
        }
    }
}

void deletefirst_relasi(list_relasi &lr, adr_relasi &r){
    if(next(first(lr)) == NULL){
        r = first(lr);
        prev(r) = NULL;
        next(r) = NULL;
        first(lr) = NULL;
    }else{
        r = first(lr);
        first(lr) = next(r);
        prev(first(lr)) = NULL;
        next(r) = NULL;
    }
}

void deletelast_relasi(list_relasi &lr, adr_relasi &r){
    adr_relasi rr = first(lr);
    while(next(next(rr)) != NULL){
        rr = next(rr);
    }
    r = next(rr);
    next(rr) = NULL;
    prev(r) = NULL;
}

void deleteafter_relasi(list_relasi &lr, adr_relasi &r, adr_relasi prec){
    r = next(prec);
    next(prec) = next(r);
    prev(next(r)) = prec;
    next(r) = NULL;
    prev(r) = NULL;
}

void delete_relasi(list_relasi &lr, adr_relasi &r, string x){
    adr_relasi rr = first(lr);
    while(rr != NULL){
        if(info(nextParent(rr)) == x){
            if(rr == first(lr)){
                    deletefirst_relasi(lr, r);
            }else{
                adr_relasi rrr = first(lr);
                while(next(rrr) != NULL && rrr != rr){
                    rrr = next(rrr);
                }
                if(next(rrr) == NULL){
                    deletelast_relasi(lr,r);
                }else{
                    deleteafter_relasi(lr,r,prev(rrr));
                }
            }
        }
        rr = next(rr);
    }
}

int hitunganak(list_relasi lr, adr_parent p){
    int res = 0;
    adr_relasi r = first(lr);
    while(r != NULL){
        if(nextParent(r) == p){
            if(nextChild(r) != NULL){
                res += 1;
            }
        }
        r = next(r);
    }
    return res;
}

int menu(){
    cout << endl << "===== Menu =====" << endl <<
    "1. Menambah list anak" << endl <<
    "2. Menambah list orang tua" << endl <<
    "3. Menambah relasi" << endl <<
    "4. Menampilkan list anak" << endl <<
    "5. Menampilkan list orang tua" << endl <<
    "6. Menampilkan list relasi" << endl <<
    "7. Menghitung banyak anak dari orang tertentu" << endl <<
    "8. Mencari data orang tua yang memiliki anak tertentu" << endl <<
    "9. Menghapus data orang tua beserta relasinya" << endl <<
    "10. Menghapus data anak pada orang tua tertentu" << endl <<
    "11. Menampilkan data keluarga yang memperoleh tunjangan terbanyak" << endl <<
    "0. Exit" << endl << endl;

    int input;
    cout << "Masukkan menu: ";
    cin >> input;
    return input;
}

adr_parent findparentfromchild(list_relasi lr, string x){
    adr_relasi r = first(lr);
    while(r != NULL){
        if(info(nextChild(r)) == x){
            return nextParent(r);
        }
        r = next(r);
    }
    return NULL;
}

adr_relasi tunjangan(list_relasi lr){
    int x = 0;
    int anak = 0;
    adr_relasi r;
    adr_relasi rr = first(lr);
    while(rr != NULL){
        anak = hitunganak(lr,nextParent(rr));
        if(anak > x){
            x = anak;
            r = rr;
        }
        rr = next(rr);
    }
    return r;
}
