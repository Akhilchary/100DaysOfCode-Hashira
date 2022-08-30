#include <bits/stdc++.h>
using namespace std;
          //function minimumGroups to calculate minimum number of Groups 
int minimumGroups(int awards[],int n,int k)
{
    sort(awards,awards+n);
    int i=1;     
    int group_count=1;   
    int min_element=awards[0];
    while(i<n)
    {      
        if(awards[i]-min_element<=k)
        { 
            i++;         
        }
        else
        {             
            group_count++;            
            min_element=awards[i];            
            i++;         
        }     
    }
    return group_count; 
}  
int main() 
{        
cout<<"Enter the size of awards array : ";
int size;
cin>>size;
int awards[size];          
cout<<"\nEnter the elements of awards array : ";
for(int i=0;i<size;i++)
{        
 cin>>awards[i];    
 }
int k;     
cout<<"\nEnter the value of k : ";     
cin>>k;
cout<<"\nMinumum number of groups will be "<<minimumGroups(awards,size,k);     
return 0; 
}