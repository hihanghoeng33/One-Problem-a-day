#include <bits/stdc++.h>
using namespace std;



struct graph{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); 
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex.first]){
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    void dijkstra(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<long, long>, 
                        vector <pair<long, long>>, 
                        greater <pair<long, long>> > pq;
        result = vector<long>(vertexCount, LONG_MAX);
        
        pq.push(make_pair(0, start));
        result[start] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int main() {
    graph g;
    long n, m, a, b, c;
    cin >> n >> m;
    getchar();
    g.init(n);

    for (long i = 0; i < m; i++) {
        cin >> a >> b >> c;
        getchar();

        g.add_edge(a - 1, b - 1, c);
    }

    long src, dest;
    cin >> src >> dest; 
    vector<long> dijkstra_result;

    g.dijkstra(dijkstra_result, src - 1); 

    cout << dijkstra_result[dest - 1] << endl; 

    return 0;
}
