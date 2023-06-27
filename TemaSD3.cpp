#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void interclasare(int* v, int st, int dr){
    int mid = (st+dr)/2;
    int index1=st;
    int index2=mid+1;
    int* r=new int[dr-st+1];
    int r_index=0;
//******INTERCLASARE*******
    while (index1<=mid&&index2<=dr){
        if (v[index1]<=v[index2])
            r[r_index++]=v[index1++];
        else
            r[r_index++]=v[index2++];
    }
    while (index1<=mid)
        r[r_index++]=v[index1++];
    while (index2<=dr)
        r[r_index++]=v[index2++];
//**********************
    for (index1=st;index1<=dr;index1++)
        v[index1]=r[index1-st];
    delete[] r;
}

int alege_poz_pivot(int* v, int st, int dr){
                                                //cout<<" pivot="<<v[(st+dr)/2]<<" ";
    return (st+dr)/2;
}

int partition_Hoare(int* v, int st, int dr){
    int pivot = v[alege_poz_pivot(v,st,dr)];
    int i=st , j=dr;
    while (1){
        while (v[i]<pivot) i++;
        while (v[j]>pivot) j--;
        if (i>=j) return j;
        swap(v[i],v[j]);
        i++;
        j--;
    }
}

int partition_Lomuto(int* v, int st, int dr){
    int poz_pivot = alege_poz_pivot(v,st,dr);
    swap(v[poz_pivot],v[dr]);
    int i=st-1;
                                                //for (int i=st;i<=dr;i++) cout<<v[i]<<" "; cout<<endl;
    for (int j=st;j<dr;j++){
        if (v[j]<v[dr])
            {swap(v[++i],v[j]);
                                                //for (int i=st;i<=dr;i++) cout<<v[i]<<" "; cout<<endl;
            }
    }
    swap(v[i+1],v[dr]);
                                                //for (int i=st;i<=dr;i++) cout<<v[i]<<" "; cout<<endl;
    return i+1;
}

void quicksort(int* v, int st, int dr, int nivel){
    if (st<dr){
        int poz_pivot = partition_Lomuto(v,st,dr);
        quicksort(v,st,poz_pivot,nivel+1);
        quicksort(v,poz_pivot+1,dr,nivel+1);
    }
}

int partition(int v[], int st, int dr){
    int poz_pivot = alege_poz_pivot(v,st,dr);
    swap(v[poz_pivot],v[dr]);
    int i = st;
    for (int j = st; j <= dr - 1; j++) {
        if (v[j] <= v[dr])
            swap(v[i++], v[j]);
    }
    swap(v[i], v[dr]);
    return i;
}

int kth(int v[], int st, int dr, int k){
    if (k > 0 && k <= dr - st + 1) {
        int poz_pivot = partition(v, st, dr);
        if (poz_pivot - st == k - 1)
            return v[poz_pivot];
        if (poz_pivot - st > k - 1)
            return kth(v, st, poz_pivot - 1, k);
        return kth(v, poz_pivot + 1, dr, k - poz_pivot + st - 1);
    }
    return -1;
}

int is_sorted(int* v, int st, int dr){
    for (int i=st;i<dr;i++)
        if (v[i]>v[i+1])
            return 0;
    return 1;
}

int main(){
    int a[5] = {2,3,5,6,7};
    int b[4] = {7,6,2,5};
    quicksort(a,0,4,2);
    quicksort(b,0,2,1);
    for(int i =0; i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int j = 0; j<4; j++)
    {
        cout<<b[j]<<" ";
    }
    cout<<endl;

    int i = 0;
    int j = 0;
    int counter = 0;
    while(j < 4) // ma plimb prin ala scurt pana ajung la capatul lui ca daca cel scurt e sortat i-ul creste pana valoarea lui a[i] depaseste pe cea a lui b[j]
    {
        if(a[i] < b[j])
        {
            i++;
        }
        else if(b[j] < a[i])
        {
            j++;
        }
        else if(b[j] == a[i])
        {
            a[i] = 0;
            counter++;
            i++;
            j++;
        }
    }
    int v = 0;
    int c[5-counter];
    for(int k = 0; k < 5; k++)
    {
        if(a[k]!=0){
            c[v] = a[k];
            v++;
        }
    }
    for(int i =0; i < 5-counter; i++)
        cout<<c[i]<<" ";
    return 0;
}