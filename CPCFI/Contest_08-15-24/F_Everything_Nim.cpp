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


void solve(){

    int n; 
    cin >> n;

    set<int> nums; 

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        nums.insert(x);
    }


    bool alice = true; 

    if(nums.size() == 1){
        int num = *nums.begin();

        if(num % 2 != 0){
            alice = false;
        }

        if(alice){
            cout << "Alice"; 
        }
        else{
            cout << "Bob";
        }

        cout << endl; 
    }
    else{
        auto primero = nums.begin();

        int quitar = *primero; 

        int max = *nums.end(); 

        nums.erase(primero); 
        
        max -= quitar;


        while(nums.size() != 1){

            primero = nums.begin(); 

            int dif = *primero - quitar; 
            max -= dif; 

            if(max <= 0){
                break; 
            }

            quitar += dif; 

            alice = !alice; 
        }

        auto ultimo = nums.begin(); 


        if(ultimo != nums.end()){
            if(*ultimo % 2 == 0){
                alice = true;
            }
            else{
                alice = false; 
            }

            if(alice){
                cout << "Alice"; 
            }
            else{
                cout << "Bob";
            }
        }
        else{
            if(alice){
                cout << "Alice"; 
            }
            else{
                cout << "Bob";
            }
        }
    }

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