#include <iostream>
using namespace std;
 
struct nod_arbore{
    char* info;
    nod_arbore* st;
    nod_arbore* dr;
};
 
struct arbore{
    nod_arbore* radacina;
    arbore(){
        radacina=NULL;
    }
    void insert_element(char* x){
        nod_arbore* nou = new nod_arbore;
        nou->info = new char[strlen(x) + 1];
        strcpy(nou->info, x);
        nou->st=NULL;
        nou->dr=NULL;
 
        if (radacina==NULL){
            radacina=nou;
            return;
        }
 
        nod_arbore* pointer_prev = NULL;
        nod_arbore* pointer = radacina;
        int directie = 0;
        while(pointer!=NULL){
            pointer_prev=pointer;
            if (strcmp(x,pointer->info) < 0){
                pointer=pointer->st;
                directie = -1;
            }else if (strcmp(x,pointer->info) > 0){
                pointer=pointer->dr;
                directie = 1;
            }
            else if(strcmp(x,pointer->info) == 0) {
            void delete_element(char* x){
                    nod_arbore* pointer_prev =NULL;
                    nod_arbore* pointer =radacina;
                    int directie=0;
                    while (pointer!=NULL && strcmp(pointer->info,x)!=0){
                        pointer_prev=pointer;
                        if (strcmp(x,pointer->info) <= 0){
                            pointer=pointer->st;
                            directie= -1;
                        }else{
                            pointer= pointer->dr;
                            directie =1;
                        }
                    }
            
                    if (pointer==NULL){
                        cout<<"nu exista "<<x<<endl;
                        return;
                    }
                    //pointer indica nodul care trebuie sters
                    //cazul in care nodul de sters nu are fii
                    if (pointer->st==NULL && pointer->dr==NULL){
                        cout<<"nu are fii "<<x<<endl;
                        if (pointer == radacina){
                            cout<<"este radacina "<<x<<endl;
                            radacina=NULL;
                            delete pointer;
                            return;
                        }
                        if (directie<0)
                            pointer_prev->st=NULL;
                        else
                            pointer_prev->dr=NULL;
                        delete pointer;
                        return;
                    }
                    //cazul in care nodul de sters are doar fiu stang
                    if (pointer->st!=NULL && pointer->dr==NULL){
                        cout<<"are doar fiu stang "<<x<<endl;
                        if (pointer == radacina){
                            cout<<"este radacina "<<x<<endl;
                            radacina=pointer->st;
                            delete pointer;
                            return;
                        }
                        if (directie<0)
                            pointer_prev->st=pointer->st;
                        else
                            pointer_prev->dr=pointer->dr;
                        delete pointer;
                        return;
                    }
                    //cazul in care nodul de sters are doar fiu drept
                    if (pointer->st==NULL && pointer->dr!=NULL){
                        cout<<"are doar fiu stang "<<x<<endl;
                        if (pointer == radacina){
                            cout<<"este radacina "<<x<<endl;
                            radacina=pointer->dr;
                            delete pointer;
                            return;
                        }
                        if (directie<0)
                            pointer_prev->st=pointer->dr;
                        else
                            pointer_prev->dr=pointer->dr;
                        delete pointer;
                        return;
                    }
                    //cazul in care nodul de sters are ambii fii
                    cout<<"are ambii fii "<<x<<endl;
                    nod_arbore* pointer_next=pointer->st;
                    while (pointer_next->st!=NULL)
                        pointer_next=pointer_next->dr;
                    char* valoare;
                    strcpy(valoare,pointer_next->info);
                    cout<<"nodul "<<valoare<<" il poate inlocui pe "<<x<<endl;
                    delete_element(valoare);//doar daca sunt toate cheile distincte
                    //am garantia ca valoare va fi sters ori cu stergerea-fara-fii
                    //ori cu stergerea doar-fiu-stang; sigur nu are fiu drept
            
                    pointer->info=valoare;
                }
            }
        }
 
        if (directie <0)
            pointer_prev->st=nou;
        else
            pointer_prev->dr=nou;
    }
    void SRD(){
        cout<<"SRD: ";
        SRD(radacina);
        cout<<endl;
    }
    void SRD(nod_arbore* pointer){
        if (pointer!=NULL){
            SRD(pointer->st);
            cout<<pointer->info<<" ";
            SRD(pointer->dr);
        }
    }
    void RSD(){RSD(radacina,0,0);}
    void RSD(nod_arbore *radacina, int nivel, int dir){
        if (radacina!=NULL){
                for (int i=0;i<nivel;i++) cout<<" ";
                    cout<<radacina->info<<(dir==-1?" st":"")<<(dir==1?" dr":"")<<endl;
            RSD(radacina->st,nivel+1,-1);
            RSD(radacina->dr,nivel+1,1);
        }
    } 

    void RSD(nod_arbore* pointer){
        if (pointer!=NULL){
            cout<<pointer->info<<" ";
            RSD(pointer->st);
            RSD(pointer->dr);
        }
    }
 
};
 
int main()
{
    arbore arb;
    
    arb.insert_element("aer");
    arb.insert_element("boaba");
    arb.insert_element("dap");
    arb.insert_element("cartof"); 
    arb.insert_element("v");
    arb.insert_element("ager");
    arb.insert_element("aver");
    arb.insert_element("aber");
    arb.insert_element("dap");

    
    arb.SRD();
    arb.RSD();
 
    return 0;
} 