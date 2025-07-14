#include<iostream>
#include<string>
#include<vector>

using namespace std;
struct team
{
    public:

        string name;
        int score;
        team(string n , int s=1){
            name = n;
            score = s;
        }
        void inc(){
            score ++;
        }
};
void print(vector<team> t){
    for(auto i:t){
        cout << i.name << " " << i.score << "\n";
    }
}
int main(){
    int n;
    cin >> n;

    vector<team>teams;
    while(n--){
        string temp;
        cin >> temp;
        int exist = 0;
        for(team &t:teams){
            if(t.name == temp){
                t.inc();
                exist = 1;
            }
        }
        if(!exist){
            team nt(temp);
            teams.push_back(nt);
        }
        // print(teams);
    }
    team winner("abc" , -1);
    for(team t: teams){
        if(t.score > winner.score){
            winner.name = t.name;
            winner.score = t.score;
        }
    }
    cout << winner.name << "\n";
}