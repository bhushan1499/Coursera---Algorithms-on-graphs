#include<bits/stdc++.h>
using namespace std;
class maxheap{
    private:
    int size{};
    vector<int >vect={-1};
    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }
    public:
    bool isEmpty();
    void insert(int val);
    void shiftUp(int i);
    int getMax();
    int extractMax();
    void shiftDown(int i);
};
bool maxheap::isEmpty(){
    return size==0;
}
int maxheap::getMax(){
   
    return vect[1];
}
void maxheap:: shiftUp(int i){
    if(i==1)
    return;
    if(vect[i]>vect[parent(i)]){
        swap(vect[parent(i)],vect[i]);
    }
    shiftUp(vect[parent(i)]);
    return;
}
void maxheap::insert(int val){
    vect[++size] = val;
    shiftUp(size);
    return ;
}
void maxheap::shiftDown(int i){
    int swapid = i;
    if(vect[i]<vect[left(i)])
    swapid = left(i);
    if(vect[i]<vect[right(i)])
    swapid = right(i);
    if(swapid!=i){
    swap(vect[i],vect[swapid]);
    shiftDown(swapid);
    }
}
int maxheap::extractMax(){
    int maxElement = vect[1];
    swap(vect[1],vect[size--]);
    shiftDown(1);
    return maxElement;
}
int main() {

	maxheap*priorityqueue = new maxheap();
	priorityqueue->insert(100);
	priorityqueue->insert(200);
	priorityqueue->insert(50);
	priorityqueue->insert(10);
	cout<<priorityqueue->getMax()<<endl;
	priorityqueue->extractMax();
	cout<<priorityqueue->getMax()<<endl;
	return 0;
}
