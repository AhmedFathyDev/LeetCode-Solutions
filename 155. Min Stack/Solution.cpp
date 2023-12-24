struct Element
{
    int val;
    Element *next_element;
};

class MinStack
{
private:
    Element *min_element;
    Element *top_element;

public:
    void push(int val)
    {
        Element *new_top_element = new Element;
        new_top_element->val = val;
        new_top_element->next_element = top_element;
        top_element = new_top_element;

        if (min_element == NULL || val <= getMin())
        {
            Element *new_min_element = new Element;
            new_min_element->val = val;
            new_min_element->next_element = min_element;
            min_element = new_min_element;
        }
    }

    void pop()
    {
        if (top_element->val == getMin())
        {
            Element *temp_min_element = min_element;
            min_element = min_element->next_element;
            delete temp_min_element;
        }

        Element *temp_top_element = top_element;
        top_element = top_element->next_element;
        delete temp_top_element;
    }

    int top()
    {
        return top_element->val;
    }

    int getMin()
    {
        return min_element->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
