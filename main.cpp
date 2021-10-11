#include <iostream>
#include <vector>
using namespace std;

//第一题，两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res={0,0};
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            if (nums[i]+nums[j]==target&&i!=j)
            {
                res={i,j};
                break;
            }
        }
    }
    return res;
}
//第八题
int reverse(int x){
    long y=0,t=0,sign=1,a=0;
    a=x;
    if(a<0){
        sign=-sign;
        a=-a;
    }
    while(a>9){
        t=a%10;
        y=y*10+t;
        a=a/10;
    }
    y=y*10+a;
    y=sign*y;
    return (int)y==y?int(y):0;
}
int reverse2(int x){
    long t=0;
    while(x!=0){
        t=t*10+x%10;
        x/=10;
    }
    return (int)t==t?int(t):0;
}
//441(每日一题)数字转换成英文
int arrangeCoins(int n){
    int rows=0;
    int rest=n;
    while(rest>rows){
        rows++;
        rest-=rows;
    }
    return rows;
}
string buildNum(int t);

string numberToWords(int num){
    string add[]={"","thousand","million","billion"};

    int t=0;
    string ans;
    if(num==0) return "zero";

    t = num % 1000;
    num /= 1000;
    if (num == 0) return buildNum(t);
    else if(t!=0) ans= " "+buildNum(t);

    t=num%1000;
    num/=1000;
    if (num == 0 ) return buildNum(t)+" "+add[1]+ans;
    else if(t!=0) ans= " "+buildNum(t)+" "+add[1]+ans;

    t=num%1000;
    num/=1000;
    if (num == 0) return buildNum(t)+" "+add[2]+ans;
    else if(t!=0) ans= " "+buildNum(t)+" "+add[2]+ans;

    t=num%1000;
    num/=1000;
    ans= buildNum(t)+" "+add[3]+ans;
    return ans;
}
string buildNum(int t){
    string low[]={"","one","two","three","four","five","six","seven","eight","nine"};
    string mid[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    string high[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};

    string temp;

    if(t==0) return "zero";
    if(t%100==0) return low[t/100]+" hundred";
    int part=0;
    part=t/100;
    t%=100;
    if(part!=0){
        temp=low[part]+" hundred ";
    }
    part=t/10;
    t%=10;
    if(part==1) temp=temp+mid[t];
    else if(part==0) temp=temp+low[t];
    else if(t!=0){
        temp=temp+high[part]+" "+low[t];
    }
    else temp=temp+high[part];
    return temp;
}

int main() {
    cout<<numberToWords(1000010);
    return 0;
}
