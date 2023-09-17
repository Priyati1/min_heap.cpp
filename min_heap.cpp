#include<iostream>
#include<vector>
using namespace std;
// heap sort
class Minheap{
	vector<int>v;
public:
	Minheap(){
		v.push_back(-1);
	}
	void heapify(int indx){
		int minindx=indx;//5
		int lc=2*indx;//10
		int rc=2*indx+1; //11
		// if(lc>v.size()-1){
		// 	return;
		// }

		if(lc<=v.size()-1 and v[lc]<v[minindx]){
			minindx=lc;//4

		}
		if(rc<=v.size()-1 and v[rc]<v[minindx]){
			minindx=rc;
		}
		if(minindx!=indx){
			swap(v[minindx],v[indx]);
			heapify(minindx);
		}
	}
	// insert
	void insert(int data){
		v.push_back(data);
		int child=v.size()-1;//10
		int parent=child/2;//5
		while(child>1 and v[child]<v[parent]){
			swap(v[child],v[parent]);
			child=parent;
			parent=child/2;
		}
	}
	// delete 
	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		heapify(1);
	}

	// top
	int top(){
		return v[1];
	}

	// empty 
	bool empty(){
		return v.size()==1;
	}

};
int main(){
	Minheap h;
	h.insert(1);
	h.insert(2);
	h.insert(3);
	h.insert(17);
	h.insert(19);
	h.insert(36);
	h.insert(7);
	h.insert(25);
	h.insert(100);

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	cout<<endl;

	return 0;
}