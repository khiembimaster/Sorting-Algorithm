#include <iostream>
#include <map>
#include <ctime>
#include <string>
#include <fstream>
#include <cstring>

#include "dataType.h"
#include "Algo_Option.h"

using namespace std;


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
void Output_Option(string out_parameter, const clock_t timer, long long comparison)
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
void OutputComparision(clock_t time1, clock_t time2, long long comparsion1, long long comparsion2)
{
    cout << "Running time: " << time1 << "|" << time2 << endl;
    cout << "Comparision:  " << comparsion1 << "|" << comparsion2 << endl;
    cout << endl
         << endl;
}
void Algorithm_Mode(string al, string input_file, int input_size, string input_order, string out_parameter, bool exist)
{
    int *a, *b;
    // Command 1
    if (exist)
    {
        fstream inp(input_file, ios::in);
        inp >> input_size;
        a = new int[input_size];
        b = new int[input_size];
        for (int i = 0; i < input_size; i++)
        {
            inp >> a[i];
            b[i] = a[i];
        }
        inp.close();
    }
    else
    {
        a = new int[input_size];
        b = new int[input_size];
        GenerateData(a, input_size, order[input_order]);
        fstream inp(input_file, ios::out);
        inp << input_size << endl;
        for (int i = 0; i < input_size; i++)
        {
            inp << a[i] << " ";
            b[i] = a[i];
        }
        inp.close();
    }

    clock_t timer;
    unsigned long long comparison;

    string temp = Algorithm_Option(al, false, timer, a, input_size);
           temp = Algorithm_Option(al, false, comparison, b, input_size);
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
    delete[] b;
}
// Comparison mode ------------------------------------------
void Comparsion_mode(string algo1, string algo2, string inputFile, int inSize, string inOrder, bool exist)
{
    int *a;
    int *b;
    if (exist)
    {
        fstream fin;
        fin.open(inputFile, ios::in);
        {
            fin >> inSize;
            a = new int[inSize];
            b = new int[inSize];
            for (int i = 0; i < inSize; i++)
            {
                fin >> a[i];
                b[i] = a[i];
            }
        }
        fin.close();
    }
    else
    {
        a = new int[inSize];
        b = new int[inSize];
        GenerateData(a, inSize, order[inOrder]);
        fstream fout;
        fout.open(inputFile, ios::out);
        {
            fout << inSize << endl;
            for (int i = 0; i < inSize; i++)
            {
                fout << a[i] << " ";
                b[i] = a[i];
            }
        }
        fout.close();
    }
    clock_t time1, time2;
    unsigned long long comparision1, comparision2;
    Algorithm_Option(algo1, false, time1, a, inSize);
    Algorithm_Option(algo2, false, time2, b, inSize);
    //Refresh arrays
    fstream fin;
    fin.open(inputFile, ios::in);
    {
        fin >> inSize;
        for (int i = 0; i < inSize; i++)
        {
            fin >> a[i];
            b[i] = a[i];
        }
    }
    fin.close();
    //end 
    Algorithm_Option(algo1, false, comparision1, a, inSize);
    Algorithm_Option(algo2, false, comparision2, b, inSize);
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
            fout<<a[i]<<" ";
        }
        fout.close();
    }
    delete[] a;
    delete[] b;
}

// Experiment mode ------------------------------------------
void Experiment_mode(){
    int dataSize[]{10'000, 30'000, 50'000, 100'000, 300'000, 500'000};
    int *a,*b,*store;
    
    string index = "0";
    string s_index = "0";
    fstream fs;
    for(int i = 0; i < 4; i++){
        string outputfile = "output_.txt";
        index = to_string(i);
        outputfile.insert(7,index); 
        fs.open(outputfile, ios::out);
        fs << Input_Order(index) << endl;                 
        for(int j = 0; j < 6; j++){
            int n = dataSize[j];
            fs << "\t" << n << endl;
            a = new int[n];
            b = new int[n];
            store = new int[n];
            GenerateData(store, n, i);
            for(int sort = 0; sort < 11; sort++){
                for(int i = 0; i < n; i++){
                    b[i] = a[i] = store[i];
                }
                clock_t timer;
                unsigned long long comparison;
                s_index = to_string(sort);
                string temp = Algorithm_Option(s_index, false, timer, a, n);
                       temp = Algorithm_Option(s_index, false, comparison, b, n);
                delete[] a;
                delete[] b;
                //Write data
                fs << "\t\tAlgorithm: " << temp << endl
                    << "\t\t\t" << "Comparisons: " << comparison << endl
                    << "\t\t\t" << "Running time: " << timer << endl;
            }
            delete[] store;
            fs << endl;
        }
        fs.close();
    }
}

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
        unsigned long long dummy;
        clock_t dummy_t;
        cout << Algorithm_Option(argv[2], true, dummy_t) << endl;
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
        unsigned long long dummy1, dummy2;
        clock_t dummy_t1, dummy_t2;
        cout << "Algorithm: " << Algorithm_Option(argv[2], true, dummy_t1) << "|"
             << Algorithm_Option(argv[3], true, dummy_t2) << endl;
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
        Experiment_mode();
    }
    break;
    default:
        break;
    }
}
