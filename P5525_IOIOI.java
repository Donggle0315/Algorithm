package baekjoon;

import java.util.Scanner;

public class P5525_IOIOI {
    static int n;
    static int m;
    static String sentence;
    static int ans = 0;

    public static void userInput(){
        Scanner sc = new Scanner(System.in);
        n = Integer.valueOf(sc.nextLine());
        m = Integer.valueOf(sc.nextLine());
        sentence = sc.nextLine();

        sc.close();
    }

    public static void userOutput(){
        System.out.println(ans);
    }

    public static void getIOI(){
        char before = sentence.charAt(0);
        int cnt = before=='I' ? 1 : 0;
        for(int i=1; i<sentence.length(); i++){
            char now = sentence.charAt(i);

            if(before != now){
                cnt++;
                if(cnt >= 2*n+1 && now == 'I'){
                    ans++;
                }
            }

            else{
                cnt = now =='I' ? 1 : 0;
            }

            before = now;
            //System.out.println("cnt : " + i + " word : " + before + " cnt : " + cnt + " ans : " + ans);

        }
    }

    public static void main(String[] args) {
        userInput();
        getIOI();
        userOutput();
    }
}
