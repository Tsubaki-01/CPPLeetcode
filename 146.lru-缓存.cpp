/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
struct Node
{
    Node* pre;
    Node* next;
    int key;
    int value;
    Node(int _key, int _value) :key(_key), value(_value), pre(nullptr), next(nullptr) {};
    Node() :key(0), value(0), pre(nullptr), next(nullptr) {};
};


class LRUCache {
private:
    int capacity_;
    int size;
    Node* dummyHead;
    Node* virtualTail;
    unordered_map<int, Node*> cache;
public:
    LRUCache(int capacity) :capacity_(capacity), size(0) {
        dummyHead = new Node();
        virtualTail = new Node();
        dummyHead->next = virtualTail;
        virtualTail->pre = dummyHead;
    }

    int get(int key) {
        if (cache[key] != nullptr)
        {
            int ret = cache[key]->value;
            moveToHead(cache[key]);
            return ret;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache[key] != nullptr)
        {
            moveToHead(cache[key]);
            cache[key]->value = value;
        }
        else {
            Node* newNode = new Node(key, value);
            push(newNode);
            cache[key] = newNode;
        }
    }

    void removeNode(Node* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        size--;
    }

    void addNodeToHead(Node* node)
    {
        Node* nextNode = dummyHead->next;
        dummyHead->next = node;
        node->pre = dummyHead;
        node->next = nextNode;
        nextNode->pre = node;
        size++;
    }

    void moveToHead(Node* node)
    {
        removeNode(node);
        addNodeToHead(node);
    }


    void push(Node* node)
    {
        addNodeToHead(node);
        if (size > capacity_)
        {
            Node* t = virtualTail->pre;
            removeNode(t);
            cache.erase(t->key);
            delete(t);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end

/*
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addToHead(node);
            ++size;
            if (size > capacity) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

 */