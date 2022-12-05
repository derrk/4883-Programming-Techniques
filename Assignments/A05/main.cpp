

/*
    UVA 161
    Traffic Lights
    Derrik Pollock
    
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
bool checkGreen(int time, int cycleTime)
{
    int green = cycleTime - 5;
    // store the full life time of a traffic light
    int fullLifeCycleTime = 2* cycleTime;  
   
    if ((time % fullLifeCycleTime) < green)
        return true;
    else
        return false;
}

int main()
{
    vector<int> arr;
    int input;
    int terminate = 0;
    while (cin >> input)
    {

        if (input == 0)
        {
             if(arr.empty())
             {// if we read a zero'0' and the vector is empty that means the end of the program 
             return 0;
             }
             // sort the vector 
            sort(arr.begin(), arr.end()); 

            // the time of the least traffic cycle will be green
            int min = arr[0] - 5; 
            bool flag = true;
            // start counting after the first traffic light turns orange
            for (int i = min + 1; i <= 5 * 60 * 60; i++) 
            {
                flag = true;
                for (int j = 0; j < arr.size(); j++)
                {
                    if (checkGreen(i, arr[j]))
                        ;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {

                    int hour = i / (60 * 60);
                    int minute = (i / 60) % 60;
                    int sec = i % 60;
                    cout << setfill('0') << setw(2);
                    cout << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << sec << endl;
                    arr.clear();
                    break;
                }
            }
            // if no syncing within the time constraint, then it will fail 
            if(!flag)
            cout<<"Signals fail to synchronise in 5 hours\n";
            arr.clear();
        }
        else
        {
            arr.push_back(input);
        }
    }
    cout<<endl;
    return 0;
}