#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int binary_search_rec(int A[], int key,int low_idx, int high_idx);
int binary_search_recursive(int A[], int key, int len);

int main (int argc, char *string[]) {

    // get the key 
    std::string key_str =  string[1];
    std::string::size_type sz;
    int key_int = std::stoi (key_str,&sz);
    
    int arr1[] = {1,2,4,7,8,12,15,19,24,50,69,80,100};
    int number_of_elements = sizeof(arr1) / sizeof(arr1[0]);
    
    int key_idx = binary_search_recursive (arr1,key_int,number_of_elements);
    
    printf ("key_idx:%d\n",key_idx);

    return -1;
}

int binary_search_rec(int A[], int key,int low_idx, int high_idx) {

    if (low_idx > high_idx) {
        return -1;
    }
    
    int mid = low_idx + ((high_idx-low_idx)/2);
    
    if (A[mid] == key) {
        return mid;
    }
    
    // providing that the array is sorted in accending order
    // only look through below the half way line
    if (key < A[mid]) {
        return binary_search_rec(A, key,low_idx,mid -1);
    }
    
    // look on the higher side
    return binary_search_rec(A,key,mid + 1, high_idx);
    
}

int binary_search_recursive(int A[], int key, int len) {
    return binary_search_rec(A,key,0,len-1);
}
