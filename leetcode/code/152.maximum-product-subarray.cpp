/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

#ifndef __utility__
#define __utility__

#include <bits/stdc++.h> // Include every standard library(s)
using namespace std;

#ifndef __constants__
#define __constants__

const double PI = acos(-1);
const int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int directions8[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
#endif

#ifndef __marcos__
#define __marcos__

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

typedef unordered_set<int> si;
#define uset unordered_set

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
#define vec vector

typedef unordered_map<int, int> mii;
typedef unordered_map<char, char> mcc;
typedef unordered_map<int, string> mis;
typedef unordered_map<string, int> msi;
typedef unordered_map<string, string> mss;
#define umap unordered_map

// bit && number
#define MODULO (1e9 + 7)
#define BIT(x, i) (x & (1 << i)) // select the bit at the position i of x. eg: BIT(5, 0) => 1; BIT(5, 2) => 4;
#define LOWBIT(x) ((x) & ((x) ^ ((x) - 1))) // get the lowest bit of x
#define SETMAX(a, b) (a) = max((a), (b))
#define SETMIN(a, b) (a) = min((a), (b))
#define CLAMP(n, min, max) ((n <= min) ? min : (n >= max ? max : n))
#define SQ(n) ((n) * (n))
#define INTMAX __INT_MAX__
#define INTMIN (-INTMAX - 1)

// array
#define arr2d(v, n, m, fill) vvi v((n), vi((m), (fill)))
#define arr2dc(v, n, m, fill) vvc v((n), vc((m), (fill)))
#define arr2db(v, n, m, fill) vvb v((n), vb((m), (fill)))
#define charmap(map, size, fill) char map[size] = { fill }
#define fi first
#define se second
#define mp make_pair
#define pb push_back

// boundary
#define IN(i, l, r) (((l) < (i)) && ((i) < (r)))
#define INL(i, l, r) (((l) <= (i)) && ((i) < (r)))
#define INR(i, l, r) (((l) < (i)) && ((i) <= (r)))
#define INLR(i, l, r) (((l) <= (i)) && ((i) <= (r)))

// iterator
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define HAS(c, v) ((c).find(v) != (c).end())
#define WHILEIT(it, c) auto it = (c).begin(); while (it != (c).end())
#define SUM(c) (reduce(ALL(c)))
#define TOSET(s, c) set s(ALL(c))
#define TOUSET(s, c) uset s(ALL(c))

// loop
#define FOR(i, l, r) for (int (i) = (l); (i) < (r); ++(i))
#define FORE(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define FFOR(i, l, r) for (int (i) = (l); (i) > (r); --(i))
#define FFORE(i, l, r) for (int (i) = (l); (i) >= (r); --(i))
#define FOREACH(v, c) for (auto &(v) : (c))
#define REPEAT(i, n) FOR(i, 0, n)
#define REPEATN(i, n) FORE(i, 1, n)

#endif

#ifndef __pretty_print__
#define __pretty_print__

#define IOS ios_base::sync_with_stdio(0) // to synchronize the input of cin and scanf
#define BREAK cout << "===========" << endl
#define VALUE(x) cout << "The value of \"" << #x << "\" is: " << x << endl

template<typename K, typename V>
ostream &operator<<(ostream &out, const pair<K, V> &pair)
{
    out << "<" << pair.first << ", " << pair.second << ">";
    return out;
}

template<typename T>
static inline ostream &__print_iterable(ostream &out, const T &container) 
{
    auto it = container.begin();
    out << "{ " << *it++;
    while (it != container.end()) {
        out << ", " << *it++;
    }
    out << " }";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &vec) {
    return __print_iterable(out, vec);
}

template<typename T, size_t Size>
ostream &operator<<(ostream &out, const array<T, Size> &arr) {
    return __print_iterable(out, arr);
}

template<typename T>
ostream &operator<<(ostream &out, const set<T> &set) {
    return __print_iterable(out, set);
}

template<typename T>
ostream &operator<<(ostream &out, const stack<T> &s) {
    out << "[";
    
    if (!s.empty()) {
        stack<T> copy = s;
        out << copy.top();
        copy.pop();

        while (!copy.empty()) {
            out << ", ";
            auto top = copy.top();
            out << top;
            copy.pop();
        }
    }

    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const queue<T> &q) {
    out << "[";
    
    if (!q.empty()) {
        queue<T> copy = q;
        out << copy.front();
        copy.pop();

        while (!copy.empty()) {
            out << ", ";
            auto front = copy.front();
            out << front;
            copy.pop();
        }
    }

    out << "]";
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, const priority_queue<T> &pq) {
    return __print_iterable(out, pq); // BUG
}

template<typename T>
ostream &operator<<(ostream &out, const deque<T> &deq) {
    return __print_iterable(out, deq); // BUG
}

template<typename K, typename V>
ostream &operator<<(ostream &out, const map<K, V> &map) {
    return __print_iterable(out, map);
}

template<typename K, typename V>
ostream &operator<<(ostream &out, const unordered_map<K, V> &map) {
    return __print_iterable(out, map);
}
#endif

#ifndef __gadgets__
#define __gadgets__

template<typename T>
struct CompareFn {
    virtual bool operator() (const T &a, const T &b); // returns false if a is first and b is second.
};

#endif
#endif

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int negativeNumCnt = 0;
        bool zeroContain = false;

        vi forward(n, 0);
        vi backward(n, 0);

        int currProduct = 1;

        // forward
        FOR(i, 0, n) {
            const int num = nums[i];
            if (num == 0) {
                zeroContain = true;
                currProduct = 1;
                continue;
            }

            currProduct *= num;
            forward[i] = currProduct;

            // maxProduct = max(maxProduct, num);
            
            // cnt negative num
            if (num < 0) {
                negativeNumCnt++;
            }
        }

        // backward
        currProduct = 1;
        FFORE(i, n - 1, 0) {
            const int num = nums[i];
            if (num == 0) {
                currProduct = 1;
                continue;
            }

            currProduct *= num;
            backward[i] = currProduct;
        }

        int maxProduct = max({ forward[n - 1], backward[0], forward[0], backward[n - 1] });

        if (zeroContain == false) {
            if (forward[0] != 0) {
            maxProduct = max(maxProduct, forward[n - 1] / forward[0]);
            }
            if (backward[n - 1] != 0) {
                maxProduct = max(maxProduct, backward[0] / backward[n - 1]);
            }
        }

        for (int i = 1; i < n - 1; ++i) {
            const int num = nums[i];
            
            maxProduct = max({maxProduct, forward[i - 1], backward[i + 1]});
            maxProduct = max({maxProduct, forward[i], backward[i]});

            if (num == 0) {
                maxProduct = max(maxProduct, 0);
            }
        }

        return maxProduct;
    }
};

// @lc code=end
int main() {

    Solution sol;
    vi nums1 { 0, 2 };
    vi nums2 { -2, 0, -1 };
    vi nums3 { -1,-2,-3,0 };
    vi nums4 { -3,-1,-1 };
    vi nums5 { -3,0,1,-2 };
    const int ans = sol.maxProduct(nums5);
    cout << ans << endl;
}