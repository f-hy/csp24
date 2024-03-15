/**FAIL
 * @file 2312.cc
 * @author Friendy (friend0@qq.com)
 * @date 2024/3/9
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
const int maxn = 1e5 + 1;
int mod = 998244353;
int n, m, v, cl, cr;
const int E[] = {1, 0, 1, 0};

struct sarr {
    int arr[4] = {0};

    sarr &operator=(const int arrs[4]) { rep(i, 0, 3) arr[i] = arrs[i]; }
};

struct inst {
    int v;
    sarr arr;
//    inst(int vv=0, int *a={0,0,0,0}) : v(vv) { rep(i, 0, 3)arr[i] = a[i]; }
};
vector<sarr> va;//cache dq
deque<sarr> dq;//compute dq


void _print(int *arr, int mm = 2, int nn = 2) {
    rep(i, 0, mm - 1) {
        rep(j, 0, nn - 1) {
            cout << arr[nn * i + j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void print(inst ins) {
    rep(i, 0, 3) cout << ins.arr.arr[i] << ' ';
    cout << '\n';
}

void mult(int *a, int *b, int *c, int mm = 2, int ss = 2, int nn = 2) {
    int z;
    rep(i, 0, mm - 1) rep(j, 0, nn - 1) {
            z = nn * i + j;
            rep(k, 0, ss - 1)c[z] += a[ss * i + k] * b[nn * k + j];
        }
}

void stepn(vector<inst> &insts, int i) {
    cin >> insts[i].v;
    if (insts[i].v == 3) return;
    rep(j, 0, 3) cin >> insts[i].arr.arr[j];
}


void getpwd(vector<inst> &insts, int l, int r) {
    int pv;
    rep(i, l, r) {//获取dq
        switch (insts[i].v) {
            case 1: {
                dq.emplace_front(insts[i].arr);
                mult(va[i - 1].arr, insts[i].arr.arr, va[i].arr);
                break;
            }
            case 2: {
                dq.emplace_back(insts[i].arr);
                mult(va[i - 1].arr, insts[i].arr.arr, va[i].arr);
                break;
            }
            case 3: {
                if (dq.empty()) {
                    va[i] = E;
                    break;
                }
                pv = insts[i - 1].v;
                if (pv != 3) {
                    if (pv == 1) dq.pop_front();
                    else dq.pop_back();
                    if (i - 2 < l) va[i] = E;
                    else va[i] = va[i - 2].arr;
                } else {//TODO 前面连续多个3时
                    break;
                }
                break;
            }
        }
    }
}

void steps(vector<inst> &insts) {
    int v, vv, l, r;
    rep(i, 0, n - 1) stepn(insts, i);
    rep(i, 0, m - 1) {
        cin >> v;
        if (v == 1) {
            cin >> vv;
            stepn(insts, vv);
        } else {
            cin >> l >> r;
            getpwd(insts, l, r);
            print(insts[r]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    file(data);
    cin >> n >> m;
    vector<inst> insts(n);
    steps(insts);
    return 0;
}