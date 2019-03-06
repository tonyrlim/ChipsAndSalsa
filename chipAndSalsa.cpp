#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

//input
void inputSalsa(string[], int[]);
//output
void printSalsa(const string[], const int[], int, int);
//comparison
void compare(const int[], int&, int&);

const int SIZE = 5;

int main()
{
    string names[SIZE];
    int sold[SIZE], bIndex, wIndex;

    inputSalsa(names, sold);
    compare(sold, bIndex, wIndex);
    printSalsa(names, sold, bIndex, wIndex);
    return 0;
}
void inputSalsa(string salsa[], int jars[]) //const string salsa would lock down the array
{
    ifstream input("salsa.txt");
    if(!input)
    {
        cout << "Error! File not found!";
        exit(0);
    }

    for(int i = 0; i < SIZE; i++)
    {
        input >> salsa[i] >> jars[i]; //parallel arrays
    }

    input.close();
}

void compare(const int jars[], int &bestIndex, int &worstIndex)
{
    int best, worst;
    worst = best = jars[0];
    worstIndex = bestIndex = 0;

    for(int i = 1; i < SIZE; i++) //Don't go out of bounds
    {
        if(best < jars[i])
        {
            best = jars[i];
            bestIndex = i;
        }
        else if(worst > jars[i])
        {
            worst = jars[i];
            worstIndex = i;
        }
    }
}

void printSalsa(const string salsa[], const int jars[], int best, int worst)
{
    int total = 0;

    for(int i = 0; i < SIZE; i++)
    {
        total += jars[i];
        cout << setw(10) << left << salsa[i] << jars[i] << endl;
    }

    cout << endl << "Total jars: " << total << endl << endl;
    cout << "Best Selling Salsa:  " << salsa[best] << endl;
    cout << "Worst Selling Salsa: " << salsa[worst] << endl;
}
