#include<bits/stdc++.h>
using namespace std;

struct node{
    int cnt,val;
    node(int x){
        cnt=val=0;
    }
    bool operator <(const node &y)const{
        return cnt>y.cnt;
    }
};

class Solution {
public:
    #define FOR(i,a,b) for(int i=(a);i<=(b),++i)
    const int maxn=1e5+7;
    int minimumOperations(vector<int>& nums) {
        vector<node> buck1(maxn,0);
        vector<node> buck2(maxn,0);
        int n=nums.size();
        for(int i=0;i<n;i+=2){
            buck1[nums[i]].val=nums[i];
            ++buck1[nums[i]].cnt;
        }
        for(int i=1;i<n;i+=2){
            buck2[nums[i]].val=nums[i];
            ++buck2[nums[i]].cnt;
        }
        int max1,sec1,max2,sec2;
        /*
        FOR(i,0,maxn){
            num1=max(num1,buck1[i]);
            num2=max(num2,buck2[i]);
        }
        */
        sort(buck1.begin(),buck1.end());
        sort(buck2.begin(),buck2.end());
        if(buck1[0].val!=buck2[0].val){
            return n-buck1[0].cnt-buck2[0].cnt;
        }
        else{
            if(buck1[1].val>buck2[1].val){
                return n-buck1[0].cnt-buck1[1].cnt;
            }
            else{
                return n-buck1[0].cnt-buck2[1].cnt;
            }
        }
    }
};

int main(){
    vector<int> nums(20);
    nums={3,1,3,2,4,3};
    Solution ans;
    int bns=ans.minimumOperations(nums);
    cout<<bns;
    return 0;
}
