#include <bits/stdc++.h>
using namespace std; 

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(a) int(a.size())
#define endl "\n"
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<ll> vll; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
void read_vi(vi &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
void read_vll(vll &a, int n){for(int i=0; i<n; i++) cin >> a[i];}
const ll MOD = 1e9+7;


struct Carta {
    int e; 
    int p; 
    string n; 
};

struct Jugador {
    int p; 
    int l; 
};



void gamplay(vector<Carta>& j1, vector<Carta>& j2, Jugador& p1, Jugador& p2, int locacion){


    ll p_j1 = 0; 
    ll p_j2 = 0; 

    int sera1 = 0; 
    int sera2 = 0; 

    for(int i = 0; i < sz(j1); i++){
        if(j1[i].n == "thunderheart" && sz(j1) >= 4){
            j1[i].p = 12; 
        }

        if(j1[i].n == "zenith" && locacion == 2){
            j1[i].p += 5; 
        }

        if(j1[i].n == "seraphina")
            sera1 = i; 
    }

        for(int i = 0; i < sz(j2); i++){
        if(j2[i].n == "thunderheart" && sz(j2) >= 4){
            j2[i].p = 12; 
        }

        if(j2[i].n == "zenith" && locacion == 2){
            j2[i].p += 5; 
        }

        if(j2[i].n == "seraphina")
            sera2 = i; 
    }

    if(sera1){
        j1[sera1].p += sz(j1);
    }

    if(sera2){
        j2[sera2].p += sz(j2); 
    }

    for(auto c: j1){
        p_j1 += c.p; 
    }

    for(auto c: j2){
        p_j2 += c.p;
    }

    if(p_j1 > p_j2)
        p1.l += 1; 

    if(p_j2 > p_j1)
        p2.l += 1; 

    p1.p += p_j1; 
    p2.p += p_j2; 
}

void solve(){
    vector<vector<Carta>> juego(6, vector<Carta>()); 

    Carta shadow; 
    shadow.e = 4; 
    shadow.p = 6; 
    shadow.n = "shadow";

    Carta gale; 
    gale.e = 3; 
    gale.p = 5; 
    gale.n = "gale"; 

        Carta ranger; 
    ranger.e = 2; 
    ranger.p = 4; 
    ranger.n = "ranger";

    Carta anvil; 
    anvil.e = 5; 
    anvil.p = 7; 
    anvil.n = "anvil";

    Carta vexia; 
    vexia.e = 2; 
    vexia.p = 3; 
    vexia.n = "vexia";

    Carta guardin; 
    guardin.e = 6; 
    guardin.p = 8; 
    guardin.n = "guardian";

    Carta thunderheart; 
    thunderheart.e = 5; 
    thunderheart.p = 6; 
    thunderheart.n = "thunderheart";

    Carta frost; 
    guardin.e = 1;   
    guardin.p = 2; 
    frost.n = "frostwhisper";

    Carta voidclaw; 
    voidclaw.e = 1; 
    voidclaw.p = 3; 
    voidclaw.n = "voidclaw";

        Carta iron; 
    iron.e = 1; 
    iron.p = 3; 
    iron.n = "ironwood";


        Carta zenith; 
    zenith.e = 6; 
    zenith.p = 4; 
    zenith.n = "zenith"; 


        Carta sera; 
    sera.e = 1; 
    sera.p = 1;   
    sera.n = "seraphina"; 

    for(int i = 0; i < 6; i++){
        int x; cin >> x; 
        for(int j = 0; j < x; j++){
            string str; cin >> str; 
            transform(all(str), str.begin(), ::tolower); 

            if(str == "shadow")
                juego[i].pb(shadow); 

            if(str == "gale")
                juego[i].pb(gale); 

            if(str == "ranger")
                juego[i].pb(ranger);
            if(str == "anvil")
                juego[i].pb(anvil);
            if(str == "vexia")
                juego[i].pb(vexia);
            if(str == "guardian")
                juego[i].pb(guardin);
            if(str == "thunderheart")
                juego[i].pb(thunderheart);

            if(str == "frostwhisper")
                juego[i].pb(frost);

            if(str == "voidclaw")
                juego[i].pb(voidclaw);  

            if(str == "ironwood")
                juego[i].pb(iron);

            if(str == "zenith")
                juego[i].pb(zenith);

            if(str == "seraphina")
                juego[i].pb(sera);                                                                                              

                                                     
        }
    }


    Jugador j1; 
    j1.l = 0; 
    j1.p = 0; 
    Jugador j2; 
    j2.l = 0; 
    j2.p = 0;


    gamplay(juego[0], juego[1], j1, j2, 1); 
    gamplay(juego[2], juego[3], j1, j2, 2); 
    gamplay(juego[4], juego[5], j1, j2, 3); 

    if(j1.l > j2.l){
        cout << "Player 1" << endl; 
        return; 
    }

    if(j2.l > j1.l){
        cout << "Player 2" << endl; 
        return; 
    }

    if(j1.p > j2.p){
        cout << "Player 1" << endl; 
        return; 
    }

    if(j2.p > j1.p){
        cout << "Player 2" << endl; 
        return; 
    }

    cout << "Tie" << endl; 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    int t = 1; 

    while(t--){
        solve(); 
    }

    return 0; 
}