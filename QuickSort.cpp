#include <cstdlib>                                      //for std::srand and std::rand
#include <iostream>                                     //for std::cout
#include <ctime>                                        //for std::time, which is needed for std::srand
#include <vector>                                       //for std::vector

int Partition(std::vector<int> &v, int low, int high)   //This function sorts the elements around the pivot element
                                                        //Elements with a value smaller than the value at pivot are
                                                        //sorted to the left of the pivot element, and elements with a
                                                        //value larger are sorted to the right
{
    int pivot = v[low+(high-low)/2];                    //makes the pivot the central element
                                                        //NOTE: THE PIVOT VARIABLE IS THE VALUE AT THE PIVOT ELEMENT
    int i = low - 1;                                    //in the first call to Partition(), i = -1
    int j = high + 1;                                   //in the first call to Partition(), j = highest element + 1
    while(1)                                            //equivalent to while(true)
    {
        while(v[++i] < pivot);                          //if value at the (i -eth element) + 1 < pivot, do nothing
        while(v[--j] > pivot);                          //if value at the (j -eth element) + 1 > pivot, do nothing
                                                        //i and j are both pre incremented and decremented respectively
        if(i >= j)
            return j;
        std::swap(v[i], v[j]);
    }
}

void QuickSort(std::vector<int> &v, int low, int high)  //Creates multiple subvectors and does the Partition() function
                                                        //on every subvector
{
    if (low < high)
    {
        int PI = Partition(v, low, high);               //PI == Partition Index
        QuickSort(v, low, PI);                          //Recursively calls this function by creating two sub vectors
        QuickSort(v, PI + 1, high);                     //which are separated at the partition index
    }
}

void printvec(std::vector<int> &v)
{
    std::cout << "\n";

    for (int i = 0; i <= v.size() - 1; i++)
        std::cout << v[i] << " ";

    std::cout << "\n\n";
}

int main()
{
    std::srand(std::time(nullptr));                     //seeding the rand() function so that it produces a random
                                                        //number every time the program runs

    std::vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(std::rand());                       //creates 100 random numbers and places them in the vector
    }

    printvec(v);

    QuickSort(v, 0, v.size() - 1);
    
    printvec(v);

    return 0;
}
