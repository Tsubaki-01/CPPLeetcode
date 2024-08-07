/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <numeric>
using namespace std;
// @lc code=start
class Node {
public:
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), value(v), freq(1) {}
};

class LFUCache {
private:
    int min_freq;
    int capacity;
    unordered_map<int, Node*> key_to_node;
    unordered_map<int, Node*> freq_to_dummy;

    Node* get_node(int key)
    {
        if (key_to_node.count(key) == 0)
            return nullptr;

        Node* node = key_to_node[key];
        int ret = node->value;

        Node* dummy = freq_to_dummy[node->freq];
        remove(node);
        if (dummy->next == dummy)
        {
            freq_to_dummy.erase(node->freq);
            delete dummy;
            if (node->freq == min_freq)
            {
                min_freq++;
            }
        }
        push_front(++node->freq, node);
        return node;
    }

    // 创建一个新的双向链表
    Node* new_list() {
        auto dummy = new Node(); // 哨兵节点
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    // 在链表头添加一个节点（把一本书放在最上面）
    void push_front(int freq, Node* x) {
        if (freq_to_dummy.count(freq) == 0)
        {
            Node* dummy = new_list();
            freq_to_dummy.emplace(freq, dummy);
        }
        Node* dummy = freq_to_dummy[freq];
        x->next = dummy->next;
        x->prev = dummy;
        dummy->next->prev = x;
        dummy->next = x;
    }

    // 删除一个节点（抽出一本书）
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if (node)
        {
            node->value = value;
            return;
        }

        if (key_to_node.size() == capacity)
        {
            Node* dummy = freq_to_dummy[min_freq];
            Node* back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            if (dummy->next == dummy)
            {
                freq_to_dummy.erase(back_node->freq);
                delete dummy;
            }
            delete back_node;
        }

        node = new Node(key, value);
        key_to_node.emplace(key, node);
        push_front(1, node);
        min_freq = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 // @lc code=end

/*
class LFUCache {
private:
    int min_freq;
    int capacity;
    unordered_map<int, Node*> key_to_node;
    unordered_map<int, Node*> freq_to_dummy;

    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) { // 没有这本书
            return nullptr;
        }
        auto node = it->second; // 有这本书
        remove(node); // 把这本书抽出来
        auto dummy = freq_to_dummy[node->freq];
        if (dummy->prev == dummy) { // 抽出来后，这摞书是空的
            freq_to_dummy.erase(node->freq); // 移除空链表
            delete dummy; // 释放内存
            if (min_freq == node->freq) { // 这摞书是最左边的
                min_freq++;
            }
        }
        push_front(++node->freq, node); // 放在右边这摞书的最上面
        return node;
    }

    // 创建一个新的双向链表
    Node* new_list() {
        auto dummy = new Node(); // 哨兵节点
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    // 在链表头添加一个节点（把一本书放在最上面）
    void push_front(int freq, Node* x) {
        auto it = freq_to_dummy.find(freq);
        if (it == freq_to_dummy.end()) { // 这摞书是空的
            it = freq_to_dummy.emplace(freq, new_list()).first;
        }
        auto dummy = it->second;
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // 删除一个节点（抽出一本书）
    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if (node) { // 有这本书
            node->value = value; // 更新 value
            return;
        }
        if (key_to_node.size() == capacity) { // 书太多了
            auto dummy = freq_to_dummy[min_freq];
            auto back_node = dummy->prev; // 最左边那摞书的最下面的书
            key_to_node.erase(back_node->key);
            remove(back_node); // 移除
            delete back_node; // 释放内存
            if (dummy->prev == dummy) { // 这摞书是空的
                freq_to_dummy.erase(min_freq); // 移除空链表
                delete dummy; // 释放内存
            }
        }
        key_to_node[key] = node = new Node(key, value); // 新书
        push_front(1, node); // 放在「看过 1 次」的最上面
        min_freq = 1;
    }
};
 */