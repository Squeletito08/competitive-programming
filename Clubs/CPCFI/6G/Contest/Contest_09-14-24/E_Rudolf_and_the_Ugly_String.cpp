#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}


#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string& pat, int M, vector<int>& lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMPSearch(string& pat, string& txt)
{
    int M = pat.length();
    int N = txt.length();

    vector<int> lps(M);

    vector<int> result;

    computeLPSArray(pat, M, lps);

    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

void solve(){
    int n; 
    int x; 
    cin >> n; 
    string s; 
    cin >> s; 

    string p = "pie";
    string m = "map"; 
    string mp = "mapie"; 

    vector<int> pie = KMPSearch(p, s);
    vector<int> map = KMPSearch(m, s);
    vector<int> mapie = KMPSearch(mp, s);

    cout << map.size() + pie.size() - mapie.size() << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int t = 1; 
    cin >> t; 

    while(t--){
        solve(); 
    }

    return 0; 
}