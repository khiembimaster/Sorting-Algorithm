#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

enum Mode{a, c};
enum Algorithm{
    Selection, Insertion, Bubble, Shaker, Shell, 
    Heap, Merge, Quick,
    Counting, Radix, Flash};
enum Order{_rand, _nsorted, _sorted, _rev, _all};
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
    output["-all"] = _all;
}

string Algorithm_Option(int key, &ifstream input_file, clock_t &timer, int &comparison, bool just_name){
    string al_name;
    clock_t start, end;
    switch (key)
    {
    //Selection, Insertion, Bubble, Shaker, Shell,
    case Selection:{
        al_name = "Selection sort";
        if(just_name) return al_name;
        start = clock();
        // call Selection_sort
        end = clock();
    }break;
    case Insertion:{
        al_name = "Insertion sort";
        if(just_name) return al_name;
        start = clock();
        // call Insertion_sort
        end = clock();
    }break;
    case Bubble:{
        al_name = "Bubble sort";
        if(just_name) return al_name;
        start = clock();
        // call Bubble_sort
        end = clock();
    }break;
    case Shaker:{
        al_name = "Shaker sort";
        if(just_name) return al_name;
        start = clock();
        // call Shaker_sort
        end = clock();
    }break;
    case Shell:{
        al_name = "Shell sort";
        if(just_name) return al_name;
        start = clock();
        // call Shell_sort
        end = clock();
    }break;
// Heap, Merge, Quick,
    case Heap:{
        al_name = "Heap sort";
        if(just_name) return al_name;
        start = clock();
        // call Heap_sort
        end = clock();
    }break;
    case Merge:{
        al_name = "Merge sort";
        if(just_name) return al_name;
        start = clock();
        // call Merge_sort
        end = clock();
    }break;
    case Quick:{
        al_name = "Quick sort";
        if(just_name) return al_name;
        start = clock();
        // call Quick_sort
        end = clock();
    }break;
// Counting, Radix, Flash
    case Counting:{
        al_name = "Counting sort";
        if(just_name) return al_name;
        start = clock();
        // call Counting_sort
        end = clock();
    }break;
    case Radix:{
        al_name = "Radix sort";
        if(just_name) return al_name;
        start = clock();
        // call Radix_sort
        end = clock();
    }break;
    case Flash:{
        al_name = "Flash sort";
        if(just_name) return al_name;
        start = clock();
        // call Flash_sort
        end = clock();
    }break;
    default:
        break;
    }
    timer = (end - start)/CLOCKS_PER_SEC;
    return al_name;
}

void Output_Option(string out_parameter, clock_t timer, int comparison){
    switch (output[out_parameter])
    {
    case _time:{
        cout << "Running time: " << timer << endl;
    }break;
    case _comp:{
        cout << "Comparison: " << comparison << endl;
    }break;
    case _both:{
        cout << "Running time: " << timer << endl;
        cout << "Comparison: " << comparison << endl;
    }break;
    
    default:
        break;
    }
}


void Algorithm_Mode(string key, int, string input_file = "", int input_size = 0, string input_order = "all",string out_parameter){
    clock_t timer;
    int comparison;
    int *a;
    bool do_all = (input_order == "all");
    
    cout << "Algorithm name: " << Algorithm_Option(algorithm[key], inp, timer, comparison, true) << endl;
    fstream inp(input_file, ios::in);
    if(inp) inp >> input_size;
    cout << "Input size:" << input_size << "\n\n";

    if(!inp){
        inp.close();
        //generate new data
        switch (order[input_order])
        {
        case _rand:{
            inp.open("input_1.txt", ios::out);
            //generate random input and print to "input_1.txt"
            //GenerateData(a, input_size, _rand);
            //Algorithm_Option(algorithm[key], inp, timer, comparison, false);
            cout << "Input order:" <<
            cout << "---------------------------" << endl;
            Output_Option(out_parameter, timer, comparison);
            cout << "\n\n";
            //--------------------
        }if(!do_all)break;
        case _nsorted:{
            inp.open("input_2.txt", ios::out);
            //generate random input and print to "input_2.txt"
            //GenerateData(a, input_size, _nsorted);
            //Algorithm_Option(algorithm[key], inp, timer, comparison, false);
            cout << "Input order:" <<
            cout << "---------------------------" << endl;
            Output_Option(out_parameter, timer, comparison);
            cout << "\n\n";
            //--------------------
        }if(!do_all)break;
        case _sorted:{
            inp.open("input_3.txt", ios::out);
            //generate random input and print to "input_3.txt"
            //GenerateData(a, input_size, _sorted);
            //Algorithm_Option(algorithm[key], inp, timer, comparison, false);
            cout << "Input order:" <<
            cout << "---------------------------" << endl;
            Output_Option(out_parameter, timer, comparison);
            cout << "\n\n";
            //--------------------
        }if(!do_all)break;
        case _rev:{
            inp.open("input_4.txt", ios::out);
            //generate random input and print to "input_4.txt"
            //GenerateData(a, input_size, _rev);
            //Algorithm_Option(algorithm[key], inp, timer, comparison, false);
            cout << "Input order:" <<
            cout << "---------------------------" << endl;
            Output_Option(out_parameter, timer, comparison);
            cout << "\n\n";
            //--------------------
        }break;
        default:
            break;
        }
    }
    inp.close();


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

