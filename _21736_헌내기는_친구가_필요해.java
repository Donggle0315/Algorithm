import java.util.Scanner;

public class _21736_헌내기는_친구가_필요해{
    static int n,m;
    static String[] campus;
    static boolean[][] visited;
    static int meet_people = 0;
    static int[][] dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        n = sc.nextInt();
        m = sc.nextInt();
        campus =  new String[n];
        visited = new boolean[n][m];
        String tmp = sc.nextLine();

        int start_row = 0, start_col = 0; 
        for(int i=0; i<n; i++){
            campus[i] = sc.nextLine();
            for(int j=0; j<campus[i].length(); j++){
                    if(campus[i].charAt(j) == 'I'){
                        start_row = i;
                        start_col = j;
                    }
            }
        }

        dfs(start_row, start_col);

        sc.close();
        if(meet_people == 0) System.out.println("TT");
        else System.out.println(meet_people);
    }
    
    public static void dfs(int row, int col){
        visited[row][col] = true;
        if(campus[row].charAt(col) == 'P') meet_people++;

        for(int i=0; i<4; i++){
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];

            if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= m) continue;
            if(visited[next_row][next_col] || campus[next_row].charAt(next_col) == 'X') continue;

            dfs(next_row,next_col);
        }
    }
}