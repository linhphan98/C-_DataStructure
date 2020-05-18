#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

void insertNode(Node* &head, int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    if(head -> data < data) {
        insertNode(head -> left, data); 
        return;
    }
    if(head -> data > data) {
        insertNode(head -> right, data); 
        return;
    }
}

Node* constructMaximumBinaryTree(vector<int>& nums){
    int max = 0;
    int posMax = 0;
    vector<int> queueLeft;
    vector<int> queueRight;
    for(int i = 0; i < nums.size(); i++){
        if(max < nums[i]){
            max = nums[i];
            posMax = i;
        }
    }
    queueLeft = vector<int>(nums.begin(), nums.begin() + posMax);
    queueRight = vector<int>(nums.begin() + posMax + 1, nums.end());

    Node* head = NULL;
    insertNode(head, max);

    if(!queueLeft.empty()){
        head -> left = constructMaximumBinaryTree(queueLeft);
    }
    if(!queueRight.empty()){
        head -> right = constructMaximumBinaryTree(queueRight);
    }

    return head;
}

void print(Node* root){
    vector<Node*> queue;
    queue.push_back(root);
    while(!queue.empty()){
        Node* front = queue.front();
        queue.erase(queue.begin());
        cout << front -> data << " ";
        if(front -> left != NULL) queue.push_back(front -> left);
        if(front -> right != NULL) queue.push_back(front -> right);
    }
}

int main(void){
    vector<int> nums;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(5);

    Node* root = constructMaximumBinaryTree(nums);
    print(root);
}