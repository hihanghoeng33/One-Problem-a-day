#include <string>

std::size_t duplicateCount(const std::string& in)
{
    std::string lowercaseString;
    std::size_t len = in.length();
    std::size_t count = 0;
    

    for(std::size_t i = 0; i < len; ++i)
    {
        char currChar = in[i];
  
        if(currChar >= 'A' && currChar <= 'Z')
        {
            currChar = currChar - 'A' + 'a';
        }
        lowercaseString += currChar;
    }

    std::string check;
    std::size_t lowercaseLen = lowercaseString.length();

    for(std::size_t i = 0; i < lowercaseLen; ++i)
    {
        char currChar = lowercaseString[i];
        bool isDup = false;
        
 
        if(check.find(currChar) != std::string::npos)
            continue; 
        

        for(std::size_t j = i + 1; j < lowercaseLen; ++j)
        {
            if(lowercaseString[j] == currChar)
            {
                isDup = true;
                break;
            }
        }
        
        if(isDup)
        {
            ++count;
            check += currChar; 
        }
    }
    
    return count;
}
