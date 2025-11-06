class LRUCache {
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

public:
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity_;
    LRUCache(int capacity) {
        capacity_ = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return;
    }
    void addAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    int get(int key) {
        int ans = -1;
        if (mp.find(key) != mp.end()) {
            Node* ansNode = mp[key];
            ans = ansNode->value;
            deleteNode(ansNode);
            addAfterHead(ansNode);
        }
        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* updateNode = mp[key];
            updateNode->value = value;
            deleteNode(updateNode);
            addAfterHead(updateNode);
            return;
        } else if (mp.size() == capacity_) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addAfterHead(newNode);
        return;
    }
};

// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */