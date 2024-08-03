#include <iostream>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

using namespace std;

// Define the comparison function for pairs
struct pair_compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a < b; // default pair comparison (lexicographical)
    }
};

// Define the ordered set with pairs
typedef tree<
    pair<int, int>,
    null_type,
    pair_compare,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set o_set;

    // Insert some pairs into the ordered_set
    o_set.insert({1, 2});
    o_set.insert({2, 3});
    o_set.insert({1, 3});
    o_set.insert({3, 1});

    // Find the lower bound for a given pair
    pair<int, int> target = {2, 2};
    auto it = o_set.lower_bound(target);

    if (it != o_set.end()) {
        cout << "Lower bound of (" << target.first << ", " << target.second << ") is (" 
             << it->first << ", " << it->second << ")" << endl;
    } else {
        cout << "Lower bound of (" << target.first << ", " << target.second << ") not found." << endl;
    }

    // Print the order of statistics
    cout << "Order of statistics: " << endl;
    for (size_t i = 0; i < o_set.size(); i++) {
        auto it = o_set.find_by_order(i);
        cout << i << ": (" << it->first << ", " << it->second << ")" << endl;
    }

    return 0;
}
