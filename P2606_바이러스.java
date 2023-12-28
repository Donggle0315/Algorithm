package baekjoon;

import java.util.ArrayList;
import java.util.Scanner;

public class P2606_바이러스 {
    static int computer;
    static int pair;
    static ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
    static boolean[] visited;

    public static void userInput(){
        Scanner sc = new Scanner(System.in);
        computer = Integer.valueOf(sc.nextLine());
        pair = Integer.valueOf(sc.nextLine());
        visited = new boolean[computer+1];
        for(int i=0;i<=computer;i++){
            edges.add(new ArrayList<>());
        }
        for(int i=0; i<pair; i++){
            String[] userinput = sc.nextLine().split(" ");
            int comA = Integer.valueOf(userinput[0]);
            int comB = Integer.valueOf(userinput[1]);

            edges.get(comA).add(comB);
            edges.get(comB).add(comA);
        }

        sc.close();
    }

    public static void userOutput(){
        int cnt = 0;
        for(boolean e : visited){
            if(e) cnt++;
        }
        cnt--;

        System.out.println(cnt);
    }

    public static void getInfectedCom(int com){
        visited[com] = true;

        for(int idx : edges.get(com)){
            if(!visited[idx]) getInfectedCom(idx);
        }
    }


    public static void main(String[] args) {
        userInput();
        getInfectedCom(1);
        userOutput();

    }
}
