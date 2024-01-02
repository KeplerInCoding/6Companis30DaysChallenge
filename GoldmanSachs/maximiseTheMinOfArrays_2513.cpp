//medium

class Solution {
public:

    int gcd(int a, int b) { //a=3, b=2,,,,,a=4, b=6 (HCF)
        if (b == 0) 
            return a; 
        return gcd(b, a % b); 
    } 

    bool check(long long A, long long n1, long long B, long long n2, long long total){
        long long by_A = total/A; //A
        long long by_B = total/B; //B
        long long LCM = (A*B)/gcd(A,B); //LCM
        long long by_both = total/LCM;  //A*B
        cout<<"total : "<<total<<"  by_A : "<<by_A<<"  by_B : "<<by_B<<"  by_both : "<<by_both<<endl;
        long long notA = total - by_A; //!A
        long long notB = total - by_B;  //!B
        long long notAandB = total - by_both; //!(A*B)
        cout<<"notAandB : "<<notAandB<<endl<<endl;
        if(n1<=notA && n2<=notB && (n1+n2)<=notAandB){
            cout<<"TRUE"<<endl<<endl;
            return true;
        }
        return false;
    }

    long long minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
        long long s = 1;
        long long e = divisor1*uniqueCnt1 + divisor2*uniqueCnt2;
        long long ans=-1;
        
        while(s<=e){
            long long mid = (s+e)/2;
            if(check(divisor1, uniqueCnt1, divisor2, uniqueCnt2, mid)){
                ans=mid;
                cout<<"mid : "<<endl;
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};