#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class LRUCache {
public:
    int capacity;
    list<int>lru;
    unordered_map<int,list<int>::iterator> mp;
    unordered_map<int,int> val;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if(!mp.count(key))  return -1;
        touch(key);
        return val[key];
    }
    void touch (int key){
        auto it = mp[key];
        lru.erase(it);
        lru.push_front(key);
        mp[key]=lru.begin();
    }
   
    void set(int key, int value) {
        if(!mp.count(key)){
            if(mp.size()>=capacity){
            auto it = lru.back();
            lru.pop_back();
            mp.erase(it);
            val.erase(it);
        }
        lru.push_front(key);
        mp[key]=lru.begin();
        val[key]=value;
        }
       
        else{
            touch(key);
            val[key]=value;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}