#include <iostream>
#include <list>
#include <string.h>
using namespace std;

class HashTable{
	private:
		int size;
		list<string> *valuePtr;
	public:
		HashTable(int size){
			this -> size = size;
			valuePtr = new list<string>[size];
		};

		// hash function to map values into key
		int hashFunction(string value){
			int sum = 0;
			for(auto x : value){
				sum += x;
			}
			return sum%size;
		};

		// insert a key into hash table
		void insertItem(string value, string email){
			int key = hashFunction(value);
			valuePtr[key].push_back(value);
			valuePtr[key].push_back(email);
		};

		// displaying the hash table
		void displayHashTable(){
			for (int i = 0; i < size; i++){
				cout << "Key: " << i; 
				int count = 0;
				for (auto x : valuePtr[i]){
					if(count == 1){
						cout << " + " << x;
						count = 0;
					}else{
						cout << " --> " << x; 
						count++;
					}					
				}
				cout << endl;
			}
		};

		// deleting a key
		void deleteValue(string value){
			int key = hashFunction(value);
			list<string>::iterator it;

			for(it = valuePtr[key].begin(); it != valuePtr[key].end(); it++){
				if(*it == value) {
					valuePtr[key].erase(it);
					valuePtr[key].erase(++it);
					return;
				}
			}
		}

		void gettingValueWithKey(string value){
			int key = hashFunction(value);
			list<string>::iterator it;

			for(it = valuePtr[key].begin(); it != valuePtr[key].end(); it++){
				if(*it == value){
					advance(it,1);
					cout << value << ": " << *it << endl;
				}
			}
		};

		bool IsEmpty(){
			int sum = 0;
			for(int i = 0; i < size; i++){
				if(valuePtr[i].empty()) sum += 1;
			}
			if(sum == size){
				return true;
			}
			return false;
		};
};

int main(void){
	HashTable obj(11);
	obj.insertItem("Mia", "Mia@gmail.com");
	obj.insertItem("Tim", "Tim@gmail.com");
	obj.insertItem("Bea", "Bea@gmail.com");
	obj.insertItem("Zoe", "Zoe@gmail.com");
	obj.insertItem("Sue", "Sue@gmail.com");
	obj.insertItem("Len", "Len@gmail.com");
	obj.insertItem("Moe", "Moe@gmail.com");
	obj.insertItem("Lou", "Lou@gmail.com");
	obj.insertItem("Rae", "Rae@gmail.com");
	obj.insertItem("Max", "Max@gmail.com");
	obj.insertItem("Tod", "Tod@gmail.com");
	obj.gettingValueWithKey("Max");
	return 0;
}

