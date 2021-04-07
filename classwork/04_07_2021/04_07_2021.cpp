void swap(int&, int&);

int bubbleSort(int[], int);

int selectionSort(int[], int);

int main(){ }

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// bubble sort -> compare and swap
void bubbleSort(int arr[], int size){
    int maxElement;
    int index;
    for(maxElement = size - 1; maxElement > 0; maxElement--){
        for(index = 0; index < maxElement; index++){
            if(arr[index] > arr[index+1]){
                swap(arr[index], arr[index+1]);
            }
        }
    }
}

// selection sort -> swap smallest with left most unswapped index
void selectionSort(int arr[], int size){
    int minIndex, minValue;

    for(int start = 0; start < (size - 1); start++){
        minIndex = start;
        minValue = arr[start];
        for(int index = start + 1; index < size; index++){
            if(arr[index] < minValue){
                minValue = arr[index];
                minIndex = index;
            }
        }
        swap(arr[minIndex], arr[start]);
    }
}