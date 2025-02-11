class Solution {
public:

    bool check(stack <char>& st, string& part, int n)
        {
            stack <char> tempStack = st;

            for(int idx = n-1; idx >= 0; idx--)
            {
                if(tempStack.top() != part[idx])
                {
                    return false;
                }
                tempStack.pop();
            }
            return true;
        }

    string removeOccurrences(string s, string part) {

        // //Approach-1 Brute-force
        // //jab tak string me characters hain
        // while(true)
        // {
        //     //us particular index se wo substring find karo
        //     int index = s.find(part);

        //     //agr substring nhi mila to
        //     if(index == string::npos)
        //     {
        //         break;
        //     }

        //    //agr mil jata hai to us particular index se
        //    //lkr part ke size tak ke charcters ko hata do
        //     s.erase(index,part.size());
        // }
        // //last me wo hi string return kar do
        // return s;


        
       
        //Approach-2 Using Stack

        stack <char> st;

        int m = s.size();
        int n = part.size();

        for(int i = 0; i < m ;i++)
        {
            st.push(s[i]);

            if(st.size() >= n && check(st,part,n) == true)
            {
                for(int j = 0; j<n;j++)
                {
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};