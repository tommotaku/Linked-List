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

Node* reverseGroup(Node* head, int k){
	Node* prev = NULL, *nxt = NULL, *curr = head;
	int count = 0; // to track k
	//reverse normally till k nodes
	while(curr && count < k){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
		count++;
	}
	if(nxt)
		head->next = reverseGroup(nxt, k); //recursively reverse groups of k and 
											// link them to head which is now reversed
	return prev; //prev is the new head which is linked to older head
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printList(head);
    head = reverseGroup(head, 3); // reverse the list in groups of 3
    printList(head);
}
