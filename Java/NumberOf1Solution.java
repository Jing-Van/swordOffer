//��һ��������1�ĸ���

//��������0x80000000��ʱ�򣬻�������ѭ��
//public class Solution {
//public int NumberOf1(int n) {
//    int count =0;
//    while(n != 0) {
//        if((n & 1) == 1)
//            ++count;
//        n = n >> 1;
//    }
//    return count;
//  }
//}

//ת��˼·����ÿλ����1���룬�жϽ������Ҫ�ж�32��
//public class Solution {
//public int NumberOf1(int n) {
//    int flag = 1;
//    int count =0;
//    while(flag != 0 ) {
//       
//        if((n & flag) != 0)
//            ++count;
//        flag = flag << 1;
//    }
//    return count;
//  }
//}

//ת��˼·��ֻ��Ҫ�ж�1�ĸ�����ô���
//���ɣ�n = n&(n-1)���ǽ�n����������ұߵ��Ǹ�1��Ϊ0
public class NumberOf1Solution {
  public int NumberOf1(int n) {
      int count =0;
      while(n != 0 ) {
          n = n &(n-1);
          ++count;
      }
      return count;
  }
}
//class Test {
//public static void main(String[] args) {
//    Solution test = new Solution();
//    int n = test.NumberOf1(0x80000000);
//    System.out.println(n);
//}
//}


//test
//2