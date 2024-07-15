#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Define an ordered set
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int> oset;

    // Insert elements
    oset.insert(10);
    oset.insert(20);
    oset.insert(30);
    oset.insert(40);
    oset.insert(50);

    // Print elements in order
    for (const auto& elem : oset) {
        cout << elem << " ";
    }
    cout << endl; // Output: 10 20 30 40 50

    // Check if an element is present
    cout << "Contains 30? " << (oset.find(30) != oset.end() ? "Yes" : "No") << endl; // Output: Yes
    cout << "Contains 60? " << (oset.find(60) != oset.end() ? "Yes" : "No") << endl; // Output: No

    // Erase an element
    oset.erase(30);
    for (const auto& elem : oset) {
        cout << elem << " ";
    }
    cout << endl; // Output: 10 20 40 50

    // Find the k-th smallest element (0-based index)
    cout << "3rd smallest element: " << *oset.find_by_order(2) << endl; // Output: 40

    // Find the order of a key (0-based index)
    cout << "Order of key 40: " << oset.order_of_key(40) << endl; // Output: 2

    return 0;
}
