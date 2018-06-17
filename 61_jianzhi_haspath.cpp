class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *visited = new bool[rows*cols]();
        
        int pathlength = 0;
        for(int i = 0; i< rows;i++)
            for(int j = 0; j< cols; j++){
                cout << visited[i*cols+j];
                if(hasPathcore(matrix,rows,cols,str,i,j,pathlength,visited))
                    return true;
            }
        delete[] visited;
        return false;
    }
    bool hasPathcore(char* matrix, int rows, int cols, char* str, int i, int j, int &pathlength, bool *visited){
        if(str[pathlength] == '\0')
            return true;
        bool haspath = false;
        if(i>=0 && i < rows && j >=0 && j < cols && matrix[i*cols+j]==str[pathlength] && !visited[i*cols+j]){
            ++pathlength;
            visited[i*cols+j] = true;
            haspath = hasPathcore(matrix,rows,cols,str,i+1,j,pathlength,visited) || hasPathcore(matrix,rows,cols,str,i-1,j,pathlength,visited) ||hasPathcore(matrix,rows,cols,str,i,j+1,pathlength,visited) || hasPathcore(matrix,rows,cols,str,i,j-1,pathlength,visited);
        }
        if(!haspath)
        {
            --pathlength;
            visited[i*cols+j] = false;
        }
        return  haspath;
    }


};