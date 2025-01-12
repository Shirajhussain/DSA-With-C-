#include <iostream>
using namespace std;

class heap{
    public:
    int* arr;
    int capacity;
    int index;
    
    heap(int n){
        this->capacity = n;
        arr = new int [n];
        index = 0;
    }
    
    void printheap(){
        for(int i = 0; i<capacity; i++){
            cout<< arr[i]<<" ";
        }
        cout<<endl;
    }
    
    void insert(int val){
        if(index == capacity - 1){
            cout<<"Overflow" << endl;
            return;
        }
        
        index++;
        arr[index] = val;
        cout<<"placing"<< val << "index:" << index <<endl;
        // now put val at right position
        // by camparing with parent no
        
        int i = index;
        while(i>1){
            int parentIndex = i/2;
            
            if(arr[parentIndex] < arr[i]){
                swap(arr[parentIndex] , arr[i]);
                i = parentIndex;
            }
            else{
                // parent already bada h , no need to do anything
                break;
            }
        }
    }
    
    void deleteFromHeap(){
        // Replacement
        swap(arr[1] , arr[index]);
        // size decrease
        index--;
        // heapify
        heapify(arr , index , 1);
    }

        // heapify value present at currIndex 
    void heapify(int* arr , int n , int currIndex){
        // n-> number of element in heap
        int i = currIndex;
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;
        
        int largestkaIndex = i;
        
        // check for left
        if(leftIndex < n && arr[leftIndex] > arr[largestkaIndex]){
            // left me badi value value mil gyi
            largestkaIndex = leftIndex;
        }
        // check for right
        if(rightIndex < n && arr[rightIndex] > arr[largestkaIndex]){
            // right me badi value value mil gyi
            largestkaIndex = rightIndex;
        }
        
        if(largestkaIndex != i){
            //left ya right me se koi h
            swap(arr[i] , arr[largestkaIndex]);
            i = largestkaIndex;
            // baaki recursion sambhal lega
            heapify(arr , n , i);
        }
    }
    
};

int main() {
    heap pq(10);
    pq.insert(10);
    pq.printheap();
    pq.insert(20);
    pq.printheap();
    pq.insert(30);
    pq.printheap();
    pq.insert(40);
    pq.printheap();
    pq.insert(50);
    pq.printheap();
    pq.insert(60);
    pq.printheap();
    
    pq.deleteFromHeap();
    pq.printheap();
    
    pq.deleteFromHeap();
    pq.printheap();
    
    pq.deleteFromHeap();
    pq.printheap();

    return 0;
}