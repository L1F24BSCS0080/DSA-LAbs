#include <iostream>
using namespace std;
class product {
	int id;
	int price;
	static int counter;
public:
	product() {
		id = ++counter;
		price = 0;
	}
	product(int price) {
		this->price = price;
		id = ++counter;
	}
	void setprice(int p) {
		price = p;
	}
	int getid() { return id; };
	int getprice() { return price; }
	void display() {
		cout << id << endl;
		cout << price << endl;
		cout << "............" << endl;
	}
};
int product::counter = 1000;
void sort(product *arr, int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			if (arr[i].getprice() > arr[j].getprice()) {
				swap(arr[i], arr[j]);
				/*
				agr manually swap krna tu
				product temp=arr[i];
				arr[i]=arr[j];
				arr[j]=arr[i];
				*/
			}
		}
	}
}
int linearsearch(product *arr, int sz, int target) {
	for (int i = 0; i < sz; i++) {
		if (arr[i].getprice() == target) return i;

	}
	return -1;
}
int binarysearch(product *arr, int sz, int target) {
	sort(arr, sz);
	int low = 0, high = sz - 1;
	int mid = 0;
	while (low < high) {
		mid = (low + high) / 2;
		if (arr[mid].getprice() == target) return mid;
		else if (arr[mid].getprice() < target) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}
int main() {
	cout << "enter numbr of products: ";
	int sz = 0;
	cin >> sz;
	product* arr = new product[sz];
	
	int price = 100;
	for (int i = 0; i < sz; i++) {
		arr[i].setprice(price);
		price++;
	}
	for (int i = 0; i < sz; i++) {
		arr[i].display();

	}
	int target = 0;
	cout << "enter price to search the product ";
	cin >> target;
	cout << "using linear search : " << linearsearch(arr, sz, target);
	cout << "\nusing binary search : " << binarysearch(arr, sz, target);
	delete arr;
	arr = nullptr;
}