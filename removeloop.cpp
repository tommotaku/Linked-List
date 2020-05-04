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

void removeLoop(Node* &head){
    //detect loop using slow and fast pointers
    //if there is a loop they will surely meet
    Node* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow == fast)//loop found
    {
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        /* Moving slowPointer to start of linked list, and making both slowPointer and 
        fastPointer to move one node at a time, they both have same distance to cover .
        They will reach at the point where the loop starts in the linked list.*/
        while(fast->next != slow)
            fast = fast->next; //finding the last node which forms loop
        fast->next = NULL; // break the link causing loop
    }
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = head;
    removeLoop(head);
    printList(head);
}