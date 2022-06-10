#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <fstream>
#include <cstring>

#include "Counting_Sort.h"
#include "DataGenerator.h"
#include "Quick_Sort.h"
#include "Radix_Sort.h"
#include "Shaker_Sort.h"
#include "Shell_Sort.h"
#include "Flash_Sort.h"
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
    algorithm["selection-sort"] = Selection;
    algorithm["insertion-sort"] = Insertion;
    algorithm["bubble-sort"] = Bubble;
    algorithm["shaker-sort"] = Shaker;
    algorithm["shell-sort"] = Shell;
    // O(Nlogn)
    algorithm["heap-sort"] = Heap;
    algorithm["merge-sort"] = Merge;
    algorithm["quick-sort"] = Quick;
    // O(N)
    algorithm["counting-sort"] = Counting;
    algorithm["radix-sort"] = Radix;
    algorithm["flash-sort"] = Flash;
}

void Init_Order()
{
    order["-rand"] = _rand;
    order["-nsorted"] = _nsorted;
    order["-sorted"] = _sorted;
    order["-rev"] = _rev;
}

void Init_Output()
{
    output["-time"] = _time;
    output["-comp"] = _comp;
    output["-both"] = _both;
}

string Algorithm_Option(string key, bool just_name, clock_t &timer, int &comparison, int a[] = nullptr, int n = 0)
{
    string al_name;
    clock_t start, end;
    comparison = 0;
    switch (algorithm[key])
    {
    // Selection, Insertion, Bubble, Shaker, Shell,
    case Selection:
    {
        al_name = "Selection sort";
        if (just_name)
            return al_name;
        start = clock();
        // call Selection_sort
        end = clock();
    }
    break;
    case Insertion:
    {
        al_name = "Insertion sort";
        if (just_name)
            return al_name;
        start = clock();
        // call Insertion_sort
        end = clock();
    }
    break;
    case Bubble:
    {
        al_name = "Bubble sort";
        if (just_name)
            return al_name;
        start = clock();
        // call Bubble_sort
        end = clock();
    }
    break;
    case Shaker:
    {
        al_name = "Shaker sort";
        if (just_name)
            return al_name;
        start = clock();
        shakerSort(a, n, comparison);
        end = clock();
    }
    break;
    case Shell:
    {
        al_name = "Shell sort";
        if (just_name)
            return al_name;
        start = clock();
        shellSort(a, n, comparison);
        end = clock();
    }
    break;
        // Heap, Merge, Quick,
    case Heap:
    {
        al_name = "Heap sort";
        if (just_name)
            return al_name;
        start = clock();
        // call Heap_sort
        end = clock();
    }
    break;
    case Merge:
    {
        al_name = "Merge sort";
        if (just_name)
            return al_name;
        start = clock();
        // call Merge_sort
        end = clock();
    }
    break;
    case Quick:
    {
        al_name = "Quick sort";
        if (just_name)
            return al_name;
        start = clock();
        quickSort(a, 0, n - 1, comparison); // 0: first element in the array, n-1: last element in the array
        end = clock();
    }
    break;
        // Counting, Radix, Flash
    case Counting:
    {
        al_name = "Counting sort";
        if (just_name)
            return al_name;
        start = clock();
        countingSort(a, n, comparison);
        end = clock();
    }
    break;
    case Radix:
    {
        al_name = "Radix sort";
        if (just_name)
            return al_name;
        start = clock();
        radixSort(a, n, comparison);
        end = clock();
    }
    break;
    case Flash:
    {
        al_name = "Flash sort";
        if (just_name)
            return al_name;
        start = clock();
        flashSort(a, n, comparison);
        end = clock();
    }
    break;
    default:
        break;
    }
    timer = (end - start);
    return al_name;
}

string Input_Order(string input_order)
{
    string name;
    switch (order[input_order])
    {
    case _rand:
    {
        name = "Randomize";
    }
    break;
    case _nsorted:
    {
        name = "Nearly Sorted";
    }
    break;
    case _sorted:
    {
        name = "Sorted";
    }
    break;
    case _rev:
    {
        name = "Reversed";
    }
    break;
    }
    return name;
}

