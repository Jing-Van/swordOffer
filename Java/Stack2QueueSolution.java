//ʹ������stackʵ��һ�����У�ʵ��ѹ��͵����Ĳ���
import java.util.ArrayList;
import java.util.Stack;
public class Stack2QueueSolution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    //ʹ��ջ1���������ݵ�ѹ�����
    public void push(int node) {
        stack1.push(node);     
    }
    //ʹ��ջ2���������ݵĵ�������
    //��ջ2��Ϊ�յ�ʱ��ֱ�ӵ��������Ϊ�գ���ջ1�����ݵ�����ѹ��ջ2�����ջ2ҲΪ�գ��׳��쳣
    public int pop() {
        if(stack2.isEmpty()) {
            if(stack1.isEmpty()) {
                System.out.println("û�����ݵ���");
                return 0;
            } else {
                //ѭ����ջ1������ȡ�����ŵ�ջ2��
                while(stack1.isEmpty() == false) {
                    int data = stack1.pop();
                    stack2.push(data);
                }
                return stack2.pop();
            }
             
        } else {
            return stack2.pop();
        }      
    
    }
}
//class Test {
//  public static void main(String[] args) {
//      Solution test = new Solution();
//      test.push(1);
//      test.push(2);
//      test.push(3);
//      System.out.println(test.pop());
//      System.out.println(test.pop());
//      System.out.println(test.pop());
//  }
//}
 
 
//test
//{1,2,3,4,5}