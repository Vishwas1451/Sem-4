// Name:VISHWAS M
// SRN: PES2UG20CS390
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) {
    heap -> arr = (int*)calloc(max_size,4);
    heap -> size = 0;
    heap->max_size = max_size;
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) {
    int i=heap->size-1;
    heap->arr[i]=key;
    while(i>0 && heap->arr[i/2]<heap->arr[i] ){
        int temp=(heap->arr[i/2]);
        (heap->arr[i/2])=(heap->arr[i]);
         heap->arr[i]=temp;
        i=i/2;
        *count_ptr +=1;
    }
    heap->size +=1;
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr) {
      if(heap->size>0){
       int temp = heap->arr[0];
       for(int i=0;i<heap->size;i++){
           *count_ptr +=1;
           heap->arr[i]=heap->arr[i+1];
       }
       heap->size -=1;
       return temp;
    }   
    else
       return -1; 
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) {
    for(int i=0;i<heap->size;i++){
        *count_ptr +=1;
        if(heap->arr[i]==key){
            return heap->arr[i];
        }
    }
    return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr) {
    if(heap->size>0){
       *count_ptr +=1;
       return heap->arr[0];
    }   
    else
       return -1;   
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) {
    if(heap->size>0){
       int j=heap->size-1,min=heap->arr[j];
       for(int i=0;i<=j/2;i++){
           *count_ptr +=1;
         if(min>heap->arr[2*i] && (2*i)<j){
             min=heap->arr[2*i];
         } 
         else if(min>heap->arr[(2*i)+1] && ((2*i)+1)<j){
             min=heap->arr[(2*i)+1];
         }
       }
       
      return min;
    }
    else
       return -1;  
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {
    heap->size=0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {
    free(heap);
}
