import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {


        // 가로 세로 100 + 100 = 200
        // 200 * 100 = 20,000 번
        // 완탐 가능
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][N];
        boolean[][] installed = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ret = 0;

        // 단순하게 가자
        // 내가 진짜 경사로를 올라가야 한다고 생각하자.
        // 낭떠러지나 절벽을 만나면.
        // 낭떠러지라면 멀리 보고 설치 할 수 있는지를 확인한다.
        // 절벽이라면 뒤를 보고 설치 할 수 있는지를 확인한다.
        // 행먼저 하자
        TEST:
        for (int i = 0; i < N; i++) {
            // 모든 가로 길에 대해
            for (int j = 0; j < N - 1; j++) {
                int currentHeight = board[i][j];
                int nextHeight = board[i][j + 1];
                if (currentHeight > nextHeight) { // 내 앞이 낭떠러지?
                    if (currentHeight - 1 == nextHeight) { // 한칸 차이여야 한다.
                        // 앞을 L 만큼 보고 모두 nextHeight 인지 확인
                        for (int k = j + 1; k < j + 1 + L; k++) {
                            if (k >= N) continue TEST; // 지도가 끝나버리면
                            if (board[i][k] != nextHeight) continue TEST; // 높이가 달라버리면
                            if (installed[i][k]) continue TEST; // 이미 계단이 설치되었다면
                            installed[i][k] = true;
                        }
                    } else {
                        continue TEST;
                    }
                } else if (currentHeight < nextHeight) { // 절벽
                    if (currentHeight + 1 == nextHeight) { // 한칸 차이여야 한다.
                        // 뒤를 L 만큼 보고 모두 nextHeight 인지 확인
                        for (int k = j; k > j - L; k--) {
                            if (k < 0) continue TEST; // 지도가 끝나버리면
                            if (board[i][k] != currentHeight) continue TEST; // 높이가 달라버리면
                            if (installed[i][k]) continue TEST; // 이미 계단이 설치되었다면
                            installed[i][k] = true;
                        }
                    } else {
                        continue TEST;
                    }
                }
            }
            ret++;
        }

        installed = new boolean[N][N];
        // 모든 세로 길에 대해
        TEST:
        for (int i = 0; i < N; i++) {
            // 과거에 내리막길 이였는지.
            boolean pastDown = true;
            // 모든 세로 길에 대해
            for (int j = 0; j < N - 1; j++) {
                int currentHeight = board[j][i];
                int nextHeight = board[j + 1][i];
                if (currentHeight > nextHeight) { // 내 앞이 낭떠러지?
                    if (currentHeight - 1 == nextHeight) { // 한칸 차이여야 한다.
                        // 앞을 L 만큼 보고 모두 nextHeight 인지 확인
                        for (int k = j + 1; k < j + 1 + L; k++) {
                            if (k >= N) continue TEST; // 지도가 끝나버리면
                            if (board[k][i] != nextHeight) continue TEST; // 높이가 달라버리면
                            if (installed[k][i]) continue TEST; // 이미 계단이 설치되었다면
                            installed[k][i] = true;
                        }
                    } else {
                        continue TEST;
                    }
                } else if (currentHeight < nextHeight) { // 절벽
                    if (currentHeight + 1 == nextHeight) { // 한칸 차이여야 한다.
                        // 뒤를 L 만큼 보고 모두 nextHeight 인지 확인
                        for (int k = j; k > j - L; k--) {
                            if (k < 0) continue TEST; // 지도가 끝나버리면
                            if (board[k][i] != currentHeight) continue TEST; // 높이가 달라버리면
                            if (installed[k][i]) continue TEST; // 이미 계단이 설치되었다면
                            installed[k][i] = true;
                        }
                    } else {
                        continue TEST;
                    }
                }
            }
            ret++;
        }


        System.out.print(ret);

    }
}
