//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<bool>v;
    void check_prime(vector<bool>&v,int N)
    {
        int i,j;
        for(i=2;(i*i)<=N;i++)
        {
            for(j=2*i;j<=N;j=j+i)
            {
                v[j]=false;
            }
        }
        return;
    }
    vector<int> sieveOfEratosthenes(int N)
    {
         int i;
        for(i=0;i<=N;i++)
        {
            v.push_back(true);
        }
        vector<int>primes;
        check_prime(v,N);
        for(i=2;i<=N;i++)
        {
            if(i!=1 && i!=0 && v[i]==true)
            {
                primes.push_back(i);
            }
        }
        return primes;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends