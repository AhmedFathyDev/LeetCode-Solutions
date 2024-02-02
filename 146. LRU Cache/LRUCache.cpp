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

    size_t cache_length;
    map<int, list_node *> cache;

    void put_head(list_node *new_head)
    {
        if (head)
        {
            new_head->prev = NULL;

            new_head->next = head;
            head->prev = new_head;

            head = new_head;

            return;
        }

        head = new_head;
        tail = new_head;
    }

    void delete_tail(void)
    {
        --cache_length;
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

    void put_head(int key)
    {
        if (cache[key] != head)
        {
            cache[key]->prev->next = cache[key]->next;

            if (cache[key] == tail)
                tail = tail->prev;
            else
                cache[key]->next->prev = cache[key]->prev;

            put_head(cache[key]);
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(NULL), tail(NULL), cache_length(0) {}

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

        ++cache_length;
        list_node *new_list_node = new list_node(key, value);
        cache[key] = new_list_node;

        put_head(new_list_node);

        if (cache_length > capacity)
            delete_tail();
    }
};
