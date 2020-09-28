template <typename T>
class graph
{
    unordered_map<T, list<pair<T, double>>> m;

public:
    graph()
    {
    }
    void addEdge(T u, T v, double dist, bool bidir = true)
    {
        m[u].push_back(make_pair(v, dist));
        if (bidir)
        {
            m[v].push_back(make_pair(u, dist));
        }
    }
    void print()
    {
        for (auto i : m)
        {
            cout << i.first << "->";
            for (auto neighbour : m[i.first])
            {
                cout << neighbour.first << " " << neighbour.second << " , ";
            }
            cout << endl;
        }
    }
    double recursiveDFS(T node , T target, map<T,bool> &visited){
        visited[node] = true;
        if(node == target) return 1.0;
        for(auto neighbour : m[node]){
            if(!visited[neighbour.first]){
                double ans = recursiveDFS(neighbour.first,target,visited);
                if(ans!=-1) return ans*neighbour.second;
            }
        }
        return -1.0;
    }
    double dfs(T source, T destination){
        map<T,bool>visited;
        if(source == destination and m.count(source)==1) return 1;
        else if (source==destination and m.count(source)==0) return -1;
        return recursiveDFS(source,destination,visited);
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph<string>g;
        for(int i=0;i<equations.size();i++){
            g.addEdge(equations[i][0],equations[i][1],values[i],false);
            g.addEdge(equations[i][1],equations[i][0],1/values[i],false);
        }
        vector<double>v;
        for(int i=0;i<queries.size();i++){
            v.push_back(g.dfs(queries[i][0],queries[i][1]));
        }
        return v;
    }
};
