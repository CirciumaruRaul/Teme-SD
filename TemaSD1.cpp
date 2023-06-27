#include <iostream>
using namespace std;

struct nod{
    int info;
    nod* next;
};
 
struct lista{
    nod* primul_element;//pointer la primul element
    nod* ultimul_element;//pointer la ultimul element
    lista(){
        primul_element=NULL;//initializare
        ultimul_element=NULL;//initializare
    }
    void insert_la_inceput(int x){
        nod* nou = new nod;//alocam spatiu
        nou->info =x;//punem x in campul intreg
        nou->next = primul_element; // punem adresa din primul_element in campul adresa next 
        // legam nou de primul_element
        primul_element = nou; // actualizam care este adresa noului nod de la inceput
        if (ultimul_element==NULL) // daca lista era goala -> acum extista 1 nod 
            ultimul_element=nou; //ultimul_element trebuie sa-l indice pe acel nod
    }
    int delete_de_la_inceput(){
        if (primul_element==NULL)//sa nu crape stergerea in lista vida
            return -1;//sa intoarcem o valoare speciala
        int ce_intorc=primul_element->info;//salvam valoarea ca sa o putem intoarce
        nod* ce_sterg=primul_element; //salvam adresa nodului pe care dorim sa-l dezalocam
        primul_element=primul_element->next; // primul_element il indica pe urmatorul
        if (primul_element==NULL) //daca prin stergere am vidat lista,
            ultimul_element=NULL; //trebuie sa actualizam si celalalt pointer
        delete ce_sterg; //dezalocam nodul folosind adresa salvata
        return ce_intorc;
    }
    void insert_la_final(int x){
        nod* nou = new nod; //alocam
        nou->info =x; //info
        nou->next = NULL; //punem NULL in adresa pentru ca acest nod va fi ultimul
        if (ultimul_element==NULL) //daca lista era vida
            primul_element=ultimul_element=nou; //atunci ambii pointeri indica noul nod
        else{
            ultimul_element->next=nou; //legam ultimul de nou
            ultimul_element=nou; //ultimul nod trebuie actualizat, stocam adresa lui in ultimul_element
        }
    }
 
    void afisare(){
        nod* pointer;
        for (pointer = primul_element; pointer !=NULL;pointer = pointer->next)
            cout<<pointer->info<< " -> ";
        cout<<endl;
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
	bool empty()
	{
		if(L.ultimul_element == NULL)
			return true;
		else
			return false;
	}
}p,q;

int main()
{	
    int image[7][7] = {
                        {0, 0, 1, 0, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0},
                        {0, 1, 0, 0, 1, 0, 1},
                        {1, 1, 1, 0, 0, 0, 1},
                        {1, 1, 1, 0, 0, 1, 1}
                        };
	int colorata[7][7] = {0};
	int culoare = 2;
	int xCurent;
	int yCurent;
	for (int i = 0; i < 7; i++) 
	{
		for (int j = 0; j < 7; j++)
		{
			if(image[i][j] == 1 && colorata[i][j]==0){
				xCurent = i;
				yCurent = j;
				p.enqueue(xCurent);
				q.enqueue(yCurent);
				colorata[i][j] = culoare;
				while(!p.empty())
				{
					int a,b;
					a = p.dequeue();
					b = q.dequeue();
					if(a>0 && image[a-1][b]==1 && colorata[a-1][b]==0)
					{
						xCurent = a-1;
						yCurent = b;
						p.enqueue(xCurent);
						q.enqueue(yCurent);
						colorata[a-1][b] = culoare;
					}
					if (a<7-1 && image[a+1][b]==1 && colorata[a+1][b]==0)
					{
						xCurent = a+1;
						yCurent = b;
						p.enqueue(xCurent);
						q.enqueue(yCurent);
						colorata[a+1][b] = culoare;
					}
					if (b>0 &&image[a][b-1]==1 && colorata[a][b-1]==0)
					{
						xCurent = a;
						yCurent = b-1;
						p.enqueue(xCurent);
						q.enqueue(yCurent);
						colorata[a][b-1] = culoare;
					}
					if (b<7-1 && image[a][b+1]==1 && colorata[a][b+1] == 0)
					{
						xCurent = a;
						yCurent = b+1;
						p.enqueue(xCurent);
						q.enqueue(yCurent);
						colorata[a][b+1] = culoare;
					}
				}
				culoare++;
			}
		} 
	}
	for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << colorata[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
