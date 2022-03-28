//
// Created by cidi on 2022/3/27.
//

#ifndef EXPLORE_PLANNING_PROBLEM_SORT_H
#define EXPLORE_PLANNING_PROBLEM_SORT_H
#include<vector>

template<class T>
void bubble_sort(std::vector<T> &input,bool is_from_small_to_large=true){
    for(int i=0;i<input.size()-1;i++){
        for(int j=i+1;j<input.size();j++){
            if(input[i]>input[j] && is_from_small_to_large==true)
                std::swap(input[i],input[j]);
            else if(input[i]<input[j] && is_from_small_to_large==false)
                std::swap(input[i],input[j]);
        }
    }
}

template<class T>
void insert_sort(std::vector<T>& input ){
    for(int i=1;i<input.size();i++){
        T key=input[i];
        int j=i;
        while(j--&&input[j]>key){
            input[j+1]=input[j];
        }
        input[j+1]=key;
    }
}

template<class T>
void merge_sort(std::vector<T>& input,int start, int end ){
    if(start==end)
        return;
    int mid=(start+end)/2;
    merge_sort(input,start,mid);
    merge_sort(input,mid+1,end);
    std::vector<T> tmp;
    int i=start, j=mid+1;
    while(i<=mid&& j<=end){
        if(input[i]<=input[j]){
            tmp.push_back(input[i]);
            i++;
        }
        else{
            tmp.push_back(input[j]);
            j++;
        }
    }
    while(i<=mid){
        tmp.push_back(input[i]);
        i++;
    }
    while(j<=end){
        tmp.push_back(input[j]);
        j++;
    }
    for(int k=0;k<tmp.size();k++){
        input[k+start]=tmp[k];
    }
}

template<class T>
void heapify(std::vector<T>& input, int start, int size){
    if(start+1>size/2)return;
    int left=(start+1)*2-1;
    int right=(start+1)*2+1-1;
    int largest=start;
    if(input[left]>input[largest]&& left<size)
        largest=left;
    if(input[right]>input[largest]&& right<size)
        largest=right;
    if(largest!=start){
        std::swap(input[largest],input[start]);
        heapify(input,largest,size);
    }
}

template<class T>
void heap_sort(std::vector<T>& input){
    for(int i=input.size()/2-1;i>=0;i--){
        heapify(input,i,input.size());
    }
    int num=input.size();
    while(num--){
        std::swap(input[num],input[0]);
        heapify(input,0,num);
    }
}

template<class T>
void quick_sort(std::vector<T>& input,int start,int end){
    if(start>=end)return;
    int i=start;
    int j=end;
    bool is_left=true;
    while(i!=j){
        if(is_left && input[i]<=input[j]){
            j--;
        }else if(is_left && input[i]>input[j]){
            is_left=false;
            std::swap(input[i],input[j]);
            i++;
        }else if(!is_left&& input[i]<=input[j]){
            i++;
        }
        else if(!is_left && input[i]>input[j]){
            is_left=true;
            std::swap(input[i],input[j]);
            j--;
        }
    }
    quick_sort(input,start,i-1);
    quick_sort(input,i+1,end);
}

#endif //EXPLORE_PLANNING_PROBLEM_SORT_H
