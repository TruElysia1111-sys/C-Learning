#include <iostream>
using namespace std;

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1;i++) {
        bool flag = false;
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // ½»»»
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }

}

int main14() {
    //std::cout << "Hello, World!" << std::endl;
    int arr[10] = { 7,4,5,3,4,1,8,9,1,2 };

    int lenth = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr,lenth);
    
    cout<<"ÅÅÐòºó£º"<<endl;
    for (int i = 0; i < lenth; i++) {

        cout << arr[i] << " ";
    }
    
    system("pause");
    return 0;
}