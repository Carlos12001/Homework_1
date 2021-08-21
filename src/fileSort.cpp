#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


class Page{
public:
    int min_value;
    int max_value;
    string id;
    int pos = -1;

    Page() = default;
    Page(int min_value, int max_value, string id){
        this->min_value=min_value;
        this->max_value = max_value;
        this->id = move(id);
    };
};


class PageArray{
public:
    int numbers_count;
    int size;
    Page mmu[12];
    string ram[6];
    string path;

    PageArray() = default;
    PageArray(string path){
        this->path = move(path);
    }
};

int main(){

    return 0;
}

