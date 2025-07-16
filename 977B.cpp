#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string mostFrequentSubstring(const vector<string>& v) {
    unordered_map<string, int> freqMap;
    for (const auto& str : v) {
        freqMap[str]++;
    }
    
    string mostFrequent;
    int maxCount = 0;
    
    for (const auto& pair : freqMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }
    
    return mostFrequent;
}

int main(){
    int n;
    scanf("%d", &n);
    char c;
    string s="", subs;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &c);
        s += c;
    }
    for (int i = 0; i < s.length()-1; i++)
    {
        subs = s.substr(i, 2);
        v.push_back(subs);
    }
    string result = mostFrequentSubstring(v);
    printf("%s\n", result.c_str());
    
    return 0;
}