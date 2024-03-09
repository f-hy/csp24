/**
 * @file tmp.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/7
 * @version 0.1
 * @brief csp competition
 * @github https://github.com/f-hy
 * @gitee https://gitee.com/friendhy
 * @copyright Copyright (c) 2024
 */
#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i, s, t) for(int i=s;i<=t;i++)
#define dwn(i, s, t) for(int i=s;i>=t;i--)
#define ite(it, s, e) for(auto it=s;it!=e;++it)

template<class T>
bool cmp(T x, T y) { return x > y; }//降序
template<typename T>
class ccmp {
public:
    bool operator()(T x, T y) { return x > y; }
};

template<typename T>
struct scmp {
    bool operator()(T x, T y) { return x > y; }
};

void _tcmp(bool _print = false) {
    set<int> ct;
    set<int, greater<int>> ctg;
    set<int, less<int>> ctl;
    set<int, scmp<int>> ctc;//ccmp,scmp
    rep(i, 0, 5) {
        ct.emplace((5 * i) % 7);
        ctg.emplace((5 * i) % 7);
        ctl.emplace((5 * i) % 7);
        ctc.emplace((5 * i) % 7);
    }
    if (_print) {
        for (auto &c: ct) cout << c << ' ';
        cout << '\n';
        for (auto &c: ctg) cout << c << ' ';
        cout << '\n';
        for (auto &c: ctl) cout << c << ' ';
        cout << '\n';
        for (auto &c: ctc) cout << c << ' ';
        cout << '\n';
    }
}

void _tpq() {
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, 0, 5) pq.emplace(i);
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

void _treverse() {
    int a[] = {1, 3, 4, 6, 3, 7, 9};
    cout << &a << endl;
    reverse(a, a + sizeof a / sizeof(int));
    cout << &a << endl;
    rep(i, 0, sizeof a / sizeof(int) - 1) cout << a[i] << ' ';
}

void _tCharNum() {
    string s = "5456";
    char cs[] = "stdio123.h";//={'s', 't', 'd', 'i', 'o', '1', '2', '3', '.', 'h', '\0'}
    cout << "cs: " << cs << endl;
    string ss(cs, cs + sizeof cs / sizeof(char));//assign
    cout << "ss: " << ss << endl;
    int n = atoi(s.c_str());
    int nn = stoi(s);
    cout << s << ' ' << n << '\n';
    string upp, low;
    upp.resize(ss.size()), low.resize(ss.size());
    transform(ss.begin(), ss.end(), upp.begin(), ::toupper);
    cout << "upp: " << upp << endl;
    transform(ss.begin(), ss.end(), low.begin(), ::tolower);
    cout << "low: " << low << endl;
    cout << char(::toupper('a')) << endl;

    string pi = "pi is " + to_string(3.1415926);//3.141593
    string perfect = to_string(1 + 2 + 4 + 7 + 14) + " is a perfect number";//28
    string aaa = to_string(0x42ff);//17151
    cout << pi << '\n';
    cout << perfect << '\n';
    cout << aaa << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    //file(data);
//    _tcmp(true);
//    _tpq();
//    _treverse();
    _tCharNum();
    return 0;
}