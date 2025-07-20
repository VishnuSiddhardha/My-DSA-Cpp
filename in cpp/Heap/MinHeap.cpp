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
            while (ind > 0 && arr[ind] < arr[(ind-1)/2]) {
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
            int ind = 0;
            while ((2*ind+1 < size)) { // if the node has atleaset one children
                int left = 2 * ind + 1;
                int right = 2 * ind + 2;
                int smallest = ind;
                if (arr[left] < arr[smallest]) smallest = left;
                if ((right < size) && (arr[right] < arr[smallest])) smallest = right;
                if (smallest == ind) break;
                else swap(arr[ind], arr[smallest]);
                ind = smallest;
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
    MyHeap hp(70);
    hp.insert(60);
    hp.insert(50);
    hp.insert(40);
    hp.insert(30);
    hp.insert(20);
    hp.insert(10);
    hp.insert(1);
    hp.display();
    hp.deleteVal();
    hp.deleteVal();
    hp.deleteVal();
    // hp.insert(1);
    // hp.deleteVal();
    hp.display();
    return 0;
}