// Algorithm mode ------------------------------------------
void Output_Option(string out_parameter, const clock_t timer, int comparison)
{
    switch (output[out_parameter])
    {
    case _time:
    {
        cout << "Running time: " << (double)timer << endl;
    }
    break;
    case _comp:
    {
        cout << "Comparison: " << comparison << endl;
    }
    break;
    case _both:
    {
        cout << "Running time: " << (double)timer << endl;
        cout << "Comparison: " << comparison << endl;
    }
    break;

    default:
        break;
    }
}
void OutputComparision(clock_t time1, clock_t time2, int comparsion1, int comparsion2)
{
    cout << "Running time: " << time1 << "|" << time2 << endl;
    cout << "Comparision:  " << comparsion1 << "|" << comparsion2 << endl;
    cout << endl
         << endl;
}
void Algorithm_Mode(string al, string input_file, int input_size, string input_order, string out_parameter, bool exist)
{
    int *a;
    // Command 1
    if (exist)
    {
        fstream inp(input_file, ios::in);
        inp >> input_size;
        a = new int[input_size];
        for (int i = 0; i < input_size; i++)
        {
            inp >> a[i];
        }
        inp.close();
    }
    else
    {
        a = new int[input_size];
        GenerateData(a, input_size, order[input_order]);
        fstream inp(input_file, ios::out);
        inp << input_size << endl;
        for (int i = 0; i < input_size; i++)
        {
            inp << a[i] << " ";
        }
        inp.close();
    }

    clock_t timer;
    int comparison;

    string temp = Algorithm_Option(al, false, timer, comparison, a, input_size);
    if (!exist)
        cout << "Input order: " << Input_Order(input_order) << endl;
    cout << "---------------------------" << endl;
    Output_Option(out_parameter, timer, comparison);
    cout << "\n\n";

    if (exist)
    {
        fstream inp("output.txt", ios::out);
        inp << input_size << endl;
        for (int i = 0; i < input_size; i++)
        {
            inp << a[i] << " ";
        }
        inp.close();
    }
    delete[] a;
}
// Comparison mode ------------------------------------------
void Comparsion_mode(string algo1, string algo2, string inputFile, int inSize, string inOrder, bool exist)
{
    int *a1;
    int *a2;
    if (exist)
    {
        fstream fin;
        fin.open(inputFile, ios::in);
        {
            fin >> inSize;
            a1 = new int[inSize];
            a2 = new int[inSize];
            for (int i = 0; i < inSize; i++)
            {
                fin >> a1[i];
                a2[i] = a1[i];
            }
        }
        fin.close();
    }
    else
    {
        a1 = new int[inSize];
        a2 = new int[inSize];
        GenerateData(a1, inSize, order[inOrder]);
        fstream fout;
        fout.open(inputFile, ios::out);
        {
            fout << inSize << endl;
            for (int i = 0; i < inSize; i++)
            {
                fout << a1[i] << " ";
                a2[i] = a1[i];
            }
        }
        fout.close();
    }
    clock_t time1, time2;
    int comparision1, comparision2;
    Algorithm_Option(algo1, false, time1, comparision1, a1, inSize);
    Algorithm_Option(algo2, false, time2, comparision2, a2, inSize);
    if (exist == false)
    {
        cout << "Input order: " << Input_Order(inOrder) << endl;
    }
    cout << "---------------------------" << endl;
    OutputComparision(time1, time2, comparision1, comparision2);
    if (exist)
    {
        fstream fout;
        fout.open("output.txt",ios::out);
        fout<<inSize<<endl;
        for(int i=0;i<inSize;i++){
            fout<<a1[i]<<" ";
        }
        fout.close();
    }
    delete[] a1;
    delete[] a2;
}

// Experiment mode ------------------------------------------

int main(int argc, char *argv[])
{
    Init_Mode();
    Init_Algorithm();
    Init_Order();
    Init_Output();

    switch (mode[argv[1]])
    {
    case 0:
    { // Algorithm mode
        cout << "ALGORITHM MODE" << endl;
        int dummy;
        clock_t dummy_t;
        cout << Algorithm_Option(argv[2], true, dummy_t, dummy) << endl;
        string temp = argv[3];
        // Command 1
        if (temp.find(".txt") != temp.npos)
        {
            cout << "Input file: " << argv[3] << endl;
            fstream inp(temp, ios::in);
            int input_size;
            inp >> input_size;
            inp.close();
            cout << "Input size: " << input_size << endl;
            Algorithm_Mode(argv[2], argv[3], 0, "", argv[4], true);
        }
        else
        {
            cout << "Input size: " << argv[3] << endl;
            // Command 2
            if (argc == 6)
                Algorithm_Mode(argv[2], "input.txt", stoi(argv[3]), argv[4], argv[5], false);
            // Command 3
            if (argc == 5)
            {
                Algorithm_Mode(argv[2], "input_1.txt", stoi(argv[3]), "-rand", argv[4], false);
                Algorithm_Mode(argv[2], "input_2.txt", stoi(argv[3]), "-nsorted", argv[4], false);
                Algorithm_Mode(argv[2], "input_3.txt", stoi(argv[3]), "-sorted", argv[4], false);
                Algorithm_Mode(argv[2], "input_4.txt", stoi(argv[3]), "-rev", argv[4], false);
            }
        }
    }
    break;
    case 1:
    { // Comparison mode
        cout << "COMPARISON MODE" << endl;
        int dummy1, dummy2;
        clock_t dummy_t1, dummy_t2;
        cout << "Algorithm: " << Algorithm_Option(argv[2], true, dummy_t1, dummy1) << "|"
             << Algorithm_Option(argv[3], true, dummy_t2, dummy2) << endl;
        if (argc == 5)
        {
            fstream fin;
            fin.open(argv[4], ios::in);
            int inputSize;
            fin >> inputSize;
            fin.close();
            cout << "Input file: " << argv[4] << endl;
            cout << "Input Size: " << inputSize<<endl;
            Comparsion_mode(argv[2],argv[3],"input.txt",0,"",true);
        }
        if(argc ==6){
            cout<<"Input size: "<<argv[4]<<endl;
            Comparsion_mode(argv[2],argv[3],"inputc.txt",stoi(argv[4]),argv[5],false);
        }
    }
    break;
    case 2:
    { // Experiment mode
        cout << "EXPERIMENT MODE" << endl;
    }
    break;
    default:
        break;
    }
}
