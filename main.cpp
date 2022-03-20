#include <iostream>
void tabDisplayer(int *tab, int size){
    for (int i = 0; i<size; i++){
        std::cout<<tab[i] << " ";
    }
}
void swapDown(int index,int *&heap, int size){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int helper;
    int max = index;
    if(index < size){
        if (left < size && heap[index] < heap[left]){
            max = left;
        }
        if (right < size && heap[max] < heap[right]){
            max = right;
        }
        if (max != index){
            helper = heap[max];
            heap[max] = heap[index];
            heap[index] = helper;
            int * tab = (int *) heap;
            swapDown(max,tab,size);
        }
    }
}
void heapify(int size,int *&heapToMade){
    for (int i = size/2; i>=0; i--){
        int * tab = (int *)heapToMade;
        swapDown(i,tab,size);
    }
}
void heapSort(int *&heap, int size){
    int unsortedSize = size;
    while (unsortedSize > 0){
        int helper = heap[0];
        heap[0] = heap[unsortedSize-1];
        heap[unsortedSize-1] = helper;
        tabDisplayer(heap,size);
        std::cout<<std::endl;
        unsortedSize--;
        heapify(unsortedSize,heap);
    }
    tabDisplayer(heap,size);
}
int main() {
    int values[] = {5, 17, 12, 13, 6, 9, 10, 7, 11, 4, 2, 8};
    int size = sizeof(values)/sizeof(int);
    int * tab = (int *) values;
    //tabExpander(tab,size,69);
    //swapDown(0,tab,size);
    heapify(size,tab);
    tabDisplayer(tab,size);
    std::cout<<std::endl;
    heapSort(tab,size);

    return 0;
}
