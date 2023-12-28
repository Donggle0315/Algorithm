package baekjoon;

import java.util.Scanner;

public class P20529_가장가까운세사람의심리적거리 {
    public static void userInput(){
        Scanner sc = new Scanner(System.in);
        int tc = Integer.valueOf(sc.nextLine());

        while(tc-- > 0 ){
            int n = Integer.valueOf(sc.nextLine());
            String[] mbtis = sc.nextLine().split(" ");
            //mbti별 개수를 담은 리스트[16]에 저장
            int[] mbtiNum = new int[16];
            for(String e : mbtis){
                mbtiNum[convertMBTI(e)]++;
            }

            int ans = getNearestDistance(n,mbtiNum);
            System.out.println(ans);
        }

        sc.close();
    }

    public static int getNearestDistance(int n, int[] mbtis) {
        int minDist = 100001;

        //삼중 반복으로 찾아도 될
        for(int i=0; i<16; i++){
            if(mbtis[i] <= 0) continue;
            mbtis[i]--;
            for(int j=0; j<16; j++){
                if(mbtis[j] <= 0) continue;
                mbtis[j]--;
                for(int k=0; k<16; k++){
                    if(mbtis[k] <= 0) continue;
                    mbtis[k]--;
                    int dist = getDistance(i,j) + getDistance(j,k) + getDistance(k,i);
                    if(dist < minDist) minDist = dist;
                    mbtis[k]++;

                }
                mbtis[j]++;
            }
            mbtis[i]++;
        }

        return minDist;
    }

    public static int getDistance(int a, int b){
        int exclusiveDist = a^b;
        int ans = 0;
        if((exclusiveDist & 1) == 1) ans++;
        if((exclusiveDist & 2) == 2) ans++;
        if((exclusiveDist & 4) == 4) ans++;
        if((exclusiveDist & 8) == 8) ans++;

        return ans;
    }

    public static int convertMBTI(String mbti) {
        int bin = 0;
        if(mbti.charAt(0) == 'E') bin |= 8;
        if(mbti.charAt(1) == 'S') bin |= 4;
        if(mbti.charAt(2) == 'T') bin |= 2;
        if(mbti.charAt(3) == 'J') bin |= 1;
        //System.out.println("mbti : " + mbti + " num : " + bin);
        return bin;
    }


    public static void main(String[] args) {
        userInput();
    }
}
