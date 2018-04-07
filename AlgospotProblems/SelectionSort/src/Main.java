/**
 * Created by huming on 2/16/16.
 */
public class Main {

    public static void main(String[] args) {

        int[] data = { 9,1,6,8,4,3,2,0};

        int mIndex, temp;
        for(int i=0; i<data.length-1; i++) {
            mIndex = i;
            for (int j = i+1; j < data.length; j++) {
                if (data[mIndex] > data[j]) {
                    mIndex = j;
                }
            }
            temp = data[mIndex];
            data[mIndex] = data[i];
            data[i] = temp;
        }

        for(int i=0; i<data.length; i++)
            System.out.print(data[i]);
    }
}
