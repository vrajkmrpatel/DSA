#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define pii pair<int, int>
#define pss pair<string, string>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define sti stack<int>
#define stc stack<char>
#define mii map<int, int>
#define mci map<char, int>
#define msi map<string, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define mod1 1e9 + 7
#define inf 1e18
#define fori(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define forle(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define forge(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define forn(a, b, c) for (int(a) = (b); (a) != (c); ++(a))
#define maxf(a, b) a = max(a, b)
#define minf(a, b) a = min(a, b)
#define reset(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allg(v) v.begin(), v.end(), greater<int>()
#define alla(arr, sz) arr, arr + sz
#define lb(a) lower_bound(all(v), a)
#define ub(a) upper_bound(all(v), a)
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define maxa(arr, sz) *max_element(alla(arr, sz))
#define mina(arr, sz) *min_element(alla(arr, sz))
#define sizev(v) (int)v.size()
#define sorta(v) sort(all(v))
#define sortd(v) sort(allg(v))
#define reversev(v) reverse(all(v))
#define mk(arr, n, type) type *arr = new type[n]
#define sortarr(arr, sz) sort(alla(arr, sz))
#define reversearr(arr, sz) reverse(alla(arr, sz))
#define permute next_permutation
#define sb(n) __builtin_popcount(n)
#define zb(n) __builtin_ctzll(n)
#define ps(x, y) fixed << setprecision(y) << x
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define nl cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define pbds tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

/*---------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------*/

void hsp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// freopen("debug.txt", "w", stderr);
#endif
}

/*---------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------*/

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*---------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------*/

int gcd(int a, int b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int expo(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(int a, int b, int *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    int x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
int mminv(int a, int b)
{
    int arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
bool revsort(int a, int b) { return a > b; }
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int combination(int n, int r, int m, int *fact, int *ifact)
{
    int val1 = fact[n];
    int val2 = ifact[n - r];
    int val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vi sieve(int n)
{
    int *arr = new int[n + 1]();
    vi vect;
    forle(i, 2, n) if (arr[i] == 0)
    {
        vect.pb(i);
        for (int j = 2 * i; j <= n; j += i)
            arr[j] = 1;
    }
    return vect;
}
int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int mod_div(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
int phin(int n)
{
    int number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
auto find_next_smaller(vector<int> v, const int x)
{
    std::sort(v.begin(), v.end());
    auto it = std::lower_bound(v.begin(), v.end(), x);
    if (it == v.end())
    {
        it = (v.rbegin() + 1).base();
    }
    else if (it != v.begin() && *it > x)
    {
        --it;
    }
    return *it;
}
void leftRotate(int arr[], int d, int n)
{
    d = d % n;
    int g_c_d;
    gcd(d, n);
    fori(i, 0, g_c_d)
    {
        int temp = arr[i];
        int j = i;
        while (1)
        {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

/*---------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------*/

signed main()
{
    hsp();

    return 0;
}