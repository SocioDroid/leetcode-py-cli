class Solution {
public:
    bool checkIfPangram(string sentence) {
        sort(sentence.begin(), sentence.end());
        int i='a';
        for(int j=0; j<sentence.length(); j++)
        {
            if(sentence[j] == i)
            {
                if(!(sentence[j+1] == i))
                    i++;
            }
            else
                return false;
        }
        if(i-1 == 'z')
            return true;
        return false;
    }
};