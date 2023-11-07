#include<iostream>
#include<string>
using namespace std;

class List{
    public:
    List():addr("-1"),expon(0),aimAddr("-1"),link(nullptr),pre(nullptr){}
    List(string a,int e,string b):addr(a),expon(e),aimAddr(b),link(nullptr),pre(nullptr){}
    string addr;
    int expon;
    string aimAddr;
    List *link;
    List *pre;
};

void attach(string a,int e,string b,List *&pRear){
    List *p = new List(a,e,b);
    pRear->link = p;
    p->pre = pRear;
    pRear = p;
}

void PlayList(List *L){
    if(!L){
        cout<<"0 0"<<endl;
        return;
    }
    for(List *temp = L->link;temp;temp = temp->link){
        cout<<temp->addr<<" "<<temp->expon<<' '<<temp->aimAddr<<endl;
    }
}

void InitArray(List *&array,int numOfNode){
    for (int i = 0; i < numOfNode; i++) {
        string address;
        int expon;
        string aimAddress;
        cin >> address >> expon >> aimAddress;
        array[i] = List(address, expon, aimAddress);
    }
}

void Connect(List *&l,string StartAddress,int numOfNode,List *array){
    List *p = l;    // p控制移动
    int count = 1;  // 记录已经连接好的点数
    for (int i = 0; i < numOfNode; i++) {
        if (array[i].addr == StartAddress) {
            attach(array[i].addr, array[i].expon,array[i].aimAddr, p);
            break;
        }
    }

    while (count < numOfNode) {
        for (int i = 0; i < numOfNode; i++) {
            if (array[i].addr == p->aimAddr) {
                attach(array[i].addr, array[i].expon,array[i].aimAddr, p);
                count++;
                break;
            }
        }
    }
}

List* Reverse(List *L,int numOfNode,int numOfReverse){
    if(numOfReverse > numOfNode)
        return L;
    reverse_time = numOfNode/numOfReverse;
    List *L1 = new List;
    List *p = L->link;
    // 需要翻转几次
    for(int i=1;i<=reverse_time;i++){
        // 遍历点
        for(int j=(i-1)*numOfReverse;j<i*numOfReverse;j++){
            if(j == (i-1)*numOfReverse){

            }
        }
    }
}

int main()
{
    string StartAddress;
    int numOfNode;
    int numOfReverse;
    cin>>StartAddress>>numOfNode>>numOfReverse;

    List *array = new List[numOfNode];
    InitArray(array,numOfNode);
    
    List *L = new List;
    Connect(L, StartAddress, numOfNode, array);
    
    List *L2 = new List;
    L2 = Reverse(L,numOfNode,numOfReverse);
    PlayList(L2);
}