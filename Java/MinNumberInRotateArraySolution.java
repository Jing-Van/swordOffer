//��һ����ת�������СֵԪ��
public class MinNumberInRotateArraySolution {
  public int minNumberInRotateArray(int [] array) {
      int length = array.length;
      if(length == 0)
          return 0;

      int low = 0;
      int high = length-1;
      int mid = (low+high)/2;
      while(low < high) { 
          if((high - low) == 1) {
              if(array[low] < array[high])
                  return array[low];
              else
                  return array[high];
          }
           
          if(array[low] == array[mid] && array[mid] == array[high]) {
              return minInOrder(array);
          }
            
          if(array[mid] > array[high]) {
              low = mid;
          }
          else {
              high = mid;
          }          
          mid = (low+high)/2;            
           
      }
       
      return array[mid];
       
  }
   
  private int minInOrder(int[] array) {
      int min = array[0];
      for(int i=0; i < array.length -1; ++i) {
          if(array[i+1]<array[i])
              min = array[i+1];
      }
      return min;
  }
}
//class Test {
//public static void main(String[] args) {
//    Solution test = new Solution();
//    int[] array = {1,2,3,4,5};
//    int n = test.minNumberInRotateArray(array);
//    System.out.println(n);
//}
//}


//test
//{1,2,3,4,5}
//{3,4,5,6,7,1,2}
//ԭʼ��{1,2,2,2,2,2},��ת����1��{2,2,1,2,2,2}����ת����2��{2,2,2,2,1,2}
//