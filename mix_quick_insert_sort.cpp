#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <chrono>

using namespace std;

void print(vector<int> &in); // print whole vector. Using for testing
void quick_sort(vector<int> &in, int p, int r);
int partition(vector<int> &in, int p, int r);
void insert_sort(vector<int> &in, int p, int r);

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

    // pirnt raw data --------------------------------------------------------------------------------
    // cout << "raw:  ";
    // print(data);

    // count start time -----------------------------------------------------------------------
    // start = clock();
    auto begin = chrono::high_resolution_clock::now();
    // cout << start << endl;


    // sorting -------------------------------------------------------------------------------
    quick_sort( data, 0, data.size()-1);


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

void quick_sort(vector<int> &in, int p, int r)
{
    if(p < r) {
        int q = partition(in, p, r);
        quick_sort(in, p, q-1);
        quick_sort(in, q+1, r);
    }
}

int partition(vector<int> &in, int p, int r)
{
    int x = in[r];
    int i = p - 1;
    int tmp = 0;

    for(int j = p; j < r; j++) {
        if( in[j] <= x) {
            i++;

            // swap in[i] in[j]
            tmp = in[i];
            in[i] = in[j];
            in[j] = tmp;
        }
    }
    tmp = in[i+1];
    in[i+1] = in[r];
    in[r] = tmp;

    return i+1;
}

void insert_sort(vector<int> &in, int p, int r)
{
    for(int i = p; i < r; i++) {
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