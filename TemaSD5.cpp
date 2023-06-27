#include <iostream>
using namespace std;

//BEGIN COPY PASTE STIVE/COZI
//BEGIN COPY PASTE STIVE/COZI
//BEGIN COPY PASTE STIVE/COZI

struct nod_lista{
    int info;
    nod_lista* next;
};

struct lista{
    nod_lista* primul_element;
    nod_lista* ultimul_element;
    lista(){
        primul_element=NULL;
        ultimul_element=NULL;
    }
    void insert_la_inceput(int x){
        nod_lista* nou = new nod_lista;
        nou->info =x;
        nou->next = primul_element;
        primul_element = nou;
        if (ultimul_element==NULL)
            ultimul_element=nou;
    }
    int delete_de_la_inceput(){
        if (primul_element==NULL)
            return -1;
        int ce_intorc=primul_element->info;
        nod_lista* ce_sterg=primul_element;
        primul_element=primul_element->next;
        if (primul_element==NULL)
            ultimul_element=NULL;
        delete ce_sterg;
        return ce_intorc;
    }
    void insert_la_final(int x){
        nod_lista* nou = new nod_lista;
        nou->info =x;
        nou->next = NULL;
        if (ultimul_element==NULL)
            primul_element=ultimul_element=nou;
        else{
            ultimul_element->next=nou;
            ultimul_element=nou;
        }
    }

    void afisare(){
        nod_lista* pointer;
        for (pointer = primul_element; pointer !=NULL;pointer = pointer->next)
            cout<<pointer->info<< " -> ";
        cout<<endl;
    }
};

struct stiva_cu_lista{
    lista L;
    void push(int x){
        L.insert_la_inceput(x);
    }
    int pop(){
        return L.delete_de_la_inceput();
    }
    void afisare(){
        cout<<"<VARF] ";
        L.afisare();
    }
};

struct coada_cu_lista{
    lista L;
    void enqueue(int x){
        L.insert_la_final(x);
    }
    int dequeue(){
        return L.delete_de_la_inceput();
    }
    void afisare(){
        cout<<"<OUT] ";
        L.afisare();
    }
};

//END COPY PASTE STIVE/COZI
//END COPY PASTE STIVE/COZI
//END COPY PASTE STIVE/COZI

//GRAFURI
struct graf{
    lista adiacenta[200];//cate o lista cu vecinii fiecarui nod din graf
    int nod_maxim=0;//cand parcurgem sa stim pana la ce nod ne uitam

    void adauga_muchie(int nod_sursa, int nod_destinatie){
        adiacenta[nod_sursa].insert_la_final(nod_destinatie);
        if (nod_maxim<nod_sursa)
            nod_maxim=nod_sursa;
        //PENTRU GRAF NEORIENTAT:
        adiacenta[nod_destinatie].insert_la_final(nod_sursa);
        if (nod_maxim<nod_destinatie)
            nod_maxim=nod_destinatie;
    }

    int exista_muchie(int nod_sursa, int nod_destinatie){
        //cauta vecinul nod_destinatie in lista lui nod_sursa
        for (nod_lista* pointer = adiacenta[nod_sursa].primul_element; pointer !=NULL;pointer = pointer->next){
            if (pointer->info == nod_destinatie){
                return 1;
            }
        }
        return 0;
    }

    void parcurgere_in_adancime(int nod_start){
        //parcurgerea primului vecin nevizitat primul
        cout<<"DFS parcurgere_in_adancime: ";
        int* vizitat = new int[nod_maxim+1];
        for (int i=0;i<=nod_maxim;i++)
            vizitat[i]=0;
        recursie_parcurgere_in_adancime(vizitat, nod_start);
        cout<<endl;
    }

    void recursie_parcurgere_in_adancime(int* vizitat, int nod_curent){
        //functie recursiva ajutatoare pentru parcurgerea in adancime, alternativ se poate folosi o stiva
        cout<<nod_curent<<" ";
        vizitat[nod_curent]=1;
        for (nod_lista* pointer = adiacenta[nod_curent].primul_element; pointer !=NULL;pointer = pointer->next)
            if (vizitat[pointer->info]==0)
                recursie_parcurgere_in_adancime(vizitat,pointer->info);
    }

    void parcurgere_in_latime(int nod_start){
        //parcurgerea tuturor vecinilor in ordine, apoi vecinii primului vecin etc...
        cout<<"BFS parcurgere_in_latime: ";
        int* vizitat = new int[nod_maxim+1];
        for (int i=0;i<=nod_maxim;i++)
            vizitat[i]=0;
        coada_cu_lista coada;
        coada.enqueue(nod_start);
        vizitat[nod_start]=1;

        while (coada.L.primul_element!=NULL){
            int nod_curent = coada.dequeue();
            cout<<nod_curent<<" ";

            for (nod_lista* pointer = adiacenta[nod_curent].primul_element; pointer !=NULL;pointer = pointer->next)
                if (vizitat[pointer->info]==0){
                    vizitat[pointer->info]=1;
                    coada.enqueue(pointer->info);
                }
        }
        cout<<endl;
    }

    void afisare(){
        for (int i=0; i<=nod_maxim;i++){
            if (adiacenta[i].primul_element!=NULL){
                cout<<i<<" : ";
                adiacenta[i].afisare();
            }
        }
    }

};

int main(){
    //graf retea patratica
    graf G2;
    int dim =6;
    for (int i=0;i<dim;i++)
        for (int j=0;j<dim;j++){
            if(i!=j)
                if(i != 1 && j != 2)
                    G2.adauga_muchie(i,j);
    }
    int contor = 0;
    for (int i=0;i<dim-2;i++)
        for (int j=i;j<dim-1;j++)
            for(int k = j; k<dim; k++)
            {
                if(G2.exista_muchie(i,j) == 1 && G2.exista_muchie(j,k) == 1 && G2.exista_muchie(i,k) == 1){
                    contor ++;
                }

            }

    G2.afisare();
    cout<<endl;
    cout<<contor;

    return 0;
}