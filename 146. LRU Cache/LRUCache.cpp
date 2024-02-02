struct node
{
    int key;
    int value;

    node *prev;
    node *next;

    node(int key, int value) : key(key), value(value), prev(NULL), next(NULL) {}
};

class LRUCache
{
private:
    size_t capacity;

    node *head;
    node *tail;

    size_t cache_length;
    map<int, node *> cache;

    void put_head(node *new_head)
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

    void update_key_location(int key)
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
        if (!cache[key])
            return -1;

        update_key_location(key);
        return cache[key]->value;
    }

    void put(int key, int value)
    {
        if (cache[key])
        {
            cache[key]->value = value;
            update_key_location(key);
            return;
        }

        ++cache_length;
        node *new_node = new node(key, value);
        cache[key] = new_node;

        put_head(new_node);

        if (cache_length > capacity)
            delete_tail();
    }
};
