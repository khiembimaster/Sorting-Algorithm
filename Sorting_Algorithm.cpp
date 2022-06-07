#include <iostream>
#include <map>
#include <string>
using namespace std;

enum Mode{a, c};
enum Algorithm{
    Selection, Insertion, Bubble, Shaker, Shell, 
    Heap, Merge, Quick,
    Counting, Radix, Flash};
enum Order{_rand, _nsorted, _sorted, _rev};
enum Output{_time, _comp, _both};

static map<string, Mode> mode;
static map<string, Algorithm> algorithm; 
static map<string, Order> order;
static map<string, Output> output;



void Init_Mode(){
    mode["-a"] = a;
    mode["-c"] = c;
}

void Init_Algorithm(){
    //O(N^2)
    algorithm["selection-sort"] = Selection;
    algorithm["insertion-sort"] = Insertion;
    algorithm["bubble-sort"] = Bubble;
    algorithm["shaker-sort"] = Shaker;
    algorithm["shell-sort"] = Shell;
    //O(Nlogn)
    algorithm["heap-sort"] = Heap;
    algorithm["merge-sort"] = Merge;
    algorithm["quick-sort"] = Quick;
    //O(N)
    algorithm["counting-sort"] = Counting;
    algorithm["radix-sort"] = Radix;
    algorithm["flash-sort"] = Flash;
}

void Init_Order(){
    order["-rand"] = _rand;
    order["-nsorted"] = _nsorted;
    order["-sorted"] = _sorted;
    order["-rev"] = _rev;
}

void Init_Output(){
    output["-time"] = _time;
    output["-comp"] = _comp;
    output["-both"] = _both;
}

int main(int argc, char* argv[]){
    Init_Mode();
    Init_Algorithm();
    Init_Order();
    Init_Output();
    

    switch (mode[argv[1]])
    {
    case 0:{// Algorithm mode
        cout << "ALGORITHM MODE" << endl;
    }break;
    case 1:{// Comparison mode
        cout << "COMPARISON MODE" << endl;
    }break;
    default:
        break;
    }
}

