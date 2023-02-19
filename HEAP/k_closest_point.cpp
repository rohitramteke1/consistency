typedef pair<int, int> p;
typedef pair<int, p> pp;
class Solution {
    vector< vector<int> > result;
    priority_queue< pp > pq;
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        for(auto &point : points) {
            int a = point[0];
            int b = point[1];
            int dist = a * a + b * b;

            pq.push( {dist, {a, b}} );
            if( pq.size() > k ) pq.pop();
        }

        while( !pq.empty() ) {
            auto top = pq.top().second;
            result.push_back( {top.first, top.second} );
            pq.pop();
        }

        return result;
    }
};