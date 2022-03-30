#include <iostream>
const int SIZE = 8; //the length of the array
void printArray(int x[]){
    for(int i=0;i<SIZE;i++){
        std::cout<< x[i] << " ";
    }
    std::cout<<"\n";
}
void heapsort(int x[]){
    int i, parent, child;
    if(SIZE == 0) return;
// preprocessing phase; create initial heap
    for(i = 1; i < SIZE; i++){
        int elt = x[i];
// bubble_up
        child = i;
        parent = (child - 1)/2;
        while(child > 0 && x[parent] < elt){
            x[child] = x[parent];
            child = parent;
            parent = (child - 1)/2;
        }
        x[child] = elt;
    }
    std::cout << "Initial heap: " <<"\t";
    printArray(x);
// selection phase; repeatedly remove x[0], insert it
// in its proper position and adjust the heap
    for(i = SIZE-1; i > 0; i--){
// bubble-down
        std::cout <<"i=" << i << "  x[i]=" << x[i] << "\t";
        printArray(x);
//put x[0] in i-th position
        int iValue = x[i];
        x[i] = x[0];
        parent = 0;
//select the large child
        if(i == 1)  child = -1;
        else child = 1;
        if(i > 2 && x[2] > x[1]) child = 2;
        while(child >= 0 && iValue < x[child]){
//move child into parent position
            x[parent] = x[child];
            parent = child;
            child = 2*parent + 1; //first child index
            if(child > i-1)  //no child
                break;
//if there is a second child and it is larger
            if(child + 1 <= i-1 && x[child] < x[child+1])
                child = child + 1;  //get second child
        }
        x[parent] = iValue;
    }
    std::cout <<"\t\t";
    printArray(x);
} // end heapsort
int main(){
    int b[] = {75, 3, 4, 83, 51, 45, 67, 72 };
    std::cout << "Numbers:\n";
    printArray(b);
    heapsort(b);
    std::cout << "\nSorted numbers using Heap sort:";
    printArray(b);
}