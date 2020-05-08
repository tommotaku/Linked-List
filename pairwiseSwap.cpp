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

Node* pairwiseSwap(Node* head){
    if(head == NULL || head->next == NULL)
        return head;
    Node* nxt, *newhead;
    if(head && head->next){
        nxt = head->next->next; //save nodes after the current 2 nodes
        newhead = head->next; //new head is the 2nd element
        head->next->next = head; //2nd element points to 1st element
        head->next = pairwiseSwap(nxt); //1st element points to head of next 2 pair
    }
    return newhead;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);
    head = pairwiseSwap(head); // reverse the list in groups of 3
    printList(head);
}