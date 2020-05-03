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

void partition(Node* head, Node** front, Node** back){
    Node* slow = head; // slow will increase by one node
    Node* fast = head->next; // fast will increase by two nodes
    while(fast){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = head; //front(a) is the first half of the list
    *back = slow->next; // slow will be the middle element so back(b) will be 2nd half list
    slow->next = NULL; // link is broken between two halves;
}

Node* mergeList(Node* a, Node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    Node* head, *list;
    if(a->val <= b->val){
        head = a;
        a = a->next;
    }
    else{ 
        head = b;
        b = b->next;
    }
    list = head;
    while(a&&b){
        if(a->val <= b->val){
            list->next = a;
            a = a->next;
        }
        else{ 
            list->next = b;
            b = b->next;
        }
        list = list->next;
    }
    if(a) list->next = a;
    if(b) list->next = b;
    return head;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* a = NULL, *b = NULL; //a will store one half of the list and b will store the other half
    partition(head, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    return mergeList(a,b);
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(4);
    printList(head);
    head = mergeSort(head);
    printList(head);
}
