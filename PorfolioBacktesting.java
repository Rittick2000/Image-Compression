package X_CompanyQuestions.BNY;

import java.util.Scanner;

public class PorfolioBacktesting {
    static int max=0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int p[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        System.out.println(rec(p, n, k, 0,0));

    }
    static  int rec(int p[], int n, int k, int i, int j)
    {
        if(i==n)
        {
            if(j>=k)
            {
                //max=Math.max(max, sum);
                return  0;

            }
            else
                return -1000000;
        }
        if(p[i]>=0)
        {
            return p[i]+rec(p, n, k,i+1, j );
        }
        else
        {
            return Math.max(p[i]+rec(p, n, k, i+1, j), 0 + rec(p,n,k, i+1, j-1));
        }
    }
}




































            
            
            
            
                
