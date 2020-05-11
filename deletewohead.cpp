#include <bits/stdc++.h>
using namespace std;
#define pb push_back  
#define loop(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define F first
#define S second
#define asort(a) sort(a,a+n)
#define vsort(v) sort(v.begin(), v.end())
#define remdup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = NULL;
    }
};

void printList(Node* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
//Given a node to delete. Delete it without using head node

void deletewohead(Node* &head, Node* node){
    if(node == NULL || node->next == NULL)
        return;
    while(node){
        node->val = node->next->val;
        if(node->next->next == NULL){
            node->next = NULL;
            return;
        }
        else node = node->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);
    deletewohead(head, head->next->next); // reverse the list in groups of 3
    printList(head);
}