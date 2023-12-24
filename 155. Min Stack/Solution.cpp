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
        Element *new_element = new Element;
        new_element->val = val;
        new_element->next_element = top_element;
        top_element = new_element;

        if (min_element == NULL || val <= getMin())
        {
            Element *new_element = new Element;
            new_element->val = val;
            new_element->next_element = min_element;
            min_element = new_element;
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
