#include <vector>

char findMissingLetter(const std::vector<char>& chars)
{
    std::vector<char> store;
    char temp;
    char oe = chars[0];
    std::vector<char> gas;
    int len = chars.size();
    int i=0, j=0;
    for (i = 0; i < len; i++)
    {
        temp = chars[i];
        store.push_back(temp);
    }
    std::sort(store.begin(), store.end());
    for (i = 0; i < len; i++)
    {
        gas.push_back(oe);
        oe+=1;
    }
    int len2 = gas.size();
    int flag = 0;
    for (i = 0; i < len2; i++)
    {
        flag = 0;
        for (j = 0; j < len; j++)
        {
            if(store[j]==gas[i]){
                flag = 1;
            }
        }
        if(!flag){
            return gas[i];
        }
    }
    return ' ';
}
