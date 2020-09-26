#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node* &head, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* last = head;
    while(last -> next != NULL){
        last = last -> next;
    }
    last -> next = newNode;
}

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

void insertNode(BstNode* &head, int data){
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    if(data < head -> data){
        insertNode(head->left, data);
    }
    if(data > head -> data){
        insertNode(head->right, data);
    }
}

void getVec (Node* head, vector<int> &list){
    Node* temp = head; 
    while(temp != NULL){
        list.push_back(temp -> data);
        temp = temp -> next;
    }
}

void DFS(BstNode* head){
    if(head == NULL) return;
    if(head -> left != NULL) DFS(head -> left);
    cout << head -> data << " ";
    if(head -> right != NULL) DFS(head -> right);
}

class Solution {
public:
    void sortedListToBST(Node* head) {
        BstNode* answer = NULL; 
        vector<int> list;
        getVec(head, list);
        int mid1 = 0;
        int mid2 = 0;

        if(list.size() % 2 == 0){
            mid1 = list.size() / 2;
            mid2 = list.size() / 2 - 1;
            cout << mid1 << endl;
            for(int i = 0; i < list.size() / 2; i++){
                insertNode(answer, list.at(mid1));
                insertNode(answer, list.at(mid2));
                mid1++; mid2--;
            }
            DFS(answer);
            return;
        }else{
            mid1 = list.size() / 2;
            mid2 = list.size() / 2;
            insertNode(answer, list.at(mid1));
            for(int i = 0; i < list.size() / 2; i++){
                mid1++; mid2--;
                insertNode(answer, list.at(mid1));
                insertNode(answer, list.at(mid2));
            }
            DFS(answer);
            return;
        }
    }
};

int main(void){
    Node* head = NULL;
    insert(head, -10);
    insert(head, -3);
    insert(head, 0);
    insert(head, 2);
    insert(head, 5);
    insert(head, 9);

    Solution obj;
    obj.sortedListToBST(head);
    return 0;
}