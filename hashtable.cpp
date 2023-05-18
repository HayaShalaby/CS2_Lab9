#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node* next;
};

int search(Node **hTable, int lastIndex, int v){
    for(int i=0; i<lastIndex; i++){
        if(hTable[i] != nullptr && hTable[i]->value == v)
            return i;
    }
    return -1;
}

int main(){
    int arr[10] = {1, 4, 7, 1, 5, 2, 4, 1, 3, 5};
    Node *hTable[10] = {nullptr};
    Node *head;
    Node *temp;
    int count = 0;
 
    for(int i=0; i<10; i++){
        int index = search(hTable, count, arr[i]%10);
        if(index != -1){
            temp = hTable[index];
            while(temp->next != nullptr)
                temp = temp->next;
            temp->next = new Node{arr[i]%10, nullptr};
        }
        else{
            hTable[count] = new Node{arr[i]%10, nullptr};
            count ++;
        }
    }

    cout << "The hash table:" <<endl;
    for(int i=0; i<count; i++){
        cout << hTable[i]->value << " ";
        temp = hTable[i];
        while(temp->next != nullptr){
            temp = temp->next;
            cout << temp->value << " ";
        }
        cout << endl;
    }

    return 0;
}
