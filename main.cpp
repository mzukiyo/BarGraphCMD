/*
    This is a simple C++ program that prints clean bar graphs in the terminal based on user input
    --- Written by mzukiyo
*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int generateRandomNumber(int min_val, int max_val);
void printGraph(int* data, int arr_size, int max_val);

int main()
{
    srand(time(nullptr));

    // Size of the array
    int arr_size = 0;
    // Min value in array
    int min_val = 0;
    // Max value in array
    int max_val = 0;

    // Getting user input
    cout << "Array Size: \n";
    cin >> arr_size;
    cout << "Enter Min Value: \n";
    cin >> min_val;
    cout << "Enter Max Value: \n";
    cin >> max_val;

    // Creation of heap-allocated array
    int* data = new int[arr_size];

    // Population the array with random numbers
    for(int i = 0; i < arr_size; i++)
        data[i] = generateRandomNumber(min_val, max_val);
    
    cout << "\n";

    // Outputs neat bar graph based on random number generation
    printGraph(data, arr_size, max_val);
}

int generateRandomNumber(int min_val, int max_val)
{
    int range = max_val - min_val + 1;
    return rand() % range + min_val;
}

void printGraph(int* data, int arr_size, int max_val)
{
    for(int i = max_val; i > 0; i--)
    {   
        // Outputs the vertical bar (y - axis)
        if(i < 10)
            cout << " " << i << "| ";
        else
            cout << i << "| ";

        // Outputs the data onto the graph
        for(int j = 0; j < arr_size; j++)
        {
            // This needs the maximum value in the array
            if(data[j] >= i && data[j] <= max_val)
                cout << "*   ";
            else
                cout << "    ";
        }

        // Jumps to a new line 
        cout << "\n";
    }

    // Outputs the hortizontal bar (x - axis) 
    cout << "  ";
    for(int i = 0; i < arr_size; i++)
        cout << "----";
    cout << "\n    ";

    // Outputs the x - axis numbers (from the data)
    for(int i = 0; i < arr_size; i++)
    {
        cout << data[i] << "  ";
        if(data[i] < 10)
            cout << " ";
    }
} 






