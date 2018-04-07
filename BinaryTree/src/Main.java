import javax.swing.*;
import java.util.Stack;

/**
 * Created by huming on 3/4/16.
 */

class Node {
    private Node left;
    private Node right;
    private int value;

    public Node(Node left, Node right, int value) {
        this.left = left;
        this.right = right;
        this.value = value;
    }

    public Node getLeft() {
        return left;
    }

    public Node getRight() {
        return right;
    }

    public int getValue() {
        return value;
    }

}

public class Main
{

    public static void main(String[] args) {

        Node FinalLeaf = new Node( null, null, 110);

        Node LeafA = new Node( null, null, 25);
        Node LeafB = new Node( null, null, 75);
        Node LeafC = new Node( FinalLeaf, null, 125);
        Node LeafD = new Node( null, null, 175);

        Node ParentA = new Node( LeafA, LeafB, 50);
        Node ParentB = new Node( LeafC, LeafD, 150);

        Node Root = new Node( ParentA, ParentB, 100);

        Node result = LookUpNode(Root, 100);

        System.out.println("The Node is " + result + " Value is " + result.getValue());

        result = LookUpNodeRecursive(Root, 100);

        System.out.println("Recursive Node is " + result + " Value is " + result.getValue());

        System.out.print("\nRecursive DFS : ");
        RecursiveDFS(Root);
        System.out.print("\n\nNormal DFS : ");
        DFS(Root);
    }

    public static Node LookUpNode(Node root, int value)
    {
        Node CurNode = root;
        while( CurNode != null)
        {
            if( CurNode.getValue() == value)
                break;

            if ( CurNode.getValue() < value)
            {
                CurNode = CurNode.getRight();
            }
            else if ( CurNode.getValue() > value)
            {
                CurNode =  CurNode.getLeft();
            }
        }
        return CurNode;
    }

    public static Node LookUpNodeRecursive(Node root, int value) {

        if (root.getValue() == value)
            return root;

        if (root.getValue() > value)
            return LookUpNodeRecursive(root.getLeft(), value);
        else if (root.getValue() < value)
            return LookUpNodeRecursive(root.getRight(), value);

        return null;
    }

    public static void RecursiveDFS(Node root)
    {
        if( root != null)
            System.out.print(root.getValue()+" ");

        if( root.getLeft() != null)
            RecursiveDFS( root.getLeft());
        if( root.getRight() != null)
            RecursiveDFS( root.getRight());
    }

    public static void DFS(Node root)
    {
        Stack st = new Stack();

        st.push(root);

        while(!st.empty())
        {
            Node CurNode = (Node)st.pop();
            System.out.print( CurNode.getValue() + " " );

            if( CurNode.getRight() != null)
                st.push( CurNode.getRight() );
            if( CurNode.getLeft() != null)
                st.push( CurNode.getLeft() );
        }

    }
}
