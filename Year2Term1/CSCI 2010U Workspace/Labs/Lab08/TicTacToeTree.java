public class TicTacToeTree {
    private static TicTacToeTreeNode root = new TicTacToeTreeNode();

    public static String treeToString(TicTacToeTreeNode rootNode){
        String newString = "";
        for(int i = 0; i < rootNode.children.size(); i++){
            newString = newString + nodeToString(rootNode.children.get(i), 1);
        }
        return newString;
    }
    
    public static String nodeToString(TicTacToeTreeNode node, int indentation){
        System.out.println(node.board);
        return node.board;
    }

    public static TicTacToeTreeNode createNode(String board, String player){
        TicTacToeTreeNode newNode = new TicTacToeTreeNode();
        System.out.println(board);
        root.board = board;
        if(board.indexOf(' ') != -1){   //if the board is not full, then..
            if(player == "x"){
                char[] charArray = board.toCharArray();
                charArray[board.indexOf(' ')] = 'x';
                String newBoard = new String(charArray);
                newNode.board = newBoard;
                root.children.add(newNode);
                return createNode(newBoard, "o");
            }else if(player == "o"){
                char[] charArray = board.toCharArray();
                charArray[board.indexOf(' ')] = 'o';
                String newBoard = new String(charArray);
                newNode.board = newBoard;
                root.children.add(newNode);
                return createNode(newBoard, "x");
            }
        }else{
            System.out.println(root.board);
            return root.children.get(0);
        }
        System.out.println(root.board);
        return root.children.get(0);
    }


    public static String makeMove(String oldBoard, int position, String player) {
        return oldBoard.substring(0, position) + player + oldBoard.substring(position + 1);
    }    

} 