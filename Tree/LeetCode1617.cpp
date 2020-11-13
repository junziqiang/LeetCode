/***
给你 n 个城市，编号为从 1 到 n 。同时给你一个大小为 n-1 的数组 edges ，其中 edges[i] = [ui, vi] 表示城市 ui 和 vi 之间有一条双向边。题目保证任意城市之间只有唯一的一条路径。换句话说，所有城市形成了一棵 树 。
一棵 子树 是城市的一个子集，且子集中任意城市之间可以通过子集中的其他城市和边到达。两个子树被认为不一样的条件是至少有一个城市在其中一棵子树中存在，但在另一棵子树中不存在。
对于 d 从 1 到 n-1 ，请你找到城市间 最大距离 恰好为 d 的所有子树数目。
请你返回一个大小为 n-1 的数组，其中第 d 个元素（下标从 1 开始）是城市间 最大距离 恰好等于 d 的子树数目。
请注意，两个城市间距离定义为它们之间需要经过的边的数目。
**/
#include<bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 1.遍历子树
 *  判断树是否合法
 *  计算最大的距离
 * 
 */

class Solution {
    vector<vector<int >> adj;//邻接表
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
       //转换为邻接表
        adj.resize(n);
        for(auto edge : edges){
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> allow(n);//判断子树
        vector<int> dist(n);//存下距离
        vector<int> count(n,0);
        //寻找子树,2的n次方个，为一的位数是选择要的
        for(int state = 1; state < (1<<n); ++state){
            int A;//随机的一个点的位置
            int nodeNum = 0;
            for(int i = 0; i < n; ++i){
                if(((state>>i)&1) == 1){
                    allow[i] = 1;
                    A = i;
                    ++nodeNum;
                }else{
                    allow[i] = 0;
                }
            }
            //两次bfs，寻找最大的距离
            /***
             * 1.任意一个点出发找到距离最大的另外一个点，则这个点一定是这个子树最大距离中两个点中的一个
             * 2.从找找到的节点出发找距离最大的节点
             * ***/
            //去掉子树
            for(int i = 0; i<n;++i)dist[i] = -1;
            int b = bfs(A,dist,allow);
            int countVisted = 0;
            for(int i= 0; i < n; ++i) countVisted +=(dist[i]!= -1);
            if(countVisted != nodeNum)continue;
            for(int i = 0; i<n;++i)dist[i] = -1;
            int C = bfs(B,dist,allow);
            //因为dist中保存了距离
            int maxDiameter = *max_element(dist.begin(),dist.end());
            count[maxDiameter]+=1;
        }
        count.erase(count.begin());
        return count;
    }

    int bfs(int start,vector<int >& dist,vector<int >& allow){
        queue<int > q;
        q.push(start);
        dist[start] = 0;
        int maxDist = 0;
        int nodeId = start;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : adj[cur]){
                if(allow[next] == 0) continue;
                if(dist[next] == -1){
                    q.push(next);
                    dist[next] = dist[cur]  + 1;
                    if(dist[next] > maxDist){
                        maxDist = dist[next];
                        nodeId = next;
                    }
                }
            }
        }
        return nodeId;
    }
};