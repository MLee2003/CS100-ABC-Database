#ifndef QUICKSORT
#define QUICKSORT

#include "./SortingStrategy.hpp"
#include "../Nodes/DatabaseNode.h"
#include <vector>
using namespace std;
class QuickSort : public SortingStrategy{
    public:
        QuickSort(){}
        
    private:
    
        //find partition. sort elements before the partition and elements after
        void sort(vector<unique_ptr<DatabaseNode>> &arr){
            quickSort(arr, 0, arr.size()-1);
        }

        void quickSort(vector<unique_ptr<DatabaseNode>> &arr, int l, int h){
            if(l < h){
                int part_in = partition(arr, l, h);
                quickSort(arr, l, part_in-1);
                quickSort(arr, part_in+1, h);
            }
        }

        //place pivot index in the correct position in the array
        int partition(vector<unique_ptr<DatabaseNode>> &arr, int low, int high){
            unique_ptr<DatabaseNode> pivot = move(arr[low]);
            int i = low+1;

            for(int j = low+1; j <= high; j++){
                if(arr[j]->print() < pivot->print()){
                    swap(arr, i, j);
                    i++;
                }
            }
            swap(arr, low, i-1);
            return(i - 1);
        }
        void swap(vector<unique_ptr<DatabaseNode>> &arr, int a, int b){
            unique_ptr<DatabaseNode>  temp = move(arr[a]);
            arr[a] = move(arr[b]);
            arr[b] = move(temp);
        }
};

#endif
