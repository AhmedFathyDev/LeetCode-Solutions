class MedianFinder
{
private:
    priority_queue<double> max;
    priority_queue<double> min;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        max.push(num);
        min.push(-max.top()), max.pop();

        if (max.size() < min.size())
            max.push(-min.top()), min.pop();
    }

    double findMedian()
    {
        return max.size() > min.size() ? max.top() : (max.top() - min.top()) / 2;
    }
};
