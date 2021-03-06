//Accelerated C++
//Chapter 3 Working with batches of data
//Question 3-1

#include <queue>
#include <iostream>
  
using namespace std;
  
struct comparator {
 bool operator()(int i, int j) {
 return i > j;
 }
};
  
int main(int argc, char const *argv[])
{

cout << "Warming up the heaps" << endl;

 priority_queue<int, std::vector<int>, comparator> minHeap;
 cout << "Min Heap: " ; 
 minHeap.push(10);
 minHeap.push(5);
 minHeap.push(12);
 minHeap.push(3);
 minHeap.push(3);
 minHeap.push(4);
  
 while (!minHeap.empty()) {
 cout << minHeap.top() << " ";
 minHeap.pop();
 }

 cout << endl;

 priority_queue<int, std::vector<int>> maxHeap;
 cout << "Max Heap: " ; 
 maxHeap.push(10);
 maxHeap.push(5);
 maxHeap.push(12);
 maxHeap.push(3);
 maxHeap.push(3);
 maxHeap.push(4);
  
 while (!maxHeap.empty()) {
 cout << maxHeap.top() << " ";
 maxHeap.pop();
 }

cout <<endl<< "Calculating the Median linearly" << endl;

 int count = 0 ;
 double median;
 double x;


    while (cin >> x)
    {
        if(maxHeap.empty()){
            maxHeap.push(x);
            median = x;
        }
        else 
        {
            if(minHeap.size() == maxHeap.size())
            {
                if(x > minHeap.top())
                {
                    
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);

                }
                else
                {
                    maxHeap.push(x);
                }
                median = maxHeap.top();

            }
        
            else
            {
                if(x <= maxHeap.top())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);

                }
                else
                {
                    minHeap.push(x);
                }
                median = (maxHeap.top()+minHeap.top())/2.0;
            }
        }
            


        count++;

        cout << "Median: " << median << endl;

    }

 return 0;
}

/*Answer: Program contains bonus that calculates the median as soon as a new number is entered
by using a min heap and a max heap. 
If any numbers from the  set are discarded, the median is altered.*/