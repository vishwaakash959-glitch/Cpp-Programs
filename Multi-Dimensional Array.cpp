#include<iostream>
using namespace std;
int main()
{
int a[10][10],r,c,i,j;
cout<<"Enter number of rows and columns:";
cin>>r>>c;
cout<<"Enter the matrix elements:\n";
for(i=0;i<r;i++)
{
for(j=0;j<c;i++)
{
cin>>a[i][j];
}
}
cout<<"\n Matrix Elements are:\n";
for(i=0;i<r;i++)
{
for(j=0;j<r;j++0
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}
return 0;
}
