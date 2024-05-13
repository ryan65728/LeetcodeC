#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int m = image.size();
            int n = image[0].size();
            queue<pair<int,int>> p_queue;
            pair<int,int> target(sr,sc);
            int init = image[target.first][target.second];
            p_queue.push(target);
            while(!p_queue.empty()){
                target = p_queue.front();
                //cout << "x:"+target.first<<" y:"+target.second<<" v:"<<image[target.first][target.second]<<endl;
                p_queue.pop();
                if(image[target.first][target.second] == color || image[target.first][target.second] != init)
                    continue;
                pair<int,int> tmp;
                if(target.first+1 < m){
                    tmp.first = target.first+1;
                    tmp.second = target.second;
                    p_queue.push(tmp);
                }
                if(target.first-1 >= 0){
                    tmp.first = target.first-1;
                    tmp.second = target.second;
                    p_queue.push(tmp);
                }
                if(target.second+1 < n){
                    tmp.first = target.first;
                    tmp.second = target.second+1;
                    p_queue.push(tmp);
                }
                if(target.second-1 >= 0){
                    tmp.first = target.first;
                    tmp.second = target.second-1;
                    p_queue.push(tmp);
                }
                
                image[target.first][target.second] = color;
            }
            return image;
        }
};

int main()
{

    vector<vector<int>> matrix {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};

    Solution a;

    matrix = a.floodFill(matrix,0,0,3);
    for(auto i:matrix){
        for(auto j:i)
            cout << j;
        cout << endl;
    }
    return 0;
}