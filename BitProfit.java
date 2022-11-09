package X_CompanyQuestions.BNY;

import java.util.Arrays;
import java.util.Scanner;

public class BitProfit {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int in[]=new int[n];
        int p[]=new int[n];
        for(int i=0;i<n;i++)
        {
            in[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            p[i]=sc.nextInt();
        }
        int dp[][]=new int[n+1][2*k];
        for(int arr[]:dp)
            Arrays.fill(arr,-1);
        System.out.println(rec(0,0,dp, in,p, k));
    }
    public static int rec(int i, int j, int dp[][], int in[], int p[], int k)
    {
        int n=in.length;
        if(i==n)
        {
            if(j<=k)
            {
                return 0;
            }
            return  Integer.MIN_VALUE;
        }
        if(j>k)
        {
            return Integer.MIN_VALUE;
        }
        if((j|in[i])<=k)
        return Math.max(rec(i+1, j|in[i],dp,in,p,k)+p[i], rec(i+1, j, dp,in,p,k));
        return rec(i+1, j, dp,in,p,k);
    }
}
