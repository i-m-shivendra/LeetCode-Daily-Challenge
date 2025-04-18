class Solution {
public:
    
     string solveit(int n)
     {
         //base case
         if(n==1)       return "1" ;   
            
         else
         {
            string s = solveit(n-1)+ " " ;
            
            string result = "" ;
            
            int count = 1 ;
            
            for( int i=1 ; i<s.length() ; i++ )
            {
                if(s[i-1]==s[i])     count++ ;
                
                else
                {
                    result = result + to_string(count) ;
                    result = result + s[i-1] ;
                    count = 1 ;
                }
            }  
         return result ;
            
        }
    }
    string countAndSay(int n) 
    {
        return solveit(n) ;
    }
};