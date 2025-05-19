class palindrome
{
public static void main(String args[])
{
int n=111, rev=0,sum=0;
while(n>0)
{
rev=n%10;
sum=sum*10+rev;
n=n/10;
}
System.out.println("reverse number="+sum);
if(n==sum)
{
System.out.println("the number is palindrome");
}
else{
System.out.println("the number is not palindrome");
}
}}
