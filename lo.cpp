#include <iostream>
#include <set>

using namespace std;

int main() {
    // Set auto-sorted hota hai: {10, 20, 30, 40, 50}
    set<int> mySet = {10, 20, 30, 40, 50};

    // =================================================================
    // 1. LOWER_BOUND(X)
    // Rule: Single value dhundta hai.
    // - Agar 'X' present hai -> Wahi 'X' dega.
    // - Agar 'X' present NAHI hai -> 'X' se agli GREATER value dega.
    // =================================================================

    // Case A: Value set mein hai (30)
    // Result: 30 hi milega.
    cout << "lower_bound(30): " << *(mySet.lower_bound(30)) << endl; 

    // Case B: Value set mein nahi hai (25)
    // Result: 25 se agli badi value '30' milegi.
    cout << "lower_bound(25): " << *(mySet.lower_bound(25)) << endl; 


    // =================================================================
    // 2. UPPER_BOUND(X)
    // Rule: HAMESHA strictly GREATER (badi) value deta hai.
    // - Chahe 'X' set mein ho ya na ho, yeh 'X' se HAMESHA BADI value dega.
    // - Barabar wali value KABHI nahi deta!
    // =================================================================

    // Case A: Value set mein hai (30)
    // Result: 30 ke barabar nahi dega, 30 se STRICTLY BADI value '40' dega.
    cout << "upper_bound(30): " << *(mySet.upper_bound(30)) << endl; 

    // Case B: Value set mein nahi hai (25)
    // Result: 25 se STRICTLY BADI value '30' dega.
    cout << "upper_bound(25): " << *(mySet.upper_bound(25)) << endl; 


    // =================================================================
    // 3. SAFE WAY TO USE (Boundary Check / Edge Case)
    // Agar hum aesi value search karein jo set ki sabse badi value se bhi badi ho (e.g., 60)
    // toh lower/upper bound 'mySet.end()' iterator deta hai.
    // Isko direct dereference (*) karna ERROR / Garbage Value deta hai!
    // =================================================================

    auto it = mySet.lower_bound(60);

    if (it != mySet.end()) {
        cout << "Found: " << *it << endl;
    } else {
        cout << "60 ya us se badi koi value set mein nahi hai!" << endl;
    }

    return 0;
}