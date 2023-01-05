#ifndef FAMILY_H_INCLUDED
#define FAMILY_H_INCLUDED

#include <iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define nextParent(p) (p)->nextParent
#define nextChild(p) (p)->nextChild

typedef struct elm_child *adr_child;
typedef struct elm_parent *adr_parent;
typedef struct elm_relasi *adr_relasi;

struct elm_child{
    string info;
    adr_child next;
};

struct elm_parent{
    string info;
    adr_parent next;
    adr_parent prev;
};

struct elm_relasi{
    adr_parent nextParent;
    adr_child nextChild;
    adr_relasi next;
    adr_relasi prev;
};

struct list_child{
    adr_child first;
};

struct list_parent{
    adr_parent first;
};

struct list_relasi{
    adr_relasi first;
};

void createlist_child(list_child &lc);
void createelm_child(string x, adr_child &c);
void insert_child(list_child &lc, adr_child c);
void show_child(list_child lc);
adr_child findelemchild(list_child lc, string x);
void deletefirst_child(list_child &lc, adr_child &c);
void deletelast_child(list_child &lc, adr_child &c);
void deleteafter_child(list_child &lc, adr_child prec, adr_child &c);
void delete_child(list_relasi &lr, list_child &lc, adr_parent p, adr_child &c);

void createlist_parent(list_parent &lp);
void createelm_parent(string x, adr_parent &p);
void insert_parent(list_parent &lp, adr_parent p);
void show_parent(list_parent lp);
adr_parent findelemparent(list_parent lp, string x);
void deletefirst_parent(list_parent &lp, adr_parent &p);
void deletelast_parent(list_parent &lp, adr_parent &p);
void deleteafter_parent(list_parent &lp, adr_parent &p, adr_parent prec);
void delete_parent(list_parent &lp, adr_parent &p, string x);

void createlist_relasi(list_relasi &lr);
void createelm_relasi(adr_relasi &r, adr_parent p, adr_child c);
void insert_relasi(list_relasi &lr, adr_relasi r);
adr_relasi findelemrelasi(list_relasi lr, string x);
void show_relasi(list_relasi lr);
void deletefirst_relasi(list_relasi &lr, adr_relasi &r);
void deletelast_relasi(list_relasi &lr, adr_relasi &r);
void deleteafter_relasi(list_relasi &lr, adr_relasi &r, adr_relasi prec);
void delete_relasi(list_relasi &lr, adr_relasi &r, string x);

int hitunganak(list_relasi lr, adr_parent p);
adr_parent findparentfromchild(list_relasi lr, string x);
adr_relasi tunjangan(list_relasi lr);





int menu();

#endif // FAMILY_H_INCLUDED
