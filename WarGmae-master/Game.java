import java.util.LinkedList;

/**
*class Game
*create player1
*create player2
*num_Battle: total Battle number in one game
*num_War: total war number in one game
*double_War: total double war number in one game
*/
public class Game
{
  private Player p1 = new Player(1);
  private Player p2 = new Player(2);
  private LinkedList<Card> p1_List = new LinkedList<Card>();
  private LinkedList<Card> p2_List = new LinkedList<Card>();
  private LinkedList<Card> p1_List2 = new LinkedList<Card>();
  private LinkedList<Card> p2_List2 = new LinkedList<Card>();
  private LinkedList<Card> tempList = new LinkedList<Card>();
  private int num_Battle;//total Battle number in one game
  private int num_War;//total war number in one game
  private int double_War;//total double war number in one game
  private boolean b1;
  private boolean b2;

  /**
  *Game()
  *default constructor
  */
  public Game()
  {
    num_Battle = 0;
    num_War = 0;
    double_War = 0;
    b1 = true;
    b2 = true;
  }

  /**
  *Compare(Card c1, Card c2)
  *override constructor
  *@param c1 first card
  *@param c2 second card
  *if the first card has larger value, then player1 gets all the cards
  *if player1 wins the card, the screen will display "Player1 wins"
  *if there is a war, put card 1 and 2 into an temp list to temp storage
  *if the deck has more than 4 card, both player flip three times
  *if it's still a war, then double war count + 1
  *if one of the player has less than or equal to 4 cards, the game will compare te last card with another.
  *if the player only has 1 card and both player has teh same card, this player lost the game
  */
  public void Compare(Card c1, Card c2)
  {
    if(c1.getValue() > c2.getValue())
    {
      p1.collect(c1);
      p1.collect(c2);
      for(Card cards : tempList)
      {
        p1.collect(cards);
      }
      tempList.clear();
      System.out.println("player1 wins.");
      num_Battle++;
      this.CheckWin();

    }
    else if(c1.getValue() < c2.getValue())
    {
      p2.collect(c2);
      p2.collect(c1);
      for(Card cards : tempList)
      {
        p2.collect(cards);
      }
      tempList.clear();
      System.out.println("player2 wins.");
      num_Battle++;
      this.CheckWin();
    }
    else if(c1.getValue() == c2.getValue())
    {
      System.out.println("That's a war.");
      num_Battle++;
      tempList.add(c1);
      tempList.add(c2);
      num_War++;

      if(p1.getListLength() > 4 && p2.getListLength() > 4)
      {
        for(int i=0; i<3; i++)
        {
          tempList.add(p1.flip());
          tempList.add(p2.flip());
        }

        Card temp1 = p1.flip();
        Card temp2 = p2.flip();

        if(temp1.getValue() == temp2.getValue())
        {
          double_War++;
        }

        this.Compare(temp1,temp2);//recursion
      }
      else if(p1.getListLength() <= 4 && p2.getListLength() > 4)
      {
        if(p1.getListLength() <= 1)
        {
          this.printWin(2);
          b2 = false;
        }
        else
        {
          for(int i=0; i<3; i++)
          {
            tempList.add(p2.flip());
          }
          p1_List.addAll(p1.getList());
          this.Compare(p1_List.getLast(), p2.flip());
        }
      }
      else if(p2.getListLength() <= 4 && p1.getListLength() > 4)
      {
        if(p2.getListLength() <= 1)
        {
          this.printWin(1);
          b1 = false;
        }
        else
        {
          for(int i=0; i<3; i++)
          {
            tempList.add(p1.flip());
          }
          p2_List.addAll(p2.getList());
          this.Compare(p1.flip(), p2_List.getLast());
        }
      }
      //there is no way both players have less than 4 cards, so these codes are useless.

      // else if(p1.getListLength() < 4 && p2.getListLength() < 4)
      // {
      //   p1_List2.addAll(p1.getList());
      //   p2_List2.addAll(p2.getList());
      //   if(p1.getListLength() <= 1)
      //   {
      //     this.printWin(2);
      //     b2 = false;
      //   }
      //   else if(p2.getListLength() <= 1)
      //   {
      //     this.printWin(1);
      //     b1 = false;
      //   }
      //   else if(p1.getListLength() <= 1 && p2.getListLength() <= 1)
      //   {
      //     b1 = false;
      //     b2 = false;
      //     System.out.println("There is no winner in this round.");
      //     System.exit(0);
      //   }
      //   else
      //   {
      //     if(p1_List2.getLast().getValue() > p2_List2.getLast().getValue())
      //     {
      //       this.printWin(1);
      //       b1 = false;
      //     }
      //     else if(p1_List2.getLast().getValue() < p2_List2.getLast().getValue())
      //     {
      //       this.printWin(2);
      //       b2 = false;
      //     }
      //     else if(p1_List2.getLast().getValue() == p2_List2.getLast().getValue())
      //     {
      //       System.out.println("There is no winner in this round.");
      //       System.exit(0);
      //     }
      //   }
      // }
    }
  }

/**
*Play()
*keep playing until one player wins
*/
  public void Play()
  {
    //print the rule
    System.out.println("==========================RULE==========================");
    System.out.println("In the game of War, two players battle each other to see who can win the most cards.");
    System.out.println("At the start of a single game a deck of 52 cards (legal values 2-10, J, Q, K, A) is split evenly\nbetween the two players such that each player holds a stack of 26 random cards.");
    System.out.println("For each battle of the game both players turn over the card at the top of their stack.");
    System.out.println("The player with the higher-valued card tales both cards and places the, on the bottom of their stack.");
    System.out.println("========================================================");

    b1 = true;
    b2 = true;

    while(b1 && b2)
    {
      Card a = p1.flip();
      Card b = p2.flip();

      this.Compare(a, b);
    }
  }
/**
*getBattle()
*@return the number of battles
*/
  public int getBattle()
  {
    return num_Battle;
  }

  /**
  *getWar()
  *@return number of wars
  */
  public int getWar()
  {
    return num_War;
  }

  /**
  *getDoubleWar()
  *@return number of double wars
  */
  public int getDoubleWar()
  {
    return double_War;
  }

/**
*printWin(int w)
@param w print which player wins the game
*if one player wins, show the congratulation message
*/
  public void printWin(int w)
  {
    System.out.println("---");
    System.out.println("---");
    System.out.println("---");
    System.out.println("Player " + w + " has won the Game! Congratulations!");
    System.out.println("---");
    System.out.println("---");
    System.out.println("---");
  }

/**
*CheckWin()
*if one of the player win, quit the loop
*/
  public void CheckWin()
  {
    if(p1.hasWon() || p2.hasWon())
    {
      if(p1.hasWon())
      {
        this.printWin(1);
      }
      else if(p2.hasWon())
      {
        this.printWin(2);
      }
      b1 = false;
    }
  }



//just for testing while coding
  // public static void main(String[] args)
  // {
  //   Game a = new Game();
  //   a.Play();
  // }
}
