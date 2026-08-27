/**
 * linear-time  maximum contiguous subsequence sum algorithm.z
 */

public static int maxSubSum(int[] a) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 0 ; i < N ; i++ ){
        thisSum += array[i];

        if(thisSum > maxSum){
            maxSum = thisSum;
        }
        else if(thisSum < 0){
            thisSum = 0;
        }
    }

    return maxSum;
}