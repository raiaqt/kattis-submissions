import java.util.Scanner;
import java.lang.StringBuilder;

public class BasicProgramming1 {
    private static Scanner sc;
    static int[] A;
    static int N, T;

    static void swap(int[] B, int i, int j) {
        int t = B[i];
        B[i] = B[j];
        B[j] = t;
    }

    static String printSeven() {
        return "7";
    }

    static String compareZeroOne() {
        if (A[0] > A[1]) {
            return "Bigger";
        } else if (A[0] == A[1]) {
            return "Equal";
        } else {
            return "Smaller";
        }
    }


    static String getMedian() {
        int[] B = {A[0], A[1], A[2]};
        if (B[0] < B[1]) {
            swap(B, 0, 1);
        }
        if (B[1] < B[2]) {
            swap(B, 1, 2);
        }
        if (B[0] < B[1]) {
            swap(B, 0, 1);
        }

        return "" + B[1];
    }

    static String getSum() {
        long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i];
        }
        return "" + sum;
    }

    static String getSumEven() {
        long sum = 0;
        for (int i= 0; i < N; i++) {
            if (A[i] % 2 == 0) {
                sum += A[i];
            }
        }
        return "" + sum;
    }

    static String getCharString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append((char) ('a' + A[i] % 26));
        }
        return sb.toString();
    }

    static String jumpIndices() {
        boolean[] visited = new boolean[N];

        int curr = 0;
        while (curr != N - 1) {
            if (curr > N - 1) {
                return "Out";
            }
            if (visited[curr]) {
                return "Cyclic";
            }
            visited[curr] = true;
            curr = A[curr];
        }
        return "Done";
    }

    public static void main(String[] args) {
       sc = new Scanner(System.in);

       N = sc.nextInt();
       T = sc.nextInt();

       A = new int[N];

       for (int i = 0; i < N; i++) {
           A[i] = sc.nextInt();
       }

       String res = "";
       switch (T) {
           case 1:
               res = printSeven();
               break;
           case 2:
               res = compareZeroOne();
               break;
           case 3:
               res = getMedian();
               break;
           case 4:
               res = getSum();
               break;
           case 5:
               res = getSumEven();
               break;
           case 6:
               res = getCharString();
               break;
           case 7:
               res = jumpIndices();
               break;
           default:
               break;
       }

       System.out.println(res);
    }
}