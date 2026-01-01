// #include<bits/stdc++.h>
// using namespace std;

   
// const int  MOD = 1e9+7;
     
// void solve(){
//     long long  n;
//     cin >> n;
//     vector<long long >ans;
//    ans.push_back(n);
//     while(n!=1){
//         if(n%2 == 0){
//             n = n/2;
//             ans.push_back(n);
//         }
//         else{
//             n = n*3+1;
//             ans.push_back(n);
//         }
//         if(n == 1){
//             break;
//         }
//     }

//     for(auto it:ans){
//         cout<<it<<" ";
//     }
//    cout<<"\n";
        
// }
   
// int  main(){
// ios::sync_with_stdio(false);
//  cin.tie(nullptr);
// long long  tt = 1;
// // cin>>tt;
// while(tt--)
// {
// solve();
// }
// return 0;
// }




#include<bits/stdc++.h>
using namespace std;

   
const int MOD = 1e9+7;

vector<int>dijkstra(int n,vector<vector<pair<int,int>>> &adj, int source){
    vector<int>dist(n+1,INT_MAX); // create array for storing min distace for each node from source node 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

    dist[source] = 0;  // set distance of source = 0
      pq.push({0,source}); // push source into the prioriyt_queue
    while(!pq.empty()){
        int currDist = pq.top().first;   // pick smallest distance  
        int u = pq.top().second; //   pick the node 
        pq.pop();

        if(currDist > dist[u]){     // if the current distance is greater than dist[u] then do not traverse the adj[u]
       continue;
        }
        for(auto neigh : adj[u]){      // travere for the neighbourse of current node and update 
                                       // update the minimum distance from the source node
            int v = neigh.first;  // distance
            int weight = neigh.second;  // weight of node

            if(dist[u] + weight < dist[v] ){
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
            }
        }

    }
   
    return dist; // return the array for sortest distance


}
     
void solve(){
    int n,m;
    cin >> n >>m;
    vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>(m+1));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >>w;
        adj[u].push_back({v,w});
    }

    vector<int>dis = dijkstra(n,adj,1);
    
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }

    
        
}
   
int main(){
ios::sync_with_stdio(false);
 cin.tie(nullptr);
int tt = 1;
// cin>>tt;
while(tt--)
{
solve();
}
return 0;
}