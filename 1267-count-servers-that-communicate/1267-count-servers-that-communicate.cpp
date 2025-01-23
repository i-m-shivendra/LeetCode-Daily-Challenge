class Solution {
public:
     int countServers(vector<vector<int>>& grid) {

        // //BruteFrorce Approach
        // int m=grid.size();
        // int n=grid[0].size();

        // int count=0;

        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(grid[i][j]==1)
        //         {
        //             //agr server hua to
        //             bool canCommunicate=false;
        //             // us row me check karo
        //             for(int col=0;col<n;col++)
        //             {
        //                 if(grid[i][col]==1 && col!=j)
        //                 {
        //                     canCommunicate=true;
        //                     break;
        //                 }
        //             }
        //             if(canCommunicate==true)
        //             {
        //                 count++;
        //             }
        //             else
        //             {
        //                 //agr row me nhi mila to 
        //                 //column me check karo
        //                 for(int row=0;row<m;row++)
        //                 {
        //                     if(grid[row][j]==1 && row!=i)
        //                     {
        //                         canCommunicate = true;
        //                         break;
        //                     }
        //                 }
        //                if(canCommunicate == true)
        //                 count++;
        //             }
                    
        //         }
        //     }
        // }
        // return count;






    //Better Approach

    //sabse pahle grid me no. of rows && cols nikal lo
    int m=grid.size();
    int n=grid[0].size();

    //2 array bana lo jisme agr sever milta hai to
    //count me add karna hai
    vector <int> colCount(n,0);
    vector <int> rowCount(m,0);

    //Ab grid me traverse karke jha par bhi server ho
    //uske corresponding row and col ka count++ kar do
    //Pre-processing part
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                colCount[j] += 1;
                rowCount[i] += 1;
            }
        }
    }

        //ab firse pure grid me traverse karke ye
        //check kar lo ki kitne servers aapas me
        //communicate kar payenge

        int server=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( grid[i][j]==1 && (colCount[j]>1 || 
                                     rowCount[i]>1) )
                {
                    server += 1;
                }
            }
        }
    return server;

   }
};