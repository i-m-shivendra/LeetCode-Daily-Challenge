class Solution {
public:
    string removeOccurrences(string s, string part) {
        //jab tak string me characters hain
        while(true)
        {
            //us particular index se wo substring find karo
            int index = s.find(part);

            //agr substring nhi mila to
            if(index == string::npos)
            {
                break;
            }

           //agr mil jata hai to us particular index se
           //lkr part ke size tak ke charcters ko hata do
            s.erase(index,part.size());
        }
        //last me wo hi string return kar do
        return s;
    }
};