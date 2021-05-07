// shortest unique prefix...a trie problem
#include <iostream>
#include <memory>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Trie {
    private:
        class TrieNode {
            public:
                bool isString;
                unordered_map<char, shared_ptr<TrieNode>> l;
        };
        shared_ptr<TrieNode> root;

    public:
        Trie() : root(shared_ptr<TrieNode>(new TrieNode{false})) {}

        bool insert(const string &s) {
            shared_ptr<TrieNode> p = root;
            for (const char &c : s) {
                if (p->l.find(c) == p->l.cend()) {
                    p->l[c] = shared_ptr<TrieNode>(new TrieNode{false});
                }
                p = p->l[c];
            }
            // at the end of the loop, the string gets put in the trie

            // s already exists
            if (p->isString == true) {
                return false;
            } else {
                p->isString = true; // indicating that this is a string
                return true;
            }
        }

        string getShortestUniquePrefix(const string &s) {
            shared_ptr<TrieNode> p = root;
            string prefix;

            for (const char &c : s) {
                prefix += c;
                if (p->l.find(c) == p->l.cend()) {
                    return prefix;
                }
                p = p->l[c];
            }
            return {};
        }
};

string find_shortest_path_prefix(const string &s, const unordered_set<string> &D) {
    // build trie given the dictionary
    Trie t;

    for (const string &word : D) {
        t.insert(word);
    }

    return t.getShortestUniquePrefix(s);
}

int main() {

    // nice solution...good example for trie builder...potentially many other applications
}