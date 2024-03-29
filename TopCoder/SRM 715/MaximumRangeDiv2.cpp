#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define rep(n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define pb(x) push_back(x)
#define INF 1410065408
using namespace std;

class MaximumRangeDiv2 {
    public:
    int findMax(string s) {
        int n = (int)s.length();
        vector<int> v;
        v.pb(0);
        if(s[0] == '+'){
            v.pb(1);
        }else{
            v.pb(-1);
        }
        cout << v.back() << " ";
        rep(n-2){
            if(s[i] == s[i+2] && s[i] != s[i+1]){

            }else{
                if(s[i+1] == '+'){
                    v.pb(v.back()+1);
                }else{
                    v.pb(v.back()-1);
                }
                cout << v.back() << " ";
            }
        }
        if(n > 1 && s.back() == '+'){
            v.pb(v.back()+1);
        }else{
            v.pb(v.back()-1);
        }
        cout << v.back() << endl;
        return *max_element(all(v)) - *min_element(all(v));
    }
};

// CUT begin
ifstream data("MaximumRangeDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    MaximumRangeDiv2 *instance = new MaximumRangeDiv2();
    int __result = instance->findMax(s);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1498523265;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "MaximumRangeDiv2 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
