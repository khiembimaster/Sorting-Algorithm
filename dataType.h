#ifndef STRUCT
#define STRUCT
#include <map>
using namespace std;
enum Mode
{
    a,
    c,
    e
};
enum Algorithm
{
    Selection,
    Insertion,
    Bubble,
    Shaker,
    Shell,
    Heap,
    Merge,
    Quick,
    Counting,
    Radix,
    Flash
};
enum Order
{
    _rand,
    _nsorted,
    _sorted,
    _rev,
    _all
};
enum Output
{
    _time,
    _comp,
    _both
};

static map<string, Mode> mode;
static map<string, Algorithm> algorithm;
static map<string, Order> order;
static map<string, Output> output;

void Init_Mode()
{
    mode["-a"] = a;
    mode["-c"] = c;
    mode["-e"] = e;
}

void Init_Algorithm()
{
    // O(N^2)
    algorithm["selection-sort"] = Selection; algorithm["0"] = Selection;
    algorithm["insertion-sort"] = Insertion; algorithm["1"] = Insertion;
    algorithm["bubble-sort"] = Bubble; algorithm["2"] = Bubble;
    algorithm["shaker-sort"] = Shaker; algorithm["3"] = Shaker;
    algorithm["shell-sort"] = Shell; algorithm["4"] = Shell;
    // O(Nlogn)
    algorithm["heap-sort"] = Heap; algorithm["5"] = Heap;
    algorithm["merge-sort"] = Merge; algorithm["6"] = Merge;
    algorithm["quick-sort"] = Quick; algorithm["7"] = Quick;
    // O(N)
    algorithm["counting-sort"] = Counting; algorithm["8"] = Counting;
    algorithm["radix-sort"] = Radix; algorithm["9"] = Radix;
    algorithm["flash-sort"] = Flash; algorithm["10"] = Flash;
}

void Init_Order()
{
    order["-rand"] = _rand; order["0"] = _rand;
    order["-nsorted"] = _nsorted; order["1"] = _nsorted;
    order["-sorted"] = _sorted; order["2"] = _sorted;
    order["-rev"] = _rev; order["3"] = _rev;
}

void Init_Output()
{
    output["-time"] = _time;
    output["-comp"] = _comp;
    output["-both"] = _both;
}

#endif