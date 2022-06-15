import java.util.*;

public class TicTacToeTreeNode {
    public String board = "         ";
    public List<TicTacToeTreeNode> children;

    public TicTacToeTreeNode() {
        children = new ArrayList<>();
    }
}