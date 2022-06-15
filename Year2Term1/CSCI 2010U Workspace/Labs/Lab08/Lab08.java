public class Lab08 {
    public static void main(String[] args) {
        String board = "x ox xo o";
        TicTacToeTreeNode root = TicTacToeTree.createNode(board, "x");
        System.out.print(TicTacToeTree.treeToString(root));
    }
}