#include <iostream>
#include <cmath>
using namespace std;

struct intrare{
    long long CNP;
    int numar;
};

struct nod{
    intrare info;
    nod* next;
};

struct lista{
    nod* primul_element;//pointer la primul element
    lista(){
        primul_element=NULL;//initializare
    }
    void insert_la_inceput(long long cheie, int valoare){
        nod* nou = new nod;
        nou->info.CNP = cheie;
        nou->info.numar = valoare;
        nou->next = primul_element;
        primul_element = nou;
    }
    intrare* cauta_dupa_cheie(long long cheie){
        nod* curent = primul_element;
        while (curent!=NULL && curent->info.CNP!= cheie)
            curent=curent->next;
        if (curent==NULL)
            return NULL;
        return &(curent->info);
    }
    void afisare(){
        nod* pointer;
        if (primul_element==NULL)
            cout<<"prim=NULL";
        else
            for (pointer = primul_element; pointer !=NULL;pointer = pointer->next)
                cout<<"["<<pointer->info.CNP<<", "<<pointer->info.numar<< "] -> ";
        cout<<endl;
    }
};

int hash_diviziune(long long cheie, int N){
    return cheie % 19;
}
const double PHI=1.6180339887498948482045868343656;
int hash_multiplicare(long long cheie, int N){
    double integer_part;
    return (int)(N*modf(PHI*cheie,&integer_part));
}
int hash_impachetare(long long cheie, int N){
    int h=0;
    while (cheie>0){
        h=h ^ (cheie&15);
        cheie = cheie >>4;
    }
    return h;
}

struct hashtable_chaining{
    lista* T;//pointer la viitor array de liste
    int n;
    int (*hashfunc)(long long, int);
    hashtable_chaining(int N, int (*H)(long long, int)){
        n=N;
        hashfunc = H;
        T=new lista[n]; //alocam un array de n liste
    }
    void put(long long cheie, int valoare){
        int hash = hashfunc(cheie,n);
        int index = hash % n;
        intrare* gasit = T[index].cauta_dupa_cheie(cheie);
        if (gasit==NULL)
            T[index].insert_la_inceput(cheie,valoare);
        else
            gasit->numar=valoare;
    }
    int get (long long cheie){
        int hash = hashfunc(cheie,n);
        int index = hash % n;
        intrare* gasit = T[index].cauta_dupa_cheie(cheie);
        if (gasit==NULL)
            return -1;
        else
            return gasit->numar;
    }
    void afisare(){
        for (int i=0;i<n;i++)
            T[i].afisare();
    }
};

int* diferenta(int A[], int &n, hashtable_chaining& tabela){
    int* rezultat_temp = new int[n];
    int nr_rezultate = 0;
    int comune = 0;
    int aux = n;
    for (int i=0;i<aux;i++){
        if (tabela.get(A[i]) == -1){
            rezultat_temp[nr_rezultate] = A[i];
            nr_rezultate++;
        }
        else
        {
            rezultat_temp[nr_rezultate] = -99;
            nr_rezultate++;
            comune++;
        }
    }
    int* rezultat = new int[aux-comune];
    int curent = 0;
    for(int i = 0; i < n; i++)
    {
        if(rezultat_temp[i] != -99)
        {
            rezultat[curent] = rezultat_temp[i];
            curent ++;
        }
    }
    n = aux - comune;
    delete[] rezultat_temp;
    return rezultat;
}
int main(){   
    int A[] = {1,2,3,4,5,6,7,8,9};
    int B[] = {2,3,4,5};
    int N = sizeof(A)/sizeof(int);  
    cout<<N<<endl;
    int M = sizeof(B)/sizeof(int);          
    hashtable_chaining tabela(100, hash_diviziune);
    for (int i=0;i<M;i++){
        tabela.put(B[i], 1);
    }
    int * rezultat = diferenta(A,N,tabela);
    for(int i = 0; i< N; i++)
    {
        cout<<rezultat[i];
    }
    cout<<endl;
    cout<<N;
    return 0;
} 
