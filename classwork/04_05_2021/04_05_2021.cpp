int linearSearch(int[], int, int);
int binarySearch(int[], int, int);

int main(){ }

// linear search -> check each element until match
int linearSearch(int arr[], int size, int value){
    int index = 0;
    int position = -1;
    bool found = false;
    while(index < size && !found){
        if(arr[index] == value){
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

// binary search -> divide in half and check left and write until match
// https://www.youtube.com/watch?v=KXJSjte_OAI
int binarySearch(int orderedArr[], int size, int value){
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;
    while(first <= last && !found){
        middle = (first + last) / 2;
        if(orderedArr[middle] == value){
            found = true;
            position = middle;
        }else if(orderedArr[middle] > value){
            last = middle - 1;
        }else{
            first = middle + 1;
        }
    }
    return position;
}