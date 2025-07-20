#include<bits/stdc++.h>
using namespace std;

class MyHeap
{
    private:
        int size;
        int total_size;
        int *arr;
    public:
        MyHeap(int total_size) {
            size = 0;
            this->total_size = total_size;
            arr = new int[total_size];
        }
        void insert(int value) {
            if (size == total_size) {
                cout << "Heap overflow\n";
                return;
            }
            int ind = size;
            arr[size] = value;
            size++;
            
            // placing at correct place, step up
            while (ind > 0 && arr[ind] > arr[(ind-1)/2]) {
                swap(arr[ind], arr[(ind-1)/2]);
                ind = (ind-1)/2;
            }
            cout << "Node: " << value << " inserted;\n";
        }
        void deleteVal() {
            if (size == 0) {
                cout << "Heap Underflow\n";
                return;
            }
            cout << "Node: " << arr[0] << " is deleted\n";
            swap(arr[0], arr[size-1]);
            size--;
            heapfy(0);
        }
        void heapfy(int ind) {
            while ((2*ind+1 < size)) { // if the node has atleaset one children
                int left = 2 * ind + 1;
                int right = 2 * ind + 2;
                int largest = ind;
                if (arr[left] > arr[largest]) largest = left;
                if ((right < size) && (arr[right] > arr[largest])) largest = right;
                if (largest == ind) break;
                swap(arr[ind], arr[largest]);
                ind = largest;
            }
        }
        int getMax() {
            if (size == 0) {
                cout << "No elements in the heap\n";
                return -1;
            }
            return arr[0];
        }
        int extractMax() {
            int ele = arr[0];
            swap(arr[0], arr[size-1]);
            size--;
            heapfy(0);
            return ele;
        }
        void increaseKey(int ind, int value) {
            arr[ind] = value;
            // placing at correct place, step up
            while (ind > 0 && arr[ind] > arr[(ind-1)/2]) {
                swap(arr[ind], arr[(ind-1)/2]);
                ind = (ind-1)/2;
            }
        }
        void display() {
            for (int i = 0; i < size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main()
{
    MyHeap hp(15);
    hp.insert(60);
    hp.insert(35);
    hp.insert(34);
    hp.insert(10);
    hp.insert(12);
    hp.insert(8);
    hp.insert(7);
    hp.display();
    cout << "Increasing index 6 to 100\n";
    hp.increaseKey(6,100);
    hp.display();
    hp.deleteVal();
    hp.display();
    cout << "extracted max: " << hp.extractMax() << endl;
    hp.display();
    cout << "current max: " << hp.getMax() << endl;
    cout << "extracted max: " << hp.extractMax() << endl;
    hp.display();
    hp.deleteVal();
    hp.display();
    return 0;
}