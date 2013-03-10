/* Jonathan Drouillard
 * Given an array of unsorted numbers, print out information that
 * allows us to sort the array (least to greatest) in one pass.
 * a = [100, 50, 60, 250]
 * p = [1, 2, 0, 3]
 * One pass sort using:
 * s[0] = a[p[0]]
 * s[1] = a[p[1]]
 * s[2] = a[p[2]]
 * s[3] = a[p[3]]
*/

#include <iostream>

#include <algorithm>

using namespace std;

int main() {
    int sz = 4;
    int a[] = {100,50,60,250};
    int original[] = {100,50,60,250};
    int j;
    for(int p=1; p < 4; p++) {
        int tmp = a[p];
        for(j = p; j>0 && tmp<a[j-1]; j--) {
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }

    int p[4];//perm
    //should be perm: 1, 2, 0, 3
    for(int i = 0; i < sz; i++) { //for each number in orig: 100, 50, 60, 250
        for(int x = 0; x < sz; x++) { //for each number in a: 50, 60, 100, 250
            if(original[i] == a[x]) {
                p[x] = i;
            }
        }
    }

    for(int i = 0; i < sz; i++)
        cout << p[i] << endl; //success: 1 2 0 3

    cin.get();cin.get();
    return 0;
}