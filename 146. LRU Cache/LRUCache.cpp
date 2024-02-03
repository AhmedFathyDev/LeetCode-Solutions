struct list_node
{
    int key;
    int value;

    list_node *prev;
    list_node *next;

    list_node(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
};

class LRUCache
{
private:
    size_t capacity;

    list_node *head;
    list_node *tail;

    size_t list_length;
    map<int, list_node *> cache;

    void put_head(int key)
    {
        if (cache[key] == head)
            return;

        if (!head)
        {
            head = cache[key];
            tail = cache[key];
            return;
        }

        if (cache[key]->prev)
            cache[key]->prev->next = cache[key]->next;

        if (cache[key]->next)
            cache[key]->next->prev = cache[key]->prev;

        if (cache[key] == tail)
            tail = cache[key]->prev;

        cache[key]->prev = NULL;
        cache[key]->next = head;

        head->prev = cache[key];
        head = cache[key];
    }

    void delete_tail(void)
    {
        --list_length;

        cache[tail->key] = NULL;
        cache.erase(tail->key);

        if (tail->prev)
        {
            tail = tail->prev;

            delete tail->next;
            tail->next = NULL;

            return;
        }

        delete tail;

        tail = NULL;
        head = NULL;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(NULL), tail(NULL), list_length(0) {}

    int get(int key)
    {
        if (!cache.count(key))
            return -1;

        put_head(key);
        return cache[key]->value;
    }

    void put(int key, int value)
    {
        if (cache[key])
        {
            cache[key]->value = value;

            put_head(key);
            return;
        }

        ++list_length;
        cache[key] = new list_node(key, value);

        put_head(key);

        if (list_length > capacity)
            delete_tail();
    }
};
