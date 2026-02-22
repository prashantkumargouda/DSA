// Alien Dictionary

// Difficulty: Hard Accuracy: 47.81%

// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> kahns(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
    }

    // iske baad create the indegree vector

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // okay so now
        // as I remove the elements from the queue I add those into the ans
        // visit the adjacent nodes

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (ans.size() != V)
        return {};
    return ans;
}

string findOrder(vector<string> &words)
{
    int N = words.size();

    // find the distinct characters ?
    // how to find the value of K

    set<char> check;

    for (int i = 0; i < N; i++)
    {
        for (int ptr = 0; ptr < words[i].size(); ptr++)
        {
            check.insert(words[i][ptr]);
        }
    }

    vector<vector<int>> adj(26);

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];

        int sz = min(s1.size(), s2.size());

        for (int pt = 0; pt < sz; i++)
        {
            if (s1[pt] != s2[pt])
            {
                adj[s1[pt] - 'a'].push_back(s2[pt] - 'a');
                break;
            }
        }
    }

    int K = check.size();

    vector<int> topo = kahns(K, adj);

    string ans = "";

    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }

    return ans;
}

int main()
{ 
    
}