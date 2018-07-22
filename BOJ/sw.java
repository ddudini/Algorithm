import java.util.Scanner;
import java.io.FileInputStream;

public class A_2{
	public static int N, ans;
	public static int[][] map;
	public static int[] dir_x = {0,  0,  1, 1, 1, 0, -1, -1, -1};
	public static int[] dir_y = {0, -1, -1, 0, 1, 1,  1,  0, -1};

	public static void solve(){
		boolean ground = false, mountain = false, water = false, waste = false;

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(map[i][j] != 0){
					ground = false;
					mountain = false;
					water = false;
					waste = false;

					for(int k=0;k<9;k++){
						int nx = i + dir_x[k];
						int ny = j + dir_y[k];
						if(nx >= 0 && nx < N && ny >= 0 && ny < N){
							if(map[nx][ny] == 1)
								water = true;
							else if(map[nx][ny] == 2)
								mountain = true;
							else if(map[nx][ny] == 3)
								ground = true;
							else if(map[nx][ny] == 0){
								waste = true;
								break;
							}
						}
					}
				}
				if(!waste && water && mountain && ground){
					//System.out.println("i: " + i + " j: " + j);
					ans++;
				}
			}
		}
	}

	public static void main(String[] args) throws Exception{
		System.setIn(new FileInputStream("A_2.txt"));
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for(int total_case=1;total_case<=T;total_case++){
			N = sc.nextInt();
			map = new int[N][N];

			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					map[i][j] = sc.nextInt();
				}
			}

			ans = 0;
			solve();
			
			System.out.println("#" + total_case + " " + ans);
		}
	}
}