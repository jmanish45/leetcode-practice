class Solution {
public:
    int largestInteger(int num) {
       // num = 2314
       // swappig parity gives  = 4312
        vector<int> a ;
        while(num>0) {
            int digit = num%10;
            a.push_back(digit);
            num/=10;
        }
        reverse(a.begin(), a.end());
        //[1,2,3,4];
        int n = a.size();
        int i = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(a[i]%2==0  && a[j]%2==0) {
                    if(a[i]<a[j]) swap(a[i],a[j]);
                }
                else if(a[i]%2!=0 && a[j]%2!=0) {
                    if(a[i]<a[j]) swap(a[i],a[j]);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans*=10;
            ans+=a[i];
        }


        
    return ans;
    }
};