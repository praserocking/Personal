/*
Problem : ISOLA - BATTLE OF BOTS - HACKEREARTH
Author: prassi
Date: 17-9-2015
*/

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int maze[7][7];
int player;
pair<int,int> temp[8] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0),make_pair(1,-1),make_pair(-1,1),make_pair(1,1),make_pair(-1,-1)};
vector<pair<int,int> > moves(temp,temp+(sizeof(temp)/sizeof(pair<int,int>)));
pair<int,int> _for,_foe;

int opp(int player){
    return player==1?2:1;
}

void read_data(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin>>maze[i][j];
        }
    }
    cin>>player;
}

void find_positions(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(maze[i][j] == player)
                _for = make_pair(i,j);
            if(maze[i][j] == opp(player))
                _foe = make_pair(i,j);
        }
    }
}

bool is_ok(int i,int j){
    return (i<7 && i>=0) && (j<7 && j>=0);
}

bool valid(int i,int j){
    return is_ok(i,j) && maze[i][j] == 0;
}

int score(int i,int j,int level){
    int _scr = 0;
    for(int x=0;x<moves.size();x++)
        if(valid((moves[x].first+i),(moves[x].second+j))){
            _scr++;
        }

    if(level == 0){
        return _scr;
    }else{
        for(int x=0;x<moves.size();x++)
            if(valid((moves[x].first+i),(moves[x].second+j))){
                _scr += score((moves[x].first+i),(moves[x].second+j),level - 1);
            }
        return _scr;
    }
}

pair<int,int> return_good_move(int i,int j){
    int max_score = INT_MIN,tmp,ii,jj;
    pair<int,int> retval;
    vector<pair<int,int> > diagonal,parallel;

    for(int x=0;x<moves.size();x++){
        if(valid((i+moves[x].first),(j+moves[x].second))){

            ii=i+moves[x].first;
            jj=j+moves[x].second;

            tmp = score(ii,jj,7);

            if(tmp>max_score){
                max_score = tmp;
                retval = make_pair(ii,jj);
            }
        }
    }
    return retval;
}

int main(){
    read_data();
    find_positions();

    pair<int,int> _for_move,_foe_move;

    _for_move = return_good_move(_for.first,_for.second);

    maze[_for.first][_for.second] = 0;
    maze[_for_move.first][_for_move.second] = player;

    _foe_move = return_good_move(_foe.first,_foe.second);

    cout<<_for_move.first<<" "<<_for_move.second<<endl;
    cout<<_foe_move.first<<" "<<_foe_move.second<<endl;

    return 0;
}
