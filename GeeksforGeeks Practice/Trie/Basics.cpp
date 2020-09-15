#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndofWord;
};

struct TrieNode* getNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndofWord = false;
    fr(i,0,25)
        pNode->children[i] = NULL;

    return pNode;
};

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *p = root;

    fr(i,0,key.length()-1){
        int id = key[i] - 'a';
        if (!p -> children[id])
            p->children[id] = getNode();
        p = p->children[id];
    }
    p->isEndofWord = true;
}

bool Search(struct TrieNode *root, string key)
{
    struct TrieNode *p = root;

    fr(i,0,key.length()-1){
        int id = key[i] - 'a';
        if (!p -> children[id])
            return false;
        p = p->children[id];
    }
    return (p != NULL && p->isEndofWord);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        struct TrieNode *root = getNode();
        string word;

        fr(i,0,n-1){
            cin >> word;
            insert(root, word);
        }

        string s;
        cin >> s;

        cout << Search(root, s) << endl;
    }
}