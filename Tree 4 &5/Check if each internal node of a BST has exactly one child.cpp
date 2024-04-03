#include <iostream>
#include <vector>
using namespace std;


bool helper(vector<int>& preorder, int n) {
   
    for (int i = 0; i < n - 1; ++i) {
        // If the current element is greater than the next element, and
        // the next element is less than the last element, then it has only one child
        if (preorder[i] > preorder[i + 1] && preorder[i + 1] < preorder[n - 1]) {
            continue;
        }
        // If the current element is less than the next element, and
        // the next element is greater than the last element, then it has only one child
        if (preorder[i] < preorder[i + 1] && preorder[i + 1] > preorder[n - 1]) {
            continue;
        }
       
        return false;
    }
  
    return true;
}

int main() {
    // Example preorder traversal of a BST
    vector<int> preorder = {10, 5, 2, 1, 3, 8, 7, 9, 40, 30, 50};

   
    int n = preorder.size();

    
    if (helper(preorder, n)) {
        cout << "true"<< endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
