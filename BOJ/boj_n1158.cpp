
#include <iostream>
#include <vector>

using namespace std;
typedef char ElementType;
class Node{
public:
    ElementType data;
    Node * nextNode;
    Node() {nextNode = NULL;}
    Node(ElementType data) {
        Node::data = data;
        nextNode = NULL;
    }
    void PrintNode(){
        cout << data << " ";
    }
};

//Class definition of singly linked list
class SLL {
public:
    int Count;
    Node * Head;
    SLL();
    ~SLL();
    void valid(int index);
    void add(ElementType data);
    void add(int index, ElementType data);
    void set(int index, ElementType data);
    void remove(int index);
    ElementType get(int index);
    int size();
    bool isEmpty();
    void PrintList();
};

SLL::SLL() {
    Count = 0;
    Head = new Node;
};
SLL::~SLL() {
    delete Head;
}
void SLL::valid(int index){
    if(Count < index){
        throw "Error: Index out of range.";
    }
}
void SLL::add(ElementType data){
    Node * newNode = new Node;
    newNode->data = data;
    
    if(Head->nextNode == NULL){
        Head->nextNode = newNode;
    }
    else {
        Node * Current = Head->nextNode;
        while(Current->nextNode != NULL){
            Current = Current->nextNode;
        }
        
        Current->nextNode = newNode;
    }
    Count++;
}

void SLL::add(int index, ElementType data){
    try{
        valid(index);
    }
    catch(const char* msg)
    {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Node * newNode = new Node(data);
    newNode->nextNode = Current->nextNode;
    Current->nextNode = newNode;
    Count++;
    
}

void SLL::set(int index, ElementType data){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Current->data = data;
    
}
void SLL::remove(int index){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return;
    }
    Node * Current = Head;
    for(int i=0 ; i < index ; i++){
        Current = Current->nextNode;
    }
    Current->nextNode = (Current->nextNode)->nextNode;
    Count--;
}
ElementType SLL::get(int index){
    try {
        valid(index);
    }
    catch(const char * msg) {
        cout << msg << endl;
        return -1;
    }
    Node * Current = Head;
    for(int i=0 ; i <= index ; i++){
        Current = Current->nextNode;
    }
    return Current->data;
}
int SLL::size()
{
    return Count;
}
bool SLL::isEmpty(){
    if(Count == 0){
        return true;
    }
    else
        return false;
}
void SLL::PrintList(){
    Node * Current = Head->nextNode;
    for(int i=1 ; Current != NULL; i++){
        cout << "[" << i << ": " << Current->data << "] ";
        Current = Current->nextNode;
    }
    cout << endl;
}

int main(){
    int N, M;
    cin >> N >> M;
    SLL list;
    for(int i=1; i <= N ; i++){
        list.add(i);
    }

    int index = 0;
    vector <int> data;
    while(!list.isEmpty()){
        index = (index+M-1) % (list.size());

        data.push_back(list.get(index));

        list.remove(index);

    }
    cout << "<";
    for(int i=0 ; i < N-1;  i++) {
        cout << data[i] <<", ";
    }
    cout << data[N-1] << ">";
}
