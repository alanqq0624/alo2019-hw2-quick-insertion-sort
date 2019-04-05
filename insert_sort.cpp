#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <chrono>

using namespace std;

void print(vector<int> &in); // print whole vector. Using for testing
void insert_sort(vector<int> &in);

int main(int argc, char const *argv[])
{

    // init variable------------------------------------------------------------------------------
    ifstream fin;
    ofstream fout;
    int size, buffer;
    vector<int> data;
    // clock_t start, end;

    // open files ---------------------------------------------------------------------------------
    fin.open("input");
    if (!fin) {
        cout << "file in failed" << endl;
        return 0;
    }
    fout.open("output");
    if (!fout) {
        cout << "file in failed" << endl;
        return 0;
    }

    // get data from input file --------------------------------------------------------------------
    fin >> size;
    cout << "Size: " << size << endl;
    for(int i = 0; i < size; i++) {
        fin >> buffer;
        if (buffer == EOF) {
            cout << "file size error: " << buffer ;
            return 1;
        }
        data.push_back(buffer);
    }

    // pirnt raw data--------------------------------------------------------------------------------
    // cout << "raw:  ";
    // print(data);

    // count start time -----------------------------------------------------------------------
    // start = clock();
    auto begin = chrono::high_resolution_clock::now();
    // cout << start << endl;

    // sorting
    insert_sort(data);

    // print sorted data --------------------------------------------------------------------------
    // cout << "sort: ";
    // print(data);

    // count end time ----------------------------------------------------------------------------------
    // end = clock();
    auto terminal = chrono::high_resolution_clock::now();
    // cout << end << endl;

    // print running time --------------------------------------------------------------------
    // cout << "Sorting time: " << (double)(end - start) << " ms" << endl;
    auto dur = terminal - begin;
    auto running_time = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
    cout << "Running time: " << running_time << " nanoseconds" << endl;

    // write sorted data to output file -----------------------------------------------------------
    fout << data.size() << endl;
    for(int i = 0; i < (int)data.size(); i++) {
        fout << data[i] << endl;
    }

    // end program stuff----------------------------------------------------------------------------
    fin.close();
    fout.close();
    return 0;
}

void print(vector<int> &in)
{
    for(int i = 0; i < (int)in.size(); i++) {
        cout << in[i] << " ";
    }
    cout << endl;
}

void insert_sort(vector<int> &in)
{
    for(int i = 1; i < (int)in.size(); i++) {
        int key = in[i];

        // insert target into queue
        int j = i - 1;
        while(i >= 0 && in[j] > key) {
            in[j+1] = in[j];
            j--;
        }

        in[j+1] = key;

    }

}