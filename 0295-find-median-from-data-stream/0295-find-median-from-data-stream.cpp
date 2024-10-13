class MedianFinder {
private:
    // Max-heap to store the smaller half of numbers
    priority_queue<int> small;
    // Min-heap to store the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> large;
    // Flag to keep track of whether the total number of elements is even or odd
    bool even = true;

public:
    // Function to add a number to the data structure
    void addNum(int num) {
        // If the total number of elements is even, we add the element to the larger half after filtering it
        if (even) {
            large.push(num); // Push into large first
            small.push(large.top()); // Move the smallest element from large to small
            large.pop();
        } 
        // If the total number of elements is odd, we add the element to the smaller half after filtering it
        else {
            small.push(num); // Push into small first
            large.push(small.top()); // Move the largest element from small to large
            small.pop();
        }
        // Toggle the flag since we've added a number
        even = !even;
    }

    // Function to find the median
    double findMedian() {
        // If even, return the average of the top elements of both heaps
        if (even) {
            return (small.top() + large.top()) / 2.0;
        } 
        // If odd, return the top of the smaller half
        else {
            return small.top();
        }
    }
};



/*
class MedianFinder {
public:
    priority_queue<int> maxheap; //1st half (left half)
    priority_queue<int,vector<int>,greater<int>> minheap; //2nd half (Right half)
    // initialize your data structure here. 
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize==0)    //num is the 1st element in stream
            maxheap.push(num);
        else if(lsize==rsize)   //Push one element in maxheap for sure
        {
            if(num<minheap.top())   //num can be pushed to maxheap (1st half) to maintain order
                maxheap.push(num);
            else    //Push root of minheap to maxheap (Push num to 2nd half)
            {
                int temp = minheap.top();   //Save root of minheap
                minheap.pop();  //Pop the root from minheap
                minheap.push(num);  //Push num in minheap
                maxheap.push(temp); //Push the previous saved root of minheap in the maxheap
            }
        }
        else    ///We assume that maxheap can be larger than minheap by a max of 1 element only
        {
            if(minheap.size()==0)
            {
                if(num>maxheap.top()) //Push num to 2nd half
                    minheap.push(num);
                else //Push num to 1st half
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if(num>=minheap.top()) //Push the element directly in minheap (2nd half)
                minheap.push(num);
            else    //Push root of maxheap to minheap
            {
                if(num<maxheap.top())   //Push num to 1st half
                {
                    int temp = maxheap.top();   //Save root of maxheap
                    maxheap.pop();  //Pop root of maxheap
                    maxheap.push(num);  //Push num to maxheap
                    minheap.push(temp); //Push previous saved root of maxheap to minheap
                }
                else    //Push num to 2nd half
                    minheap.push(num);
            }
        }
    }
    
    double findMedian() 
    {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize > rsize)  //Return top of maxheap for odd no of elements
            return double(maxheap.top());
        else    //Else return avg of top of maxheap and minheap
            return (double(maxheap.top())+double(minheap.top()))/2;
    }
};
*/
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */