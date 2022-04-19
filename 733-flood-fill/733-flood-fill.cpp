class Solution {
public:
    
    
    void solve(vector<vector<int>>& image,int i,int j,int pi,int pj,int nc,int x,vector<vector<int>> &v)
    {
        cout<<i<<" "<<j<<endl;
        int m=image.size(),n=image[0].size();
        if(i>=m||j>=n||i<0||j<0)
            return;
        if(image[i][j]!=x||v[i][j])
            return;
        v[i][j]=1;
        x=image[i][j];
        image[i][j]=nc;
        if(i-1!=pi||j!=pj)
            solve(image,i-1,j,i,j,nc,x,v);
         if(i+1!=pi||j!=pj)
            solve(image,i+1,j,i,j,nc,x,v);
         if(i!=pi||j-1!=pj)
            solve(image,i,j-1,i,j,nc,x,v);
         if(i!=pi||j+1!=pj)
            solve(image,i,j+1,i,j,nc,x,v);
        
        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> v(image.size(),vector<int>(image[0].size(),0));
        cout<<v[0].size()<<endl;
        v[sr][sc]=1;
        int x=image[sr][sc];
        image[sr][sc]=newColor;
        solve(image,sr-1,sc,sr,sc,newColor,x,v);
        solve(image,sr+1,sc,sr,sc,newColor,x,v);
        solve(image,sr,sc-1,sr,sc,newColor,x,v);
        solve(image,sr,sc+1,sr,sc,newColor,x,v);
        
        return image;
        
    }
};