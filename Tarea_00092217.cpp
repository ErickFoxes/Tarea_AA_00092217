// No entendí bien lo que pedia :s
// El Heapsort use el que nos diste (no sabia si no lo podiamos usar)
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}


void MaxHeapify(int A[], int i, int size){
    int l, r, largest, temp;
    l = left(i);
    r = right(i);
    if( (l<=size) && (A[l]>A[i]) ){
        largest = l;
    }else{
        largest = i;
    }
    if( (r<=size) && (A[r]>A[largest]) ){
        largest = r;
    }
    if(largest!=i){
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest, size);
    }
}

void BuildMaxHeap(int A[], int size){
    for(int i=size/2; i>=0; i--){
        MaxHeapify(A, i, size);
    }
}

int NumeroMultiplo(int N, int multiplo){
	if(N%multiplo==0){
		return 1;
	}else{
		return 0;
	}
}

int NumeroPositivo(int N){
	if(N>0){
		return 1;
	}else{
		return 0;
	}
}
void imprimirMissingNumber(int A[], int N){
	if(NumeroPositivo(A[N-1])==1 && NumeroMultiplo(A[N-1],2)==1){
		cout<<A[N-1]+2<<endl;
	}else if(NumeroPositivo(A[N-1])==1 && NumeroMultiplo(A[N-1],2)==0){
		cout<<A[N-1]+1<<endl;
	}else{
		cout<<2<<endl;
	}
}

//void printArray(int A[], int size){
//    for(int i=0; i<size; i++){
//		cout<<A[i]<<", ";
//    }
//    cout<<endl;
//}

int main()
{
	int T;
	cout<<"Cuantos casos deseas realizar? ";
	cin>>T;
	while(T<0 || T>10){
        cout<<"Cuantos casos deseas realizar? ";
        cin>>T;
        cout<<endl;
	}
  	
	for(int j=0;j<T;j++){
		int N,elemento;
		cout<<"Cuantos numeros habra en el arreglo? ";
	  	cin>>N;
	  	cout<<endl;
	  	int A[N];

         for(int x=1; x<=N; x++){
            cout<<"ingrese elemento "<<x<<": ";
			cin>>elemento;
			if(elemento<0){
				cout<<"Numero no valido, ingrese un numero positivo por favor";
				x--;
			}else{
                A[x-1]= elemento;
			}
		}
		int temp=0;
	    int size = sizeof(A)/sizeof(A[0]);
	    BuildMaxHeap(A, size);
	    for(int i=size; i>=1; i--){
	        temp = A[0];
	        A[0] = A[i];
	        A[i] = temp;
	   		size--;
	        MaxHeapify(A, 0, size);
	    }
     	imprimirMissingNumber(A,N);

	}


    system("PAUSE");
    return 0;

}
