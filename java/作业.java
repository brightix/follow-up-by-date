import java.util.Scanner;
class Solution
{
    public static void main(String[] args)
    {
        test4();
    }

    public static void test1(String[] args)
    {
        int a = (int)(Math.random()*9);
        int b = (int)(Math.random()*9);
        int ans = a*b;
        System.out.print(a+"*"+b+"=");
        Scanner kb = new Scanner(System.in);
        int input = kb.nextInt();
        kb.close();
        if(input == ans)
        {
            System.out.println("你答对了!");
        }
        else
        {
            System.out.println("回答错误!正确答案是: "+ ans);
        }
    }
    public static void gradeSort(){
        Scanner kb = new Scanner(System.in);
        int grade = kb.nextInt();
        if(grade<60)
            System.out.println("不及格");
        else if(grade < 70)
            System.out.println("及格");
        else if(grade < 80)
            System.out.println("中等");
        else if(grade < 90)
            System.out.println("良好");
        else if(grade <= 100)
            System.out.println("优秀");
    }

    public static void randomCom(){
        while(true){
            int a =(int)(Math.random()*20);
            int b =(int)(Math.random()*20);
            int symbal = (int)(Math.random()*3);

            switch(symbal){
                case 0: System.out.println(a + " + " + b + " = " );
                    break;
                case 1: System.out.println(a + " - " + b + " = " );
                    break;
                case 2: System.out.println(a + " x " + b + " = " );
                    break;

            }
            Scanner kb = new Scanner(System.in);
            int input = kb.nextInt();
            switch(symbal){
                case 0:
                    if(input == a+b) System.out.println("回答正确！");
                    else             System.out.println("很遗憾，回答错误！");
                    break;
                case 1:
                    if(input == a-b) System.out.println("回答正确！");
                    else             System.out.println("很遗憾，回答错误！");
                    break;
                case 2:
                    if(input == a*b) System.out.println("回答正确！");
                    else             System.out.println("很遗憾，回答错误！");
                    break;
            }
        }
    }  
    public static void test2(){
        Scanner kb = new Scanner(System.in);
        int h = kb.nextInt();
        int r = kb.nextInt();
        double pi = 3.14;
        double ans = 20000.0/(pi*r*r*h);
        System.out.println((ans>(int)ans?(int)ans+1:(int)ans));
    }
    public static void test3(){
        Scanner kb = new Scanner(System.in);
        int a = kb.nextInt();
        int b = kb.nextInt();
        int c = kb.nextInt();
        System.out.println(a > b ? (a>c?a:c):b>c?b:c);
    }
    public static void test4(){
        Scanner kb = new Scanner(System.in);
        int h = kb.nextInt();
        int m = kb.nextInt();
        int s = kb.nextInt();
        if(++s == 60){
            s = 0;
            if(++m == 60){
                m = 0;
                if(++h == 24){
                    h = 0;
                }
            }
        }
        System.out.printf("%02d:%02d:%02d",h,m,s);
        kb.close();
    }
};
