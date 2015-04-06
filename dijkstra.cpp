#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
#define v 7
int add;
int am[7][7]={		{0,0,0,0,0,0,0},
					{0,0,4,5,0,0,0},
			     	{0,4,0,0,6,6,0},
					{0,5,0,0,3,4,0},
					{0,0,6,3,0,0,1},
					{0,0,6,4,0,0,6}};
	
	int permanent[v+1],neighbour[v+1];
	int parentN[v+1],parentP[v+1];
	int vertexN[v+1],vertexP[v+1];
	int perm[v];
	
void addtoneighbour(int a,int b,int c,int neighbour[v+1])
	{
	add=neighbour[b];


	if((neighbour[c] >(add+a) && perm[c]!=1)|| (neighbour[c]==0 && perm[c]!=1))
		{
			
		neighbour[c]=a+add;
		parentN[c]=b;
		vertexN[c]=c;
		cout<<"-"<<endl<<neighbour[c]<<endl;
		}
	}
void addtopermanent(int loc,int neighbour[v+1])
	{
		permanent[loc]=neighbour[loc];
		parentP[loc]=parentN[loc];
		vertexP[loc]=vertexN[loc];
	
		
	}
int shortest(int neighbour[v+1])
	{
	int sm=200022;
	int loc=1;
		for(int i=2;i<=v;i++)
		{
			if(sm>neighbour[i] && neighbour[i]!=0 && perm[i]!=1)
			{
				sm=neighbour[i];
				loc=i;
				
			}
			
		}
		perm[loc]=1;
	
		return loc; 
	}
int check()
	{
		int flag=0;
		for(int i=1;i<v;i++)
		{
			if(permanent[i]==0)
			flag=1;
		}
	if(flag==1)
	return 0;
	else return 1;
	}
void print()
{
	for(int i=1;i<=v;i++)
	{
		cout<<neighbour[i]<<" ";
	}
	cout<<endl;
	
	for(int i=1;i<=v;i++)
	{
		cout<<perm[i]<<"   ";
	}
	cout<<endl<<endl;
	
	for(int i=1;i<=v;i++)
	{
		cout<<permanent[i]<<"   ";
	}
	cout<<endl<<endl;
}
//------------------MAIN FUNCTION----------------------//
int main()
{
int h,k=1,p=1;
perm[1]=1;
do
{
	
	for(int j=1;j<=v;j++)
	{
		if(am[k][j]!=0 )
		{
			
			int aa=am[k][j];
			
			addtoneighbour(aa,k,j,neighbour);
			print();
		}
	}
	
	int l=shortest(neighbour);	
	addtopermanent(l,neighbour);
	k=l;
	cout<<neighbour[k]<<"grg"<<endl;
	 
	p++;
	h=check();		
	
}while(p!=10);
cout<<endl;
for(int i=1;i<=v;i++)
	{
		cout<<permanent[i];
		cout<<parentP[i];
		cout<<vertexP[i]<<endl;
	}
	
	int start,end,mid;
	cin>>start>>end;
	while(mid!=1)
	{
       for(int i=1;i<=v;i++)
       {
          if(vertexP[i] == end)
          {
             mid = i;
             cout<<vertexP[i];
             end = parentP[i];
          }
         
       }
    }      
   cout<<start;          
	system("pause");
}

