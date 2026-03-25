#include "array.h"
class Product {
	int id;
	string name;//
	float price;
	int quantity;
public:
	Product() {
		id = 0;
		name = "";
		price = 0;
		quantity = 0;
	}
	Product(int id, string name, float p, int q) {
		this->id = id;
		this->name = name;
		this->price = p;
		this->quantity = q;
	}
	void display() {
		cout << "id: " << id << endl;
		cout << "name: " << name<<endl;
		cout << "price: " << price<<endl;
		cout << "quantity: " << quantity<<endl;
	}
	int getid() {
		return id;
	}
	bool operator==(Product& p) {
		return this->id == p.getid();
	}
	friend ostream& operator<<(ostream& out, Product& p);
};
ostream& operator<<(ostream& out, Product& p) {
	out << "id: " << p.id << endl;
	out << "name: " << p.name << endl;
	out << "price: " << p.price << endl;
	out << "quantity: " << p.quantity << endl;
	return out;
}
int main() {
	Array<Product> arr(5);
	Product p1(10,"book",500.5,3);
	Product p2(11, "mobile", 50000.5, 3);
	Product p3(12, "table", 5000.5, 3);
	Product p4(13, "charger", 700.5, 4);
	arr.insertval(p1);
	arr.insertval(p2);
	arr.insertval(p3);
	arr.insertval(p4);
	arr.display();
	cout << "...................................\n";
	cout<<"product 3 index :"<<arr.search(p3)<<endl<<"removing prouct 3 table \n";
	arr.removeval(p3);
	arr.display();
}
