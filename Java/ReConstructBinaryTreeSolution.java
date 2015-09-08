//���ݶ�������ǰ�����к��������У��������ö�����
//����ǰ�����еĵ�һ��Ϊ���ڵ㣬�����������б������ڵ���Եõ���������������
//ͨ���ݹ飬���Թ������Ŷ�����

public class ReConstructBinaryTreeSolution {
  public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
      int length = pre.length;
      if(length <= 0) return null;
       
      int preStart = 0;
      int preEnd = length-1;
      int inStart = 0;
      int inEnd = length-1;
      return constructBinaryTree(pre, preStart, preEnd,
              in, inStart, inEnd);   
  }
   
  private TreeNode constructBinaryTree(int[] pre, int preStart, int preEnd,
          int[] in, int inStart, int inEnd) {
      int rootValue = pre[preStart];
      TreeNode root = new TreeNode(rootValue);
      root.left = null;
      root.right = null;
       
      //�ݹ�����һ�Σ�����root�ڵ�
      if(preStart == preEnd) {
          if(inStart == inEnd && pre[preStart] == in[inStart]) {
              return root;
          }
      }
       
      //�����������У��ҵ����ڵ�
      int rootIndex=inStart;
      while(rootIndex <= inEnd) {
          if(in[rootIndex] == rootValue) break;
          if(rootIndex == inEnd) {
              System.out.println("input is unvalid!");
          }
          else ++rootIndex;
      }
       
      int leftTreeLength = rootIndex-inStart;
      int leftPreEnd = preStart+leftTreeLength;
      if(leftTreeLength > 0) {
          //����������
          root.left = constructBinaryTree(pre, preStart+1, leftPreEnd,
                  in, inStart, rootIndex-1);
      }
      if(leftTreeLength < preEnd-preStart) {
          //����������
          root.right = constructBinaryTree(pre, leftPreEnd+1, preEnd,
                  in, rootIndex+1, inEnd);
      }
      return root;
  }
}
//class Test {
//public static void main(String[] args) {
//    Solution test = new Solution();
//    int[] pre = {1,2,4,7,3,5,6,8};
//    int[] in = {4,7,2,1,5,3,8,6};
//    TreeNode n = test.reConstructBinaryTree(pre, in);
//    //System.out.println(n);
//}
//}


//test
//{1,2,3,4,5}
//{3,4,5,6,7,1,2}
//ԭʼ��{1,2,2,2,2,2},��ת����1��{2,2,1,2,2,2}����ת����2��{2,2,2,2,1,2}
//