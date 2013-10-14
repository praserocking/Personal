/* DBMS Lab Tryout- Algo:BFS */
/*Debug it */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
char graph[50][50];
vector<int>ans;
int cnt;
void bfs(int i,int j){
	pair<int,int>tmp;
	cnt=0;
	queue<pair<int,int> >q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		for(int k=-1;k<=1;k++)
			for(int l=-1;l<=1;l++)
				if(graph[tmp.first+k][tmp.second+k]==graph[tmp.first][tmp.second]+1&&(k!=0&&l!=0)){
					cnt++;
					q.push(make_pair(tmp.first+k,tmp.second+k));
				}
		ans.push_back(cnt);
	}
}
int main(){
int r,c;
while(true){
	cin>>r>>c;
	if(r==0&&c==0)break;
	for(int i=0;i<r;i++)
		cin>>graph[i];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(graph[i][j]=='A')bfs(i,j);
	cout<<*max_element(ans.begin(),ans.end());
}
return 0;
}
