#include <iostream>
using namespace std;

class Polynomial {
public:
    Polynomial() : coef(0), expon(0), link(nullptr) {}
    Polynomial(int c, int e) : coef(c), expon(e), link(nullptr) {}

    int coef;
    int expon;
    Polynomial* link;
};

void attach(int c, int e, Polynomial*& pRear) {
    Polynomial* p = new Polynomial(c, e);
    pRear->link = p;
    pRear = p;
}

Polynomial* Read() {
    int N, c, e;
    cin >> N;
    Polynomial* P = new Polynomial;
    Polynomial* Rear = P;
    while (N--) {
        cin >> c >> e;
        attach(c, e, Rear);
    }
    return P->link;
}

void Print(Polynomial* L) {
    if (!L) {
        cout << "0 0" << endl;
        return;
    }
    int tag = 0;
    for (Polynomial* temp = L; temp; temp = temp->link) {
        if (tag == 0) {
            tag = 1;
        } else {
            cout << " ";
        }
        cout << temp->coef << " " << temp->expon;
    }
    cout << endl;
}

Polynomial* Add(Polynomial* P1, Polynomial* P2) {
    Polynomial* P = new Polynomial;
    Polynomial* Rear = P;
    Polynomial* t1 = P1;
    Polynomial* t2 = P2;
    while (t1 && t2) {
        if (t1->expon == t2->expon) {
            int sum = t1->coef + t2->coef;
            if (sum != 0) {
                attach(sum, t1->expon, Rear);
            }
            t1 = t1->link;
            t2 = t2->link;
        } else if (t1->expon > t2->expon) {
            attach(t1->coef, t1->expon, Rear);
            t1 = t1->link;
        } else {
            attach(t2->coef, t2->expon, Rear);
            t2 = t2->link;
        }
    }
    while (t1) {
        attach(t1->coef, t1->expon, Rear);
        t1 = t1->link;
    }
    while (t2) {
        attach(t2->coef, t2->expon, Rear);
        t2 = t2->link;
    }
    return P->link;
}

Polynomial* Multiply(Polynomial* P1, Polynomial* P2) {
    Polynomial* P = new Polynomial;
    Polynomial* Rear = P;
    Polynomial* t1 = P1;
    Polynomial* t2 = P2;

    while (t1) {
        t2 = P2;
        Rear = P;
        while (t2) {
            int e = t1->expon + t2->expon;
            int c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e) {
                Rear = Rear->link;
            }
            if (Rear->link && Rear->link->expon == e) {
                if (Rear->link->coef + c != 0) {
                    Rear->link->coef += c;
                } else {
                    Polynomial* temp = Rear->link;
                    Rear->link = temp->link;
                    delete temp;
                }
            } else {
                Polynomial* temp = new Polynomial(c, e);
                temp->link = Rear->link;
                Rear->link = temp;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    return P->link;
}

int main() {
    Polynomial* L1 = Read();
    Polynomial* L2 = Read();

    Polynomial* L = Multiply(L1, L2);
    Print(L);

    L = Add(L1, L2);
    Print(L);

    delete L1;
    delete L2;
    delete L;

    return 0;
}
