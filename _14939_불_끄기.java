import java.util.Scanner;

public class _14939_불_끄기 {
    static boolean[][] arr = new boolean[10][10];
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args){
        for(int i=0; i<10; i++){
            String line = sc.nextLine();
            for(int j=0; j<line.length(); j++){
                if(line.charAt(j) == '0') arr[i][j] = true;
            }
        }

        for(int i=0; i<10; i++){//첫번째 줄

        }
    }
}
